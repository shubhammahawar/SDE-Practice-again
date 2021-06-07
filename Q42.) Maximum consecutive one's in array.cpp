#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Given a binary array nums, return the maximum number of consecutive 1's in the array.

T.C = O(N)
S.C = O(1)

INPUT -
13
0 0 1 1 0 1 1 1 1 0 0 1 1

Output -4

ANALYSIS - Whenever there is 1 increment cnt 
           and if 0 is encounteretd store the maximum
           lenth 1's as a ans and cnt=0


    */       



lli ConsecutiveMax1s(vector<lli>&arr,lli n)
{
	lli ans=0,cnt=0,i;

	for(i=0;i<n;i++)
	{
		if(arr[i]==1)
			cnt++;

		else
		{
			if(cnt>ans)
				ans=cnt;

			cnt=0;
		}
	}

	if(cnt>ans)
		ans=cnt;

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

int ans=ConsecutiveMax1s(arr,n);

cout<<"Maximum no of consecutive one's\n";
cout<<ans<<"\n";
}