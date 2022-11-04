/*
Q6. Concatenate three numbers
Problem Description
Given three 2-digit integers, A, B, and C, find out the minimum number obtained by concatenating them in any order.
Return the minimum result obtained.

Problem Constraints
10 <= A, B, C <= 99

Input Format
The first argument of input contains an integer, A.
The second argument of input contains an integer, B.
The third argument of input contains an integer, C.

Output Format
Return an integer representing the answer.

Example Input
Input 1:
 A = 10
 B = 20
 C = 30
Input 2:
 A = 55
 B = 43
 C = 47 

Example Output
Output 1:
 102030 
Output 2:
 434755 

Example Explanation
Explanation 1:
 10 + 20 + 30 = 102030 
Explanation 2:
 43 + 47 + 55 = 434755 

*/
int Solution::solve(int A, int B, int C) {
    if(A<=B && A<=C){
        if(B <= C){
            int x = A * 10000;
            int y = B * 100;
            return x+y+C;
        }
        else{
            int x = A*10000;
            int y = C*100;
            return x+y+B;
        }
    }
    else if(B<=A && B<=C){
        if(A<=C){
            int x = B*10000;
            int y = A*100;
            return x+y+C;
        }
        else{
             int x = B*10000;
            int y = C*100;
            return x+y+A;
        
        }
    }   
    else if(C<=B && C<=A){
        if(B<=A){
            int x = C*10000;
            int y = B*100;
            return x+y+A;
        }
        else{
            int x = C*10000;
            int y = A*100;
            return x+y+B;
        }
    }
    return -1;       
}
