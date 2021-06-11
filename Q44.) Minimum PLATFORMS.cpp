#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Minimum Platform---

Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms,

T.C = O(2NLogn) + O(2N) =~ O(NLOGN)
S.C = O(1)

Example -

Input  - 6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000

Output- 3


Analysis - 
             First sort the arrival and departure time of all trains
             irrespective of their indexes cz the only thing  we just have to think
             about availability of platform when one train arrives and other train departs.
             Then if a arrival time of some train is less than departure time
             of other train we have to need another platform otherwise previous
             platform will be free and new train will accomodate that platform.



*/






lli Minplatform(vector<lli>&str,vector<lli>&end)
{

	lli s=0,e=0;
	lli m=str.size();
	lli plt=0,maxe=0;
	sort(str.begin(),str.end());
	sort(end.begin(),end.end());


	while(s<m && e<m)
	{
		if(str[s]<=end[e])
		{
			plt++;
			s++;
		}
		else
		{
			plt--;
			e++;
		}
		if(plt>maxe)
			maxe=plt;

	}

	return maxe;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i;
	cin>>n;

	vector<lli>str;
	vector<lli>end;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		str.push_back(val);
	}

	for(i=0;i<n;i++)
{
		lli val;
		cin>>val;
		end.push_back(val);
	}

lli ans=Minplatform(str,end);

cout<<"Minimum no of platform required for a trains to arrive and depart\n";
cout<<ans<<"\n";
}