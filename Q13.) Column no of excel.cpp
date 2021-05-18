#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/*  Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 

*/



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string str;
	cin>>str;
	double i,sume=0,l=str.length();




	for(i=l-1;i>=0;i--)
	{
		sume+=(str[i]-'A'+1)*pow(26,l-i-1);
	}

	cout<<"column no of Excel is"<<sume<<"\n";

}