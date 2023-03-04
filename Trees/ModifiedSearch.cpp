/*
Q22. Modified Search
Problem Description
Given two arrays of strings A of size N and B of size M.
Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using exactly one modification in B[i], Else C[i] = '0'.
NOTE: modification is defined as converting a character into another character.

Problem Constraints
1 <= N <= 30000
1 <= M <= 2500
1 <= length of any string either in A or B <= 20
strings contains only lowercase alphabets

Input Format
First argument is the string arrray A.
Second argument is the string array B.

Output Format
Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using one modification in B[i], Else C[i] = '0'.

Example Input
Input 1:
 A = [data, circle, cricket]
 B = [date, circel, crikket, data, circl]
Input 2:
 A = [hello, world]
 B = [hella, pello, pella]

Example Output
Output 1:
 "10100"
Output 2:
 "110"

Example Explanation
Explanation 1:
 1. date = dat*(can be found in A)
 2. circel =(cannot be found in A using exactly one modification)
 3. crikket = cri*ket(can be found in A)
 4. data = (cannot be found in A using exactly one modification)
 5. circl = (cannot be found in A using exactly one modification)
Explanation 2:
 Only pella cannot be found in A using only one modification.

*/
class TrieNode {
    public:
    bool isEnd;
    map<char, TrieNode*> mp;
    TrieNode(){
        isEnd = false;
    }
};

void addString( TrieNode* r, string str){
    int n = str.length();
    for ( int i = 0 ; i < n ; i++){
        char ch = str[i];
        if ( r->mp.find(ch) != r->mp.end()){
            r = r->mp[ch];
        } else {
            TrieNode* newNode = new TrieNode();
            r->mp[ch] = newNode;
            r = newNode;
        }
    }
    r->isEnd = true;
}

bool findString(TrieNode* r, int idx, string str, bool flag){
    bool ans = false;
    if ( idx == str.length()){
        if ( flag && r->isEnd){
            return true;
        }
        return false;
    }

    char c = str[idx];
    if ( flag == 0){
    for (auto x = r->mp.begin(); x != r->mp.end(); x++) {
        if (x->first == c) {
            ans = ans | findString(x->second, idx + 1, str, flag);
        } else {
            ans = ans | findString(x->second, idx + 1, str, 1 - flag);
        }
    }
    } else {
        if (r->mp.find(c) != r-> mp.end()) {
            ans = ans | findString(r->mp[c], idx + 1, str, flag);
        }
    }
    return ans;
}

string Solution::solve(vector<string> &A, vector<string> &B) {
    string ans = "";
    TrieNode* root = new TrieNode();
    for( int i = 0; i < A.size(); i++){
        addString(root, A[i]);
    }
    for( int i = 0; i < B.size(); i++){
        if(findString(root,0, B[i], 0)){
            ans += "1";
        } else {
            ans += "0";
        }
    }
    return ans;
}