Task : Words with typos
	You are given a text T consisting of words in which there may be typos. Your task is to count how many times a given word W is used in this text. However, you need to include in this count the cases in which this word was written with a typo.
	For this task, a word w' in T is considered to be an instance of w if:
	1.it's exactly the same as W
	2.it has the same length as W and up to 2 letters are different
	3.W' can be obtained from W by removing or adding 1 letter

Constrain:
	5 <= w.length() <= 20;
	1 <= T.size() <= 10,000

Example:
Input:
	banana
	there are three bananas on the tree and one banano on the ground
Output:
	2
