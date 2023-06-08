/*
Q7. Construct Roads
Problem Description
A country consist of N cities connected by N - 1 roads. King of that country want to construct maximum number of roads such that the new country formed remains bipartite country.
Bipartite country is a country, whose cities can be partitioned into 2 sets in such a way, that for each road (u, v) that belongs to the country, u and v belong to different sets. Also, there should be no multiple roads between two cities and no self loops.
Return the maximum number of roads king can construct. Since the answer could be large return answer % 109 + 7.
NOTE: All cities can be visited from any city.

Problem Constraints
1 <= A <= 105
1 <= B[i][0], B[i][1] <= N

Input Format
First argument is an integer A denoting the number of cities, N.
Second argument is a 2D array B of size (N-1) x 2 denoting the initial roads i.e. there is a road between cities B[i][0] and B[1][1] .

Output Format
Return an integer denoting the maximum number of roads king can construct.

Example Input
Input 1:
 A = 3
 B = [
       [1, 2]
       [1, 3]
     ]
Input 2:
 A = 5
 B = [
       [1, 3]
       [1, 4]
       [3, 2]
       [3, 5]
     ]

Example Output
Output 1:
 0
Output 2:
 2

Example Explanation
Explanation 1:
 We can't construct any new roads such that the country remains bipartite.
Explanation 2:
 We can add two roads between cities (4, 2) and (4, 5).

*/
void bfsBipert(vector<int> adj[], vector<int> &color, int &src )
{
    if(color[src] == -1)
        color[src] = 1;

     queue<int> q;

     q.push(src);

    while(!q.empty())
    {
        int ele = q.front();    
                    q.pop();

     for(int u : adj[ele])
     {
         if(color[u] == -1)
            {
                color[u] = 1 - color[ele];
                q.push(u);
            }
     }

    }
   
}



int Solution::solve(int A, vector<vector<int> > &B) {

vector<int> adj[A+1];

for(int i = 0; i<B.size(); i++)
{
    adj[B[i][0]].push_back(B[i][1]);
     adj[B[i][1]].push_back(B[i][0]);
}

vector<bool> vis(A+1,false);
vector<int> color(A+1,-1);

 for(int i = 1; i <= A; i++)
 {
     if(color[i] == -1)
     {
         bfsBipert(adj,color,i);
     }
 }

    int grpA = 0;
    int grpB = 0;

    for(int i = 1; i<=A; i++)
    {
        if(color[i] == 1)
            grpA++;
        else
            grpB++;
    }

    long MOD = 1e9 +7;

    int newRoads = ((grpA%MOD) * (grpB)%MOD ) - (A-1) ;

    return newRoads;
}