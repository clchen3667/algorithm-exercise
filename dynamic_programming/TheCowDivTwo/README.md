 Problem Statement for TheCowDivTwo

Problem Statement
    Farmer John had N cows numbered 0 to N-1. One day he saw K cows running away from his farm. Fox Brus computed the sum of the numbers of the escaped cows. She only told John that the sum was divisible by N. 
	Your task is to help John by counting the number of possible sets of escaped cows. This number may be very big, so return it modulo 1,000,000,007.

Definition  	
Class:	TheCowDivTwo
Method:	find
Parameters:	int, int
Returns:	int
Method signature:	int find(int N, int K)
(be sure your method is public)

Constraints
-	N will be between 1 and 1,000, inclusive.
-	K will be between 1 and 47, inclusive.
-	K will be less than or equal to N.

Examples
0)	  	
7
4
Returns: 5
7 cows are numbered 0 to 6 and 4 of them run away. Possible sets of escaped cows are {0, 1, 2, 4}, {0, 3, 5, 6}, {1, 2, 5, 6}, {1, 3, 4, 6}, {2, 3, 4, 5}.

1)	   	
1
1
Returns: 1

2)	  	
58
4
Returns: 7322

3)	
502
7
Returns: 704466492

4)	
1000
47
Returns: 219736903

Solution:
	The problem asks us to count all possible sets of K numbers from 0 to N-1 that would have a total sum that is a multiple of N. It may be possible to consider all the available possibilities and count them. We will head towards a dynamic programming solution because it is a counting problem and it often pays to try to imagine a dynamic programming solution in those problems when constraints are large. If we want to try dynamic programming, we first need a recurrence. We will begin considering the overall case: We have a list of number from 0 to N-1, we need to pick K of them and the sum of the picked elements must be be a multiple of N. For now, our function takes a list of numbers List, and the amount of numbers to pick K.
	When we begin the recurrence, we have some numbers in the List, we need to decide which of them goes to the set of K elements. We will begin with the first number in the List: List[0]. If we do not add List[0] to the set, then K stays the same but we should remove List[0] from the list, we can call the recurrence again with the new list and the value of K that will give us the amount of sets of K elements that do not include List[0] that have a sum that is a multiple of N. If instead, we want List[0] to go to the set, then we should decrease K by 1, because one of the K numbers has been decided. We also need to again remove List[0] from the list so that we do not consider it anymore. However, we are no longer interested in the number of sets of K-1 elements of the new list that have a sum equal to a multiple of N. We will add List[0] to the sum of the numbers. So we want the number of sets of K-1 elements from the updated List that have a sum S such that : (S+List[0] is a multiple of N).
	Whenever we read "A is a multiple of B" we can read it as : "When we divide A by B, the remainer is 0" or "A = 0 modulo B". We will use the latter, because modular arithmetic may be useful in this case since (S+List[0] = 0 mod N) is actually an equation.In effect, we will need to count the number of sets of K-1 elements that have a sum that is equal to (N-List[0]) modulo N. The first step of our recurrence, needed sums that are multiples of N, which is the same as saying sums that are equal to 0 modulo N. The required modulo of the sum can become an argument to the recurrence. 
	Our recurrence is then: countSets(List, K, S) - The number of sets of K elements from List that yield a total sum that is equal to S modulo N. The solution to the main problem is: countSets([0, 1, ..., N-1], K, 0), because we want the number of sets of K unique numbers from 0 to N-1 that have a sum equal to 0 modulo N (multiple of N).

function countSets(List, K, S) {
    List' = remove List[0] from List.
    return countSets(List', K-1, (S-List[0]) mod N) + countSets(List', K, S)
}

	What the recurrence does is count the sets that begin with List[0] that follow the rule, and then add the number of sets that do not begin with List[0]. A recurrence needs a base case. When K=0, then the only result is an empty set {}, the sum of elements of the empty set is 0. 0 is always a multiple of N, always (0 mod N). Therefore, if S=0 and K=0 then there is exactly one set that has the result and if K=0 and S!=0, then it is not possible to do it. Another thing, is when the list is empty and K is not 0, there are no elements left that we could add to have K elements, the result is always 0. 

	Removing elements from a list tends to be a very taxing operation and it is also complicated to implement. In order to simplify it, note that the original list is 0,1,...N-1. We always remove elements from the list in each step. So, the first list is [0,1,...N-1], the list given to the sub-instances is [1,2,...,N-1], then [2,...N-1]. We can describe a list by its starting number p. So if p=0, then the list is 0,1,...,N-1, if p=6, then the list is 6,7,...,N-1. List[0] is simply equal to p and the process of removing the first element of the List is as simple as increasing p

The current recurrence is:

function countSets(p, K, S) {
    if (K == 0) {
        if (S == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (p >= N ) {  //no more elements in the list to use
        return 0;
    }
    return countSets(p+1, K-1, (S-p) mod N) + countSets(p+1, K, S)
}

	The recurrence is acyclic because it always calls sub-instances of it with greater values of p. p can be a number from 0 to N. So there are N+1 possible values of p. K starts equal to the original value of K in the statement and is then decreased until it gets to 0. K+1 values in total. S will always be a value modulo N, values modulo N can only be numbers from 0 to N-1, so there are N possible values of S. Then there are at most (N+1) * (K+1) * N possible argument combinations we can give to that function. Each instance of the function does individually O(1) operations (call sub-instances, and do a couple of conditions checks). If we use memoization to make sure the function is evaluated at most once for each argument combination, then the running time complexity is O( N*K*N), remember that N<=1000 and K<=47. This time complexity is actually good enough for the 2 seconds time limit in TopCoder's computers. Unfortunately, since we used memoization, we also need O(N*K*N) memory - actually 4*(N+1)*(K+1)*(N+1) bytes = 4*1001*48*1000 bytes ~= 183 Megabytes. The memory limit in TopCoder is 64 MB.

	The last trick to get this solution working is to consider that in the recurrence, we only call the sub-instances that have p = p + 1. If we calculate the results of the recurrence in descending order of p we will only need to remember the states for (p = p + 1). By doing this, We will only need O(K * N) memory. This can be understood better if we modify that recurrence to instaed be a iterative dynamic programming solution:

    table[N+1][K+1][N] // Arguments are: [p][k][S]
    for p = N to 0 {
      for k = 0 to K {
        for S = 0 to N-1 {
          if (k == 0) {
            if (S==0) {
                table[p][k][s] = 1
            } else {
                table[p][k][s] = 0
            }
          } else if (p == N) {
            table[p][k][s] = 0
          } else {
            table[p][k][s] = table[p+1][k-1][(S-p) mod N] + table[p+1][k][S] 
          }
        }
      }
    }    

	That is the iterative way to calculate the complete recurrence. This is the place where we note that instead of needing a [N+1] for the table array, we only need two dimensions, because we always need to remember the results for p+1. An easy way to do this is to instead of using [p], use [p%2] and instead of using [p+1] use [(p+1)%2] when accessing the table array. This way all even values of p will share the same space and all odd values of p will also share their same space. Since p%2 and (p+1)%2 may only be 0 or 1, we can change the first dimension of the table array to [2]. The following is the final c++ implementation of the optimized recurrence. The result when using that recurrence is very large, but since the problem asks for it modulo 1000000007, we can get that modulo after every addition operation because (a+b)%M is equal to (a%M) + (b%M). Also note that in order to calculate (s-p) mod N, (s-p)%N is not enough in c++ because negative numbers behave differently in c++ than in modular arithmetic, to fix it it is useful to add N to negative numbers before using the % operator.
