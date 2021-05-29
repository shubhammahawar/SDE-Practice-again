#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

T.C = O(N)
S.C = O(1)

Eg 1-

Input: head = [1,2,3,4,5], n = 2  means 2nd element from back
Output: [1,2,3,5]

Eg 2-

Input: head = [1,2,3,4,5], n = 5
Output: [2,3,4,5]

Analysis - if n=4 it means 4th element from back 
           so first* traverse a pointer to 4 position from start

           now by the time now first pointer reaches end
           the new second* pointer will start from first position and 
           will reach the position from where
           we set second->next=second->next->next


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


struct Node*DeleteNthNode(struct Node*head,lli n)
{

 
 struct Node* dum=(struct Node*)malloc(sizeof(struct Node));
 dum->next=head;

 struct Node*fast= dum;
 struct Node*slow=dum;


 for(lli i=0;i<n;i++)
 	fast=fast->next;

 while(fast->next!=NULL)
 {
 	slow=slow->next;
 	fast=fast->next;
 }
 slow->next=slow->next->next;

 return dum->next;

}


void display(struct Node*temp)
{
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}

}




int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,m,i;
	cin>>n>>m;

	vector<lli>list1;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		list1.push_back(val);
	}

   struct Node* head1= push(list1);
   struct Node* temp= DeleteNthNode(head1,m);

   display(temp);

}