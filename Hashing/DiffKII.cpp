/*
Q10. Diffk II
Problem Description
Given an array A of integers and another non negative integer B . Find if there exists 2 indices i and j such that A[i] - A[j] = B and i != j.

Problem Constraints
1 <= |A| <= 106
0 <= A[i] <= 109
0 <= B <= 109

Input Format
First argument A is an array of integer
Second argument B is an integer

Output Format
Return 1 if two such indexes are found and 0 otherwise

Example Input
Input 1:
A = [1, 5, 3]
B = 2
Input 2:
A = [2, 4, 3]
B = 3

Example Output
Output 1:
1
Output 2:
0

Example Explanation
For Input 1:
The given value of A[1] = 1 and A[3] = 3.
The value of A[3] - A[1] = 2.
For Input 2:
There are no pairs such that difference is B.

*/
int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int,int> hm;
    for(int i=0;i<n;i++)
        hm[A[i]]++;
    for(int i=0;i<n;i++){
        int temp = A[i] + B;
        if(A[i] == temp){
            int tem = hm[A[i]];
            if(tem > 1)
                return 1;
        }
        else if(hm.find(temp)== hm.end()){

        }
        else{
            return 1;
        }
    }
    return 0;
}
