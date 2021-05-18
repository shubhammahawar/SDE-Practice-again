#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 T.C = O(N)
 S.C = O(1)

 Eg- Input: nums = [2,2,1,1,1,2,2]
     Output: 2

     Analysis -
     We are taking element as majority if it is a majority element 
     it will be available at the end of our algo with cnt value>0

     */


*/


void majorityelement(vector<lli>&arr,lli n)
{
	lli i,maj,cnt=0;


	for(i=0;i<n;i++)
	{
		if(cnt==0)
			maj=arr[i];


         if(maj==arr[i])
         	cnt++;

         else
         	cnt--;

	}

	cout<<"majority element of an array who appear more than n/2 times in an array "<<maj<<"\n";

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vector<lli>arr;

	lli n,i;
	cin>>n;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	majorityelement(arr,n);

}