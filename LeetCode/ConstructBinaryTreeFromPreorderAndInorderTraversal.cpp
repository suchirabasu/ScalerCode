/*
Q3. Construct Binary Tree From Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
 
Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

*/
class Solution {
public:
TreeNode * build(unordered_map<int,int>&mp,vector<int>&pre,int &nd,int s,int e)
{
    
    TreeNode* node  = new TreeNode(pre[nd]);

    int ind  = mp[pre[nd]];
    nd++;
      if(s==e)return node;
      if(nd<pre.size()&&s<=ind-1)
    node->left = build(mp,pre,nd,s,ind-1);
    if(nd<pre.size()&&ind+1<=e)
    node->right = build(mp,pre,nd,ind+1,e);
    return node;
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
  unordered_map<int,int>mp;
    for(int i=0;i<in.size();i++)
    mp[in[i]]=i;

    int x=0;
     return build(mp,pre,x,0,in.size()-1);
    }
};