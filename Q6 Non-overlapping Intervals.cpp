#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input. */

/* T.C =O(LOGN) +O(N)
   LOGN for sorting and N for linearly traversing.

   S.C= O(N) // WORST CASE  */


bool comparator(const vector<lli>&v1,const vector<lli>&v2)
{
	return (v1[0]<v2[0]);
}

void MergeoverlappingInterval(vector<vector<lli>>& v,lli n)
{

   sort(v.begin(),v.end(),comparator);

   lli st=v[0][0];
   lli ed=v[0][1];

   lli i,j;
   
   vector<vector<lli>>res;
   vector<lli>ch=v[0];
  
  
for(auto it : v)
{
	if(it[0]<=ch[1])
		ch[1]=max(ch[1],it[1]);

	else
	{
		res.push_back(ch);
		ch=it;
	}
}

res.push_back(ch);


   cout<<"After Overlapping intervals combined"<<"\n";


for(i=0;i<res.size();i++)
{
	for(j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
}


}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    lli n,i,st,ed;
    cin>>n;

	vector<vector<lli>>v1;

	

	for(i=0;i<n;i++)
	{
		vector<lli>temp;
		cin>>st>>ed;
		temp.push_back(st);
		temp.push_back(ed);
		v1.push_back(temp);
	}

     MergeoverlappingInterval(v1,n);
   



}