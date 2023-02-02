/*
Q15. Kth Symbol
Problem Description
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
Given row number A and index B, return the Bth indexed symbol in row A. (The values of B are 1-indexed.).

Problem Constraints
1 <= A <= 20
1 <= B <= 2A - 1

Input Format
First argument is an integer A.
Second argument is an integer B.

Output Format
Return an integer denoting the Bth indexed symbol in row A.

Example Input
Input 1:
 A = 2
 B = 1
Input 2:
 A = 2
 B = 2

Example Output
Output 1:
 0
Output 2:
 1

Example Explanation
Explanation 1:
 Row 1: 0
 Row 2: 01
Explanation 2:
 Row 1: 0
 Row 2: 01

*/
int Solution::solve(int A, int B) {
    int n=A;
    if(A==0){
        return 0;
    }
    vector<int> res(1,0);
        for(int i=0;i<n;i++){
            int s=res.size();
            for(int j=0;j<s;j++){
                if(res[j]==0){
                    res.push_back(1);
                }
                else{
                    res.push_back(0);
                }
            }
        }
    return res[B-1];
}
