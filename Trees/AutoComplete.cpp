/*
Q19. Auto Complete
Problem Description
There is a dictionary A of N words, and ith word has a unique weight Wi.
Another string array B of size M contains the prefixes. For every prefix B[i], output atmost 5 words from the dictionary A that start with the same prefix.
Output the words in decreasing order of their weight.
NOTE: If there is no word that starts with the given prefix output -1.

Problem Constraints
1 <= T <= 5
1 <= N <= 20000
1 <= M <= 10000
1 <= Wi <= 106
1 <= length of any string either in A or B <= 30

Input Format
First line is an integer T denoting the number of test cases.
For each test case,
First line denotes two space seperated integer N and M.
Second line denotes N space seperated strings denoting the words in dictionary.
Third line denotes N space seperated integers denoting the weight of each word in the dictionary.
Fourth line denotes M space seperated integers denoting the prefixes.

Output Format
For every prefix B[i], print the space seperated output on a new line.
NOTE: After every output there should be a space.

Example Input
Input 1:
 1
 6 3
 abcd aecd abaa abef acdcc acbcc
 2 1 3 4 6 5
 ab abc a
Input 2:
 1
 5 3
 aaaa aacd abaa abaa aadcc
 3 4 1 2 6 
 aa aba abc

Example Output
Output 1:
 abef abaa abcd 
 abcd 
 acdcc acbcc abef abaa abcd 
Output 2:
 aadcc aacd aaaa 
 abaa abaa 
 -1 

Example Explanation
Explanation 1:
 For the prefix "ab" 3 words in the dictionary have same prefix: ("abcd" : 2, "abaa" : 3, "abef" : 4). Ouput them in decreasing order of weight.
 For the prefix "abc" only 1 word in the dictionary have same prefix: ("abcd" : 2).
 For the prefix "a" all 6 words in the dictionary have same prefix: ("abcd" : 2, "aecd" : 1, "abaa" : 3, "abef" : 4, "acdcc" : 6, "acbcc" : 5).
 Since we can output atmost 5 words. Output top 5 weighted words in decreasing order of weight.
Explanation 2:
 For the prefix "aa" 3 words in the dictionary have same prefix: ("aaaa" : 3, "aacd" : 4, "aadcc" : 6). Ouput them in decreasing order of weight.
 For the prefix "aba" 2 words in the dictionary have same prefix: ("abaa" : 1, "abaa" : 2).
 For the prefix "abc" there is no word in the dictionary which have same prefix. So print -1.

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<utility>

using namespace std;

class Node
{
    public:
    bool isEnd;
    unordered_map<char, Node*> child;
    vector<pair<int, int>> iNw; //list of indiesAndWeight pair
    int count;
    Node()
    {
        isEnd = false;
        child = unordered_map<char, Node*>();
        count = 0;
    }
};

void insert(Node* root, string word, int index, int weight)
{
    Node* temp = root;
    for(int i = 0; i < word.length(); i++)
    {
        if(temp->child.find(word[i]) == temp->child.end())
        {
            Node* t = new Node();
            temp->child[word[i]] = t;
        }
        //if(temp->child[word[i]]->iNw.size() < 5)//we do not want to store more than 5 at any node
        temp->child[word[i]]->iNw.push_back(make_pair(index, weight)); //Missed, I was restricting more than 5 while adding, instead we should keep adding all words to the node,
                                                                    //because we do not know the order of weights while adding. During retrieval at the end of sort, we can restrict to 5
        temp = temp->child[word[i]];
    }
    temp->isEnd = true;
}

bool comparator(pair<int,int> a, pair<int, int> b)
{
    if(a.second > b.second)
        return true;
    else //a's weight is less than b then swap a and b => greater weights should be ahead;
        return false;
}

void retrieve(Node* root, string prefix, vector<int>& retVec)
{
    Node* temp = root;
    for(int i = 0; i < prefix.length(); i++)
    {
        if(temp->child.find(prefix[i]) != temp->child.end()) //character found
        {
            temp = temp->child[prefix[i]];
        }
        else //Missed, when we do not have a match of prefix for any word, then we find that requested haracter is missing. In this case we should return a empty vector of indices
            return;
    }
    sort(temp->iNw.begin(), temp->iNw.end(), comparator);
   
    for(int j = 0; j < temp->iNw.size() && j < 5; j++) //we should at max get 5 elements having huge weight, we should restrict the count after sorting by weight
        retVec.push_back(temp->iNw[j].first);
}

int main()  
{
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int K; //Number of test cases;
    cin>>K;
    int n, m;
    vector<string> A;
    vector<int> W;
    vector<string> B;
    for(int j = 0; j < K; j++) //Looping through the cases
    {
        //resetting the vectors
        A = vector<string>();
        W = vector<int>();
        B = vector<string>();
        cin>>n>>m;
        string t;
        for(int i = 0; i < n; i++) //fetching dictionary
        {
            cin>>t;
            A.push_back(t);
        }
        int w;
        for(int i = 0; i < n; i++) //fetching weights
        {
            cin>>w;
            W.push_back(w);
        }

        for(int i = 0; i < m; i++) //fetching prefixes
        {
            cin>>t;
            B.push_back(t);
        }

        //Insert into Trie
        Node* root = new Node();
        for(int i = 0; i < n; i++)
        {
            insert(root, A[i], i, W[i]);
        }
        //retrieval and print the corresponding words
        for(int i = 0; i < m; i++)
        {
            vector<int> indices;
            retrieve(root, B[i], indices);
            if(indices.size() == 0) //Missed, when we do not have a match of any word for a prefix, we return an empty vector of indices. In this case we should print -1<space>.
                cout<<"-1 ";
            else
            {
                for(int k = 0; k < indices.size(); k++)
                {
                    cout<<A[indices[k]]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}