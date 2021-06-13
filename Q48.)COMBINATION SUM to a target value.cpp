#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

 SUM COMBINATION 


Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

T.C = O(2^target)*k 
      k- average length of combination 
      2^target - cz if target = 10 and 1 is in input
      1+1+1+1+-----t times = 10

 S.C = O(k*x) // unpredicatble dependson no of combination
       x- no of combination

Example - 

3 4(target)
2 1 3

Output - 
2 2 
2 1 1 
1 1 1 1 
1 3 


Analysis -- Our task is to pick and non pick the element
            if we pick the element then reduce it from target
            if we don't pick the element ,increment the index.

            and once we reach end of index and target ==0 
            means we got the combination otherwise return;

     */       







\
void findcombination(lli ind,lli tg,vector<lli>&arr,
	              vector<lli>&temp,vector<vector<lli>>&ans)
{

if(ind==arr.size())
{
	if(tg==0)
		ans.push_back(temp);

	return;
}

if(arr[ind]<=tg)
{  
	temp.push_back(arr[ind]);
	findcombination(ind,tg-arr[ind],arr,temp,ans);
	temp.pop_back();
}

findcombination(ind+1,tg,arr,temp,ans);


}


void  Sumcombination(vector<lli>&arr,lli tg)
{
	vector<vector<lli>>ans;
	vector<lli>temp;
	lli i,j;

	findcombination(0,tg,arr,temp,ans);

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

    Sumcombination(arr,tg);


}