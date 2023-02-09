/*
Q13. Reverse Pairs
Problem Description
Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
Return the number of important reverse pairs in the given array A.

Problem Constraints
1 <= length of the array <= 105
-2 * 109 <= A[i] <= 2 * 109

Input Format
The only argument given is the integer array A.

Output Format
Return the number of important reverse pairs in the given array A.

Example Input
Input 1:
 A = [1, 3, 2, 3, 1]
Input 2:
 A = [4, 1, 2]

Example Output
Output 1:
 2
Output 2:
 1

Example Explanation
Explanation 1:
 There are two pairs which are important reverse i.e (3, 1) and (3, 1).
Explanation 2:
 There is only one pair i.e (4, 1).

*/
long merge(vector<int> &A, int s, int m, int e){
    int T[e - s + 1];
    int p1 = s, p2 = m + 1;
    int count = 0;
    while(p1 <= m && p2 <= e){
        if((long)A[p1] > (long)2 * A[p2]){
            count += (m - p1 + 1);
            p2++;
        } 
        else p1++;
    }
    p1 = s; p2 = m + 1;
    int p3 = 0;
    while(p1 <= m && p2 <= e){
        if(A[p1] < A[p2]) T[p3++] = A[p1++];
        else T[p3++] = A[p2++];
    }
    while(p1 <= m) T[p3++] = A[p1++];
    while(p2 <= e) T[p3++] = A[p2++];
    for(int i = s; i <= e; i++){
        A[i] = T[i - s];
    }
    return count;
}
int getReversePairs(vector<int> &A, int s, int e){
    if(s >= e) return 0;
    int mid = s + (e - s) / 2;
    int l = getReversePairs(A, s, mid);
    int r = getReversePairs(A, mid+1, e);
    return (l + r + merge(A, s, mid, e));
}
int Solution::solve(vector<int> &A) {
return getReversePairs(A, 0, A.size() - 1);
}
