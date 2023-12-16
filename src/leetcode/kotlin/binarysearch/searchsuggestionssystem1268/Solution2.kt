package leetcode.kotlin.binarysearch.searchsuggestionssystem1268


/**
 * TIME COMPLEXITY: O(N * M + M * K)
 * BUILDING TRIE: O(N * M)
 * for each product N, insert takes len of product which is average M
 * so, building trie needs N * M, N num of product, M average length of product string
 * SEARCHING FOR SUGGESTIONS: O(M * K)
 * for each character in searchWord K characters
 *  1. retrieving TrieNode for the prefix = O(K)
 *  2. performing DFS O(3 * M) in the worst case, we traverse all characters in TRIE
 */
class Solution2 {
  fun suggestedProducts(products: Array<String>, searchWord: String): List<List<String>> {
    val trie = Trie()
    products.forEach { product ->
      trie.insert(product)
    }
    return trie.getWordsForPrefix(searchWord)
  }

  class TrieNode(var key: Char?) {
    val children = Array<TrieNode?>(26) { null }
    var isTerminating = false
  }

  class Trie {
    private val root = TrieNode(null)
    fun insert(str: String) {
      var current = root
      str.forEach { c ->
        val index = c.code - 'a'.code
        val child = current.children[index] ?: TrieNode(c)
        current.children[index] = child
        current = child
      }
      current.isTerminating = true
    }


    fun getWordsForPrefix(prefix: String): List<List<String>> {
      return prefix.mapIndexed { index, _ ->
        val currPrefix = prefix.substring(0, index + 1)
        val currNode = getPrefixTrieNode(currPrefix) ?: return@mapIndexed emptyList()
        val currResult = mutableListOf<String>()
        dfs(currNode, currPrefix, currResult)
        currResult
      }
    }

    private fun getPrefixTrieNode(prefix: String): TrieNode? {
      var current = root
      prefix.forEach { c ->
        val index = c.toIndex
        val child = current.children[index] ?: return null
        current = child
      }
      return current
    }

    private fun dfs(curr: TrieNode, prefix: String, result: MutableList<String>) {
      if (result.size == 3) {
        return
      }
      if (curr.isTerminating) {
        result.add(prefix)
      }
      curr.children.forEachIndexed { index, node ->
        if (node != null) {
          dfs(node, prefix + index.indexToChar, result)
        }
      }
    }

    val Char.toIndex: Int
      get() = this.code - 'a'.code

    val Int.indexToChar: Char
      get() = (this + 'a'.code).toChar()
  }
}



fun main() {
  Solution2().suggestedProducts(
    arrayOf("mobile", "mouse", "moneypot", "monitor", "mousepad"), "mouse"
  ).println()
  Solution2().suggestedProducts(
    arrayOf("havana"), "havana"
  ).println()
  Solution2().suggestedProducts(
    arrayOf("bags", "baggage", "banner", "box", "cloths"), "bags"
  ).println()
}

fun Any?.println() = println(this)

