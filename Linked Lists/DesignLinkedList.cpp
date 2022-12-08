/*
Q2. Design Linked List
Problem Description
Given a matrix A of size Nx3 representing operations. Your task is to design the linked list based on these operations.
There are four types of operations:

0 x -1: Add a node of value x before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
1 x -1: Append a node of value x to the last element of the linked list.
2 x index: Add a node of value x before the indexth node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
3 index -1: Delete the indexth node in the linked list, if the index is valid.
A[i][0] represents the type of operation.
A[i][1], A[i][2] represents the corresponding elements with respect to type of operation.
Note: Indexing is 0 based.

Problem Constraints
1 <= Number of operations <= 1000
1 <= All node values <= 109

Input Format
The only argument given is matrix A.

Output Format
Return the pointer to the starting of the linked list.

Example Input
Input 1:
    A = [   [0, 1, -1]
            [1, 2, -1]
            [2, 3, 1]   ]
Input 2:
    A = [   [0, 1, -1]
            [1, 2, -1]
            [2, 3, 1]
            [0, 4, -1]
            [3, 1, -1]
            [3, 2, -1]  ]

Example Output
Output 1:
    1->3->2->NULL
 
Output 2:
    4->3->NULL

*/
ListNode* head;
static int sizell;//Size of linked list

void addAtFirst(int value) {
    if (head == NULL){
        head = new ListNode(value);
    } else {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
    sizell++;
}

void addAtLast(int value){
    ListNode* newnode = new ListNode(value);
    ListNode* temp = head;
    if (head == NULL) {
        head = newnode;
    } 
    else {
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    sizell++;
}

void addAtIndex(int value, int index){
    if(sizell < index-1)
        return;
    int count = 0;
    ListNode* temp = head;
    while (count < index - 1) {
        temp = temp->next;
        count++;
    }
    ListNode* newNode = new ListNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    sizell++;
}

void addNode(int value, int index){
    if(index > sizell || index <0)
        return;
    if (index == 0) {
        addAtFirst(value);
    }
    else if(index == sizell)
    {
        addAtLast(value);
    }
    else {
        addAtIndex(value, index);
    }
} 

void deleteByValue(int position){
    if (head == NULL || position < 0) 
        return;
    ListNode* ptr = head;
    if(position < sizell)
    {
        if (position == 0){
            head = head->next;
        }
        else {
            int counter=0;// Since indexing is from 0 from the NOTE starting counter from 0.
            ListNode* curr=head;
            while(counter<position-1){
                counter++;
                curr=curr->next;   
            }
            ListNode
 * temp = curr->next;
            curr->next=temp->next;
            delete temp;
        }
    }
    sizell--;
}

ListNode* Solution::solve(vector<vector<int> > &A) {
    head = NULL;
    for(auto i=0; i<A.size(); i++)
    {  
        if (A[i][0] == 0){
            addAtFirst(A[i][1]);
        } else if (A[i][0] == 1) {
            addAtLast(A[i][1]);
        } else if (A[i][0] == 2) {
            addNode(A[i][1], A[i][2]);                
        } else if (A[i][0] == 3){
            deleteByValue(A[i][1]);
        }
    }
    return head;
}