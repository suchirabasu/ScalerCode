/*
Q12. Max Sum Contiguous Subarray
Problem Description
Find the contiguous non-empty subarray within an array, A of length N, with the largest sum.

Problem Constraints
1 <= N <= 1e6
-1000 <= A[i] <= 1000

Input Format
The first and the only argument contains an integer array, A.

Output Format
Return an integer representing the maximum possible sum of the contiguous subarray.

Example Input
Input 1:
A = [1, 2, 3, 4, -10] 
Input 2:
A = [-2, 1, -3, 4, -1, 2, 1, -5, 4] 

Example Output
Output 1:
10 
Output 2:
6 


Example Explanation
Explanation 1:
The subarray [1, 2, 3, 4] has the maximum possible sum of 10. 
Explanation 2:
The subarray [4,-1,2,1] has the maximum possible sum of 6. 

*/
int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int maxSum = INT_MIN;
    vector<int> prefixSum(n,0);
    prefixSum[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    int minPrefixSum = 0;
    for (int i = 0; i < n; i++) {
        maxSum = max(maxSum, prefixSum[i] - minPrefixSum);
        minPrefixSum = min(minPrefixSum, prefixSum[i]);
    }

// Kadan's algorithem for this is problem is 
    int currentSum = 0;
    for(int i = 0; i < n; i++){
        currentSum += A[i];
        if(currentSum > maxSum){
            maxSum = currentSum;
        }
        if(currentSum < 0){
            currentSum = 0;
        }
    }
    return maxSum;

}
