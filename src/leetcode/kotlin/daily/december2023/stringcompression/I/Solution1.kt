package leetcode.kotlin.daily.december2023.stringcompression.I

class Solution1 {
  fun compress(chars: CharArray): Int {
    var compressedIndex = 0
    var start = 0
    while (start < chars.size) {
      var end = start + 1
      var count = 1
      while (end < chars.size && chars[start] == chars[end]) {
        count++
        end++
      }
      chars[compressedIndex++] = chars[start]
      if (count != 1) {
        for (c in count.toString()) {
          chars[compressedIndex++] = c
        }
      }
      start = end
    }
    return compressedIndex
  }
}