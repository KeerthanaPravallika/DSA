/*

Link : https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

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

        ListNode* res = new ListNode();
        ListNode* temp = res;

        while (list1 != NULL && list2 != NULL) {
            while (list1 != NULL && list2 != NULL && list1->val <= list2->val) {
                ListNode* node = new ListNode(list1->val);
                temp->next = node;
                temp = temp->next;
                list1 = list1->next;
            }

            while ( list1 != NULL && list2 != NULL && list2->val <= list1->val) {
                ListNode* node = new ListNode(list2->val);
                temp->next = node;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        while (list1 != NULL) {
            ListNode* node = new ListNode(list1->val);
            temp->next = node;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            ListNode* node = new ListNode(list2->val);
            temp->next = node;
            temp = temp->next;
            list2 = list2->next;
        }

        return res->next;
    }
};