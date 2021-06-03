#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Write a Function--

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

 T.C = O(n)
 S.C = o(1)

 ANALYSIS-- 
            First we use the concept of slow and fast pointer
            slow moves one step and fast moves 2 step
            if slow and fast will match a node then that point
            will be a collision node
            now run fast from head and slow from collison node
            by one- one sstep and wherever they meet ,that node
            will be start of the cycle.

*/


 ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                
            {
                fast=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        
        return NULL;
        
    }