/*
Q13. 'Problem Description
Surprisingly, in an alien language, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given an array of words A of size N written in the alien language, and the order of the alphabet denoted by string B of size 26, return 1 if and only if the given words are sorted lexicographically in this alien language else, return 0.

Problem Constraints
1 <= N, length of each word <= 105
Sum of the length of all words <= 2 * 106

Input Format
The first argument is a string array A of size N.
The second argument is a string B of size 26, denoting the order.

Output Format
Return 1 if and only if the given words are sorted lexicographically in this alien language else, return 0.

Example Input
Input 1:
 A = ["hello", "scaler", "interviewbit"]
 B = "adhbcfegskjlponmirqtxwuvzy"
Input 2:
 A = ["fine", "none", "no"]
 B = "qwertyuiopasdfghjklzxcvbnm"

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 The order shown in string B is: h < s < i for the given words. So return 1.
Explanation 2:
 "none" should be present after "no". Return 0.

*/
bool comp(string s1,string s2 ,unordered_map<char,int> &hm ){
    //return true if  smaller  string should come first
   
    int lenA=s1.size();
    int lenB=s2.size();
    int min_len=min(lenA,lenB);
    for(int i = 0 ; i < min_len; i++  ){
        if(s1[i]!=s2[i]){
            if(hm[{s1[i]}] < hm[{s2[i]}]){
                return true ;
            }else{
                return false;
            }
        }
    }
    if(lenA < lenB){
        return true;
    }
    else{
        return false;
    }
       
}
int Solution::solve(vector<string> &A, string B) {
    //insert all elements of B in hashmap
    unordered_map<char,int> hm;
    for(int i = 1 ; i<=26;i++){
        hm.insert({B[i],i});
    }
    bool flag=false;
    int N = A.size();
    if(N <= 1) return true;
    for(int i = 0 ; i < N-1 ; i++){
        if(comp(A[i],A[i+1],hm)){
            flag=true;
        }else{
            return false;
        }
    }
    return flag ;
}
