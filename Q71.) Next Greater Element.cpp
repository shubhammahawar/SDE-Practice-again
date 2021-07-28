#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*
Find Next Greater Element of an array

T.C = O(N)+O(N) -~ O(N)
S.C = O(N)

Input - 7
7 1 3 2 4 6 8

Output - 8 3 4 4 6 8 -1 

Analysis - We will use Stack and run from backward 
           and since we are thinking it as a circular
           array so taking it as a 2*n-1 loop 
           So we store elements from back and if
           current element is greater than top of the stack
           we will pop the stack element otherwise 
           make top of the stack as next greater element and at
           last we will store element in stack.

*/

void nextgreaterelement(vector<lli>&arr,vector<lli>&ans)
{
	stack<lli>st;
	lli n=arr.size();

	for(lli i=2*n-1;i>=0;i--)
	{
		while(!st.empty() && st.top()<=arr[i%n])
		{
			st.pop();
		}

		if(!st.empty())
			ans[i%n]=st.top();

		st.push(arr[i%n]);
	}

	cout<<"The next greater element of an array is\n";
	for(lli i=0;i<n;i++)
		cout<<ans[i]<<" ";

	cout<<"\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

lli n;
cin>>n;

vector<lli>arr;

for(lli i=0;i<n;i++)
{
	lli val;
	cin>>val;
	arr.push_back(val);
}

vector<lli>ans(n,-1);

nextgreaterelement(arr,ans);
}