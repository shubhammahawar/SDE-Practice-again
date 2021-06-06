#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Optimal approach--

T.C = O(N)
S.C = O(1)

Example -

Input -
12
0 1 0 2 1 0 1 3 2 1 2 1

Output -6


Analysis - we will use the two pointer technique
           left pointer will point to 0 and right pointer
           will point to n-1
           we will compare the height of left and right pointer
           and compare with their lmax and max and update it in the ans


          */ 




lli Rainwatertrap(vector<lli>&arr,lli n)
{
	lli left=0,right=n-1;
	lli lmax=0,rmax=0,ans=0;


	while(left<=right)
	{
		if(arr[left]<=arr[right])
		{

			if(arr[left]>=lmax)
				lmax=arr[left];
			else
				ans+=lmax-arr[left];

			left++;
		}


		else
		{
			if(arr[right]>=rmax)
				rmax=arr[right];
			else
				ans+=rmax-arr[right];

			right--;
		}
	}

	return ans;
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

	lli store=Rainwatertrap(arr,n);


	cout<<"The amount of water stored\n";
cout<<store<<"\n";
}