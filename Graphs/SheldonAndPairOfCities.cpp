/*
Q17. Sheldon and Pair of Cities
Problem Description
Sheldon lives in a country with A cities (numbered from 1 to A) and B bidirectional roads.
Roads are denoted by integer array D, E and F of size M, where D[i] and E[i] denotes the cities and F[i] denotes the distance between the cities.
Now he has many lectures to give in the city and is running short of time, so he asked you C queries, for each query i, find the shortest distance between city G[i] and H[i].
If the two cities are not connected then the distance between them is assumed to be -1.

Problem Constraints
1 <= A <= 200
1 <= B <= 200000
1 <= C <= 100000
1 <= F[i] <= 1000000
1 <= D[i], E[i], G[i], H[i] <= A

Input Format
First argument is an integer A.
Seocnd argument is an integer B.
Third argument is an integer C.
Fourth argument is an integer array D.
Fifth argument is an integer array E.
Sixth argument is an integer array F.
Seventh argument is an integer array G.
Eight argument is an integer array H.

Output Format
Return an integer array of size C, for each query denoting the shortest distance between the given two vertices.
If the two vertices are not connected then output -1.

Example Input
Input 1:
 A = 4
 B = 6
 C = 2
 D = [1, 2, 3, 2, 4, 3]
 E = [2, 3, 4, 4, 1, 1]
 F = [4, 1, 1, 1, 1, 1]
 G = [1, 1]
 H = [2, 3]
Input 2:
 A = 3
 B = 3
 C = 2
 D = [1, 2, 1]
 E = [2, 3, 3]
 F = [3, 1, 1]
 G = [2, 1]
 H = [3, 2]

Example Output
Output 1:
 [2, 1]
Output 2:
 [1, 2]

Example Explanation
Explanation 1:
 Distance between (1,2) will 2 if we take path 1->4->2.
 Distance between (1,3) will 1 if we take path 1->3.
Explanation 2:
 Distance between (2,3) will 1 if we take path 1->3.
 Distance between (1,2) will 2 if we take path 1->3->2.

*/
#define inf 1000000000000
#define ll long long
using namespace std;
vector < int > Solution::solve(int A, int B, int C, vector < int > & D, vector < int > & E, vector < int > & F, vector < int > & G, vector < int > & H) {
    ll dp[205][205] = {};
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++) {
            if (i != j)
                dp[i][j] = inf;
            else
                dp[i][j] = 0;
        }
    }
    for (int i = 0; i < B; i++) {
        int uu = D[i] - 1;
        int vv = E[i] - 1;
        dp[uu][vv] = min(dp[uu][vv], (ll) F[i]);
        dp[vv][uu] = min(dp[vv][uu], (ll) F[i]);
    }

    for (int k = 0; k < A; k++) {
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < A; j++) {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    vector < int > answer;
    for (int i = 0; i < C; i++) {
        int aa = G[i] - 1;
        int bb = H[i] - 1;
        if (dp[aa][bb] == inf) {
            answer.push_back(-1);
        } else {
            answer.push_back((int) dp[aa][bb]);
        }
    }
    return answer;
}