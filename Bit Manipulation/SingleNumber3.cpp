/*
Q6. Single Number III
Problem Description
Given an array of positive integers A, two integers appear only once, and all the other integers appear twice.
Find the two integers that appear only once. Note: Return the two numbers in ascending order.

Problem Constraints
2 <= |A| <= 100000
1 <= A[i] <= 109

Input Format
The first argument is an array of integers of size N.

Output Format
Return an array of two integers that appear only once.

Example Input
Input 1:
A = [1, 2, 3, 1, 2, 4]
Input 2:
A = [1, 2]

Example Output
Output 1:
[3, 4]
Output 2:
[1, 2]

Example Explanation
Explanation 1:
3 and 4 appear only once.
Explanation 2:
1 and 2 appear only once.

*/
vector<int> Solution::solve(vector<int> &A) {
     int k=0,unique_bit=0,side1=0,side2=0;
    vector <int> B(2);
    for(int i=0;i<A.size();i++){
        k=k^A[i]; //find the xor of all elements
    }


    unique_bit=(k&(k-1))^k; //find unique_bit which is present in only 1 of the 2 numbers that appear once
    for(int i=0;i<A.size();i++){
        if(unique_bit&A[i]){ //if unique bit is present, ie, and_value!=0
            side1=side1^A[i]; //xor such numbers separately
        }
        else side2=side2^A[i];
    }

    B[0]=min(side1,side2);
    B[1]=max(side2,side1);
    return B;
}
