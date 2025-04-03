The time complexity of your solution is O(N), where N is the length of the input string command. Here’s why:

The solution iterates through command once, processing each character exactly once.

The checks for "()" and "(al)" are constant-time operations since they only involve a few character comparisons.

Concatenation to ans in C++ is amortized O(1) per operation.

Complexity Breakdown:
Best Case (Only 'G'): O(N) (since each 'G' is processed individually)

Worst Case (Mixed "()", "(al)", "G"): O(N) (every character is processed once)

Space Complexity: O(N) (storing the output string)
