#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Find the position of a element in a sorted rotated array

T.C= O(Logn)
S.C = O(1)

Input - 11 14
8 9 11 14 17 20 22 1 4 5 7

Output - 3


Analysis - We will check if left side of a mid is sorted or not
           if it is sorted then we will check if our target lies 
           b/w the left side or not

           Similarly if left side is not sorted then right side will 
           be sorted then we will check if our target lies 
           b/w the left side or not

           and return the arr[md]== target return md;



*/




lli searchrotatedsortedarray(vector<lli>&arr,lli target)
{
	lli n=arr.size();

	lli low=0,high=n-1;

	while(low<=high)
	{
		lli md=(low+high)/2;

		if(arr[md]==target)
			return md;

		if(arr[low]<=arr[md])
		{
			if(target>=arr[low] && target<=arr[md])
				high=md-1;
			else
				low=md+1;
		}

        else
        {
        	if(target>=arr[md] && target<=arr[high])
        		low=md+1;
        	else
        		high=md-1;
        }

	}
 return -1;

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i,target;
	cin>>n>>target;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

  lli ans=searchrotatedsortedarray(arr,target);
  cout<<"The position of an element  present in a sorted rotated array is\n";
  cout<<ans<<"\n";

}