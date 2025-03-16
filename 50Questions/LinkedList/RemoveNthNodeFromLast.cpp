/*

Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-interview-150

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 



*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode * start = new ListNode();
            start -> next = head;
            ListNode* fast = start;
            ListNode* slow = start; 
    
            // Point fast pointer n steps ahead
    
            // 1 2 3 4 5 n = 2
            // fast = 3
            for(int i=0;i<n;i++)
                fast = fast->next;
            
            // move both the pointers till end 
            // slow = 3
            while(fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
    
           //  1 2 3 5
            slow->next = slow->next->next;
    
            return start->next;
    
        }
    };