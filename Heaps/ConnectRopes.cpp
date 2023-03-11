/*
Q3. Connect Ropes
Problem Description
You are given an array A of integers that represent the lengths of ropes.
You need to connect these ropes into one rope. The cost of joining two ropes equals the sum of their lengths.
Find and return the minimum cost to connect these ropes into one rope.

Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 1000

Input Format
The only argument given is the integer array A.

Output Format
Return an integer denoting the minimum cost to connect these ropes into one rope.

Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
Input 2:
 A = [5, 17, 100, 11]

Example Output
Output 1:
 33
Output 2:
 182

Example Explanation
Explanation 1:
 Given array A = [1, 2, 3, 4, 5].
 Connect the ropes in the following manner:
 1 + 2 = 3
 3 + 3 = 6
 4 + 5 = 9
 6 + 9 = 15
 So, total cost  to connect the ropes into one is 3 + 6 + 9 + 15 = 33.
Explanation 2:
 Given array A = [5, 17, 100, 11].
 Connect the ropes in the following manner:
 5 + 11 = 16
 16 + 17 = 33
 33 + 100 = 133
 So, total cost  to connect the ropes into one is 16 + 33 + 133 = 182.

*/
class Heap {

    int *heap;
    int heapSize;
    int heapCapacity;

    public:
        Heap() {
            heapSize = 0;
            heapCapacity = 0;
        }

        Heap(int N) {
            heapSize = 0;
            heapCapacity = N;
            heap = new int[N];
        }

        void insert(int X);
        void deleteMin();
        void swap(int i, int j);
        int getMin();
        int getSize();
        bool isEmpty();
};

void Heap::insert(int X) {
    if(heapSize == heapCapacity)
        return;
   
    heap[heapSize++] = X;
   
    int index = heapSize - 1;
    int parentIndex = (index - 1) >> 1;

    while(index > 0 && heap[index] < heap[parentIndex]) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex = (index - 1) >> 1;
    }
}

void Heap::deleteMin() {
    heap[0] = heap[heapSize - 1];
    heap[heapSize - 1] = -1;
    heapSize--;

    int index = 0;
    while(2*index + 1 < heapSize) {
        int leftChild = (2 * index) + 1;
        int rightChild = (2 * index) + 2;

        int minVal = min(heap[index], heap[leftChild]);
        minVal = (rightChild < heapSize) ? min(minVal, heap[rightChild]) : minVal;

        if(minVal == heap[leftChild]) {
            swap(index, leftChild);
            index = leftChild;
        }
        else if(rightChild < heapSize && minVal == heap[rightChild]) {
            swap(index, rightChild);
            index = rightChild;
        }
        else {
            break;
        }
    }
}

void Heap::swap(int i, int j) {
    heap[i] = heap[i] + heap[j];
    heap[j] = heap[i] - heap[j];
    heap[i] = heap[i] - heap[j];
}

int Heap::getMin() {
    return heap[0];
}

int Heap::getSize() {
    return heapSize;
}

bool Heap::isEmpty() {
    return (heapSize == 0);
}


int Solution::solve(vector<int> &A) {
    int minimumRopeLength = 0;
    int ropeCount = A.size();

    Heap ropes(A.size());

    for(int i=0; i<ropeCount; i++)
        ropes.insert(A[i]);

    while(ropeCount-- > 1) {
        int firstRopeLength = ropes.getMin();
        ropes.deleteMin();
        int secondRopeLength = ropes.getMin();
        ropes.deleteMin();

        minimumRopeLength += firstRopeLength + secondRopeLength;

        ropes.insert(firstRopeLength + secondRopeLength);
    }

    return minimumRopeLength;
}