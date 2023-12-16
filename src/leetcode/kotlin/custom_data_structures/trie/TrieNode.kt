package leetcode.kotlin.custom_data_structures.trie

class TrieNode<Key>(var key: Key?, var parent: TrieNode<Key>?) {
  val children: HashMap<Key, TrieNode<Key>> = HashMap()
  var isTerminating = false
}