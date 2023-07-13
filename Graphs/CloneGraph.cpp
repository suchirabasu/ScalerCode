/*
Q20. Clone Graph
Problem Description
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
Note: The test cases are generated in the following format (use the following format to use See Expected Output option):
First integer N is the number of nodes.
Then, N intgers follow denoting the label (or hash) of the N nodes.
Then, N2 integers following denoting the adjacency matrix of a graph, where Adj[i][j] = 1 denotes presence of an undirected edge between the ith and jth node, O otherwise.

Problem Constraints
1 <= Number of nodes <= 105

Input Format
First and only argument is a node A denoting the root of the undirected graph.

Output Format
Return the node denoting the root of the new clone graph.

Example Input
Input 1:
      1
    / | \
   3  2  4
        / \
       5   6
Input 2:
      1
     / \
    3   4
   /   /|\
  2   5 7 6

Example Output
Output 1:
 Output will the same graph but with new pointers:
      1
    / | \
   3  2  4
        / \
       5   6
Output 2:
      1
     / \
    3   4
   /   /|\
  2   5 7 6

Example Explanation
Explanation 1:
 We need to return the same graph, but the pointers to the node should be different.

*/
UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *graph) {
    if (!graph) return NULL;

    map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    queue<UndirectedGraphNode *> q;
    q.push(graph);

    UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
    map[graph] = graphCopy;

    while (!q.empty()) {
        UndirectedGraphNode *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) {
            UndirectedGraphNode *neighbor = node->neighbors[i];
            // no copy exists
            if (map.find(neighbor) == map.end()) {
                UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            } else {     // a copy already exists
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
    }

    return graphCopy;
}
