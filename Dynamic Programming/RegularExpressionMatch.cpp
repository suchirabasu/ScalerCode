/*
Q28. Regular Expression Match
Problem Description
Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.
' ? ' : Matches any single character.
' * ' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Problem Constraints
1 <= length(A), length(B) <= 104

Input Format
The first argument of input contains a string A.
The second argument of input contains a string B.

Output Format
Return 1 if the patterns match else return 0.

Example Input
Input 1:
 A = "aaa"
 B = "a*"
Input 2:
 A = "acz"
 B = "a?a"

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 Since '*' matches any sequence of characters. Last two 'a' in string A will be match by '*'.
 So, the pattern matches we return 1.
Explanation 2:
 '?' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.


*/
int Solution::isMatch(const string A, const string B) {
    unordered_map<int,bool> B_mpp;
    int n = A.size(), m = B.size();
//for handling base case
    bool char_bfr = false;
    for(int i=0; i<m; i++){
        if(B[i] == '*'){
            B_mpp[i] = char_bfr;
        }
        else char_bfr = true;
    }
    vector<bool> pre(m+1,0);
    pre[0] = 1;
    vector<bool> curr(m+1,0);
    for(int j=1; j<=m; j++){
        if(B[j-1] == '?') pre[j] = 0;
//base depends on if any characters present bfr a '*'
        else if(B[j-1] == '*') pre[j] = !B_mpp[j-1];
        else pre[j] = 0;
    }
    for(int i=1; i<=n; i++){
        curr[0] = 0;
        for(int j=1; j<=m; j++){
            if(A[i-1] == B[j-1]) curr[j] = pre[j-1];
            else{
                if(B[j-1] == '?') curr[j] = pre[j-1];
                else if(B[j-1] == '*') curr[j] = (pre[j]|curr[j-1]);
                else curr[j] = 0;
            }
        }
        pre = curr;
    }
    return pre[m];
}