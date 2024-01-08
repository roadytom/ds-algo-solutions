package pramp.flattendictionary


class Solution1 {
  fun flattenDictionary(dict: HashMap<String, Any>): HashMap<String, String> {
    val source = HashMap<String, String>()
    doGenerate("", dict, source)
    return source
  }

  private fun doGenerate(upperKey: String, dict: HashMap<String, Any>, source: HashMap<String, String>) {
    // think about base case
    for ((key, value) in dict) { //O(n) //Memory -
      val currentKey = if (upperKey != "" && key != "") {
        "$upperKey.$key"
      } else if (upperKey != "") {
        upperKey
      } else {
        key
      }
      if (value is HashMap<*, *>) {
        doGenerate(currentKey, value as HashMap<String, Any>, source)
      } else {
        if (currentKey != "") {
          source[currentKey] = value as String
        }
      }
    }
  }
}