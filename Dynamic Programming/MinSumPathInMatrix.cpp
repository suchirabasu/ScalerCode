/*
Q12. Min Sum Path in Matrix
Problem Description
Given a M x N grid A of integers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Return the minimum sum of the path.
NOTE: You can only move either down or right at any point in time.

Problem Constraints
1 <= M, N <= 2000
-1000 <= A[i][j] <= 1000

Input Format
First and only argument is a 2-D grid A.

Output Format
Return an integer denoting the minimum sum of the path.

Example Input
Input 1:
 A = [
       [1, 3, 2]
       [4, 3, 1]
       [5, 6, 1]
     ]
Input 2:
 A = [
       [1, -3, 2]
       [2, 5, 10]
       [5, -5, 1]
     ]

Example Output
Output 1:
 8
Output 2:
 -1

Example Explanation
Explanation 1:
 The path will be: 1 -> 3 -> 2 -> 1 -> 1.
Input 2:
 The path will be: 1 -> -3 -> 5 -> -5 -> 1.

*/
int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<int> pre(m,0);
    vector<int> curr(m,0);
    pre[m-1] = A[n-1][m-1];
    for(int j=m-2; j>=0; j--){
        pre[j] = pre[j+1] + A[n-1][j];
    }
    int pre_sum = A[n-1][m-1];
    for(int i=n-2; i>=0; i--){
        curr[m-1] = pre_sum + A[i][m-1];
        pre_sum = curr[m-1];
        for(int j=m-2; j>=0; j--){
            curr[j] = A[i][j] + min(curr[j+1], pre[j]);
        }
        pre = curr;
    }
    return pre[0];
}
