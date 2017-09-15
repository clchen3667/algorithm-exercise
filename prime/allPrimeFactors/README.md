Given an integer N, for which 2 <= N <= 10^12, find its prime factors. The result must be a list of sorted prime numbers where each number is listed as many times as it is present in the prime decomposition of N.

Examples:
	1.For N=20 the prime decomposition is 20 = 2 * 2 * 5, so you must return 2, 2, 5;
	2.For N=64 the prime decomposition is 64 = 2 * 2 * 2 * 2 * 2 * 2, result must be 2, 2, 2, 2, 2, 2.



solution:
	One quick optimization is not to iterate all numbers between 1 and N but to only try the numbers between 1 and the squared root of N. Each time we find a prime factor we divide N by it as many times as needed. In the end the remaining value will either be 1, or something bigger than 1. If it's bigger than 1, this means that N has a prime factor, which is bigger than the squared root of N.
	The second optimization is that we don't have to check if the numbers are prime. Starting with 2 and going up, we can be sure that if a number divides N then it is a prime divisor. Let's assume this is not true and following our algorithm we reach a number M that divides N but is not prime. This would mean that this number M has prime divisors. But these prime divisors are also divisors of N and they will be smaller than M. This means that we should have already processed them and should have divided the number N by them. We reached a contradiction with our initial assumption.	
