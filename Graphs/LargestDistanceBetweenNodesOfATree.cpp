/*
Q18. Largest Distance between nodes of a Tree
Problem Description
Find largest distance Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes.
The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).
The nodes will be numbered 0 through N - 1.
The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.

Problem Constraints
2 <= |A| <= 40000

Input Format
First and only argument is vector A

Output Format
Return the length of the longest path

Example Input
Input 1:
A = [-1, 0]
Input 2:
A = [-1, 0, 0]

Example Output
Output 1:
 1
Output 2:
 2

Example Explanation
Explanation 1:
 Path is 0 -> 1.
Explanation 2:
 Path is 1 -> 0 -> 2.

*/
#define pb push_back
#define mp make_pair
#define N 111111
#define F first
#define S second

vector < int > g[N];
pair < int, int > ans;

void dfs(int v, int p = -1, int d = 0) {
    if (d > ans.F) {
        ans = mp(d, v);
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v, d + 1);
        }
    }
}

int Solution::solve(vector < int > & A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        int x = A[i];
        if (x != -1) {
            assert(x != i);
            g[x].pb(i);
            g[i].pb(x);
        }
    }
    int v = 0;
    ans = mp(-1, -1);
    dfs(v);
    v = ans.S;
    ans = mp(-1, -1);
    dfs(v);
    return ans.F;
}
Python 3 (Python-3.8)
