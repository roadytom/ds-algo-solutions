from sortedcontainers import SortedList, SortedDict, SortedSet


def is_triplet(data):
    if len(data) < 3:
        return False
    dict = SortedDict()
    dict.peekitem()
    dict1 = SortedSet()
    dict3 = SortedList()
    dict3.index()
    dict1.bisect_left()
    dict.bisect_left(12)
    tree = SortedList(data[1:])
    left_minimum = data[0]
    for j in range(1, len(data) - 1):
        tree.remove(data[j])
        r = tree.bisect_left(data[j]) - 1
        l = tree.bisect_right(left_minimum)
        if l <= r:
            return True
        left_minimum = min(left_minimum, data[j])
    return False


print(is_triplet([3, 1, 4, 2]))

a = SortedList()
a.add(1)
a.add(2)
a.add(4)
print(a.bisect_left(3))
