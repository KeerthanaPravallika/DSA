/*
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input:
n = 1
A[] = {1}
Output: 1
Explanation: Since its the only 
element hence its the only equilibrium 
point. 
Example 2:

Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2).
*/
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n == 1)
            return 1;
        long long leftSum = a[0];
        long long rightSum =0;
        int i;
        for(i=2;i<n;i++)
            rightSum += a[i];
        for(i=0;i<n;i++)
        {
           // cout<<leftSum<<" "<<rightSum<<endl;
            if(leftSum == rightSum)
                return i+2;
            leftSum += a[i+1];
            rightSum -= a[i+2];
            
        }
        
        return -1;
        
    }

};
