#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Find the median of 2 sorted number.

T.C = O(Log(min(n1,n2)))
n1 - arr1 length
n2 - arr2 length

S.C = O(1)


Example  1- 

4 7
1 4 5 13
4 6 9 10 12 14 15

sorted array - 1 4 4 5 6 9 10 12 13 14 15

median is - 11/2 i.e 6th element = 9


Example  2- 

4 6
1 4 5 13
4 6 9 10 12 14 

sorted array - 1 4 4 5 6 9 10 12 13 14 

median is - (n1+n2)/2 + (n1+n2+1)/2 
  i.e (5th + 6th element)/2 = (6+9)/2= 7


  Explanation - We have to find the partition at which we can 
                partition the 1st and 2nd array.

                For  eg-
1 4 5 13
4 6 9 10 12 14 

low=0,high=4
cut1 = 2 cut2 = 3

left1=arr1[cut1-1]=4   right1=arr[cut1]=5
left2 =arr[cut2-1]=9  right2=arr[cut2]=10

left1 and left2 are the maximum of left side elements
right1 and right2 is the minimum of right side elements


if left1<=right2 && left2<=right1 if this condition saisies means we got our partition

otheriwse if left1>right2 it measn we have to shift high to left
else low to right

and we will return the median of even or odd length array




*/



lli medianof2sortedarray(vector<lli>&arr1,vector<lli>&arr2)
{
	if(arr1.size()>arr2.size())
		return (medianof2sortedarray(arr2,arr1));

lli n1=arr1.size();
lli n2=arr2.size();

lli low=0,high=n1;

while(low<=high)
{
	lli cut1=(low+high)/2;
	lli cut2=(n1+n2+1)/2-cut1;

   lli left1=cut1==0?INT_MIN:arr1[cut1-1];
   lli left2=cut2==0?INT_MIN:arr2[cut2-1];

   lli right1=cut1==n1?INT_MAX:arr1[cut1];
   lli right2=cut2==0?INT_MAX:arr2[cut2];


 if(left1<=right2 && left2<=right1)
 {
 	if( (n1+n2)%2==0)
 		return (max(left1,left2)+min(right1,right2))/2;
 	else
 		return max(left1,left2);
 }
 else if(left1>right2)
 	high=cut1-1;

 else
 	low=cut1+1;
}


return 0;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,m,i;
	cin>>n>>m;

	vector<lli>arr1;
	vector<lli>arr2;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr1.push_back(val);
	}

 
	for(i=0;i<m;i++)
	{
		lli val;
		cin>>val;
		arr2.push_back(val);
	}

lli med=medianof2sortedarray(arr1,arr2);

cout<<"Median of 2 sorted array\n";
cout<<med<<"\n";
}



