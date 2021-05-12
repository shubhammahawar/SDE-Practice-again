#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

 // FIND MISSING & REPEATED NUMBER IN AN ARRAY of size N and each number is in [1,,...N],
// IN WHICH ONE NUMBER IS REPEATING EXACTLY


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vector<lli>arr;

lli val,n,i,sumcal=0,sumsqcal=0,rems,sumdif,sumsqdif,mis,
rep,sumac=0,sumsqac=0;
cin>>n;

sumac=(n*(n+1))/2;
sumsqac=(n*(n+1)*(2*n+1))/6;

for(i=0;i<n;i++)
{
	cin>>val;
	arr.push_back(val);
	sumcal+=val;
	sumsqcal+=val*val;
}

sumdif=sumac-sumcal;
sumsqdif=sumsqac-sumsqcal;

rems=sumsqdif/sumdif;

mis=(sumdif+rems)/2;
rep=(rems-sumdif)/2;

cout<<"missing number is "<<mis<<"\n";
cout<<"repeated number is "<<rep<<"\n";


}