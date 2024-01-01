class Solution1 {
  fun maxLengthBetweenEqualCharacters(s: String): Int {
    var ans = -1
    for (i in 0 until s.length) {
      for (j in s.lastIndex downTo 1) {
        if (s[i] == s[j]) {
          ans = ans.coerceAtLeast(j - i - 1)
          break
        }
      }
    }
    return ans
  }
}
fun main() {
  println(Solution1().maxLengthBetweenEqualCharacters("abca"))
}