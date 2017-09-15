Prime Counting
	A classic math task is to count the prime numbers less than or equal to some integer number N. In this task you have to write a function, which does this for a given N, where 1 <= N <= 10^6. We don't count 1 a prime.

Examples:
	1.For N=10, the prime numbers, which are less than or equal to 10 are: 2, 3, 5, 7, thus the function must return 4;
	2.For N=31, the prime numbers are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31. The function must return 11.

Solution:
	A simple solution that comes to mind is to iterate over all numbers between 2 and N and check if they are prime. For each one that is prime increase a counter by 1. How do we find if a number P is prime? We could iterate over all integers in the range [2, sqrt(P)] and check if any is a divisor (in our case sqrt(P) is the biggest integer that is not bigger than the square root of P). If none is found then P is prime. Note that we don't have to iterate over the numbers in the range [2, P]. If no number up to sqrt(P) is a divisor then there will be no divisors among the other numbers.
	
A solution with much more memory but less time : The sieve of Eratosthenes
	The technique in question is called "the sieve of Eratosthenes". It allows us to find the prime numbers in a given range more quickly then just checking for each number if it's prime or not. However, it uses more memory than the previously discussed solution.
	The idea is that we maintain in memory an array P, for which P[i] tells us if i is prime or not. In the beginning we set all values of P to true. Then we start to iterate from 2 up to the other end of the range to cover. For each number i we iterate we check if P[i] is currently marked as prime. If it is we run a nested loop starting from i * i with a step of i and mark the values that we iterate as not prime because obviously i is a factor for them.
	The time complexity of this algorithm is known to be O(n * log log n), which is better than what we evaluated for the first solution discussed. But there is the trade-off of more memory used. The maximum memory allowed for this problem should be enough to apply this algorithm in any of the supported programming languages. But you have to be aware that at an interview you need to know what your memory constraints are. They may be very low and render this solution not suitable for the case. 
