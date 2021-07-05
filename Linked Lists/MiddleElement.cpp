/*
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. 
For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, 
e need to print the second middle element. For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

*/
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   int i=0,len=0,index=0;
   Node *tmp = head;
   while(tmp != NULL)
   {
       len++;
       tmp = tmp->next;
   }
   if(len == 0)
    return -1;
   
    index = (len/2);
        
    Node *tmp1 = head;
   while(i < index)
   {
       tmp1 = tmp1->next;
       i++;
   }
   return tmp1->data;
   
}
