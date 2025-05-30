from collections import OrderedDict


class LRUCacheUsingOrderDict:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key] = value
            self.cache.move_to_end(key)
        else:
            if len(self.cache) == self.capacity:
                self.cache.popitem(False)
            self.cache[key] = value


class LRUCache:
    class DoublyLinkedList:
        def __init__(self, head=None, tail=None):
            self.head = head
            self.tail = tail

        def popleft(self):
            if self.head is None:
                raise Exception("no element")
            popped = self.head
            self.head = self.head.next
            if self.head is None:
                self.tail = None
            return popped

        def append(self, node):
            if self.head is None:
                self.head = node
                self.tail = node
            else:
                self.tail.next = node
                node.prev = self.tail
                node.next = None
                self.tail = node

        def remove(self, node):
            if self.head == node:
                self.popleft()
                return
            node.prev.next = node.next
            node.next.prev = node.prev
            del node

        def move_to_last(self, node):
            if self.tail == node:
                return
            if self.head == node:
                self.head = self.head.next
                self.head.prev = None
            else:
                node.prev.next = node.next
                node.next.prev = node.prev
            node.prev = self.tail
            node.next = None
            self.tail.next = node
            self.tail = node

    class Node:
        def __init__(self, key, val, prev=None, next=None):
            self.prev = prev
            self.next = next
            self.val = val
            self.key = key

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.doubly_linked_list = self.DoublyLinkedList()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self.doubly_linked_list.move_to_last(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.doubly_linked_list.move_to_last(node)
            node.val = value
        else:
            if self.capacity == len(self.cache):
                popped = self.doubly_linked_list.popleft()
                self.cache.pop(popped.key)
            new_node = self.Node(key, value)
            self.cache[key] = new_node
            self.doubly_linked_list.append(new_node)
            a = []
            a.pop(2)
