/*
Q7. Check Palindrome 2
Problem Description
Given a string A consisting of lowercase characters. Check if characters of the given string can be rearranged to form a palindrome.
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Problem Constraints
1 <= |A| <= 105
A consists only of lower-case characters.

Input Format
First argument is an string A.

Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Example Input
Input 1:
 A = "abcde"
Input 2:
 A = "abbaee"

Example Output
Output 1:
 0
Output 2:
 1

Example Explanation
Explanation 1:
 No possible rearrangement to make the string palindrome.
Explanation 2:
 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome.
 */
int Solution::solve(string A) {
    int count[26] = {0};
for(int i = 0; i < A.length(); i++){
count[A[i] - 'a']++;
}
for(int i = 0; i < 26; i++){
count[i] %= 2;
}
int ans = 0;
for(int i = 0; i < 26; i++){
ans += count[i];
}
if(ans == 0 || ans == 1) return 1;
else return 0;
}
