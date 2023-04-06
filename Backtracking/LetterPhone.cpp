/*
Q6. Letter Phone
Problem Description
Given a digit string A, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
The digit 0 maps to 0 itself. The digit 1 maps to 1 itself.
NOTE: Make sure the returned strings are lexicographically sorted.

Problem Constraints
1 <= |A| <= 10

Input Format
The only argument is a digit string A.

Output Format
Return a string array denoting the possible letter combinations.

Example Input
Input 1:
 A = "23"
Input 2:
 A = "012"

Example Output
Output 1:
 ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
Output 2:
 ["01a", "01b", "01c"]

Example Explanation
Explanation 1:
 There are 9 possible letter combinations.
Explanation 2:
 Only 3 possible letter combinations.

*/
void combinationOfLetters(int index, string &typedString, string &currStr,vector<string> &possibleLetters, vector<string> &result){
    if(index == typedString.length()){
        result.push_back(currStr);
        return;
    }
    for(int i=0;i<possibleLetters[typedString[index]-'0'].length();i++){
        currStr[index] = possibleLetters[typedString[index]-'0'][i];
        combinationOfLetters(index+1, typedString, currStr, possibleLetters, result);
    }
    return;
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> possibleLetters(10);
    possibleLetters[0] = "0";
    possibleLetters[1] = "1";
    possibleLetters[2] = "abc";
    possibleLetters[3] = "def";
    possibleLetters[4] = "ghi";
    possibleLetters[5] = "jkl";
    possibleLetters[6] = "mno";
    possibleLetters[7] = "pqrs";
    possibleLetters[8] = "tuv";
    possibleLetters[9] = "wxyz";
    string currStr = A;
    vector<string> result;
    combinationOfLetters(0, A, currStr, possibleLetters, result);
    return result;
}