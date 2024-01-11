package pramp.findpairswithgivendifference

class Solution1 {
  fun findPairsWithGivenDifference(arr: IntArray, k: Int): Array<IntArray> {
    val result = mutableListOf<Pair<Int, Int>>()
    val set = mutableSetOf<Int>()
    for (e in arr) {
      set += e
    }
    for (y in arr) {
      if ((k + y) in set) {
        result.add((k + y) to y)
      }
    }
    return result.map { p -> intArrayOf(p.first, p.second) }.toTypedArray()
  }
}