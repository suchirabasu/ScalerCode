/*
Q16. Maximum Depth
Problem Description

Given a Tree of A nodes having A-1 edges. Each node is numbered from 1 to A where 1 is the root of the tree.

You are given Q queries. In each query, you will be given two integers L and X. Find the value of such node which lies at level L mod (MaxDepth + 1) and has value greater than or equal to X.

Answer to the query is the smallest possible value or -1, if all the values at the required level are smaller than X.

NOTE:

Level and Depth of the root is considered as 0.
It is guaranteed that each edge will be connecting exactly two different nodes of the tree.
Please read the input format for more clarification.


Problem Constraints

2 <= A, Q(size of array E and F) <= 105

1 <= B[i], C[i] <= A

1 <= D[i], E[i], F[i] <= 106



Input Format

The first argument is an integer A denoting the number of nodes.

The second and third arguments are the integer arrays B and C where for each i (0 <= i < A-1), B[i] and C[i] are the nodes connected by an edge.

The fourth argument is an integer array D, where D[i] denotes the value of the (i+1)th node

The fifth and sixth arguments are the integer arrays E and F where for each i (0 <= i < Q), E[i] denotes L and F[i] denotes X for ith query.



Output Format

Return an array of integers where the ith element denotes the answer to ith query.



Example Input

Input 1:

 A = 5
 B = [1, 4, 3, 1]
 C = [5, 2, 4, 4]
 D = [7, 38, 27, 37, 1]
 E = [1, 1, 2]
 F = [32, 18, 26]
Input 2:

 A = 3
 B = [1, 2]
 C = [3, 1]
 D = [7, 15, 27]
 E = [1, 10, 1]
 F = [29, 6, 26]


Example Output

Output 1:

 [37, 37, 27]
Output 2:

 [-1, 7, 27]


Example Explanation

Explanation 1:

      1[7]
     /    \
   5[1]  4[37]
        /    \
       2[38]  3[27]

 Query 1: 
    L = 1, X = 32
    Nodes for level 1 are 5, 4
    Value of Node 5 = 1 < 32
    Value of Node 4 = 37 >= 32
    Ans = 37
Explanation 2:

      1[7]
     /    \
   2[15]  3[27]

 Query 1: 
    L = 1, X = 6
    Nodes for level 1 are 2, 3 having value 15 and 27 respectively.
    Answer = -1 (Since no node is greater or equal to 29).
 Query 1: 
    L = 10 % 2 = 0, X = 6
    Nodes for level 0 is 1 having value 7.
    Answer = 7.     
*/
vector<int> Solution::solve(int a, vector<int> &b, vector<int> &c, vector<int> &d, vector<int> &e ,vector<int> &f) {
    vector<vector<int>>edges(a+1);  // making edges
    for(int i=0;i<b.size();i++){
        edges[b[i]].push_back(c[i]);
        edges[c[i]].push_back(b[i]);
    }
    vector<int>visited(a+1,false);  visited[1]=true;
    vector<vector<int>>tree_level;  tree_level.push_back({d[0]});
    queue<int>que;  que.push(1);
    while(!que.empty()){    // creating level order by BFS
        int sz=que.size();
        vector<int>temp;
        while(sz--){
            int node=que.front();
            que.pop();
            for( auto i: edges[node]){
                if(!visited[i]){
                    temp.push_back(d[i-1]);
                    que.push(i);
                    visited[i]=true;
                }
            }
        }
        if(!temp.empty()){                               // to avoid inserting empty vector
            sort(temp.begin(),temp.end()); //sort each value at node;
            tree_level.push_back(temp);
        }
    }
    vector<int>ans;
    int depth=tree_level.size();
    for( int i=0;i<e.size();i++){
        int l=e[i]%depth;
        int val=f[i];
        // finding the value in level L  using binary_search;
        int start=0,end=tree_level[l].size()-1;
        int answer=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if( tree_level[l][mid] == val){
                answer=val;
                break;
            }else if( tree_level[l][mid]< val){
                start=mid+1;
            }else {
                answer=tree_level[l][mid];
                end=mid-1;
            }
        }ans.push_back(answer);
    }
    return ans;
}