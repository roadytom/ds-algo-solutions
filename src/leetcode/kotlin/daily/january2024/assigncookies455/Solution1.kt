package leetcode.kotlin.daily.january2024.assigncookies455

class Solution1 {
  fun findContentChildren(children: IntArray, cookies: IntArray): Int {
    children.sort()
    cookies.sort()
    var cookieIndex = 0
    var answer = 0
    for (child in children) {
      while (cookieIndex < cookies.size && child > cookies[cookieIndex]) {
        cookieIndex++
      }
      if (cookieIndex < cookies.size) {
        answer++
				cookieIndex++
      }
    }
    return answer
  }
}

fun main(args: Array<String>) {
  println(Solution1().findContentChildren(intArrayOf(1, 2), intArrayOf(1, 2, 3)))
}