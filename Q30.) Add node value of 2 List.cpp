#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;




/*


You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.




T.C = O(max(n,m)) m,n - length of linked list
S.C = O(n)  

Eg 1 -

Input - 7 4
9 9 9 9 9 9 9 
9 9 9 9

Output - 8 9 9 9 0 0 0 1 

Analysis --  We have used one dummy node and adding the
              data value of both and adding it to new node.


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


struct Node*AddListNodes(struct Node* head1,struct Node*head2)
{
	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));

    lli cur=0;
    struct Node*r=temp;

   while(head1 || head2||  cur)
   {
     lli sum=0;
     if(head1!=NULL)
     {
     	sum+=head1->data;
     	head1=head1->next;
     }

     if(head2!=NULL)
     {
     	sum+=head2->data;
     	head2=head2->next;
     }
     sum+=cur;
     cur=sum/10;
     struct Node*q=(struct Node*)malloc(sizeof(struct Node));
     temp->next=q;
     temp=q;
     temp->data=(sum%10);

 
   }
   temp->next=NULL;

return r->next;
}







    /* sum=head1->data+head2->data+cur;
    temp->data=sum%10;
    cur =sum/10;

 head1=head1->next;
 head2=head2->next;

 struct Node*r=temp;

while(head1!=NULL && head2!=NULL)
{
	sum=head1->data+head2->data+cur;
	struct Node*q=(struct Node*)malloc(sizeof(struct Node));
    temp->next=q;
    temp=q;
    temp->data=sum%10;
    cur =sum/10;
    head1=head1->next;
head2=head2->next;
}

while(head1!=NULL)
{
	sum=head1->data+cur;
	struct Node*q=(struct Node*)malloc(sizeof(struct Node));
    temp->next=q;
    temp=q;
    temp->data=sum%10;
    cur =sum/10;
    head1=head1->next;
}


while(head2!=NULL)
{
	sum=head2->data+cur;
	struct Node*q=(struct Node*)malloc(sizeof(struct Node));
    temp->next=q;
    temp=q;
    temp->data=sum%10;
    cur =sum/10;
    head2=head2->next;
}



if(cur>0)
{
   struct Node*q=(struct Node*)malloc(sizeof(struct Node));
   temp->next=q;
   temp=q;
   temp->data=cur;

}

temp->next=NULL;

return r;
} */







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
	vector<lli>list2;


	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		list1.push_back(val);
	}

   for(i=0;i<m;i++)
	{
		lli val;
		cin>>val;
		list2.push_back(val);
	}

	struct Node* head1= push(list1);
	struct Node* head2= push(list2);


	struct Node* temp=AddListNodes(head1,head2);

cout<<"List after adding node value of 2 List "<<"\n";
	display(temp);

}













