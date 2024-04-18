#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;





/* Merge Two Sorted Lists

T.C = O(N1+N2) N1,N2- length of linked list
S.C = O(1)

Eg-


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]


Analysis - We are inplace  sorting the 2 linked list 
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

struct Node* merge(struct Node*head1,struct Node*head2)
{
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	struct Node*r=NULL;
	struct Node*temp;

	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
		//	cout<<"data"<<head1->data<<" ";
          if(r==NULL)
          {
          	 r=head1;
          	temp=r;
          }
          else
          { 
          	r->next=head1;
          	r=head1;
          	
          }
         
          head1=head1->next;
		}
       else
       {// cout<<"data"<<head2->data<<" ";
       	if(r==NULL)
       	{
       		r=head2;
       		temp=r;
       	}
       	else
       	{   
       		r->next=head2;
       		r=head2;
       		
       	}
       	
       	head2=head2->next;
      }
}


while(head1!=NULL)
{
	r->next=head1;
	r=head1;
	head1=head1->next;
}

while(head2!=NULL)
{
	r->next=head2;
	r=head2;
	head2=head2->next;
}
return temp;

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
//display(head1);
//display(head2);
   struct Node* temp=merge(head1,head2);

   cout<<"Inplace Merges two  sorted linked list "<<"\n";
   display(temp);


}

 2nd method (IN JAVA):


public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
// T.C = O(N1+N2)  SC.C = O(1)


        ListNode dummyNode = new ListNode(-1);
        ListNode temp = dummyNode;

        while(list1!=null & list2!=null){
            if(list1.val<=list2.val){
                temp.next=list1;
                list1=list1.next;
            }
            else{
                temp.next=list2;
                list2=list2.next;
            }
            temp=temp.next;
        }

        if(list1!=null){
            temp.next=list1;
        }
        else{
            temp.next=list2;
        }

        return dummyNode.next;
    }
