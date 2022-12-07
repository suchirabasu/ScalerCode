/*
Q1. Linked-List
Problem Description
Design and implement a Linked List data structure.
A node in a linked list should have the following attributes - an integer value and a pointer to the next node. It should support the following operations:

insert_node(position, value) - To insert the input value at the given position in the linked list.
delete_node(position) - Delete the value at the given position from the linked list.
print_ll() - Print the entire linked list, such that each element is followed by a single space.

Note:
If an input position does not satisfy the constraint, no action is required.
Each print query has to be executed in a new line.

Problem Constraints
1 <= value <= 105
1 <= position <= n where, n is the size of the linked-list.

Input Format
First line contains an integer denoting number of cases, let's say t.
Next t line denotes the cases.

Output Format
When there is a case of print_ll(),  Print the entire linked list, such that each element is followed by a single space.
NOTE: You don't need to return anything.


Example Input
5
i 1 23
i 2 24
p
d 1
p


Example Output
23 24
24


Example Explanation
After first two cases linked list contains two elements 23 and 24.
At third case print: 23 24.
At fourth case delete value at first position, only one element left 24.
At fifth case print: 24.

*/
#include<iostream>
using namespace std;
//static int length = 0;
class Node
{
    public:
          int value ;
          Node * next;
               
            Node (int val)
            {
                value = val;
                next = NULL;
            }
};
Node * head = NULL;
static int length = 0;
void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    if(length+1 <position){
        return;
    }
    Node* temp = new Node(value);
    if(position == 1){
        temp->next = head;
        head = temp;
    }
    else{
        int count = 1;
        Node* curr = head;
        while(position - 1 > count){
            curr = curr->next;
            count++;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    length++;
}

void delete_node(int position) {
    // @params position, integer
    if(position > length){
        return;
    }
    if(position == 1){
        head = head->next;
    }
    else{
        int count=1;
        Node* prev = head;
        Node* curr = head->next;
        while(position -1 > count){
            prev = prev->next;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;

    }
    length--;
}


void print_ll() {
    // Output each element followed by a space
    if(length==0)
        return;
    Node* temp = head;
    while(temp->next != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<temp->value;
}
