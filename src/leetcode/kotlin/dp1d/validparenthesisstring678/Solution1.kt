package leetcode.kotlin.dp1d.validparenthesisstring678

import leetcode.kotlin.println

/**
 * BRUTE FORCE, TLE SOLUTION
 * TIME COMPLEXITY: O(n * 3^n)
 * EXPONENTIAL
 */
class Solution1 {
  fun checkValidString(s: String): Boolean {
    return checkValidString(s, 0, StringBuilder())
  }

  private fun checkValidString(s: String, idx: Int, generatedString: StringBuilder): Boolean {
    if (s.length == idx) {
      return generatedString.isValid()
    }
    val curr = s[idx]
    var possible = false
    if (curr == '*') {
      for (sign in "()") {
        generatedString.append(sign)
        possible = possible || checkValidString(s, idx + 1, generatedString)
        generatedString.deleteAt(generatedString.lastIndex)
      }
      possible = possible || checkValidString(s, idx + 1, generatedString)
    } else {
      generatedString.append(curr)
      possible = possible || checkValidString(s, idx + 1, generatedString)
      generatedString.deleteAt(generatedString.lastIndex)
    }
    return possible
  }

  private fun StringBuilder.isValid(): Boolean {
    val stack = ArrayDeque<Char>()
    for (c in this) {
      if (c == ')') {
        if (stack.firstOrNull() == '(') {
          stack.removeFirst()
        } else {
          return false
        }
      } else {
        stack.addFirst(c)
      }
    }
    return stack.isEmpty()
  }
}

fun main() {
  Solution1().checkValidString("(*)))").println()
}