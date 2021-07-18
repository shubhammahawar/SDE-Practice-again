#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* 

Find a element that appears exactly once in a sorted array and 
all other elements are appearing twice.

T.C = O(Logn)
S.C = O(1)

Input - 9
1 1 2 2 3 3 4 4 5 

Output - 5


Analysis - As it is sorted array we will use binary search
           We have to separate it in left and right part
           Left part in which all element are appears twice
           and right part in which have single element is present.

          if element is coming 1st instance -
                                    it should be on even index 

          if element is coming 2nd instance -
                                    it should be on odd index

          To check this we will use XOR
          arr[pos]==arr[pos^1]

          if pos is odd it means 2nd instance of element so we have to check
          previous index i.e even so eg-
          pos=3 
          11 -3 
         ^01 - 1
         ----
          10 -2 
          ---     
          if pos is even it means 1st instance of element so we have to check
          next index i.e odd so eg-
          pos=2
          10 -2
         ^01 - 1
         ----
          11- 3
          ---                                                   

We have to shrink the left and right part.
till high reaches to previous of right part
and left reaches to next of left part.

*/

lli singlenonduplicate(vector<lli>&arr)
{
	lli n=arr.size();
	lli low=0,high=n-2;

	while(low<=high)
	{
		lli md=(low+high)/2;

		if(arr[md]==arr[md^1])
			low=md+1;
		else
			high=md-1;
	}
	return arr[low];
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

  lli ans=singlenonduplicate(arr);
  cout<<"The elemenet which is present only 1 time in a sorted array is\n";
  cout<<ans<<"\n";

}

