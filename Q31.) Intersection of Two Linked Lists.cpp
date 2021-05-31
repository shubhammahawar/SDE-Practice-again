 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Function to get Intersection of Two Linked Lists 

T.C = O(2M) // worst case there is no Intersection so will travel complete 2 list
S.C = O(1)

Eg-
Input

listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]

Output- Intersection Node is 8 (not the value)

Analysis -> we will travel the head of both the list
            if any one reaches end of list
            we will assign it to head of another list
            and by the time difference of no of nodes in 
             both list will be travelled
            and again they will move 1-1 step and Intersection node
            will be found.


*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *r1=headA;
        ListNode *r2=headB;

        while(headA!=headB)
        {    
            if(headA==NULL)
                headA=r2;
               
            else
                headA=headA->next;
            
            
            if(headB==NULL)
                headB=r1;
             
            else
                headB=headB->next;
            
        }
            
        return headA;
        
    }         





