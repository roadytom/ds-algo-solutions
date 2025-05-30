class AllOne:
    class DoublyLinkedList:
        class Node:
            def __init__(self, count=1, prev=None, next=None):
                self.prev = prev
                self.next = next
                self.keys = set()
                self.count = count

            def __repr__(self):
                return f'[{self.count}:{self.keys}]'

        def __init__(self, head=None, tail=None):
            self.head = head
            self.tail = tail

        def appendleft(self, count, key):
            node = self.Node(count)
            node.keys.add(key)
            if self.head is None:
                self.head = node
                self.tail = node
            else:
                self.head.prev = node
                node.next = self.head
                self.head = node
            return node

        def append(self, count, key):
            node = self.Node(count)
            node.keys.add(key)
            if self.head is None:
                self.head = node
                self.tail = node
            else:
                self.tail.next = node
                node.prev = self.tail
                self.tail = node
            return node

        def add_next(self, count, key, node):
            if node == self.tail:
                return self.append(count, key)
            else:
                new_node = self.Node(count)
                new_node.keys.add(key)

                new_node.next = node.next
                node.next = new_node
                new_node.prev = node
                if new_node.next is not None:
                    new_node.next.prev = new_node
                return new_node

        def add_prev(self, count, key, node):
            if node == self.head:
                return self.appendleft(count, key)
            else:
                new_node = self.Node(count)
                new_node.keys.add(key)

                new_node.prev = node.prev
                node.prev = new_node
                new_node.next = node
                if new_node.prev is not None:
                    new_node.prev.next = new_node
                return new_node

        def popleft(self):
            if self.head is None:
                raise Exception("no element")
            popped = self.head
            self.head = self.head.next
            if self.head is None:
                self.tail = None
            else:
                self.head.prev = None
            return popped

        def remove(self, node):
            if self.head == node:
                self.popleft()
                return
            if self.tail == node:
                self.tail = self.tail.prev
                self.tail.next = None
                return
            node.prev.next = node.next
            node.next.prev = node.prev
            del node

        def __repr__(self):
            if self.head is None:
                return "None"
            curr = self.head
            ans = []
            while curr is not None:
                ans.append(curr.__repr__())
                curr = curr.next
            return "->".join(ans)

    def __init__(self):
        # key -> count
        self.key_to_count = {}
        # count -> Node
        self.count_to_node = {}
        self.list = self.DoublyLinkedList()

    def inc(self, key: str) -> None:
        if key not in self.key_to_count:
            self.key_to_count[key] = 1
            if 1 in self.count_to_node:
                self.count_to_node[1].keys.add(key)
            else:
                new_node = self.list.appendleft(1, key)
                self.count_to_node[1] = new_node
        else:
            curr_count = self.key_to_count[key]
            curr_node = self.count_to_node[curr_count]
            # move element to prev count
            self.key_to_count[key] = curr_count + 1
            if curr_count + 1 in self.count_to_node:
                self.count_to_node[curr_count + 1].keys.add(key)
            else:
                new_node = self.list.add_next(curr_count + 1, key, curr_node)
                self.count_to_node[curr_count + 1] = new_node
            curr_node.keys.remove(key)
            if len(curr_node.keys) == 0:
                self.list.remove(curr_node)
                del self.count_to_node[curr_count]

    def dec(self, key: str) -> None:
        curr_count = self.key_to_count[key]
        curr_node = self.count_to_node[curr_count]
        if curr_count != 1:
            self.key_to_count[key] = curr_count - 1
            if curr_count - 1 in self.count_to_node:
                self.count_to_node[curr_count - 1].keys.add(key)
            else:
                new_node = self.list.add_prev(curr_count - 1, key, curr_node)
                self.count_to_node[curr_count - 1] = new_node
        else:
            del self.key_to_count[key]
        curr_node.keys.remove(key)
        if len(curr_node.keys) == 0:
            self.list.remove(curr_node)
            del self.count_to_node[curr_count]

    def getMaxKey(self) -> str:
        if self.list.tail is None:
            return ""
        keys = self.list.tail.keys
        return next(iter(keys))

    def getMinKey(self) -> str:
        if self.list.head is None:
            return ""
        keys = self.list.head.keys
        return next(iter(keys))


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc("a")
# print(obj.list)
# obj.inc("b")
# print(obj.list)
# obj.inc("b")
# print(obj.list)
# obj.inc("c")
# print(obj.list)
# obj.inc("c")
# print(obj.list)
# obj.inc("c")
# print(obj.list)
# obj.dec("b")
# print(obj.list)
# obj.dec("b")
# param_4 = obj.getMinKey()
# print(param_4)
# obj.dec("a")
# param_4 = obj.getMaxKey()
# print(param_4)
# param_4 = obj.getMinKey()
# print(param_4)
# ["AllOne","inc","inc","inc","inc","inc","dec","dec","getMaxKey","getMinKey"]
obj = AllOne()
obj.inc("hello")
print(obj.list)
obj.inc("world")
print(obj.list)
obj.inc("hello")
print(obj.list)
obj.dec("world")
print(obj.list)
obj.inc("hello")
print(obj.list)
obj.inc("leet")
print(obj.list)
print(obj.count_to_node)
print(obj.key_to_count)
print(obj.list.head)
print(obj.list.tail)
print("decccccc")
obj.dec("hello")
print(obj.list)
print(obj.count_to_node)
print(obj.key_to_count)
print(obj.list.head)
print(obj.list.tail)
print(obj.list.tail.prev)
# print(obj.list)
# obj.dec("hello")
# print(obj.list)
# obj.dec("hello")
# print(obj.list)
# print(obj.getMaxKey())
