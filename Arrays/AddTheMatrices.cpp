/*
Q19. Add the matrices
Problem Description
You are given two matrices A & B of same size, you have to return another matrix which is the sum of A and B.

Problem Constraints
1 <= A.size(), B.size() <= 1000
1 <= A[i].size(), B[i].size() <= 1000
1 <= A[i][j], B[i][j] <= 1000

Input Format
First argument is vector of vector of integers representing matrix A.
Second argument is vecotor of vector of integers representing matrix B.

Output Format
You have to return a vector of vector of integers after doing required operations.

Example Input
Input 1:
A = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]
B = [[9, 8, 7],[6, 5, 4],[3, 2, 1]]

Example Output
Output 1:
[[10, 10, 10], [10, 10, 10], [10, 10, 10]]

Example Explanation
Explanation 1:
A + B = [[1+9, 2+8, 3+7],[4+6, 5+5, 6+4],[7+3, 8+2, 9+1]] = [[10, 10, 10], [10, 10, 10], [10, 10, 10]].

*/
vector<vector<int> > Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > sum(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    return sum;
}