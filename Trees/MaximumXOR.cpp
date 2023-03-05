/*
Q23. Maximum XOR
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.

Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 109

Input Format
The only argument given is the integer array A.

Output Format
Return an integer denoting the maximum result of A[i] XOR A[j].

Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
Input 2:
 A = [5, 17, 100, 11]

Example Output
Output 1:
 7
Output 2:
 117

Example Explanation
Explanation 1:
 Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
Explanation 2:
 Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117
*/
class Node{
    public:
        Node* children[2];
        Node(){
            for(int i=0;i<2;i++) this->children[i] = NULL;
        }
};

int Solution::solve(vector<int> &A) {
    Node* root = new Node();
    int maxVal = INT_MIN;
    for(auto x: A){
        if(x>maxVal) maxVal = x;
    }
    int sizeOfTrie = log2(maxVal);  //largest no in array takes this many bits
    
    for(int i=0;i<A.size();i++){
        Node* curr = root;
//filling the trie
        for(int j=sizeOfTrie;j>=0;j--){
            if(A[i]&(1<<j)){
                if(curr->children[1]==NULL) curr->children[1] = new Node();
                curr = curr->children[1];
            }
            else {
                if(curr->children[0]==NULL) curr->children[0] = new Node();
                curr = curr->children[0];
            }
        }
    }
    int maxXor = INT_MIN;
//checking for flipped bits if any no exist then save in currXor and check at end of loop
    for(int i=0;i<A.size();i++){
        Node* curr = root;
        int currXor = 0;
        for(int j=sizeOfTrie;j>=0;j--){
            if(A[i]&(1<<j)){
                if(curr->children[0]!=NULL) curr = curr->children[0];
                else {
                    curr = curr->children[1];
                    currXor |= (1<<j);
                }
            }
            else {
                if(curr->children[1]!=NULL) {
                    curr = curr->children[1];
                    currXor |= (1<<j);
                }
                else curr = curr->children[0];
            }
        }
        if((currXor^A[i])>maxXor) maxXor = (currXor^A[i]);
    }
    return maxXor;
}
