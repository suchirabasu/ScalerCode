/*
Q7. Longest Palindromic String
Problem Description
Given a string A of size N, find and return the longest palindromic substring in A.
Substring of string A is A[i...j] where 0 <= i <= j < len(A)
Palindrome string:
A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.
Incase of conflict, return the substring which occurs first ( with the least starting index).

Problem Constraints
1 <= N <= 6000

Input Format
First and only argument is a string A.

Output Format
Return a string denoting the longest palindromic substring of string A.

Example Input
A = "aaaabaaa"

Example Output
"aaabaaa"

Example Explanation
We can see that longest palindromic substring is of length 7 and the string is "aaabaaa".

*/
vector<int> expand(string &A, int i, int j) {
    vector<int> str = {0,0};
    while (i>=0 && j<A.size() && A[i]==A[j]) {
        str[0] = i;
        str[1] = j;
        i--;
        j++;
    }
    return str;
}
string Solution::longestPalindrome(string A) {
    int n = A.size();
    vector<int> s;
    int count = 1;
    int start =0;
    int end =0;
    string ans = "";
    for(int i=0;i<n;i++) {
        s = expand(A,i,i);
        if(s[1]-s[0]+1 > count) {
            count = s[1]-s[0]+1;
            start = s[0];
            end = s[1];
        }
        s = expand(A,i,i+1);
        if(s[1]-s[0]+1 > count) {
            count = s[1]-s[0]+1;
            start = s[0];
            end = s[1];
        }
    }
    for(int i=start;i<=end;i++) {
        ans += A[i];
    }
    return ans;
}
