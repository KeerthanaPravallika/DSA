/*
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 
*/
class Solution {
    int countTriplet(int arr[], int n) {
        // code here
        
        Arrays.sort(arr);
        int i,j,k,count=0 , sumt = 0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
               //System.out.println(arr[i]+" "+arr[j]);
                sumt = arr[i] + arr[j];
                for(k=j+1;k<n;k++)
                {
                    if(sumt == arr[k])
                    {
                       // System.out.println(arr[i]+" "+arr[j]+" "+arr[k]);
                        count++;
                        break;
                    }
                    else if(sumt < arr[j+1])
                        break;
                }
            }
        }
        return count;
    }
}
