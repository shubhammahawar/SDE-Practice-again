#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Write a Function 

Given head, the head of a linked list, determine if the linked list has a cycle in it.

T.C = O(n)
S.C = O(1)

Analysis -- Using tortoise Method
            slow will move one -one step and fast willmove
            2-2 step and whenever slow reaches the fast,
            it means there is a cycle in Linked LIST
            otheriwse not.

            */

bool hasCycle(struct Node *head) {
  if(head==NULL || head->next==NULL)
  	return false;
   
   struct Node*slow=head;
   struct Node*fast=head;

   while(fast && fast->next)
   {
   	 slow=slow->next;
   	 fast=fast->next->next;

   	 if(slow==fast)
   	 	return true;

   }

   return false


	}
