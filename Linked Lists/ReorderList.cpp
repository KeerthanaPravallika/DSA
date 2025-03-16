/*

Link: https://leetcode.com/problems/reorder-list/description/

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Input: head = [1,2,3,4]
Output: [1,4,2,3]


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

 /*

[1,2,3,4]
1. Find middle element 
2. reverse the second half 
[1,2] [4,3]
3. Merge two lists alternatively
[1,4,2,3]

 */
 class Solution {
    public:
    
    ListNode* reverseLL(ListNode* head) {
            ListNode* prev = nullptr;
            while (head) {
                ListNode* next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            return prev;
        }
        
        void reorderList(ListNode* head) {
            if(!head || !head->next) return;
    
            // Finding middle element
            ListNode* slow = head, *fast = head;
    
            while(fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // slow will be pointing to first element of second half
    
            // reverse the second half
            ListNode *second = reverseLL(slow->next);
            slow->next = NULL; // Splitting the list into two halves
    
    
            // Merge two lists alternatively
    
            ListNode *first = head;
    
            while(second)
            {
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
    
                first->next = second;
                second->next = temp1;
    
                first = temp1;
                second = temp2;
    
            }
        }
    };