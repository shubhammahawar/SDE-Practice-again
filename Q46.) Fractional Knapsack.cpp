#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;




/* Fractionall Knapsack----------

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item


T.C = O(nlogn)+O(n) =~ O(N logn)
S.C = O(1)


Input -- 

   N - 3 W- 50
Value-   60 100 120
Weight - 10 20 30

Output - 240 



ANALYSIS - First we sort the value/Weight order in decreasing order
           that will give what profit we will get on single
           weight
           Then only just add profit on particular weight.

           */



struct knapsack
{
	int value,weight;
};



bool comparator(struct knapsack k1,struct knapsack k2)
{
	double d1=(double)k1.value/(double)k1.weight;
	double d2=(double)k2.value/(double)k2.weight;

	return (d1>d2);
}


double FractionalKnapsack(vector<lli>&value,vector<lli>&weight,lli w)
{
	lli n= value.size(),i;
	struct knapsack data[n];


  for(i=0;i<n;i++)
  {
  	data[i].value=value[i];
  	data[i].weight=weight[i];
  }


sort(data,data+n,comparator);
double ans=0;

for(i=0;i<n;i++)
{
	if(w>0)
	{
	if(data[i].weight<w)
	{
       ans+=data[i].value;
       w-=data[i].weight;
	}

   else
   {
   	ans+=(double)w/data[i].weight *data[i].value;
   	w-=data[i].weight;
   }

}

else
	break;
}

return ans;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i,w;
	cin>>n>>w;

	vector<lli>value;
	vector<lli>weight;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		value.push_back(val);
	}

	for(i=0;i<n;i++)
{
		lli val;
		cin>>val;
		weight.push_back(val);
	}
  

  lli ans=FractionalKnapsack(value,weight,w);

  cout<<"Maximum total value in a knapsack\n";
  cout<<ans;
}