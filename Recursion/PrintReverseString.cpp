/*
Q4. Print Reverse String
Problem Description
Write a recursive function that, given a string S, prints the characters of S in reverse order.

Problem Constraints
1 <= |s| <= 1000

Input Format
First line of input contains a string S.

Output Format
Print the character of the string S in reverse order.

Example Input
Input 1:
 scaleracademy
Input 2:
 cool

Example Output
Output 1:
 ymedacarelacs
Output 2:
 looc

Example Explanation
Explanation 1:
 Print the reverse of the string in a single line.

*/
#include <istream>
#include <string>

using namespace std;

string printRev(string str, int idx) {
    if(idx == str.size()-1) {
        string blank = "";
        return blank + str.at(idx);
    }
    ++idx;

    return printRev(str, idx) + str[idx-1];
}

int main()  {
    string str;
    cin>>str;

    string revStr = printRev(str, 0);

    cout<<revStr;
    return 0;
}