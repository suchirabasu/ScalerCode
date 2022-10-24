/*
Q33. Length of Longest Consecutive Ones
Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved.

Input Format
The only argument given is string A.

Output Format
Return the length of the longest consecutive 1’s that can be achieved.

Constraints
1 <= length of string <= 1000000
A contains only characters 0 and 1.

For Example
Input 1:
    A = "111000"
Output 1:
    3
Input 2:
    A = "111011101"
Output 2:
    7
*/
int Solution::solve(string A) {
    int n = A.length();
    int c = 0;
    int ans = 0;
    for (int i=0;i<n;i++) {
        int ch = A[i]-'0'; // -‘0’ is to convert it into proper integer
        c+=ch; // c is number of 1s
    }
    if (c==n) {
        return n;
    }
    for (int i=0;i<n;i++) {
        int count = 0;
        int l=0, r=0;
        if (A[i]-'0' == 0) {
            for (int j=i-1;j>=0;j--) {
                if (A[j]-'0' == 1) {
                l=l+1;
                } else {
                    break;
                }
            }
            for (int k=i+1;k<n;k++) {
                if (A[k]-'0' == 1) {
                    r = r+1;
                } else {
                    break;
                }
            }
        count = l+r;
        if (c>l+r) { // if we have one extra one present… then we can swap…
            count = count+1;
        }
        }
        if (ans<count) {
            ans = count;
        }
    }
    return ans;
}
