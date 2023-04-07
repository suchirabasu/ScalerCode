/*
Q7. Remove Invalid Parentheses
Problem Description
Given a string A consisting of lowercase English alphabets and parentheses '(' and ')'. Remove the minimum number of invalid parentheses in order to make the input string valid.
Return all possible results.
You can return the results in any order.

Problem Constraints
1 <= length of the string <= 20

Input Format
The only argument given is string A.

Output Format
Return all possible strings after removing the minimum number of invalid parentheses.

Example Input
Input 1:
 A = "()())()"
Input 2:
 A = "(a)())()"

Example Output
Output 1:
 ["()()()", "(())()"]
Output 2:
 ["(a)()()", "(a())()"]

Example Explanation
Explanation 1:
 By removing 1 parentheses we can make the string valid.
        1. Remove the parentheses at index 4 then string becomes : "()()()"
        2. Remove the parentheses at index 2 then string becomes : "(())()"
Explanation 2:
 By removing 1 parentheses we can make the string valid.
        1. Remove the parentheses at index 5 then string becomes : "(a)()()"
        2. Remove the parentheses at index 2 then string becomes : "(a())()"

*/
void rec(int idx, string & s, string curr_str, int off_left, int off_right, set < string > & res_set, int balance) {
    // If we reached the end of the string, just check if the resulting expression is valid or not and 
    // also if we have removed the total number of left and right parentheses that we should have removed.
    if (idx == s.length()) {
        if (off_left == 0 && off_right == 0) {
            res_set.insert(curr_str);
        }
    } else if (balance >= 0) {
        if (s[idx] == '(' && off_left > 0) {
            rec(idx + 1, s, curr_str, off_left - 1, off_right, res_set, balance);
        }
        if (s[idx] == ')' && off_right > 0) {
            rec(idx + 1, s, curr_str, off_left, off_right - 1, res_set, balance);
        }
        int diff = 0;
        if (s[idx] == ')') {
            diff = -1;
        }
        if (s[idx] == '(') {
            diff = 1;
        }
        rec(idx + 1, s, curr_str + s[idx], off_left, off_right, res_set, balance + diff);
    }
}

void set_off_counts(int & off_left, int & off_right, string & s) {
    for (char c: s) {
        if (c == '(')
            off_left++;
        if (c == ')') {
            if (off_left > 0) {
                off_left--;
            } else {
                off_right++;
            }
        }
    }
}

vector < string > removeInvalidParentheses(string s) {
    int off_left = 0, off_right = 0;
    // we find out the number of misplaced left and right parentheses
    set_off_counts(off_left, off_right, s);
    set < string > res_set;
    rec(0, s, "", off_left, off_right, res_set, 0);
    vector < string > res;
    for (string val: res_set)
        res.push_back(val);
    return res;
}

vector < string > Solution::solve(string A) {
    vector < string > ans = removeInvalidParentheses(A);
    return ans;
}