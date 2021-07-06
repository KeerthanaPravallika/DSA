/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
*/
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* last; 
        Node* init; 
        Node* prev;
        
        last = init = prev = head ;
        int count = 0;
        while(last->next != NULL)
        {
            if(count == k-1)
            {
                prev = last;
                head = prev->next;
               
            }
            count++;
            last = last->next;
        }
       
        if(count == k-1)
            return init;
         prev->next = NULL;
        last->next = init;
       
        return head;
    }
};
