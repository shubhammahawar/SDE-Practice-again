#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* 
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


T.C = O(2^n) * K 
 2^n - maximum possible combination if all elements are unique
 K- average length of combination cz we are transferring
 one data structure into other.

 S.C = O(K*x)  , x- no of combination 


Input 5 4
 
1 2 1 1 3

Output -   1 1 2 
           1 3 


Analysis - First we have to sort the data

           Next  thing we can select anyone of
           the element as our 1st elemnt

           so for ith element we will run till n-1 element

           and if arr[i]== arr[i-1] continue

           Also if arr[i] element is greater then target value
           dont do recursive call,just break it

           and if we select ith element as our combination value
           move the index to next position and decrease value from target


           

*/


void findcombination2(lli ind,lli targ,vector<lli>&arr,
	vector<lli>&temp,vector<vector<lli>>&ans)
{
	if(targ==0)
	{
		ans.push_back(temp);
		return;
	}

	for(lli i=ind;i<arr.size();i++)
	{
		if(i>ind && arr[i]==arr[i-1])
			continue;
		if(arr[i]>targ)
			break;

		temp.push_back(arr[i]);
		findcombination2(i+1,targ-arr[i],arr,temp,ans);
		temp.pop_back();
	}
}


void Sumcombination2(vector<lli>&arr,lli &tg)
{
	sort(arr.begin(),arr.end());

	vector<vector<lli>>ans;
	vector<lli>temp;
	lli i,j;

	findcombination2(0,tg,arr,temp,ans);

	cout<<"No of unique combination to a target sum\n";


	for(i=0;i<ans.size();i++)
	{
		for(j=0;j<ans[i].size();j++)
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

	lli n,tg,i;
	cin>>n>>tg;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

    Sumcombination2(arr,tg);
}
