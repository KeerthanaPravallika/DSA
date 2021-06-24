/*
Given an array A of positive integers. Your task is to find the leaders in the array. 
An element of array is leader if it is greater than or equal to all the elements to its right side. T
he rightmost element is always a leader. 

Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.

*/
class Solution{
    //Function to find the leaders in the array.
    static ArrayList<Integer> leaders(int arr[], int n){
        // Your code here
        
        ArrayList<Integer> al = new ArrayList<Integer>();
        
        /*
        int i,j,flag=0;
        for(i=0;i<n;i++)
        {
            flag = 0;
            for(j=i+1;j<n;j++)
            {
                if(arr[i] < arr[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                al.add(arr[i]);
        }
        return al;
        */
        
        int i;
        
        int max_from_right = arr[n-1];
        al.add(max_from_right);
        for(i=n-2;i >= 0;i--)
        {
            if(max_from_right <= arr[i])
            {
                max_from_right = arr[i];
                al.add(max_from_right);
            }
        }
        Collections.reverse(al);
        return al;
        
        
    }
}


 
