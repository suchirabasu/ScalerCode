/*
Q6. Check Bipartite Graph
Problem Description
Given a undirected graph having A nodes. A matrix B of size M x 2 is given which represents the edges such that there is an edge between B[i][0] and B[i][1].
Find whether the given graph is bipartite or not.
A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B
Note:
There are no self-loops in the graph.
No multiple edges between two pair of vertices.
The graph may or may not be connected.
Nodes are Numbered from 0 to A-1.
Your solution will run on multiple testcases. If you are using global variables make sure to clear them.

Problem Constraints
1 <= A <= 100000
1 <= M <= min(A*(A-1)/2,200000)
0 <= B[i][0],B[i][1] < A

Input Format
The first argument given is an integer A.
The second argument given is the matrix B.

Output Format
Return 1 if the given graph is bipartide else return 0.

Example Input
Input 1:
A = 2
B = [ [0, 1] ]
Input 2:
A = 3
B = [ [0, 1], [0, 2], [1, 2] ]

Example Output
Output 1:
1
Output 2:
0

Example Explanation
Explanation 1:
Put 0 and 1 into 2 different subsets.
Explanation 2:
It is impossible to break the graph down to make two different subsets for bipartite matching

*/
const int N = 100005;
vector < int > graph[N];

void clean(int n) {
    for (int i = 0; i <= n; ++i)
        graph[i].clear();
}

void make_graph(int n, vector < vector < int > > & edges) {
    clean(n);
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

bool isBipartite(int n) {
    if (!n)
        return true;
    int color[n];
    memset(color, -1, sizeof color);
    queue < int > q;
    for (int i = 0; i < n; ++i) {
        if (color[i] != -1)
            continue;
        color[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto & it: graph[x]) {
                if (color[it] == -1) {
                    color[it] = color[x] ^ 1;
                    q.push(it);
                } else if (color[it] == color[x])
                    return false;
            }
        }
    }
    return true;
}

int Solution::solve(int A, vector < vector < int > > & B) {
    make_graph(A, B);
    if (isBipartite(A))
        return 1;
    return 0;
}