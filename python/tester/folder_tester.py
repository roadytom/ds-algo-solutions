import io
import sys

from cse_problem_list.range_queries.range_update_queries import main

FILE_COUNT = 4
if __name__ == '__main__':
    ALL_PASSED = True
    for i in range(FILE_COUNT):
        # Redirect sys.stdin to read from input.txt
        with open(f'tests/{i + 1}.in', 'r') as f:
            sys.stdin = io.StringIO(f.read())

        # Capture printed output
        from contextlib import redirect_stdout
        import io

        output_buffer = io.StringIO()
        with redirect_stdout(output_buffer):
            main()

        # Read expected output from file
        with open(f'tests/{i + 1}.out', 'r') as f:
            expected_output = [line.strip() for line in f.readlines()]

        # Get actual output
        actual_output = output_buffer.getvalue().strip().split('\n')

        # Print comparison
        print("Your Output:   ", actual_output)
        print("Expected Output:", expected_output)

        if actual_output != expected_output:
            print(f"❌ Output does NOT match expected results on test {i + 1}.")
            ALL_PASSED = False
            break
    if ALL_PASSED:
        print("✅ Output matches expected results.")
