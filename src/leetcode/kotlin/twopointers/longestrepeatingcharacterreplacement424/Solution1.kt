package leetcode.kotlin.longestrepeatingcharacterreplacement424

/**
 * not optimal solution in the worst case can be O(N*N)
 * but a little bit better
 */
class Solution1 {
    fun characterReplacement(s: String, k: Int): Int {
        val len = s.length
        var max = 1
        for (left in 0..<len) {
            val map = mutableMapOf<Char, Int>()
            var currentMax = 0
            for (right in left..<len) {
                val c = s[right]

                val currentCount = (map[c] ?: 0) + 1
                map[c] = currentCount

                currentMax = maxOf(currentCount, currentMax)
                if (right - left + 1 - currentMax <= k) {
                    max = maxOf(max, right - left + 1)
                } else {
                    //no need to continue because already not enough k
                    break;
                }
            }
        }
        return max
    }
}

fun main() {
    check(Solution1().characterReplacement("AABABBA", 1) == 4)
    check(Solution1().characterReplacement("ABAB", 2) == 4)
    check(Solution1().characterReplacement("ABBB", 2) == 4)
    check(Solution1().characterReplacement("BAAA", 0) == 3)
}