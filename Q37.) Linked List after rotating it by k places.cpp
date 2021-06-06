#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Linked lIst after rotating it by k places

T.C = O(N)
S.C = O(1)

Input: 
          head = [1,2,3,4,5], k = 2
Output: 
          [4,5,1,2,3]

Analysis - First we will caluclate the length of linked list
           then we will pointthe last node next to first node
           just like circular linked list
           After that we traverse len-k node and head will point to next of this node
           and this node->next=NULL and will return the head;

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


struct Node*Rotatebykplaces(struct Node*head,lli k)
{
	if(head==NULL || head->next==NULL || k==0)
		return head;


  lli len=1;
  struct Node*temp=head;

  while(temp->next!=NULL)
  {
  	temp=temp->next;
  	len++;
  }

temp->next=head;
k=k%len;
k=len-k;

while(k>0)
{
	temp=temp->next;
	k--;
}
head=temp->next;
temp->next=NULL;


return head;
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

	lli n,k,i;
	cin>>n>>k;

	vector<lli>list1;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		list1.push_back(val);
	}

   struct Node* head1= push(list1);

struct Node*rev=Rotatebykplaces(head1,k);

cout<<"Linked List afe=ter rotating it by "<< k <<" places\n ";

display(rev);

}