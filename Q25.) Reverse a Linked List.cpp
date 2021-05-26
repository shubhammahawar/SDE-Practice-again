#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Given the head of a singly linked list, reverse the list, and return the reversed list.

T.C =  O(N)
S.C =  O(1)

Example :
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


*/



struct Node
{
	int data;
	struct Node*next;
};

struct Node*push(vector<lli>&arr)
{
	struct Node*p,*q,*temp;
     lli n=arr.size();
	p=(struct Node*)malloc(sizeof(struct Node));
	temp=p;
	p->data=arr[0];

	for(lli i=1;i<n;i++)
	{
		q=(struct Node*)malloc(sizeof(struct Node));
		p->next=q;
		p=q;
		p->data=arr[i];
	}
	p->next=NULL;
	return temp;

}

struct Node*Reverse(struct Node*head)
{
	struct Node*r=NULL;
	struct Node*cur=head;

	while(head!=NULL)
	{
		cur=head->next;
		head->next=r;
		r=head;
		head=cur;
	}
	return r;
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

	struct Node*temp=Reverse(head);

	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}

}



