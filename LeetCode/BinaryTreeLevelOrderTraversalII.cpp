/*
Q5. Binary Tree Level Order Traversal II
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //int i=0;
        vector<vector<int>> v;
         if(root==NULL) return v;
        queue<TreeNode*>q;
       
        q.push(root);
        q.push(NULL);
        vector<int>v1;
        while(!q.empty()){
            TreeNode *cur=q.front();
            q.pop();
            
            if(cur==NULL){
                v.push_back(v1);
                v1.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            }else{
                    v1.push_back(cur->val);
            if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);
            }
            
            
        }
        stack<vector<int>>s;
        int n=v.size();
        for(int i=0;i<n;i++){
            s.push(v[i]);
        }
        vector<vector<int>> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};