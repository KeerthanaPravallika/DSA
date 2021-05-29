/* Given an array arr of N integers. Find the contiguous sub-array with maximum sum. */

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int i,meh=0,msf=0;
        for(i=0;i<n;i++)
        {
            meh = meh + arr[i];
            if(arr[i] > meh)
                meh = arr[i];
            if(msf < meh)
                msf = meh;
        }
        return msf;
        
    }
};
