/*

Link: https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };


 Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

 */
 class Solution {
    public:
        bool hasCycle(ListNode *head) {
    
            if(head == NULL) return false;
    
           ListNode *fast = head, *slow = head;
    
           while(fast->next != NULL && fast->next->next != NULL)
           {
            fast = fast->next->next;
            slow = slow->next;
    
            if(fast == slow) return true;
           } 
    
           return false;
            
        }
    };


    // 2nd approach

    class Solution {
        public:
            bool hasCycle(ListNode* head) {
                if (head == NULL) {
                    return false;
                }
                map<ListNode*, bool> visited;
                ListNode* temp = head;
        
                while (temp != NULL) {
                    if (visited[temp] == true) {
                        return true;
                    }
                    visited[temp] = true;
                    temp = temp->next;
                }
                return false;
            }
        };