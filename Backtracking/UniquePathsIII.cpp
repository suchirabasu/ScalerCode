/*
Q3. Unique Paths III
Problem Description
Given a matrix of integers A of size N x M . There are 4 types of squares in it:
1. 1 represents the starting square.  There is exactly one starting square.
2. 2 represents the ending square.  There is exactly one ending square.
3. 0 represents empty squares we can walk over.
4. -1 represents obstacles that we cannot walk over.
Find and return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.

Problem Constraints
2 <= N * M <= 20
-1 <= A[i] <= 2

Input Format
The first argument given is the integer matrix A.

Output Format
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example Input
Input 1:
A = [   [1, 0, 0, 0]
        [0, 0, 0, 0]
        [0, 0, 2, -1]   ]
Input 2:
A = [   [0, 1]
        [2, 0]    ]

Example Output
Output 1:
2
Output 2:
0

Example Explanation
Explanation 1:
We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Explanation 1:
Answer is evident here.

*/
bool isSafe(vector<vector<int>>& A, vector<vector<bool>>& vis, int i, int j){
    if(i >= 0 && i<A.size() && j >= 0 && j<A[0].size() && (A[i][j] == 0 || A[i][j] == 2) && !vis[i][j])
        return true;
    else return false;
}

void fun(vector<vector<int>>& A, vector<vector<bool>>& vis, int t, int& sum, int destRow, int destCol, int i, int j, int& ans){
    if(i == destRow && j == destCol){
        //cout<<sum<<" “<<t<<”, ";
        if((sum-1) == t)
            ans++;
        return;
    }

    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    int k;
    for(k=0; k<4; k++){
        int r = i + row[k];
        int c = j + col[k];

        if(isSafe(A, vis, r, c)){
            vis[r][c] = true;
            sum++;

            fun(A, vis, t, sum, destRow, destCol, r, c, ans);

            sum--;
            vis[r][c] = false;
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int i, j;
    int n = A.size();
    int m = A[0].size();
    int sRow = -1, sCol = -1, destRow = -1, destCol = -1;
    int t = 0;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(A[i][j] == 0)
                t++;
            else if(A[i][j] == 1){
                sRow = i;
                sCol = j;
            }
            else if(A[i][j] == 2){
                destRow = i;
                destCol = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int sum = 0;
    int ans = 0;

    vis[sRow][sCol] = true;
    fun(A, vis, t, sum, destRow, destCol, sRow, sCol, ans);

    return ans;
}