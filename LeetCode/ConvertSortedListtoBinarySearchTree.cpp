/*
Q6. Convert Sorted List to Binary Search Tree
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:
Input: head = []
Output: []
 
Constraints:
The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105

*/
class Solution {
public:
    vector<int> getArray(ListNode* head){
        vector<int> ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        return ans;
    }
    TreeNode* createBinarySearchTree(TreeNode* root,vector<int>& arr,int s,int e){
        if(s>e) return NULL;
        int mid=s+(e-s)/2;
        root=new TreeNode(arr[mid]);
        root->left=createBinarySearchTree(root->left,arr,s,mid-1);
        root->right=createBinarySearchTree(root->right,arr,mid+1,e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root=NULL;
        vector<int> arr=getArray(head);
        return createBinarySearchTree(root,arr,0,arr.size()-1);
    }
};