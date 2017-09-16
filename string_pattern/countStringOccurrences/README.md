Count the string occurrences
	You are given two strings T and P. Write a program, which counts how many time P is found in T. If different occurrences of P in T overlap count each one of them.

Examples:
	T = babalabalabalatheend 
	P = alabala
	The string P is found twice in T, first occurrence starts at position 4 (first letter is at position 1) and the second occurrence start at position 8.

Solution
	It's a classic version of the task for string pattern matching.
	This is a great opportunity to try implementing the Krnuth_Morris-Pratt algorithm, which should be efficient enough to pass all test cases.
