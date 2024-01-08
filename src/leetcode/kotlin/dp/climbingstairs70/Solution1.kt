package leetcode.kotlin.dp.climbingstairs70


class Solution1 {
  fun climbStairs(n: Int): Int {
    return climbMemoized(0, n)
  }

  val climbMemoized = { a: Int, b: Int -> climb(a, b) }.memoize()

  private fun climb(current: Int, n: Int): Int {
    return if (current > n) 0
    else if (current == n) {
      1
    } else climbMemoized(current + 1, n) + climbMemoized(current + 2, n)
  }


  private class Memoize<in T, in Dummy, out R>(val f: (T, Dummy) -> R) : (T, Dummy) -> R {
    private val values = mutableMapOf<T, R>()

    override operator fun invoke(x: T, d: Dummy): R {
      return values.getOrPut(x) { f(x, d) }
    }
  }

  private fun <T, Dummy, R> ((T, Dummy) -> R).memoize(): (T, Dummy) -> R = Memoize(this)
}


fun main() {
  println(Solution1().climbStairs(10))
}