#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

T.C =O(N)+O(N)+O(N) ~= O(N)
(N- for finding first position
N- finding just greater element
N- for reversing)

S.C= O(1)

Eg- I/p -    9 6 2 9 8 7
    O/p -    9 6 7 2 8 9

    I/p -    5 4 3 2 1
    O/p -    1 2 3 4 5

    */


void swap(lli *a,lli *b)
{
	lli temp=*a;
	*a=*b;
	*b=temp;
}


 void next_largestpermutation(vector<lli>&arr,lli n)
{
	lli i,j,pos=-1;

	if(arr.empty() || arr.size()<=1)
		return;

	for(i=n-1;i>=1;i--)
       if(arr[i-1]<arr[i])
       	{pos=i-1;
       		break;
       	}

//cout<<"pos"<<pos<<"\n";
       if(pos>=0)
       {
       for(i=n-1;i>pos;i--)
       {
          if(arr[i]>arr[pos])
          {
          	swap(&arr[i],&arr[pos]);
          	break;
          }
       }
   }



       
       	 reverse(arr.begin()+pos+1,arr.end());
       






cout<<"Next Largest Permutation"<<"\n";
for(i=0;i<n;i++)
	cout<<arr[i]<<" ";


} 


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

lli n,val,i;
cin>>n;
vector<lli>arr;
//cout<<"n"<<n<<"\n";

for(i=0;i<n;i++)
{
   cin>>val;
 //  cout<<"val"<<val<<"\n";
   arr.push_back(val);
}


for(i=0;i<n;i++)
	cout<<arr[i]<<" ";

cout<<"\n";

next_largestpermutation(arr,n);

}