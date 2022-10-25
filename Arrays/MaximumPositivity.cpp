/*
Q35. Maximum Positivity
Problem Description
Given an array of integers A, of size N. Return the maximum size subarray of A having only non-negative elements. If there are more than one such subarray, return the one having the smallest starting index in A.
NOTE: It is guaranteed that an answer always exists.

Problem Constraints
1 <= N <= 105
-109 <= A[i] <= 109

Input Format
The first and only argument given is the integer array A.

Output Format
Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.

Example Input
Input 1:
 A = [5, 6, -1, 7, 8]
Input 2:
 A = [1, 2, 3, 4, 5, 6]

Example Output
Output 1:
 [5, 6]
Output 2:
 [1, 2, 3, 4, 5, 6]

Example Explanation
Explanation 1:
 There are two subarrays of size 2 having only non-negative elements.
 1. [5, 6]  starting point  = 0
 2. [7, 8]  starting point  = 3
 As starting point of 1 is smaller, return [5, 6]
Explanation 2:
 There is only one subarray of size 6 having only non-negative elements:
 [1, 2, 3, 4, 5, 6]

*/
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    int leastIdx = -1;
    int idx = -1;
    int len =0;
    int maxLen=0;
    vector<int> v;

    for(int i=0;i<n;i++){
    if(A[i]>=0){
    if(idx==-1) idx=i;
    len++;
    }

    if(A[i]<0 || i==n-1){
    if(len>maxLen){
    maxLen = len;
    leastIdx = idx;
    }
    idx=-1;
    len=0;
    }
    }

    for(int i=leastIdx; i<(leastIdx+maxLen); i++){
    v.push_back(A[i]);
    }
    return v;
}
