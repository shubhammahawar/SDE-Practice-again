#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

T.C= O(n!)xO(n)

n! - for generating all combination
n - for running loop for every permutation.

S.C = O(n)+O(n)

O(n) - for freq array
O(n) - for temporary dsata structure.


Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Analysis - We will use the frequency array 
           and check for if element of that map is not visited
           we will recurively go till the ds size reaches to given
           arr size cz all the numbers should be in permutation.





*/



void findAllpermutation(vector<lli>arr,int freq[],vector<lli>&ds,
	                      vector<vector<lli>>&ans)
{
	if(ds.size()==arr.size())
	{
		ans.push_back(ds);
		return;
	}

	for(lli i=0;i<arr.size();i++)
	{
		if(freq[i]==0)
		{
			ds.push_back(arr[i]);
			freq[i]=1;
			findAllpermutation(arr,freq,ds,ans);
			ds.pop_back();
			freq[i]=0;
		}
	}
}

void AllPermutation(vector<lli>arr)
{
	vector<vector<lli>>ans;
	vector<lli>ds;
	int freq[arr.size()];

	for(lli i=0;i<arr.size();i++)
		freq[i]=0;

     findAllpermutation(arr,freq,ds,ans);

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