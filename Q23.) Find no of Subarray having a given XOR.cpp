#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*  Count the number of subarrays having a given XOR


T.C = O(NLOGN)  N for iteration and LOGN for searching in a 
                map in Worst Case.

S.C = O(N)

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4

Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}


Analysis :            SXOR
                 -----------  K
                 --------- -------
                      B

             B ^ K = SXOR
             B = SXOR ^ K

So we get the SXOR value now if we take its XOR with K(given Xor value)
if we get the B value it means subarray having a given XOR " K " exist.

*/






lli CountSubarraywithgivenXOR(vector<lli>&arr,lli n,lli xorv)
{
	lli xrsum=0,cnt=0,i;
	unordered_map<lli,lli>mp;

	for(i=0;i<n;i++)
	{
		xrsum^=arr[i];
		if(xrsum==xorv)
			cnt++;

		lli ch=xrsum^xorv;

		if(mp.find(ch)!=mp.end())
		{
			cnt+=mp[ch];
		}
		
			mp[xrsum]++;
	}

	return cnt;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i,xorv;
	cin>>n>>xorv;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	lli ans=CountSubarraywithgivenXOR(arr,n,xorv);

    cout<<"No of Subarray with given XOR value are "<<"\n";
    cout<<ans<<"\n";


}