#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


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
