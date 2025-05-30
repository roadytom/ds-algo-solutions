package leetcode.kotlin.daily.december2023.designfoodratingsystem2353

import java.util.*

/**
 * TIME COMPLEXITY:
 * initialization: n * log(n)
 * changing: m * log(n + m)
 * highest rating: m * log(n + m)
 * TOTAL: n * log(n) + m * log(n + m)
 */
class Solution1

class FoodRatings1(foods: Array<String>, cuisines: Array<String>, ratings: IntArray) {
  private val cuisineToFood = mutableMapOf<String, PriorityQueue<Pair<String, Int>>>()
  private val foodRating = mutableMapOf<String, Int>()
  private val foodToCuisine = mutableMapOf<String, String>()

  init {
    for (index in 0..foods.lastIndex) {
      val food = foods[index]
      val cuisine = cuisines[index]
      val rating = ratings[index]

      val pq = cuisineToFood[cuisine] ?: PriorityQueue { a, b ->
        if (a.second != b.second) b.second - a.second else a.first.compareTo(b.first)
      }
      pq.offer(food to rating)
      cuisineToFood[cuisine] = pq

      foodRating[food] = rating

      foodToCuisine[food] = cuisine
    }
  }

  fun changeRating(food: String, newRating: Int) {
    if (food !in foodRating || food !in foodToCuisine) {
      throw IllegalArgumentException("food not exist")
    }
    foodRating[food] = newRating

    val cuisine = foodToCuisine[food]
    val pq = cuisineToFood[cuisine] ?: throw IllegalArgumentException("cuisine not exit")
    pq.offer(food to newRating)
  }

  fun highestRated(cuisine: String): String {
    val pq = cuisineToFood[cuisine] ?: throw IllegalArgumentException("cuisine not exist")
    var (food, rating) = pq.peek()
    while (foodRating[food] != rating) {
      pq.poll()
      food = pq.peek().first
      rating = pq.peek().second
    }
    return food
  }
}

fun main() {
  val foodRatings = FoodRatings1(
    arrayOf(
      "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"
    ), arrayOf("korean", "japanese", "japanese", "greek", "japanese", "korean"), intArrayOf(9, 12, 8, 15, 14, 7)
  )
  foodRatings.highestRated("korean") // return "kimchi"
  // "kimchi" is the highest rated korean food with a rating of 9.
  foodRatings.highestRated("japanese") // return "ramen"
  // "ramen" is the highest rated japanese food with a rating of 14.
  foodRatings.changeRating("sushi", 16) // "sushi" now has a rating of 16.
  foodRatings.highestRated("japanese") // return "sushi"
  // "sushi" is the highest rated japanese food with a rating of 16.
  foodRatings.changeRating("ramen", 16) // "ramen" now has a rating of 16.
  foodRatings.highestRated("japanese") // return "ramen"
  // Both "sushi" and "ramen" have a rating of 16.
  // However, "ramen" is lexicographically smaller than "sushi".
}