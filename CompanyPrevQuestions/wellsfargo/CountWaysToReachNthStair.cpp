

/*

Link: https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?topList=wells-fargo-interview-questions&problemListRedirection=true&sort_entity=recents&sort_order=DESC&leftPanelTabValue=PROBLEM&count=25&page=2&search=&customSource=studio_nav
Problem statement
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.



Each time, you can climb either one step or two steps.



You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

Example :
N=3

We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.

*/

import java.util.*;

import java.io.*;

 

public class Solution {

    public static long countDistinctWayToClimbStair(int nStairs) {

        int[] dp = new int[nStairs + 1];

        dp[0] = 1;

        for (int i = 1; i <= nStairs; i++) {

            if (i == 1) {

                dp[i] = 1;

            } else {

                dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;

            }

        }

        return dp[nStairs];

    }

}