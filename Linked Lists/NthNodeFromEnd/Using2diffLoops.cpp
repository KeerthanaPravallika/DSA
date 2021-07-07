/*
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8.  
Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of nodes in the
linked list, the output is -1.
*/
int getNthFromLast(Node *head, int n)
{
       // Your code here
    int count=1;
    struct Node *temp = head;
    while(temp != NULL)
    {
        temp=temp->next;
        count++;
    }
    //cout<<count<<endl;
    if(n > (count-1))
        return -1;
    temp = head;
    int i=0,index = count - n-1;
    //cout<<index<<endl;
    while(i < index)
    {
        temp = temp->next;
        i++;
    }
    return temp->data;
}
