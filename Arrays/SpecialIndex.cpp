/*
Q2. Special Index
Problem Description
Given an array, arr[] of size N, the task is to find the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.

Problem Constraints
1 <= n <= 105
-105 <= A[i] <= 105


Input Format
First argument contains an array A of integers of size N

Output Format
Return the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.


Example Input
Input 1:
A=[2, 1, 6, 4]
Input 2:
A=[1, 1, 1]


Example Output
Output 1:
1
Output 2:
3

Example Explanation
Explanation 1:
Removing arr[1] from the array modifies arr[] to { 2, 6, 4 } such that, arr[0] + arr[2] = arr[1]. 
Therefore, the required output is 1. 
Explanation 2:

Removing arr[0] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[1] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[2] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Therefore, the required output is 3.
*/
int Solution::solve(vector<int> &A) {
    int n = A.size(), count = 0;
    vector<int> pfodd(n,0);
    vector<int> pfeven(n,0);
    pfodd[0] = 0;
    pfeven[0] = A[0];
    for(int i=1;i<n;i++){
        if(i%2==0){
            pfeven[i] = pfeven[i-1] + A[i];
            pfodd[i] = pfodd[i-1]; 
        }
        else{
            pfodd[i] = pfodd[i-1] + A[i];
            pfeven[i] = pfeven[i-1];
        }
    }
    if(pfeven[n-1] - A[0] == pfodd[n-1])
        count++;
    for(int i=1;i<n;i++){
        int totaleven = pfeven[i-1] + pfodd[n-1] - pfodd[i];
        int totalodd = pfodd[i-1] + pfeven[n-1] - pfeven[i];
        if(totaleven == totalodd)
            count++;
    }
    return count;
}
