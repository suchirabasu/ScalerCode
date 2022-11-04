/*
Q5. Repeating and Missing number array
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :
Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Note that in your output A should precede B.

Example:
Input:[3 1 2 5 3] 
Output:[3, 4] 
A = 3, B = 4

*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> res(2,0);
    int n = A.size();
long sqr1=0,sqr2=0;
long s1=0,s2=0;
for(int i=0;i<n;i++){
s1+=A[i];          // no need to type cast to long as max range is 10^5…
sqr1+=(long)A[i]*A[i];          // need to type cast as 10^5*10^5=10^10 (long)…
s2+=(i+1);
sqr2+=(long)(i+1)*(i+1);
}
long r=(sqr1-sqr2)/(s1-s2);
long t=r+(s1-s2);               // this value is twice of repeating element.
t=t>>1;                 // ‘t’ is divided by 2, to get the actual number.
long p=t-(s1-s2);
res[0] = (int)t;
res[1] = (int)p;
//return new int[]{(int)t,(int)p};
    return res;
}