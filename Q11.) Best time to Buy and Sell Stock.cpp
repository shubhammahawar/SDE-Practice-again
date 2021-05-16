#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* 
maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

T.C = O(N)
S.C = O(1)

Eg - Input - 7 1 5 3 6 4
     Output - 5  (Buying at 2nd day and selling at 5th day)

     Input - 5 4 3 2 1
     Output - 0 (can't get a profit so returning 0)

     */





void Buy_andSell(vector<lli>&arr,lli n)
{
	lli mine=INT_MAX;
	lli maxe=0,i;

	for(i=0;i<n;i++)
	{
		mine=min(mine,arr[i]);
		maxe=max(maxe,arr[i]-mine);
	}

	cout<<"Maximum Profit of Buy and Sell stock"<<"\n";

	cout<<maxe<<"\n";
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,val,i;
	cin>>n;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
        cin>>val;
        arr.push_back(val);
	}

	Buy_andSell(arr,n);

}
