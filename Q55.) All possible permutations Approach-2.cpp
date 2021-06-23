#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

T.C= O(n!)xO(n)

n! - for generating all combination
n - for running loop for every permutation.

S.C = O(1)

Auxilary space - O(n) // depth of Recursion



Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Analysis - Here we will generate all the permutaion using 
           Swapping technique.
           For every combination we will run loop and swap
           every position's value.

           

*/


void swap(lli *a,lli*b)
{
	lli temp=*a;
	*a=*b;
	*b=temp;
}

void findallpermutation(lli ind,vector<lli>&arr,vector<vector<lli>>&ans)
{
	if(ind==arr.size())
	{
		ans.push_back(arr);
		return ;
	}

	for(int i=ind;i<arr.size();i++)
	{
        swap(&arr[ind],&arr[i]);
        findallpermutation(ind+1,arr,ans);
        swap(&arr[ind],&arr[i]);
	}

}


void AllPermutation(vector<lli>&arr)
{
	vector<vector<lli>>ans;

	findallpermutation(0,arr,ans);

	cout<<"All the possible permutation are\n";
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

	lli n,i;
	cin>>n;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	AllPermutation(arr);
}