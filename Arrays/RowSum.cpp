/*
Q30. Row Sum
Problem Description
You are given a 2D integer matrix A, return a 1D integer array containing row-wise sums of original matrix.

Problem Constraints
1 <= A.size() <= 103
1 <= A[i].size() <= 103
1 <= A[i][j] <= 103

Input Format
First argument A is a 2D array of integers.(2D matrix).

Output Format
Return an array conatining row-wise sums of original matrix.

Example Input
Input 1:
[1,2,3,4]
[5,6,7,8]
[9,2,3,4]

Example Output
Output 1:
{10,26,18}

Example Explanation
Explanation 1
Row 1 = 1+2+3+4 = 10
Row 2 = 5+6+7+8 = 26
Row 3 = 9+2+3+4 = 18

*/
vector<int> Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            ans[i] = ans[i] + A[i][j];
    }
    return ans;
}
