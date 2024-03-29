/*
Q26. Valid Phone Directory
Problem Description
Given a phone directory in the form of string array A containing N numeric strings.
If any phone number is prefix of another phone number then phone directory is invalid else it is valid.
You need to check whether the given phone directory is valid or not if it is valid then return 1 else return 0.

Problem Constraints
2 <= N <= 105
1 <= |A[i]| <= 50
A[i] consists only of numeric digits.

Input Format
First and only argument is an string array A.

Output Format
Return 1 if the given phone directory is valid else return 0.

Example Input
Input 1:
 A = ["1234", "2342", "567"]
Input 2:
 A = ["00121", "001"]

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 No number is prefix of any other number so phone directory is valid so we will return 1.
Explanation 2:
 "001" is prefix of "00121" so phone directory is invalid so we will return 0.

*/
int Solution::solve(vector<string> &A) {
    vector<int> digits (10);    // 0 - 9
        for (int i = 0; i < A.size(); i++) {
               int val = A[i][0] - '0';
               if (digits[val] != 0) return 0;
              digits[val] = 1;
       }
       return 1;
}
