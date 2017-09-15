This is a classic task requiring you to count all integer factors of a positive integer number N, including 1 and the number itself. Note that this is not just about the prime factors but all of them.

Examples:
	1.For 12 there are 6 such factors: 1, 2, 3, 4, 6, 12, thus you should return 6

Constrain:
	1 <= N <= 10^12


Solution:
	All integer factors of a given integer N are the product of some subset of the prime factors of N. One could think that if we just count all subsets of the prime factors of N we would get the answer. However, this won't give you the correct answer in many cases. The reason is that if N has several prime factors that are equal it doesn't matter, which of them are used when forming the subsets. Here is an example with N=12, 12 = 2 * 2 * 3. Its factors are 1, 2, 3, 4, 6, 12. All subsets of the prime factors are 2^3 = 8 but 12 only has 6 different factors. This is because it has 2 as a factor twice. So, we need something smarter to compute the answer.
	If we think about it we can group the prime factors by value. For 12 we would have 2 groups: 2 times the factor 2 and 1 time the factor 3. To form a factor of N we would need to choose from each group the number of factors to use: from 0 up to the number of factors in the group. Once we have chosen how many factors to use from each group we multiple them and this produces a factor of N. This would mean that if Gi is the number of factors in the i-th group there will be (G1 + 1) * (G2 + 1) * ... * (Gk + 1) different ways to choose factors from the groups.
	Now we need to find an efficient way to find all prime factors of N and we are done with this problem. Finding the prime factors is a classic problem, one that you should definitely be confident solving at an interview.
	Just go and see the problem "All prime factors"
