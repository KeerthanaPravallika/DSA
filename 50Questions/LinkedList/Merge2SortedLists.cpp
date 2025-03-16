/*

Link: https://leetcode.com/problems/merge-two-sorted-lists/description
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* dummy = new ListNode(0);
            ListNode* nl = dummy;
    
            while(list1 && list2)
            {
                if(list1->val > list2->val)
                {
                    nl->next = list2;
                    list2 = list2->next;
                }
                else
                {
                    nl->next = list1;
                    list1 = list1->next;
                }
                nl = nl->next;
            }
    
            nl->next = list1 ? list1 : list2;
    
            return dummy->next;
        }
    };


