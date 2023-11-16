package leetcode.kotlin.backspacestringcompare844

class Solution1 {
    fun backspaceCompare(str1: String, str2: String): Boolean {
        val strBuilder1 = StringBuilder()
        val strBuilder2 = StringBuilder()
        return str1.backslashesRemoved() == str2.backslashesRemoved()
    }

    private fun String.backslashesRemoved(): String {
        val strBuilder = StringBuilder()
        for (c in this) {
            if (c == '#') {
                if (strBuilder.isNotEmpty()) strBuilder.deleteCharAt(strBuilder.length - 1)
            } else {
                strBuilder.append(c)
            }
        }
        return strBuilder.toString()
    }
}