#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Check if Linked List is a palindrome or Not

T.C = O(n)
S.C = O(1)

Eg -

Input -
8
1 4 3 4 4 3 2 1

Output - Not a palindrome


Analysis -
            First we will find out the middle of the linked
            list using Tortoise approach
            then we reverse the second half of the linked lits
            After that we run the head of second half of linked
            list till it reaches the NULL and compare with the
            value of 1st half linked list.
            If any value does not match then it is Not a Plaindrome
            otherwise it is a palindrome 



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


void display(struct Node*temp)
{
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }

}

//- Finding Middle of Linked list

struct Node*Middleelement(struct Node*head)
{
  struct Node*slow=head;
  struct Node*fast=head;

  while(fast->next && fast->next->next)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}


// Reversing the second half and checking the palindrome

lli CheckPalindrome(struct Node*slow,struct Node*head)
{

  struct Node*cur=slow->next;
  struct Node*r=NULL;
  struct Node*sec;

  while(cur!=NULL)
  {
    sec=cur->next;
    cur->next=r;
    r=cur;
    cur=sec;
  }
slow->next=r;

//display(head);
//cout<<"slow-data"<<slow->data<<" ";

slow=slow->next;
//cout<<"p-data"<<p->data<<" ";

while(slow!=NULL)
{
  if(head->data!=slow->data)
    return 0;
  

   slow=slow->next;
   head=head->next;
}

return 1;

}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  lli n,i;
  cin>>n;

  vector<lli>list1;

  for(i=0;i<n;i++)
  {
    lli val;
    cin>>val;
    list1.push_back(val);
  }

   struct Node* head1= push(list1);

   struct Node*temp=Middleelement(head1);

   lli val=CheckPalindrome(temp,head1);

   if(val==1)
   cout<<"Linked list is palindrome "<<"\n";
 else
  cout<<"Linked list is not palindrome "<<"\n";

}
