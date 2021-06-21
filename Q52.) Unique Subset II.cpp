#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* 

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

T.C = O(2^n)*n // extra n is to assigning temp data structure
                  to ans data structure


S.C = O(2^n)*O(k) // k is average length of recursion.


Input - : 3 
          1 2 1

Output - : []    // these are all unique subset of Input
           [1]
           [1,1]
           [1,1,2]
           [1,2]
           [2]  


Analysis - : First we will sort the input data
             Now we will select the every input and
             check if it is first time selected then 
             it is okay otherwise continue
             We are storing the 0 length,1 length .....
             ....n length subset into a ans datastructure


*/



void finduniquesubset(lli ind,lli n,vector<lli>&arr,
	vector<lli>&temp,vector<vector<lli>>&ans)
{

    ans.push_back(temp);

	for(lli i=ind;i<n;i++)
	{
		if(i>ind && arr[i]==arr[i-1])
			continue;
		temp.push_back(arr[i]);
		finduniquesubset(i+1,n,arr,temp,ans);
		temp.pop_back();
	}
}


void UniqueSubset(vector<lli>arr)
{
	vector<lli>temp;
	vector<vector<lli>>ans;
    sort(arr.begin(),arr.end());
	finduniquesubset(0,arr.size(),arr,temp,ans);

	cout<<"All unique subset of an array are\n";

	for(lli i=0;i<ans.size();i++)
	{
		for(lli j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";

		cout<<"\n";
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n;
	cin>>n;


	vector<lli>arr;

	for(lli i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

  UniqueSubset(arr);
}


