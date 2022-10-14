/*
Q7. Closest MinMax
Problem Description
Given an array A, find the size of the smallest subarray such that it contains at least one occurrence of the maximum value of the array and at least one occurrence of the minimum value of the array.

Problem Constraints
1 <= |A| <= 2000

Input Format
First and only argument is vector A

Output Format
Return the length of the smallest subarray which has at least one occurrence of minimum and maximum element of the array

Example Input
Input 1:
A = [1, 3]
Input 2:
A = [2]

Example Output
Output 1:
2
Output 2:
1

Example Explanation
Explanation 1:
Only choice is to take both elements.
Explanation 2:
Take the whole array.

*/
int Solution::solve(vector<int> &A) {
    int n = A.size();
    int maxi = -1, mini = -1, ans = INT_MAX;
    int tempmax=A[0], tempmin = A[0];
    for(int i=1;i<n;i++){
        if(tempmax < A[i])  
            tempmax = A[i];
        if(tempmin > A[i])
            tempmin = A[i];    
    }
    for(int i=0;i<n;i++){
        if(A[i]==tempmin)
            mini = i;
        if(A[i]== tempmax)
            maxi = i;
        if(maxi != -1 && mini != -1){
            ans = min(ans, abs(maxi - mini) + 1);
        }       
    }
    return ans;
}        
        