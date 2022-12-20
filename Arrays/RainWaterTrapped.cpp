/*
Q37. Rain water Trapped
Problem Description
Given a vector A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Problem Constraints
1 <= |A| <= 100000

Input Format
First and only argument is the vector A

Output Format
Return one integer, the answer to the question

Example Input
Input 1:
A = [0, 1, 0, 2]
Input 2:
A = [1, 2]

Example Output
Output 1:
1
Output 2:
0

Example Explanation
Explanation 1:
1 unit is trapped on top of the 3rd element.
Explanation 2:
No water is trapped.

*/
int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> leftmax(n,0);
    vector<int> rightmax(n,0);
    leftmax[0] = A[0];
    for(int i=1;i<n;i++)
        leftmax[i] = max(A[i], leftmax[i-1]);
    rightmax[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--)
        rightmax[i] = max(A[i], rightmax[i+1]);
    int sum = 0;
    for(int i=1;i<n-1;i++){
        sum += min(leftmax[i], rightmax[i]) - A[i];
    }
    return sum;
}
