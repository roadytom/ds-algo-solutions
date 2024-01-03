package leetcode.kotlin.dp1d.validparenthesisstring678

class Solution2 {
  fun checkValidString(s: String): Boolean {
    val memo = Array(s.length) { Array<Boolean?>(s.length) { null } }
    return checkValidString(s, 0, s.length - 1, memo)
  }

  private fun checkValidString(s: String, start: Int, end: Int, memo: Array<Array<Boolean?>>): Boolean {
    if (start > end) {
      return true
    }
    memo[start][end]?.let { return it }
    // just omit current character
    if (s[start] == '*' && checkValidString(s, start + 1, end, memo)) {
      return equalizeAndReturn(memo, start, end, true)
    }
    // find pair if it is beginning of the parenthesis
    if (s[start] == '*' || s[start] == '(') {
      for (k in (start + 1)..end) {
        if ((s[k] == ')' || s[k] == '*') && checkValidString(s, start + 1, k - 1, memo) && checkValidString(
            s, k + 1, end, memo
          )
        ) {
          return equalizeAndReturn(memo, start, end, true)
        }
      }
    }
    return equalizeAndReturn(memo, start, end, false)
  }

  private fun equalizeAndReturn(memo: Array<Array<Boolean?>>, start: Int, end: Int, value: Boolean): Boolean {
    return value.also { memo[start][end] = it }
  }
}