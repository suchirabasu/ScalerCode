/*
Q10. Majority Element
Problem Description
Given an array of size N, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exists in the array.

Problem Constraints
1 <= N <= 5*105
1 <= num[i] <= 109

Input Format
Only argument is an integer array.

Output Format
Return an integer.

Example Input
[2, 1, 2]

Example Output
2

Example Explanation
2 occurs 2 times which is greater than 3/2.

*/
int Solution::majorityElement(const vector<int> &A) {
    int max = A[0];
    int n = A.size();
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(A[i] == max)
            cnt++;
        else if(cnt == 0){
            cnt = 1;
            max = A[i];
        }    
        else
            cnt--;
    }
    int freq=0;
    for(int i=0;i<n;i++){
        if(A[i] == max)
            freq++;
    }
    if(freq > n/2)
        return max;
    return -1;    
}
