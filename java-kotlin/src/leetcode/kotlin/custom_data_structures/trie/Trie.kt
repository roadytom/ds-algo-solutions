package leetcode.kotlin.custom_data_structures.trie

class Trie<Key> {
  val root = TrieNode<Key>(null, null)
  fun insert(list: List<Key>) {
    var current = root
    list.forEach { key ->
      val child = current.children[key] ?: TrieNode(key, current)
      current.children[key] = child
      current = child
    }
    current.isTerminating = true
  }

  fun contains(list: List<Key>): Boolean {
    var current = root
    list.forEach { key ->
      val child = current.children[key] ?: return false
      current = child
    }
    return current.isTerminating
  }

  fun collections(prefix: List<Key>): List<List<Key>> {
    var current = root
    prefix.forEach { key ->
      val child = current.children[key] ?: return emptyList()
      current = child
    }
    return collections(prefix, current)
  }

  fun collections(prefix: List<Key>, node: TrieNode<Key>?): List<List<Key>> {
    val results = mutableListOf<List<Key>>()
    if (node?.isTerminating == true) {
      results.add(prefix)
    }
    node?.children?.forEach { (key, node) ->
      results.addAll(collections(prefix + key, node))
    }
    return results
  }
}