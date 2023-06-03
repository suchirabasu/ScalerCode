/*
Q2. First Depth First Search
Problem Description
You are given N towns (1 to N). All towns are connected via unique directed path as mentioned in the input.
Given 2 towns find whether you can reach the first town from the second without repeating any edge.
B C : query to find whether B is reachable from C.
Input contains an integer array A of size N and 2 integers B and C ( 1 <= B, C <= N ).
There exist a directed edge from A[i] to i+1 for every 1 <= i < N. Also, it's guaranteed that A[i] <= i for every 1 <= i < N.
NOTE: Array A is 0-indexed. A[0] = 1 which you can ignore as it doesn't represent any edge.

Problem Constraints
1 <= N <= 100000

Input Format
First argument is vector A
Second argument is integer B
Third argument is integer C

Output Format
Return 1 if reachable, 0 otherwise.

Example Input
Input 1:
 A = [1, 1, 2]
 B = 1
 C = 2
Input 2:
 A = [1, 1, 2]
 B = 2
 C = 1

Example Output
Output 1:
 0
Output 2:
 1

Example Explanation
Explanation 1:
 Tree is 1--> 2--> 3 and hence 1 is not reachable from 2.
Explanation 2:
 Tree is 1--> 2--> 3 and hence 2 is reachable from 1.

*/
void dfs(int src,int dest,vector<int> adj[],vector<int> &vis){
     vis[src]=1;
     if(src==dest) return;
     for(auto x:adj[src]){
         if(!vis[x]){
             dfs(x,dest,adj,vis);
         }
     }
}
int Solution::solve(vector<int> &A, const int B, const int C) {
    int n = A.size();
    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        adj[A[i]].push_back(i+1);
    }
    vector<int> vis(n+1,0);
    dfs(C,B,adj,vis);
    return vis[B];
}