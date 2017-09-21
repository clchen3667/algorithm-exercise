Given two binary max heaps as arrays, merge the given heaps.

Examples:

Input  : a = {10, 5, 6, 2}, 
         b = {12, 7, 9}
Output : {12, 10, 9, 2, 5, 7, 6}

Solution:
	The idea is simple. We create an array to store result. We copy both given arrays one by one to result. Once we have copied all elements, we call standard build heap to construct full merged max heap.
