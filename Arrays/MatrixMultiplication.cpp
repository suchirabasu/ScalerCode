/*
Q22. Matrix Multiplication
Problem Description
You are given two integer matrices A(having M X N size) and B(having N X P). You have to multiply matrix A with B and return the resultant matrix. (i.e. return the matrix AB).

Problem Constraints
1 <= M, N, P <= 100
-100 <= A[i][j], B[i][j] <= 100

Input Format
First argument is a 2D integer matrix A.
Second argument is a 2D integer matrix B.

Output Format
Return a 2D integer matrix denoting AB.

Example Input
Input 1:
A = [[1, 2],            B = [[5, 6],
    [3, 4]]                 [7, 8]] 
Input 2:
A = [[1, 1]]            B = [[2],
                            [3]] 
Example Output
Output 1:
[[19, 22],
[43, 50]]
Output 2:
[[5]]

*/
vector<vector<int> > Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int r1 = A.size();
    int c1 = A[0].size();
    int r2 = B.size();
    int c2 = B[0].size();
    vector<vector<int> > mult(r1, vector<int>(c2,0));
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
            for(int k = 0; k < c1; ++k)
            {
                mult[i][j] += A[i][k] * B[k][j];
            }
   return mult;
}

