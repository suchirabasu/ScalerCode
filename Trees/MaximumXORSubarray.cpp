/*
Q24. Maximum XOR Subarray
Problem Description
Given an array, A of integers of size N. Find the subarray AL, AL+1, AL+2, ... AR with 1<=L<=R<=N, which has maximum XOR value.
NOTE: If there are multiple subarrays with the same maximum value, return the subarray with minimum length. If the length is the same, return the subarray with the minimum starting index.

Problem Constraints
1 <= N <= 100000
0 <= A[i] <= 109

Input Format
First and only argument is an integer array A.

Output Format
Return an integer array B of size 2. B[0] is the starting index(1-based) of the subarray and B[1] is the ending index(1-based) of the subarray.

Example Input
Input 1:
 A = [1, 4, 3]
Input 2:
 A = [8]

Example Output
Output 1:
 [2, 3]
Output 2:
 [1, 1]

Example Explanation
Explanation 1:
 There are 6 possible subarrays of A:
 subarray            XOR value
 [1]                     1
 [4]                     4
 [3]                     3
 [1, 4]                  5 (1^4)
 [4, 3]                  7 (4^3)
 [1, 4, 3]               6 (1^4^3)
 [4, 3] subarray has maximum XOR value. So, return [2, 3].
Explanation 2:
 There is only one element in the array. So, the maximum XOR value is equal to 8 and the only possible subarray is [1, 1].
*/
class Node{
    public:
        Node* childrens[2];
        Node(){
            this->childrens[0] = NULL;
            this->childrens[1] = NULL;
        }
};

vector<int> Solution::solve(vector<int> &A) {

    unordered_map<int, int> umap;
    vector<int> pfXor;

    Node* root = new Node();
    pfXor.push_back(A[0]);
    
    int maxXor = A[0], leftIndex = 0, rightIndex = 0, sizeOfTrie = 31;

    //creating pfXor array and simultaneously checking for maxXor
    for(int i=1;i<A.size();i++){
        if(A[i]>maxXor){
            maxXor = A[i];
            leftIndex = i, rightIndex = i;
        }

        pfXor.push_back(pfXor[i-1]^A[i]);
        
        if(pfXor[i]>maxXor){
            maxXor = pfXor[i];
            leftIndex = 0, rightIndex = i;
        }
    }

    //inserting in unordered_map for index retrival
    for(int i=0;i<pfXor.size();i++)
        if(umap.find(pfXor[i])==umap.end()) umap.insert({pfXor[i],i});
    
    //inserting bits of elements from pfXor into Trie
    for(int i=0;i<pfXor.size();i++){
        Node* curr = root;
        for(int j=sizeOfTrie;j>=0;j--){

            if(pfXor[i]&(1<<j)){
                if(curr->childrens[1]==NULL) curr->childrens[1] = new Node();
                curr = curr->childrens[1];
            } else {
                if(curr->childrens[0]==NULL) curr->childrens[0] = new Node();
                curr = curr->childrens[0];
            }

        }
    }

    //finding element with max diff bits and updating maxXor if found
    for(int i=0;i<pfXor.size();i++) {

        Node* curr = root;
        int currXor = 0;

        for(int j=sizeOfTrie;j>=0;j--) {

            if(pfXor[i]&(1<<j)) {
                if(curr->childrens[0]!=NULL) {
                    curr = curr->childrens[0];
                } else {
                    curr = curr->childrens[1];
                    currXor |= (1<<j);
                }
            } else {
                if(curr->childrens[1]!=NULL) {
                    curr = curr->childrens[1];
                    currXor |= (1<<j);
                } else 
                    curr = curr->childrens[0];
            }

        }
        //here we check if maxXor is equal to currXor then if length of newMaxXorSubarr is less than that of prevMaxXor Subarr 
        if( ((pfXor[i]^currXor) > maxXor) || ( (maxXor <= (pfXor[i]^currXor)) && ((max(i+1, umap[currXor]) - min(i+1, umap[currXor])) < (rightIndex - leftIndex)) ) ){
            maxXor = (pfXor[i]^currXor);
            leftIndex = min(i+1, umap[currXor]);
            rightIndex = max(i+1, umap[currXor]);
        }
    }
    return {leftIndex+1, rightIndex+1};
}