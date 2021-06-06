#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*   
 
 Copy List with Random Pointer

 A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.


 T.C = O(N) + O(N) +O(N) ~= O(N)

1st step- O(N) for making deep copy of every node
2nd step- O(N) for connecting random pointer of deep copy node
3rd step- O(N) for restoring original list and copy  list 



Analysis -

1st step we will create a copy node of every node in b/w the node
2nd step we will join the randm pointer of copy node
3rd step we will restore the original list and copy list

*/



Node*copyRandomList(Node*head)
{
	Node*item=head;
	Node*front;


// STEP 1----

	while(item!=NULL)
	{
		front=item->next;

		Node*copy=new Node(item->val);

		item->next=copy;
		copy->next=front;
		item=front;
	}

  item=head;

// STEP 2---

  while(item!=NULL)
  {
    if(item->random)
    {
    	item->next->random=item->random->next;
    }

  item=item->next->next;
}


//STEP 3---

Node*dummy=new Node(0);
Node*ans=dummy;
item=head;

while(item!=NULL)
{
	front=item->next->next;
	dummy->next=item->next;
	dummy=dummy->next;
	item->next =front;
	item=front;

}
return ans->next;



}