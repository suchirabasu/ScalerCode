/*
Q9. Symmetric Binary tree
Problem Description
Given a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Problem Constraints
1 <= number of nodes <= 105

Input Format
First and only argument is the root node of the binary tree.

Output Format
Return 0 / 1 ( 0 for false, 1 for true ).

Example Input
Input 1:

    1
   / \
  2   2
 / \ / \
3  4 4  3
Input 2:

    1
   / \
  2   2
   \   \
   3    3

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 The above binary tree is symmetric. 
Explanation 2:
The above binary tree is not symmetric.

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
bool preorder(TreeNode* lhs, TreeNode* rhs){
    if(lhs==NULL && rhs==NULL) return true;
    if(lhs==NULL || rhs==NULL) return false;
    if(lhs->val == rhs->val) return (preorder(lhs->left, rhs->right) && preorder(lhs->right, rhs->left));
    return false;
}

int Solution::isSymmetric(TreeNode* A) {
    if(preorder(A->left, A->right)) return 1;
    return 0;
}
