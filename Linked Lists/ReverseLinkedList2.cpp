/*

Link : https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode(0,head); // if left = 1 , it will be easy for traversal

        // reach node at position left
        ListNode* leftPrev = dummy, *curr = head;
        int i=0;
        while(i < left-1)
        {
            leftPrev = curr;
            curr = curr->next;
            i++;
        }

        // Now curr="left", leftPrev="node before left"
        // reverse from left to right

        ListNode *prev = NULL, *tmpNext;
        for(i = 0;i<right-left+1;i++)
        {
            tmpNext = curr->next;
            curr->next = prev;

            prev = curr;
            curr = tmpNext;
        }

        //Update pointers
        leftPrev->next->next = curr; // curr is node after "right"
        leftPrev->next = prev; // prev is right

        return dummy->next;
        


    }
};