package leetcode.kotlin.dailydecember2023.validanagram242

/**
 * USING SORTING AND CHECKING ONE BY ONE
 */
class Solution2 {
  fun isAnagram(s: String, t: String): Boolean {
    val ss = s.toList().sorted()
    val st = t.toList().sorted()
    return ss.size == st.size && ss.zip(st).all { (fc, sc) -> fc == sc }
  }
}