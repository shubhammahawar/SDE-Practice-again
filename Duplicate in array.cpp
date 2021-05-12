#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


lli Find_duplicate(lli arr[],lli n)
{
    lli slow,fast;
    slow=arr[0];
    fast=arr[0];

 do{

 	slow=arr[slow];
 	fast=arr[arr[fast]];

 }while(slow!=fast);


slow=arr[0];

while(slow!=fast)
{
	slow=arr[slow];
	fast=arr[fast];
}
return fast;

}



int main()
{
#ifndef ONLINE_JUDGE
// for getting input from input.txt
freopen("input.txt","r",stdin);
// for writing output to output.txt
freopen("output.txt","w",stdout);
#endif

	lli n;
	cin>>n;

	lli arr[n+1],i;

	for(i=0;i<n+1;i++)
	{
		cin>>arr[i];
	}

	lli dup=Find_duplicate(arr,n);

	cout<<"duplicate element is"<<dup<<"\n";



}