#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.


T.C = O(N)
S.C = O(1)

Input 7
      0 0 0 1 1 1 2

O/p - 0 1 2


ANALYSIS -- the task is to  inplictly remove the duplicate
            values and return the length of unique array 
            values and that should be in front of array

            We will use 2 Pointers and whenever the
            value of both pointers will not match
            we will replace the left pointer value
            with right pointer 
            and at the end the position of left pointer will be
            the answer of unique elements in array.

            We do not have to worry about remaining elements at the back of array
            just return the length of unique elements and duplicate elements
            will be placed at back of array.

            */



lli Removeduplicates(vector<lli>&arr,lli n)
{
	if(n==0)
		return 0;

	lli left=0;

	for(lli i=0;i<n;i++)
	{
		if(arr[i]==arr[left])
		{}

	   else
	   {
	   	arr[++left]=arr[i];
	   }
	}

	return (left+1);
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

	lli size=Removeduplicates(arr,n);

cout<<"Modified array after inplacitly removing duplicates\n";
	for(i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";

}