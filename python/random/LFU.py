from sortedcontainers import SortedList
from collections import namedtuple


class LFUCache:
    class FrequencyNode:
        def __init__(self, count, key, timestamp=0):
            self.count = count
            self.key = key
            self.timestamp = timestamp

        def __lt__(self, other):
            return (self.count, self.timestamp) < (other.count, other.timestamp)

        def __eq__(self, other):
            return self.count == other.count and self.key == other.key

        def __hash__(self):
            return hash(self.key)

        def __repr__(self):
            return f"FrequencyNode(count={self.count}, key={self.key})"

    def __init__(self, capacity: int):
        self.CacheNode = namedtuple("CacheNode", ["count", "value", "timestamp"])
        self.cache = {}
        # (frequency, key)
        self.frequency = SortedList()
        self.capacity = capacity
        self.timestamp = 0

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self.frequency.remove(self.FrequencyNode(node.count, key, node.timestamp))
            self.frequency.add(self.FrequencyNode(node.count + 1, key, self.timestamp + 1))
            self.cache[key] = self.CacheNode(node.count + 1, node.value, self.timestamp + 1)
            self.timestamp += 1
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.frequency.remove(self.FrequencyNode(node.count, key, node.timestamp))
            self.frequency.add(self.FrequencyNode(node.count + 1, key, self.timestamp + 1))
            self.cache[key] = self.CacheNode(node.count + 1, value, self.timestamp + 1)
        else:
            if len(self.frequency) == self.capacity:
                popped = self.frequency.pop(0)
                self.cache.pop(popped.key)
            self.cache[key] = self.CacheNode(1, value, self.timestamp + 1)
            self.frequency.add(self.FrequencyNode(1, key, self.timestamp + 1))
        self.timestamp += 1


# Your LFUCache object will be instantiated and called as such:
obj = LFUCache(2)
obj.put(3, 1)
obj.put(2, 1)
obj.put(2, 2)
obj.put(4, 4)
print(obj.get(2))
