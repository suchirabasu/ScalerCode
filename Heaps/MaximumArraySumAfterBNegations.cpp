/*
Q1. Maximum Array Sum After B negations
Problem Description
Given an array of integers A and an integer B. You must modify the array exactly B number of times. In a single modification, we can replace any one array element A[i] by -A[i].
You need to perform these modifications in such a way that after exactly B modifications, sum of the array must be maximum.

Problem Constraints
1 <= length of the array <= 5*105
1 <= B <= 5 * 106
-100 <= A[i] <= 100

Input Format
The first argument given is an integer array A.
The second argument given is an integer B.

Output Format
Return an integer denoting the maximum array sum after B modifications.

Example Input
Input 1:
 A = [24, -68, -29, -9, 84]
 B = 4
Input 2:
 A = [57, 3, -14, -87, 42, 38, 31, -7, -28, -61]
 B = 10

Example Output
Output 1:
 196
Output 2:
 362

Example Explanation
Explanation 1:
 Final array after B modifications = [24, 68, 29, -9, 84]
Explanation 2:
 Final array after B modifications = [57, -3, 14, 87, 42, 38, 31, 7, 28, 61]

*/
int Solution::solve(vector < int > & A, int B) {

    priority_queue < int, vector < int > , greater < int >> pq;

    // insert all elements into the queue
    for (int x: A) pq.push(x);

    // perform B modifications

    while (B > 0) {
        // pop minimum lement from the queue
        int x = pq.top();
        pq.pop();

        // if minimum element is 0, we will use all remaining opeations on this and the result will be same      
        if (x == 0) {
            B = 0;
        }
        // if minimum element is negative, modify the element to -x and push -x to queue.
        else if (x < 0) {
            pq.push(-x);
        } else {
            //if remaining operations are even, then in one operation we convert x to -x and in another -x to x. So, no change
            //if operations are odd, we will change the number to -x. Set B = 0.
            if (B % 2 == 0) {
                pq.push(x);
            } else {
                pq.push(-x);
            }

            B = 0;
            break;
        }

        B--;
    }

    int ans = 0;

    // add all the elements in the queue to the answer
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    return ans;
}