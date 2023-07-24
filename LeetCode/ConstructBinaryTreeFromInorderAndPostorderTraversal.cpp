/*
Q4. Construct Binary Tree from inorder and postorder traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 
Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.


*/
class Solution {
public:
    TreeNode* solver(vector<int> &postorder,vector<int> &inorder,int size,int &postIndex,int start,int end,     unordered_map<int,int>  &mp)
   {
       if(postIndex<0 || start>end)
       {
           return NULL;
       }

       int element=postorder[postIndex];
       postIndex--;
       int pos= mp[element];
       TreeNode* root=new TreeNode(element);
       root->right=solver(postorder,inorder,size,postIndex,pos+1,end,mp);
       root->left= solver(postorder,inorder,size,postIndex,start,pos-1,mp); 
       return root;
       
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=postorder.size();
        int postIndex=size-1;
        int start=0;
        int end=size-1;
        unordered_map<int,int>  mp;
        for(int i=0;i<size;i++)
        {
            mp[inorder[i]]=i;
        }

        TreeNode* root=solver(postorder,inorder,size,postIndex,start,end,mp);
        return root;
    }
};