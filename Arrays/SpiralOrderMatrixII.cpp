/*
Q25. Spiral Order Matrix II
Problem Description
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.

Problem Constraints
1 <= A <= 1000

Input Format
First and only argument is integer A

Output Format
Return a 2-D matrix which consists of the elements added in spiral order.

Example Input
Input 1:
1
Input 2:
2
Input 3:
5

Example Output
Output 1:
[ [1] ]
Output 2:
[ [1, 2], [4, 3] ]
Output 2:
[ [1, 2, 3, 4, 5], [16, 17, 18, 19, 6], [15, 24, 25, 20, 7], [14, 23, 22, 21, 8], [13, 12, 11, 10, 9] ]

*/
vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
}
