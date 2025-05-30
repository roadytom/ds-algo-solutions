package leetcode.kotlin.binarysearch.timebasedkeyvaluestore

import leetcode.kotlin.binarysearch.timebasedkeyvaluestore.Solution1.TimeMap
import leetcode.kotlin.println


class Solution1 {
  class TimeMap {
    val keyValueMap = mutableMapOf<String, MutableList<Pair<String, Int>>>()
    fun set(key: String, value: String, timestamp: Int) {
      val list = keyValueMap[key] ?: mutableListOf()
      val insertionIndex = list.findInsertionPoint(timestamp)
      list.add(insertionIndex, value to timestamp)
      keyValueMap[key] = list
    }


    fun get(key: String, timestamp: Int): String {
      val list = keyValueMap[key]
      if (list == null) {
        return ""
      }
      val lessThanOrEqual = list.findInsertionPoint(timestamp) - 1
      return if (lessThanOrEqual != -1) {
        list[lessThanOrEqual].first
      } else {
        ""
      }
    }

    fun List<Pair<String, Int>>.findInsertionPoint(timestamp: Int): Int {
      var left = 0
      var right = size
      while (left < right) {
        val mid = (right - left) / 2 + left
        if (this[mid].second > timestamp) {
          right = mid
        } else {
          left = mid + 1
        }
      }
      return left
    }
  }
}

fun main() {
  val timeMap = TimeMap()
  timeMap.set("foo", "bar", 1) // store the key "foo" and value "bar" along with timestamp = 1.

  timeMap.get("foo", 1).println() // return "bar"

  timeMap.get(
    "foo",
    3
  )
    .println() // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".

  timeMap.set("foo", "bar2", 4) // store the key "foo" and value "bar2" along with timestamp = 4.

  timeMap.get("foo", 4).println() // return "bar2"

  timeMap.get("foo", 5).println() // return "bar2"

}