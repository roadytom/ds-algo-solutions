package leetcode.kotlin

class Memoize<in T, out R>(val f: (T) -> R) : (T) -> R {
  private val values = mutableMapOf<T, R>()

  override operator fun invoke(x: T): R {
    return values.getOrPut(x) { f(x) }
  }
}

class Memoize2<in T, in Dummy, out R>(val f: (T, Dummy) -> R) : (T, Dummy) -> R {
  private val values = mutableMapOf<T, R>()

  override operator fun invoke(x: T, d: Dummy): R {
    return values.getOrPut(x) { f(x, d) }
  }
}

class Test(val a: Int) {
  operator fun invoke(): String {
    return "a"
  }
}


fun <T, R> ((T) -> R).memoize(): (T) -> R = Memoize(this)
