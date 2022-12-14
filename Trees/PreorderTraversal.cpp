/*
Q2. Preorder Traversal
Problem Description
Given a binary tree, return the preorder traversal of its nodes values.
NOTE: Using recursion is not allowed.

Problem Constraints
1 <= number of nodes <= 105

Input Format
First and only argument is root node of the binary tree, A.

Output Format
Return an integer array denoting the preorder traversal of the given binary tree.

Example Input
Input 1:
   1
    \
     2
    /
   3
Input 2:
   1
  / \
 6   2
    /
   3

Example Output
Output 1:
 [1, 2, 3]
Output 2:
 [1, 6, 2, 3]

Example Explanation
Explanation 1:
 The Preoder Traversal of the given tree is [1, 2, 3].
Explanation 2:
 The Preoder Traversal of the given tree is [1, 6, 2, 3].

*/
/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode left;
      TreeNode right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorderTraversal_helper(TreeNode A, vector<int>&ans) {
    if(A!=NULL) {
        ans.emplace_back(A->val);
        preorderTraversal_helper(A->left, ans);
        preorderTraversal_helper(A->right, ans);
    }
}

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int>ans;
    preorderTraversal_helper(A, ans);
    return ans;
}