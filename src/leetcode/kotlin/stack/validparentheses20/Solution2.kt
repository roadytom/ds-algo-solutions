package leetcode.kotlin.stack.validparentheses20

import leetcode.kotlin.println

/**
 * SOLUTION mimicking to VALID PARENTHESIS with * symbol
 * Greedy solution
 * WILL NOT WORK FOR THIS PROBLEM
 * I JUST TRY TO MIMIC
 * BUT IT WILL NOT WORK FOR STRING "([)]"
 */
class Solution2 {
  fun isValid(s: String): Boolean {
    val map = mutableMapOf(
      '(' to (0 to 1),
      ')' to (0 to -1),
      '[' to (1 to 1),
      ']' to (1 to -1),
      '{' to (2 to 1),
      '}' to (2 to -1),
    )
    val balance = intArrayOf(0, 0, 0)

    for (c in s) {
      val (idx, value) = map.getValue(c)
      balance[idx] += value
      if (balance[idx] < 0) {
        return false
      }
    }
    return balance.all { it == 0 }
  }
}

fun main() {
  Solution2().isValid("()[]{}").println()
  Solution2().isValid("()").println()
}