#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].


T.C= O(NLOGN) + O(N) + O(N)

NLOGN - FOR MERGE SORT 
N- FOR MERGE
N- FOR COUNTING A[i]>2*A[j] i.e traversing

S.C= O(N) for temporary array

Analysis - Using merge sort but while merging modifying the algo
           if (A[j]<2*A[i])  then A[j-1,j-2...] also smaller than 
           2*A[i]

           */








lli Merge(vector<lli>&arr,lli left,lli md,lli right,
	vector<lli>&temp)
{
	lli i,j=md,k,inv=0;

  
for(i=left;i<md;i++)
{
	while(j<=right && arr[i]>(long)arr[j]*2)
		j++;

inv+=(j-(md));
}
i=left,j=md,k=left;

while(i<md && j<=right)
{
	if(arr[i]<=arr[j])
		temp[k++]=arr[i++];
	else
		temp[k++]=arr[j++];
}

while(i<md)
temp[k++]=arr[i++];



while(j<=right)
temp[k++]=arr[j++];


for(i=left;i<=right;i++)
	arr[i]=temp[i];



return inv;



}



lli Mergersort(vector<lli>&arr,vector<lli>&temp,lli left,lli right)
{
	lli inv=0;

	if(left<right)
	{
		lli md=(left+right)/2;

		inv+=Mergersort(arr,temp,left,md);
		inv+=Mergersort(arr,temp,md+1,right);

		inv+=Merge(arr,left,md+1,right,temp);
	}

	return inv;
  
}


void Reversepair(vector<lli>&arr,lli n)
{vector<lli>temp(n);

   
   lli ans=Mergersort(arr,temp,0,n-1);

   cout<<"No of reverse pairs are "<<"\n";
   cout<<ans<<"\n";

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i;
	cin>>n;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	Reversepair(arr,n);
}