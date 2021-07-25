#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


void push(lli ele,lli arr[],lli &cnt,lli n,lli &rear,lli &front)
{
	if(cnt>=n)
		cout<<"Queue is FULL\n";
		
	else if(front==rear && front==-1)
	{
		front=(front+1)%n;
		rear=(rear+1)%n;
		
		arr[rear]=ele;
		cnt++;
	}
	else
	{
		rear=(rear+1)%n;
		arr[rear]=ele;
		cnt++;
	}
}

void pop(lli arr[],lli &cnt,lli &front,lli n)
{
  if(cnt<=0)
  	cout<<"Queue is Empty\n";

  else
  {
  
  	cout<<"the popped element is "<<arr[front%n]<<"\n";
  	arr[front%n]=-1;
  	front=(front+1)%n;
  	cnt--;
  }
  
}

void Topelement(lli arr[],lli &cnt,lli &front,lli n)
{
	 if(cnt<=0)
  	cout<<"Queue Empty\n";

  else
  	cout<<"Top element from Queue is "<<arr[front%n]<<"\n";
}

void Sizequeue(lli &cnt)
{
	cout<<"Size of a Queue is "<<cnt<<"\n";
} 


int main()
{
/*	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif */

   lli n,ele,front=-1,rear=-1,ch,cnt=0;

   cout<<"Enter the size of an array\n";
	cin>>n;

   lli arr[n];

   


while(1)
{
	cout<<"\n";
	cout<<"select the below operation to perform\n";
	cout<<"1. Push operation to add element into Queue\n";
	cout<<"2. Pop operation to remove element from Queue\n";
	cout<<"3. Return the top most element\n";
	cout<<"4. Size of a Queue\n";
	cin>>ch;
   switch (ch)
   {

   case 1:
   cout<<"Enter the element to be inserted\n";
   cin>>ele;
   push(ele,arr,cnt,n,rear,front);
          break;

   case 2:
   pop(arr,cnt,front,n);         
          break;


    case 3:
    Topelement(arr,cnt,front,n);
          break;

    case 4:
     Sizequeue(cnt); 
          break; 

     default :
        cout<<"Out of scope\n";
        exit(0);
          break;  

    }


}

}