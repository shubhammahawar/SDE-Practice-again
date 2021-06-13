#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Minimum no of coins----------

T.C = O(V)
S.C = O(1)

Input
 V= 1112

 Output - 4 coin change are required i.e 1000,1000,10,2

 Analysis - we just run the array pf coin change from 
            backward and store the result if V is 
            divisible by that coin.

        */    
    
lli Minimumnoofcoins(vector<lli>&v,lli n,vector<lli>&change)
{
	lli d=0;
	
	
	for(lli i=v.size()-1;i>=0;i--)
	{
		if(n==0)
			break;

         d+=n/v[i];
         if(n%v[i]!=n)
         	change.push_back(v[i]);

        n=n%v[i];
        
	}

	

return d;

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n;
	cin>>n;

	vector<lli>v{1,2,5,10,20,50,100,500,1000};
	vector<lli>change;


	lli ans=Minimumnoofcoins(v,n,change);

	cout<<"Minimum no of coins required to make a change of "<<n <<" ruppe are \n";
	cout<<ans<<"\n";
	cout<<"required notes of "<<"\n";

	for(lli i=0;i<change.size();i++)
		cout<<change[i]<<" ";

}
