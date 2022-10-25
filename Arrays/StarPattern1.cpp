/*
Q36. Star Pattern.cpp
Problem Description
Write a program to input an integer N from user and print hollow diamond star pattern series of N lines.
See example for clarifications over the pattern.

Problem Constraints
1 <= N <= 1000

Input Format
First line is an integer N

Output Format
N lines conatining only char '*' as per the question.

Example Input
Input 1:
4
Input 2:
6

Example Output
Output 1:
********
***  ***
**    **
*      *
*      *
**    **
***  ***
********
Output 2:
************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************

*/
#include<iostream>

using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int N;
    cin>>N;
    for (int i = 0; i < N*2; i++) {
            for (int j = 0; j < N*2; j++) {
                if ((i < N && (j < N-i || j >= N+i)) || (j <= i-N || j > N*2-i+N-2)) {
                    cout<<"*";
                } else {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
       
    return 0;
}