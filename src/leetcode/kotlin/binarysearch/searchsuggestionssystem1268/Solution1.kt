package leetcode.kotlin.binarysearch.searchsuggestionssystem1268

import leetcode.kotlin.println

class Solution1 {
  fun suggestedProducts(products: Array<String>, searchWord: String): List<List<String>> {
    var start = 0
    val sortedProducts = products.sorted()
    return buildList {
      val builder = StringBuilder()
      for (c in searchWord) {
        builder.append(c)
        val (list, nextStart) = suggestedProductsForEach(sortedProducts, builder.toString(), start)
        add(list)
        start = nextStart
      }
    }
  }

  private fun suggestedProductsForEach(
    sortedProducts: List<String>, searchWord: String, start: Int
  ): Pair<List<String>, Int> {
    var left = start
    var right = sortedProducts.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (sortedProducts[mid] >= searchWord) {
        right = mid
      } else {
        left = mid + 1
      }
    }
    return if (left == sortedProducts.size) {
      emptyList<String>() to left
    } else {
      val suggestedProducts = mutableListOf<String>()
      for (index in left..minOf(left + 2, sortedProducts.lastIndex)) {
        if (isPrefix(sortedProducts[index], searchWord)) {
          suggestedProducts += sortedProducts[index]
        } else {
          break
        }
      }
      suggestedProducts to left
    }
  }

  private fun isPrefix(str: String, searchWord: String): Boolean {
    if (str.length < searchWord.length) {
      return false
    }
    var index = 0
    while (index < searchWord.length) {
      if (str[index] != searchWord[index]) {
        return false
      }
      index++
    }
    return true
  }
}

fun main() {
  Solution1().suggestedProducts(
    arrayOf("mobile", "mouse", "moneypot", "monitor", "mousepad"), "mouse"
  ).println()
  Solution1().suggestedProducts(
    arrayOf("havana"), "havana"
  ).println()
  Solution1().suggestedProducts(
    arrayOf("bags", "baggage", "banner", "box", "cloths"), "bags"
  ).println()
}