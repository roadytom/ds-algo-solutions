package leetcode.kotlin.stack

import java.util.*

class KotlinStack {
}


// Class MyStack, a generic class to implement a stack data structure.
class MyStack<T> {
  // A Stack object to store the elements.
  private val stack = ArrayDeque<T>()

  val isEmpty: Boolean
    // Method to check if the stack is empty.
    get() = stack.isEmpty() // Returns true if the stack is empty, false otherwise.

  // Method to add an element to the top of the stack.
  fun push(data: T) {

    stack.push(data) // Adds 'data' to the top of the stack.
  }

  // Method to remove and return the top element of the stack.
  fun pop(): T {
    if (isEmpty) {
      throw EmptyStackException() // Throws an exception if the stack is empty.
    }
    return stack.pop() // Returns and removes the top element of the stack.
  }

  // Method to return the top element of the stack without removing it.
  fun peek(): T {
    if (isEmpty) {
      throw EmptyStackException() // Throws an exception if the stack is empty.
    }
    return stack.peek() // Returns the top element of the stack without removing it.
  }
}
