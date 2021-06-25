

 
   Arrays.sort(arr);
   int i,j,k,count=0 ;
        
        for(i = n-1;i >=0 ;i--)
        {
            j = 0;
            k = i - 1;
            while(j < k)
            {
                if(arr[i] == arr[j]+arr[k])
                {
                    count++;
                    j +=1;
                    k -= 1;
                }
                else if (arr[i]>arr[j]+arr[k])
                    j += 1;
                else
                    k -= 1;
            }
        }
        return count; 
