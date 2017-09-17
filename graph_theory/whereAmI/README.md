Task : Where am I?
	A robot is dropped on a rectangular field containing square cells. Some cells are empty and can be used for walking, others are occupied and the robot cannot pass through.The robot is always dropped on an empty cell. It has in its memory a map of the whole field but it does not know where it is on that map. However, it can scan the surroundings and try to map the view to a spot on the map.
	The robot has the goal to reach a given cell, which is always empty. It needs to compute the length of the shortest path in terms of cells (including the start and final ones) from its start cell to the final cell.
	It is possible that there are more than one cells on the map, which have the same surrounding as what the robot sees. In such a case it should return the most pessimistic answer it can find.
	It is also possible that no cell on the map corresponds to what the robot sees. In such cases it should return the number -1.
	If the robot matches one or more possible starting locations on the map but from at least one of them there is no path to the final cell it must return -2.
	The surroundings that the robot sees will be presented as a smaller rectangle with empty and occupied cells.The field can be at most 1000 by 1000 cells big. The surroundings rectangle's size will be at most 16 by 16 cells and it will never be bigger than the map.
	The input will be read from the standard input and will contain 4 numbers on the first line: N, M, P, Q, where:
	N - number of rows in the map
	M - number of columns in the map
	P - number of rows in the surroundings
	Q - number of columns in the surroundings

	The second line will contain two integers: X and Y, the row and column of the destination cell. Rows and columns are numbered starting from 1 at the top and at the left correspondingly.

	Then there will be N lines with M characters, either 0 or 1. After that there will be P lines with Q characters, either 0 or 1, and the cell where the robot is will be marked as 2.

Example:
Input:
	6 10 2 3
	4 9
	0100000000
	1000000000
	0000000000
	0010000000
	0000000000
	0000000000
	010
	102
OutPut:
8



Solution:
We can divide the solution into two steps:
	1.Find possible starting positions of the robot on the map.
	2.Compute the longest distance from a possible starting position to the goal.

	For the first step it will be sufficient to just go through all possible positions for the input pattern and check if it matches. For example, you could start at the cell in row 1, column 1, and check whether if you apply the pattern's top-left corner in this cell it will match the corresponding cells of the big field.
	Doing this for all possible positions in the big field you will have all possible starting positions. At this point if no possible starting positions were found you can return -1 and stop.
	If there are one or more possible starting positions you could use breadth-first search (BFS) to find the shortest paths from them to the final cell. To make things easier you could start your BFS from the final cell and let it reach all cells of the rectangular field that can be reached.
	After the BFS is done you will have information about the shorted distance in terms of robot moves to all other cells. You just need to iterate over all found possible starting cells and select the one with the longest distance and return this distance. Also, keep in mind that if for at least one of these possible starting cells the BFS didn't find a path to it, you must return -2.
	This is probably the most efficient solution to this problem. The first step will take O(N * M * P * Q) and after that the time complexity of the BFS will be O(N * M). This is because N * M is the number of nodes in the graph formed by the rectangular field. The number of edges in it is lower than 4 * N * M because all cells have 4 or less adjacent cells. So, the overall time complexity will be defined by the first step.
	In terms of memory, you will need to store the rectangular field and the pattern and the distances found by the BFS, so it will be O(N * M).
