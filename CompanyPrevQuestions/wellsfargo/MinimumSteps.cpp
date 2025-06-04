/*
Link: https://www.naukri.com/code360/problems/minimum-steps_2221412?topList=wells-fargo-interview-questions&problemListRedirection=true&sort_entity=recents&sort_order=DESC&leftPanelTabValue=PROBLEM
Problem statement
You are given an array ‘ARR’ consisting of ‘N’ integers. Your task is to make all the numbers equal. You decrease one of the largest numbers present in the array into a number that is just lower than the maximum number in one step.

For example:
You are given ‘ARR’ = [5, 2, 3]
In the first step, you can change 5 to 3, so the new array is [3, 2,3].

In the second step, you can change the 3 to 2, then the array is [2, 2,3].

In the third step, you can change the 3 to 2, then the array is [2, 2, 2] 

Hence the answer is 3.


*/

/*

Here's how the code works:

 

    It uses a map m to store the frequencies of each number in the input vector.

    Then, it iterates through the map, calculating the sum of products of frequencies and indices. This sum represents the minimum number of steps required to make all numbers equal according to the given rule.

 

Here's an example to help illustrate how the code works:

 

Suppose the input vector is: [4, 7, 7, 2, 2, 7].

 

    The map m will store: {2: 2, 4: 1, 7: 3}.

    The number of steps required will be: (2 * 0) + (1 * 1) + (3 * 2) = 0 + 1 + 6 = 7.

 

So, the minimum number of steps required to make all numbers equal is 7.

*/

 

#include <map>

 

int minimumSteps(int n, vector<int> &arr)

{

    // Write your code here

 

    map<int,int> m;

 

    for(int i=0;i<n;i++)

    {

        if(m.find(arr[i]) == m.end())

            m[arr[i]] = 1;

        else

            m[arr[i]]++;

    }

 

    int sum = 0;

    int i=0;

    for(auto it: m)

    {

        sum += it.second*i;

        i++;

    }

 

    return sum;

}

    