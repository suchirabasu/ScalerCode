/*
Q14. Reversing Edges
Problem Description
Given a directed graph with A nodes and M edges.
Find the minimum number of edges that needs to be reversed in order to reach node A from node 1.

Problem Constraints
1 <= A, M <= 10 5
1 <= B[i][0], B[i][1] <= A
There can be multiple edges or self loops (B[i][0] = B[i][1])

Input Format
The first argument is an integer A, denoting the number of nodes in the graph.
The second argument is a 2D integer array B, denoting the directed edges in the graph.

Output Format
Return a single integer denoting the minimum number of edges to be reversed.

Example Input
Input 1:
A = 5
B = [[1, 2],
     [2, 3],
     [4, 3],
     [4, 5]]
Input 2:
A = 5
B = [[1, 2],
     [2, 3],
     [3, 4],
     [4, 5]]

Example Output
Output 1:
1
Output 2:
0

Example Explanation
Explanation 1:
Reversing the edge (4, 3) is only required.
Explanation 2:
There already exists a path between 1 and A, so no edges need to be reversed.

*/
int Solution::reverseEdges(int A, vector<vector<int> > &B) {
    unordered_map<int,vector<pair<int,int>>>G;
    for(auto x:B){
        G[x[0]].push_back(make_pair(x[1],0));
        G[x[1]].push_back(make_pair(x[0],1));
    }
    queue<pair<int,int>>q;
    vector<int>ans(A+1,INT_MAX);
    q.push(make_pair(0,1));
    ans[1]=0;
    while(!q.empty())
    {
        int d=q.front().first;
        int x=q.front().second;
        q.pop();
        if(ans[x]==d){
            for(auto y:G[x]){
                int node=y.first;
                int dis_node=y.second;
                if(d+dis_node<ans[node]){
                    ans[node]=d+dis_node;
                    q.push(make_pair(d+dis_node,node));
                }
            }
        }
    }
    for(auto &x:ans){
        if(x==INT_MAX) x=-1;
    }
    return ans[A];
}
