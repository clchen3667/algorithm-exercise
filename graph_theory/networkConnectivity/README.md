Task : Network connectivity
	The computers in one company's head quarters are connected by a local area network. However, due to various restrictions not all computers may be reachable from all other computers in the building.
	The system administrators of the building have a list of all connections between nodes on the network (computers and network devices). The list consists of pairs of numbers where each number is the assigned ID of a node on the network. The connections allow for communication in both directions.
	Your task is to write a program, which can be used to determine how many network nodes are reachable from a given node with ID S.
	The network has N nodes where 1 <= N <= 512.
	The input is read from the standard input. On the first line there will be three integers N - the number of nodes, M - the number of connected pairs of nodes and S - the ID of the node which we are asking the question for. Then M lines will follow each containing two integers - IDs of network nodes. The IDs will be in the range [1, N].
	The output is written to the standard output. It must contain only one integer - the number of network nodes reachable from the node with ID S.

Example:
Input:
	7 8 2
	1 2
	1 4
	4 2
	4 3
	3 1
	5 6
	5 7
	7 6	
Output:
	3
