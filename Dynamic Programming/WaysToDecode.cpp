/*
Q7. Ways to Decode
Problem Description
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message denoted by string A containing digits, determine the total number of ways to decode it modulo 109 + 7.



Problem Constraints
1 <= length(A) <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return an integer, representing the number of ways to decode the string modulo 109 + 7.



Example Input
Input 1:

 A = "12"
Input 2:

 A = "8"


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.
Explanation 2:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.

*/
int Solution::numDecodings(string A) {
    int mod = 1000000007;
    
    if(A[0]=='0') return 0;
    
    long long first = 1, second = 1, curr = 0;
    for(int i=1;i<A.length();i++){
        if(A[i] == '0' && A[i-1] > '2') {
            return 0;
        }
        else if(A[i]=='0' && A[i-1]<='2'){
            curr = first;
            second = first;
            first = 0;
            continue;
        }
        else if((A[i-1]=='2' && A[i]<='6') || (A[i-1]=='1')){
            curr = first + second;
            curr %= mod;
        } else {
            curr = second;
        }
        first = second;
        second = curr;
    }
    return second;

}
