/*
Q3. Divisibility By 8
Problem Description
You are given a number A in the form of a string. Check if the number is divisible by eight or not.
Return 1 if it is divisible by eight else, return 0.

Problem Constraints
1 <= length of the String <= 100000
'0' <= A[i] <= '9'

Input Format
The only argument given is a string A.

Output Format
Return 1 if it is divisible by eight else return 0.

Example Input
Input 1:
A = "16"
Input 2:
A = "123"

Example Output
Output 1:
1
Output 2:
0

Example Explanation
Explanation 1:
 16 = 8 * 2
Explanation 2:
123 = 15 * 8 + 3

*/
int Solution::solve(string A) {
    int N = A.size();
    if(N==0){
        return 0;
    }
    // Only one digit
    if(N==1){
        return ((A[0]-'0')%8 == 0);
    }
    // Only two digit
    if(N==2){
        return (((A[N-2]-'0')*10+A[N-1]-'0')%8==0);
    }
    int last = A[N-1]-'0';
    int sec_last = A[N-2]-'0';
    int third_last = A[N-3]-'0';
    return ((third_last*100+sec_last*10+last)%8 == 0);

}
