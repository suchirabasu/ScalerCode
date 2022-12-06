/*
Q10. Gray Code
Problem Description
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer A representing the total number of bits in the code, print the sequence of gray code.
A gray code sequence must begin with 0.

Problem Constraints
1 <= A <= 16

Input Format
The first argument is an integer A.

Output Format
Return an array of integers representing the gray code sequence.

Example Input
Input 1:
A = 2
Input 1:
A = 1

Example Output
output 1:
[0, 1, 3, 2]
output 2:
[0, 1]

Example Explanation
Explanation 1:
for A = 2 the gray code sequence is:
    00 - 0
    01 - 1
    11 - 3
    10 - 2
So, return [0,1,3,2].
Explanation 1:
for A = 1 the gray code sequence is:
    00 - 0
    01 - 1
So, return [0, 1].

*/
vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>ans;
    ans.push_back(0);
    for(int i=0;i<A;i++){
        for(int j=ans.size()-1;j>=0;j--){
            ans.push_back(ans[j]| 1<<i); // 0 ,0|1 =1, 1|2^1 = 3, 0|2^1 = 2 : a = 2 size = 1
        }
    }
    return ans;
}
