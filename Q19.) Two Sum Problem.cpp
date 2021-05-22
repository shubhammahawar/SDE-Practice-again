#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


T.C = O(N) // unordered map for insertion and searching average O(1)
S.C = O(N) // for using unordered map

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]


Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]


*/




void TwoSum(vector<lli>&arr,lli n,lli target)
{
	unordered_map<lli,lli>mp;
	vector<lli>ans;
	lli i;


   for(i=0;i<n;i++)
   {
   	
   	if(mp.find(target-arr[i])!=mp.end())
   	{
   		ans.push_back(mp[target-arr[i]]);
   		ans.push_back(i);
   		break;
   	}
   	else
   		mp[arr[i]]=i;


   }

   for(i=0;i<ans.size();i++)
   	cout<<ans[i]<<" ";



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
	map<lli,lli>mp;

	for(i=0;i<n;i++)
	{
      lli val;
      cin>>val;
      arr.push_back(val);
	}

     TwoSum(arr,n,target);

 }






