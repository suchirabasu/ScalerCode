/*
Q17. Odd and Even Levels
Problem Description
Given a binary tree of integers. Find the difference between the sum of nodes at odd level and sum of nodes at even level.
NOTE: Consider the level of root node as 1.

Problem Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 109

Input Format
First and only argument is a root node of the binary tree, A

Output Format
Return an integer denoting the difference between the sum of nodes at odd level and sum of nodes at even level.

Example Input
Input 1:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  /
 8 
Input 2:
        1
       / \
      2   10
       \
        4

Example Output
Output 1:
 10
Output 2:
 -7

Example Explanation
Explanation 1:
 Sum of nodes at odd level = 23
 Sum of ndoes at even level = 13
Explanation 2:
 Sum of nodes at odd level = 5
 Sum of ndoes at even level = 12

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    int level = 1;
    int evenSum = 0;
    int oddSum = 0;
    while(q.size() > 1){
        TreeNode* curr = q.front();
        q.pop();
        if(curr==NULL){
            level++;
            q.push(NULL);
        }
        else {
            if(level&1) oddSum += curr->val;
            else evenSum += curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return oddSum-evenSum;

}
