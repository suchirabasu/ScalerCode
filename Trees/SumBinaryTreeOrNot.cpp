/*
Q12. Sum Binary Tree or Not
Problem Description
Given a binary tree. Check whether the given tree is a Sum-binary Tree or not.
Sum-binary Tree is a Binary Tree where the value of a every node is equal to sum of the nodes present in its left subtree and right subtree.
An empty tree is Sum-binary Tree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.
Return 1 if it sum-binary tree else return 0.

Problem Constraints
1 <= length of the array <= 100000
0 <= node values <= 50

Input Format
The only argument given is the root node of tree A.

Output Format
Return 1 if it is sum-binary tree else return 0.

Example Input
Input 1:
       26
     /    \
    10     3
   /  \     \
  4   6      3
Input 2:
       26
     /    \
    10     3
   /  \     \
  4   6      4

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 All leaf nodes are considered as SumTree. 
 Value of Node 10 = 4 + 6.
 Value of Node 3 = 0 + 3 
 Value of Node 26 = 20 + 6 
Explanation 2:
 Sum of left subtree and right subtree is 27 which is not equal to the value of root node which is 26.

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
int check(TreeNode* A){
    if(A==NULL) return 0;
    int leftSum = check(A->left);
    int rightSum = check(A->right);
    if(leftSum==-1 || rightSum==-1) return -1;
    if((A->val == leftSum+rightSum) || (leftSum==rightSum && rightSum==0)) return leftSum+rightSum+A->val;
    return -1;
}

int Solution::solve(TreeNode* A) {
    if(check(A)>0) return 1;
    return 0;
}
