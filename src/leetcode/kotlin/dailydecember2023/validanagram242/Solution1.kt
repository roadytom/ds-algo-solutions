package leetcode.kotlin.dailydecember2023.validanagram242

/**
 * SOLUTION using HASHMAP
 */
class Solution1 {
  fun isAnagram(s: String, t: String): Boolean {
    val sCount = s.groupingBy { it }.eachCount()
    val tCount = t.groupingBy { it }.eachCount()
    return tCount.size == sCount.size && tCount.all { (char, count) ->
      val currCount = sCount[char] ?: return@all false
      currCount == count
    }
  }
}