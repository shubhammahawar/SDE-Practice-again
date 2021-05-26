#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

T.C = O(N)
S.C = O(1)

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])

Example 2:

Input: [100,200,300,400,500,600]
Output: Node 400 from this list (Serialization: [400,500,600])


ANALYSIS -: We are using the Tortoise method,
             the slow pointer moves one distance and fast ptr moves
             2 distance and when fast pointer reaches last node or out of boundary
             that point of time slow ptr will be at the middle of the linked list


             



*/



struct Node{
	lli data;
    struct Node*next;
};

struct Node*push(vector<lli>&arr)
{
	lli n=arr.size(),i;
	Node*p,*q,*temp;

	p=(struct Node*)malloc(sizeof(struct Node));

	p->data=arr[0];
	temp=p;

   for(i=1;i<n;i++)
   {
      Node*q=(struct Node*)malloc(sizeof(struct Node));
      p->next=q;
      p=q;
      p->data=arr[i];
   }
   p->next=NULL;



return temp;

}


struct Node*Middle_element(struct Node*head)
{
	struct Node*slow=head,*fast=head;

	while(fast !=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

	}
	return slow;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i;
	cin>>n;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	struct Node* head= push(arr);

   struct Node*temp=Middle_element(head);

   cout<<"Middle element of the linked list is "<<"\n";
   cout<<temp->data<<"\n";


}