package leetcode.kotlin

fun Any?.println() = println(this)

fun Array<IntArray>.print2d() {
  this.forEach { row ->
    row.forEach { value ->
      if (value != Int.MAX_VALUE) {
        print(String.format("%3d", value))
      } else {
        print(String.format("%3s", "x"))
      }
    }
    kotlin.io.println()
  }
}

fun Array<IntArray>.print2dWithString(source: String, target: String) {
  print(String.format("%3s", " "))
  for (c in target) {
    print(String.format("%3s", c))
  }
  kotlin.io.println()
  for (i in this.indices) {
    if (i < source.length) {
      print(String.format("%3s", source[i]))
    }
    for (j in this[0].indices) {
      if (this[i][j] != Int.MAX_VALUE) {
        print(String.format("%3d", this[i][j]))
      } else {
        print(String.format("%3s", "x"))
      }
    }
    kotlin.io.println()
  }
}
