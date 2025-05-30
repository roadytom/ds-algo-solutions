package leetcode.kotlin.daily.december2023.decodeways91

class Solution3 {
  fun numDecodings(s: String): Int {
    if (s.isEmpty()) {
      return 0
    }
    var twoBefore = 1
    var oneBefore = if (s[0] == '0') 0 else 1
    for (i in 2..s.length) {
      val c = s[i - 1]
      var curr = 0
      if (c != '0') {
        curr += oneBefore
      }
      if (s.substring(i - 2, i).toInt() in 10..26) {
        curr += twoBefore
      }
      twoBefore = oneBefore
      oneBefore = curr
    }
    return oneBefore
  }
}