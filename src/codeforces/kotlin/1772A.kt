package codeforces.kotlin

private fun solve(): Int {
    return readln().split("+")
        .sumOf { it.toInt() }
}

fun main() {
    repeat(readInt()) {
        println(solve())
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }