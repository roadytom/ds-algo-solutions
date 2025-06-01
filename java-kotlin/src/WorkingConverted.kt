import java.lang.Math.log
import kotlin.math.*

// Reading utilities
fun readWords() = readln().split(" ")

fun readInt() = readln().toInt()

fun readCharList() = readln().toList()

fun readIntList() = readln().split(" ").map { it.toInt() }

fun readIntList0Indexed() = readln().split(" ").map { it.toInt() - 1 }

fun readWordCharLists() = readln().split(" ").map { it.toList() }

fun readNLines(n: Int) = List(n) { readln().trim() }

fun readNLinesWords(n: Int) = List(n) { readWords() }

fun readNInts(n: Int) = List(n) { readInt() }

fun readNIntLists(n: Int) = List(n) { readIntList() }

fun readNIntLists0Indexed(n: Int) = List(n) { readIntList0Indexed() }

fun readNCharLists(n: Int) = List(n) { readCharList() }

fun readNWordCharLists(n: Int) = List(n) { readWordCharLists() }

fun perm(n: Int, r: Int): Long = (factorial(n) / factorial(r))

fun comb(n: Int, r: Int): Long = factorial(n) / (factorial(r) * factorial(n - r))

fun factorial(n: Int): Long = (1..n).fold(1L) { acc, i -> acc * i }

fun <T> makeList(n: Int, vararg dims: Int, default: T): List<Any> =
    if (dims.isEmpty()) List(n) { default as Any }
    else List(n) { makeList(dims[0], *dims.drop(1).toIntArray(), default = default) }

val dire = listOf(listOf(1, 0), listOf(0, 1), listOf(-1, 0), listOf(0, -1))
val dire8 = listOf(
    listOf(1, 0), listOf(1, 1), listOf(0, 1), listOf(-1, 1),
    listOf(-1, 0), listOf(-1, -1), listOf(0, -1), listOf(1, -1)
)
const val MOD = 1_000_000_007
val INF = Double.POSITIVE_INFINITY

class SegmentTree(arr: List<Double>) {
    private val n = arr.size
    private val tree = DoubleArray(4 * n)

    init {
        buildTree(arr, 0, 0, n - 1)
    }

    private fun buildTree(arr: List<Double>, idx: Int, left: Int, right: Int) {
        if (left == right) {
            tree[idx] = arr[left]
            return
        }
        val mid = (left + right) / 2
        buildTree(arr, 2 * idx + 1, left, mid)
        buildTree(arr, 2 * idx + 2, mid + 1, right)
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2]
    }

    fun query(queryLeft: Int, queryRight: Int): Double {
        fun doQuery(idx: Int, left: Int, right: Int): Double {
            if (right < queryLeft || left > queryRight) return 0.0
            if (queryLeft <= left && right <= queryRight) return tree[idx]
            val mid = (left + right) / 2
            val leftSum = doQuery(2 * idx + 1, left, mid)
            val rightSum = doQuery(2 * idx + 2, mid + 1, right)
            return leftSum + rightSum
        }
        return doQuery(0, 0, n - 1)
    }

    fun update(index: Int, newValue: Double) {
        fun doUpdate(treeIdx: Int, left: Int, right: Int) {
            if (left == right) {
                tree[treeIdx] = newValue
                return
            }
            val mid = (left + right) / 2
            if (index <= mid) {
                doUpdate(2 * treeIdx + 1, left, mid)
            } else {
                doUpdate(2 * treeIdx + 2, mid + 1, right)
            }
            tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2]
        }
        doUpdate(0, 0, n - 1)
    }
}

fun main() {
    val nodesCount = readInt()
    val tree = List(nodesCount) { mutableListOf<Int>() }
    repeat(nodesCount - 1) {
        val (a, b) = readIntList0Indexed()
        tree[a].add(b)
        tree[b].add(a)
    }

    val inTime = IntArray(nodesCount) { -1 }
    val outTime = IntArray(nodesCount) { -1 }

    fun convertTreeToArrayWithEulerTour() {
        fun dfs(node: Int, parent: Int, timer: Int): Int {
            inTime[node] = timer
            var localTimer = timer
            for (child in tree[node]) {
                if (child == parent) continue
                localTimer = dfs(child, node, localTimer + 1)
            }
            outTime[node] = localTimer
            return localTimer
        }
        dfs(0, -1, 0)
    }

    convertTreeToArrayWithEulerTour()
    val segmentTree = SegmentTree(List(nodesCount) { 0.0 })

    val q = readInt()
    repeat(q) {
        val (t, xRaw, yRaw) = readIntList()
        val x = xRaw - 1
        if (t == 1) {
            val left = inTime[x]
            val y = ln(yRaw.toDouble())
            segmentTree.update(left, y)
        } else {
            val y = yRaw - 1
            val xLeft = inTime[x]
            val xRight = outTime[x]
            val yLeft = inTime[y]
            val yRight = outTime[y]
            val xSubtreeVal = segmentTree.query(xLeft, xRight)
            val ySubtreeVal = segmentTree.query(yLeft, yRight)
            val logDiff = xSubtreeVal - ySubtreeVal
            val ansLog = max(ln(1e-9), min(ln(1e9), logDiff))
            println("%.10f".format(exp(ansLog)))
        }
    }
}