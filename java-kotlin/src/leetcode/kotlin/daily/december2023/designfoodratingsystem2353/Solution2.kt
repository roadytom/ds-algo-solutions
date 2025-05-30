package leetcode.kotlin.daily.december2023.designfoodratingsystem2353

import leetcode.kotlin.println
import java.util.*

/**
 * TIME COMPLEXITY:
 * initialization: n * log(n)
 * changing: log(n)
 * highest rating: m * log(n)
 * TOTAL: n * log(n) + m * log(n)
 */
class Solution2
class FoodRatings2(foods: Array<String>, cuisines: Array<String>, ratings: IntArray) {
  private val foodToCuisineRating = mutableMapOf<String, Pair<String, Int>>()
  private val cuisineToFoodRating = mutableMapOf<String, TreeSet<Pair<Int, String>>>()

  init {
    for (index in 0..foods.lastIndex) {
      val food = foods[index]
      val cuisine = cuisines[index]
      val rating = ratings[index]
      foodToCuisineRating[food] = cuisine to rating
      val foodRating = cuisineToFoodRating[cuisine] ?: TreeSet { fr1, fr2 ->
        if (fr1.first != fr2.first) {
          fr1.first.compareTo(fr2.first)
        } else {
          fr2.second.compareTo(fr1.second)
        }
      }
      foodRating.add(rating to food)
      cuisineToFoodRating[cuisine] = foodRating
    }
  }

  fun changeRating(food: String, newRating: Int) {
    val (cuisine, rating) = foodToCuisineRating[food] ?: throw IllegalArgumentException("food not exist")

    val foodRating = cuisineToFoodRating[cuisine] ?: throw IllegalArgumentException("cuisine not exist")
    foodRating.remove(rating to food)
    foodRating.add(newRating to food)

    foodToCuisineRating[food] = cuisine to newRating
  }

  /**
   * O(log(N))
   */
  fun highestRated(cuisine: String): String {
    val treeSet = cuisineToFoodRating[cuisine] ?: throw IllegalArgumentException("cuisine not exist")
    return treeSet.last().second
  }
}

fun main() {
  val foodRatings = FoodRatings2(
    arrayOf(
      "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"
    ), arrayOf("korean", "japanese", "japanese", "greek", "japanese", "korean"), intArrayOf(9, 12, 8, 15, 14, 7)
  )
  foodRatings.highestRated("korean").println() // return "kimchi"
  // "kimchi" is the highest rated korean food with a rating of 9.
  foodRatings.highestRated("japanese").println() // return "ramen"
  // "ramen" is the highest rated japanese food with a rating of 14.
  foodRatings.changeRating("sushi", 16) // "sushi" now has a rating of 16.
  foodRatings.highestRated("japanese").println() // return "sushi"
  // "sushi" is the highest rated japanese food with a rating of 16.
  foodRatings.changeRating("ramen", 16) // "ramen" now has a rating of 16.
  foodRatings.highestRated("japanese").println() // return "ramen"
  // Both "sushi" and "ramen" have a rating of 16.
  // However, "ramen" is lexicographically smaller than "sushi".
}