#
# @lc app=leetcode id=3337 lang=python3
#
# [3337] Total Characters in String After Transformations II
#
from typing import List

# @lc code=start
L = 26
MOD = 10 ** 9 + 7


class Matrix:
    def __init__(self, clone_from=None):
        self.matrix = [[0] * L for _ in range(L)]
        for i in range(L):
            for j in range(L):
                self.matrix[i][j] = clone_from[i][j]

    def __mul__(self, other):
        result = Matrix()
        for i in range(L):
            for j in range(L):
                for k in range(L):
                    result.matrix[i][j] = (result.matrix[i][j] + self.matrix[i][k] + other[k][j]) % MOD
        return result

def I():
    identity_matrix = Matrix()
    for i in range(L):
        identity_matrix.matrix[i][i] = 1
    return identity_matrix

def fast_pow(x, y):
    if y == 0:
        return I()
    half = fast_pow(x, y // 2)
    if y % 2 == 0:
        return half * half
    else:
        return half * half * x

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        T = Matrix()
        for i in range(L):
            s = set([(x + 1) % 26 for x in range(nums[i])])
            for j in range(L):
                if j in s:
                    T.matrix[i][j] = 1

        res = fast_pow(T, t)
        f = [0] * 26
        for ch in s:
            f[ord(ch) - ord('a')] += 1
        ans = 0
        for i in range(L):
            for j in range(L):
                ans = (ans + res.matrix[i][j] * f[j]) % MOD
        return ans

# @lc code=end
