/*
Q4. Rotten Oranges
Problem Description
Given a matrix of integers A of size N x M consisting of 0, 1 or 2.
Each cell can have three values:
The value 0 representing an empty cell.
The value 1 representing a fresh orange.
The value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.
Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.

Problem Constraints
1 <= N, M <= 1000
0 <= A[i][j] <= 2

Input Format
The first argument given is the integer matrix A.

Output Format
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1 instead.

Example Input
Input 1:
A = [   [2, 1, 1]
        [1, 1, 0]
        [0, 1, 1]   ]
Input 2:
A = [   [2, 1, 1]
        [0, 1, 1]
        [1, 0, 1]   ]

Example Output
Output 1:
 4
Output 2:
 -1

Example Explanation
Explanation 1:
Minute 0: [ [2, 1, 1]
            [1, 1, 0]
            [0, 1, 1] ]
Minute 1: [ [2, 2, 1]
            [2, 1, 0]
            [0, 1, 1] ]
Minute 2: [ [2, 2, 2]
            [2, 2, 0]
            [0, 1, 1] ]
Minute 3: [ [2, 2, 2]
            [2, 2, 0]
            [0, 2, 1] ]
Minute 4: [ [2, 2, 2]
            [2, 2, 0]
            [0, 2, 2] ]
At Minute 4, all the oranges are rotten.
Explanation 2:
The fresh orange at 2nd row and 0th column cannot be rotten, So return -1.

*/
int dir[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int inf = 99999999;

int solveit(vector < vector < int >> & grid) {
  int n = grid.size();
  int m = grid[0].size();
  int distance[n][m];
  queue < pair < int, int > > q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 1 || grid[i][j] == 0)
        distance[i][j] = inf;
      else {
        distance[i][j] = 0;
        q.push({ i, j });
      }
    }
  }
  int x, y;

  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    int dx, dy;
    for (int k = 0; k < 4; ++k) {
      dx = x + dir[k][0];
      dy = y + dir[k][1];
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 1 && distance[x][y] + 1 < distance[dx][dy]) {
        distance[dx][dy] = 1 + distance[x][y];
        q.push({ dx, dy });
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 1) {
        ans = max(ans, distance[i][j]);
      }
    }
  }
  return (ans == inf ? -1 : ans);
}

int Solution::solve(vector < vector < int > > & A) {
  return solveit(A);
}