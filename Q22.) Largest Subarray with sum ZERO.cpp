#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Largest subarray with 0 sum

TC = O(NLOGN) ,N- FOR TRAVERSING LOGN FOR MAP
SC = O(N) // FOR MAP

Example1 :

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Analysis.
The intuition is if particular prefix sum is S and after moving 
some another prefix sum is S ,it means between them is sum 0.
so just store the maximum length of zero sum.

               0
    S     ------------
 --------
-----------------------
          S
*/



lli LargestSubarraySumZero(vector<lli>&A,lli n)
{
	map<lli,lli>mp;
	lli sum=0,ans=0,i;
mp[0]=-1;
	for(i=0;i<n;i++)
	{
       sum+=A[i];
       if(mp.find(sum)!=mp.end())
       {
       	 //B if(sum==0)
          ans=max(ans,i-mp[sum]);
       }
       else
       	mp[sum]=i;
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

	lli ans=LargestSubarraySumZero(arr,n);

	cout<<"Largest Subarray with Sum equal to Zero"<<"\n";
	cout<<ans<<"\n";
}