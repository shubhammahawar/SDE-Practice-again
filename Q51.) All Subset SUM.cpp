#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Subset Sum----

Given a list(Arr) of N integers, print sums of all subsets in it. Output should be printed in increasing order of sums.

T.C= O(2^N + 2^NLOG(2^N) ) 2nd one for sorting
S.C= O(2^n) cz total 2^n subset will generate

Input - 3 
         1 2 4

Output - 0 1 2 3 4 5 6 7   


Analysis -- Here just think position is selected or not
            If selected then consider this element 
            into subset,if not don't consider it.


   */
                   




void findsubsetsum(lli ind,lli n,lli temp,vector<lli>&arr
                     ,vector<lli>&ans)
{


if(ind==n)
{
	ans.push_back(temp);
	return;
}

  temp+=arr[ind];
  findsubsetsum(ind+1,n,temp,arr,ans);
  temp-=arr[ind];
  findsubsetsum(ind+1,n,temp,arr,ans);

}

void Subsetsum(vector<lli>&arr)
{
	vector<lli>ans;
	lli temp=0;

	findsubsetsum(0,arr.size(),temp,arr,ans);


	cout<<"Sum of all subset of an array\n";
  sort(ans.begin(),ans.end());
	for(lli i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";


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

  Subsetsum(arr);
}



