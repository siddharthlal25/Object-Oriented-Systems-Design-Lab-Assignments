OOSD Lab Problem Sheet 7

Implement the following in C++:

1) Given two strings, find the longest common subsequence among them. Your program should read the two strings from a file input.txt, and print the longest common subsequence in a file output.txt. Use a dynamic programming paradigm.

2) Suppose that a thief carrying a knapsack sneaks into a treasury. He can carry away as much goods as is the capacity of his knapsack. His knapsack can accommodate goods weighing at most W.  The total number of goods or objects in the treasury is n. Object o_i has weight w_i and value v_i. The thief's aim is to steal goods worth the most, i.e. he wants to maximize the cumulative value of the goods while keeping their cumulative weight at most W.
Write a program that gives the optimum solution in O(nW) time. Your program should read the input from a file input.txt, where the first line shall contain W, and the second line shall contain v_i, w_i pairs serially. The output shall be printed on a file output.txt, and will indicate which objects have been chosen. Create some good sample input cases which nicely demonstrate the working of your program.

3) Write a program that gives a solution that is more than half of the optimum. The program should run in polynomial time. Input-output shall be the same as the previous question.

4) Consider three stacks: A, B and C. The stack A has the numbers 1, 2, ..., n in ascending order. Your task is to move all the numbers from A to B, so that they remain in ascending order. You may only pop or push the top number in each stack. You may use all three stacks for your operations, but at every instance, all the three stacks must have their contents in ascending order only. Your program will take n as input, and display each stage of the computation in a file output.txt. To show each stage of computation, the output will contain three consecutive lines showing stacks A, B and C respectively, for each move, followed by a blank line.
