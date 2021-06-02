#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*  

 Reverse Nodes in k-Group

 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


T.C = O(N/k)*k =O(N)  since running N/K group and each group K-1 times
S.C = O(1)


EG-

Input - 8 3
        1 2 3 4 5 6 7 8

Output  3 2 1 6 5 4 7 8


Input - 9 3
        1 2 3 4 5 6 7 8 9

Output  3 2 1 6 5 4 9 8 7


Analysis -- First we will find out the length of linked list
            Also if we go in groups we have to reverse the link
            and for each group we run loop (k-1) times.




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


struct Node*ReverseGroup(struct Node*temp,lli k)
{
	if(temp==NULL || k==1)
		return temp;


   struct Node*p=temp;
   int len=0;
   while(p!=NULL)
   {
     p=p->next;
     len++;
   }

   struct Node*dum=(struct Node*)malloc(sizeof(struct Node));


dum->next=temp;
struct Node*cur=dum,*pre=dum,*nex=dum;

while(len>=k)
{
	cur=pre->next;
	nex=cur->next;
	for(lli i=1;i<k;i++)
	{
		cur->next=nex->next;
		nex->next=pre->next;
		pre->next=nex;
		nex=cur->next;
	}
	len-=k;
	pre=cur;
}


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



   struct Node* temp=ReverseGroup(head1,k);

cout<<"Linked List after reversing them in lenth of k Group"<<"\n";

   display(temp);
}


