#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Count Inversions in an array |  (Using Merge Sort)

Problem Inversion - count (A[i] > A[j] if i<j)


 T.C= O(NLOGN) // cz of sorting
 S.C= O(N) // temp array used in merging.

 Eg - I/p - 9 1 3 5 2 4
      O/p - No of inversions are - 8

          Analysis - (9,1),(9,3),(9,5),(9,2),(9,4)
                     (3,2),(5,2),(5,4)


      I/p - 1 2 3 4 5
      O/p - 0 

      Analysis - No A[i]>A[j] such that i<j


      I/p - 5 4 3 2 1
      O/p - 10


      Analysis - (5,4),(5,3),(5,2),(5,1)
                 (4,3),(4,2),(4,1),(3,2),(3,1),(2,1)


*/



lli Merge(vector<lli>&arr,vector<lli>&temp,
	lli left,lli md,lli right)
{
	lli i=left;
	lli j=md;
	lli k=left,inv=0;


	while(i<md && j<=right)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			inv+=(md-i);
		}
	}

   while(i<md)
   	temp[k++]=arr[i++];

   while(j<=right)
   	temp[k++]=arr[j++];


  for(i=left;i<=right;i++)
  	arr[i]=temp[i];

  return inv;

}




lli Mergesort(vector<lli>&arr, vector<lli>&temp,
	lli left,lli right)
{
	lli inv=0;
	if(left<right)
	{
		lli md=(left+right)/2;

         inv+=Mergesort(arr,temp,left,md);
         inv+=Mergesort(arr,temp,md+1,right);

         inv+=Merge(arr,temp,left,md+1,right);

	}
	return inv;
}




void No_ofInversion(vector<lli>&arr,lli n)
{
	vector<lli>temp(n);
	
	
	lli ans=Mergesort(arr,temp,0,n-1);

	cout<<"No of Inversions are"<<"\n";
	cout<<ans<<"\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


lli n,val,i;
cin>>n;

vector<lli>v;

for(i=0;i<n;i++)
{
	cin>>val;
	v.push_back(val);
}

No_ofInversion(v,n);
}