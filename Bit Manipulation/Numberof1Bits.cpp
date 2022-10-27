/*
Q3. Number of 1 bits
Problem Description
Write a function that takes an integer and returns the number of 1 bits it has.


Problem Constraints
1 <= A <= 109


Input Format
First and only argument contains integer A


Output Format
Return an integer as the answer


Example Input
Input1:
11


Example Output
Output1:
3


Example Explanation
Explaination1:
11 is represented as 1011 in binary.

*/
int Solution::numSetBits(int A) {
    int count = 0;
    while(A>0){
        int temp = A%2;
        if(temp == 1)
            count++;
        A = A / 2;    
    }
    return count;
}
