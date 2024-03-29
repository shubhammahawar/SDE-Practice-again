#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Implement Stack using two queue.

T.C = O(N)
S.C ~= O(N) //since using 2 queue so 2N so nearly ~

Analysis - we will be using two queue and everytime 
           we will be puhing into Q2 queue and then 
           popping  element by element from q1 to q2
           and then swapping Q1 and Q2.

       */

void push(lli ele,queue<lli>&q1,queue<lli>&q2,lli &cnt,lli n)
{
	if(cnt==n)
	{
		cout<<"Data structure is Full\n";
		return;
	}

   cnt++;
  q2.push(ele);
  while(!q1.empty())
  {
  	q2.push(q1.front());
  	q1.pop();
  }
  queue<lli>temp=q1;
  q1=q2;
  q2=temp;

}

void pop(queue<lli>&q1,lli &cnt)
{
	if(q1.empty())
	{
		cout<<"No elements in queue";
		return;
	}

	cout<<"the popped element is "<<q1.front();
	q1.pop();
	cnt--;
}


void Topelement(queue<lli>&q1)
{
	cout<<"The topped element is "<<q1.front();
}

void sizeds(lli &cnt)
{
	cout<<"size of data structure is "<<cnt<<"\n";
}



int main()
{
	queue<lli>q1;
	queue<lli>q2;
 
  lli n,ele,ch,cnt=0;

   cout<<"Enter the size of an array\n";
	cin>>n;


	while(1)
{
	cout<<"\n";
	cout<<"select the below operation to perform\n";
	cout<<"1. Push operation\n";
	cout<<"2. Pop operation \n";
	cout<<"3. Return the top most element\n";
	cout<<"4. Size of data structure\n";
	cin>>ch;
   switch (ch)
   {

   case 1:
   cout<<"Enter the element to be inserted\n";
   cin>>ele;
   push(ele,q1,q2,cnt,n);
          break;

   case 2:
   pop(q1,cnt);         
          break;


    case 3:
    Topelement(q1);
          break;

    case 4:
     sizeds(cnt); 
          break; 

     default :
        cout<<"Out of scope\n";
        exit(0);
          break;  

    }
}

}
