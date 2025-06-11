class Solution:
    def findLexicographicallyLargestSuffix(self, string: str) -> str:
        """
        Find the lexicographically largest suffix of the string.

        This uses a clever two-pointer technique:
        - We maintain two candidates for the best suffix starting at positions 'left' and 'right'
        - We compare these suffixes character by character
        - When we find a difference, we keep the better one and move the pointers optimally

        Key insight: If we're comparing suffixes starting at positions i and j,
        and they match for k characters, then if s[i+k] < s[j+k], we know that
        suffix starting at j is better. But we can also eliminate all positions
        between i and i+k as potential candidates because they would all be worse than j.
        """
        left_candidate = 0  # Position of current best suffix candidate
        right_candidate = 1  # Position of alternative suffix to compare
        string_length = len(string)

        while right_candidate < string_length:
            # Compare suffixes starting at left_candidate and right_candidate
            match_length = 0  # How many characters match from the start

            # Find the length of common prefix between the two suffixes
            while (right_candidate + match_length < string_length and
                   string[left_candidate + match_length] == string[right_candidate + match_length]):
                match_length += 1

            # If we've reached the end, right_candidate suffix is shorter, so left wins
            if right_candidate + match_length >= string_length:
                right_candidate = right_candidate + match_length + 1
            # If left_candidate suffix has smaller character, right_candidate wins
            elif string[left_candidate + match_length] < string[right_candidate + match_length]:
                # Update left_candidate to right_candidate position
                # Also, we can skip positions between left_candidate and left_candidate + match_length
                # because they would all lose to right_candidate
                next_left = right_candidate
                next_right = max(right_candidate + 1, left_candidate + match_length + 1)
                left_candidate, right_candidate = next_left, next_right
            else:
                # left_candidate suffix has larger character, so it wins
                # We can skip to right_candidate + match_length + 1
                right_candidate = right_candidate + match_length + 1

        return string[left_candidate:]

    def findLexLargestString(self, word: str, numFriends: int) -> str:
        """
        Find the lexicographically largest string that can appear in any valid split.

        Strategy:
        1. If numFriends == 1, we take the entire word as one part
        2. Otherwise, find the lexicographically largest suffix of the word
        3. Truncate this suffix to the maximum allowed length for a single part

        Why this works:
        - The lexicographically largest suffix gives us the best possible starting point
        - We can only take at most (n - numFriends + 1) characters for our part
          because we need to leave at least (numFriends - 1) characters for other parts
        """
        if numFriends == 1:
            return word

        # Find the lexicographically largest suffix
        largest_suffix = self.findLexicographicallyLargestSuffix(word)

        word_length = len(word)
        suffix_length = len(largest_suffix)

        # Maximum length our chosen part can have
        max_part_length = word_length - numFriends + 1

        # Take at most max_part_length characters from the largest suffix
        return largest_suffix[:min(suffix_length, max_part_length)]


# Let's trace through the algorithm with examples
def trace_algorithm():
    solution = Solution()

    print("=== Tracing the algorithm ===\n")

    # Example 1: word = "dbca", numFriends = 2
    print("Example 1: word = 'dbca', numFriends = 2")
    print("Step 1: Find lexicographically largest suffix")
    print("  Suffixes: 'dbca', 'bca', 'ca', 'a'")
    print("  Largest: 'dbca' (starts with 'd' which is largest)")
    print("Step 2: Calculate max_part_length = 4 - 2 + 1 = 3")
    print("Step 3: Take first 3 characters of 'dbca' = 'dbc'")
    result1 = solution.findLexLargestString("dbca", 2)
    print(f"Result: '{result1}'\n")

    # Example 2: word = "abc", numFriends = 2
    print("Example 2: word = 'abc', numFriends = 2")
    print("Step 1: Find lexicographically largest suffix")
    print("  Suffixes: 'abc', 'bc', 'c'")
    print("  Largest: 'c' (lexicographically largest)")
    print("Step 2: Calculate max_part_length = 3 - 2 + 1 = 2")
    print("Step 3: Take first min(1, 2) = 1 character of 'c' = 'c'")
    result2 = solution.findLexLargestString("abc", 2)
    print(f"Result: '{result2}'\n")

    # Example 3: word = "gggg", numFriends = 4
    print("Example 3: word = 'gggg', numFriends = 4")
    print("Step 1: Find lexicographically largest suffix")
    print("  All suffixes are identical: 'gggg', 'ggg', 'gg', 'g'")
    print("  Largest: 'gggg' (first one, they're all equal)")
    print("Step 2: Calculate max_part_length = 4 - 4 + 1 = 1")
    print("Step 3: Take first min(4, 1) = 1 character of 'gggg' = 'g'")
    result3 = solution.findLexLargestString("gggg", 4)
    print(f"Result: '{result3}'\n")


def explain_suffix_algorithm():
    print("=== How the suffix finding algorithm works ===\n")
    print("The key insight is that we use two pointers to efficiently find")
    print("the lexicographically largest suffix without comparing all O(n²) pairs.\n")

    print("Algorithm steps:")
    print("1. Start with two candidates: position 0 and position 1")
    print("2. Compare their suffixes character by character")
    print("3. When we find a difference:")
    print("   - If left < right: right wins, move left to right's position")
    print("   - If left > right: left wins, move right forward")
    print("4. Key optimization: when left loses, we can skip positions")
    print("   because they would also lose to the same right candidate\n")

    print("Time complexity: O(n) - each character is examined at most twice")
    print("Space complexity: O(1) - only using pointers\n")


if __name__ == "__main__":
    trace_algorithm()
    explain_suffix_algorithm()

    # Test with the original examples
    solution = Solution()
    test_cases = [
        ("dbca", 2),
        ("gggg", 4),
        ("abc", 2),
        ("abcde", 3),
    ]

    print("=== Test Results ===")
    for word, numFriends in test_cases:
        result = solution.findLexLargestString(word, numFriends)
        print(f"word='{word}', numFriends={numFriends} -> '{result}'")