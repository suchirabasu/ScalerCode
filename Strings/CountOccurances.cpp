/*
Q9. Count Occurances
Problem Description
Find the number of occurrences of bob in string A consisting of lowercase English alphabets.

Problem Constraints
1 <= |A| <= 1000

Input Format
The first and only argument contains the string A, consisting of lowercase English alphabets.

Output Format
Return an integer containing the answer.

Example Input
Input 1:
  "abobc"
Input 2:
  "bobob"

Example Output
Output 1:
  1
Output 2:
  2

Example Explanation
Explanation 1:
  The only occurrence is at second position.
Explanation 2:
  Bob occures at first and third position.

*/
int Solution::solve(string A) {
    int n = A.size();
    int count = 0;
    for(int i=0;i<n-2;i++){
        //cout<<A[i]<<" ";
        if(A[i] == 'b' && A[i+1] == 'o' && A[i+2] == 'b')
            count++;
    }
    return count;
}
