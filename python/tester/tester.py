from dp.partitiondp.plates import main
import io
import os
import sys
sys.path.append(os.getcwd())


if __name__ == '__main__':
    # print("Current Working Directory:", os.getcwd())

    # Redirect sys.stdin to read from input.txt
    with open('test_input.txt', 'r') as f:
        sys.stdin = io.StringIO(f.read())

    # Capture printed output
    from contextlib import redirect_stdout
    import io

    output_buffer = io.StringIO()
    with redirect_stdout(output_buffer):
        main()

    # Read expected output from file
    with open('test_output.txt', 'r') as f:
        expected_output = [line.strip() for line in f.readlines()]

    # Get actual output
    actual_output = output_buffer.getvalue().strip().split('\n')

    # Print comparison
    print("Your Output:   ", actual_output)
    print("Expected Output:", expected_output)
    if actual_output == expected_output:
        print("✅ Output matches expected results.")
    else:
        print("❌ Output does NOT match expected results.")
