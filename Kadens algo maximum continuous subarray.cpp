#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Maximum Continuous Subarray using Kadens Algorithm 

T.C= O(N)
S.C=O(1) */

lli Kadensalgo(vector<lli>&v,lli n)
{
	lli cur=v[0],fin=v[0],i;

	for(i=1;i<n;i++)
	{
		if( (fin+v[i]) >v[i])
			fin=fin+v[i];
		else
			fin=v[i];

		if(fin>cur)
			cur=fin;
	}

	return cur;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vector<lli>v1;

	lli n,i,val,maxsum;
	cin>>n;

	for(i=0;i<n;i++)
	{
         cin>>val;
         v1.push_back(val);
	}


	maxsum=Kadensalgo(v1,n);

	cout<<"Maximum contiguous Subarray "<<maxsum<<"\n";
}
