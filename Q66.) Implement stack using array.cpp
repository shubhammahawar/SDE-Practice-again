#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


void push(lli ele,lli arr[],lli &top,lli n)
{
	if(top==n-1)
		cout<<"Stack overflow\n";
	else
  arr[++top]=ele;
}

void pop(lli arr[],lli &top)
{
  if(top==-1)
  	cout<<"Stack Underflow\n";

  else
  	cout<<"the popped element is "<<arr[top--]<<"\n";
}

void Topelement(lli arr[],lli &top)
{
	 if(top==-1)
  	cout<<"Stack Underflow\n";

  else
  	cout<<"Top element from stack is "<<arr[top]<<"\n";
}

void Sizestack(lli &top)
{
	cout<<"Size of a stack is "<<top+1<<"\n";
} 


int main()
{
/*	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif */

   lli n,ele,top=-1,ch;

   cout<<"Enter the size of an array\n";
	cin>>n;

   lli arr[n];

   


while(1)
{
	cout<<"\n";
	cout<<"select the below operation to perform\n";
	cout<<"1. Push operation to add element into stack\n";
	cout<<"2. Pop operation to remove element from stack\n";
	cout<<"3. Return the top most element\n";
	cout<<"4. Size of a Stack\n";
	cin>>ch;
   switch (ch)
   {

   case 1:
   cout<<"Enter the element to be inserted\n";
   cin>>ele;
   push(ele,arr,top,n);
          break;

   case 2:
   pop(arr,top);         
          break;


    case 3:
    Topelement(arr,top);
          break;

    case 4:
     Sizestack(top); 
          break; 

     default :
        cout<<"Out of scope\n";
        exit(0);
          break;  

    }


}

}