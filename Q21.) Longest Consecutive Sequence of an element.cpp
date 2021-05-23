#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

T.C = O(N)+O(N)+O(N)
O(N)= for pushing values into set
O(N)= for iterating the vector array
O(N)= for checking and itertaing the consective values.

S.C= O(N) for using set.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Analysis :

The intuition is find the minimum element and then iterate to upper
consecutive values

if suppose num=9, its one less value is 8 if it is present 
then move next in the array  as 9 is  not the minimum element
of this consecutive length elements.

if it is minimum element then iterate to upper consecutive elements.



*/





lli LongestConsecutiveSequence(vector<lli>&nums,lli n)
{
	set<lli>s;
	lli ans=0;

	for(lli num:nums)
		s.insert(num);

	for(lli num:nums)
	{
		if(s.count(num-1))
		{}

	    else
	    {
	    	lli j=num;
	    	lli ct=0;
	    	while(s.count(j))
	    	{
               j++;
               ct++;
	    	}
	    	 ans=max(ans,ct);
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

	vector<lli>arr;\

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	lli ans=LongestConsecutiveSequence(arr,n);
	cout<<"Longest Consecutive Sequence of an array is " <<"\n";
	cout<<ans<<"\n";
}
