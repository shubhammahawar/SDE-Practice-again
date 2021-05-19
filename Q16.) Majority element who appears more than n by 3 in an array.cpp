#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?


T.C  = O(N)
S.C  = O(1)

Example 1:

Input: nums = [3,2,3]
Output: [3]

Example 2:

Input: nums = [5,2,5,3,3,2,5,1,2,5,2]
Output: [2,5]

Analysis : There can't be more than 2 majority element here
           Take 2 variables if first no came we assume this is our
           a mjority element and similar for 2nd number.
           If a 3rd no. comes just decrease the count of other 2 numbers.

           At the end just validate the count of majority element by running linearily

*/




void majorityelement(vector<lli>&arr,lli n)
{
	lli el1=-1,el2=-1,cnt1=0,cnt2=0,i;

for(i=0;i<n;i++)
{
	if(arr[i]==el1)
		cnt1++;
	else if(arr[i]==el2)
		cnt2++;

   else if(cnt1==0)
   {
   	el1=arr[i];
   	cnt1=1;
   }

   else if(cnt2==0)
   {
   	el2=arr[i];
   	cnt2=1;
   }

   else
   {
   	cnt1--;
   	cnt2--;
   }
}

lli count1=0,count2=0;
for(i=0;i<n;i++)
{
	if(arr[i]==el1)
		count1++;

	else if(arr[i]==el2)
		count2++;
}

cout<<"Majority elements are "<<"\n";
if(count1>n/3)
	cout<<el1<<" ";


if(count2>n/3)
cout<<el2<<" ";
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	lli n,i;
	cin>>n;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	majorityelement(arr,n);
}