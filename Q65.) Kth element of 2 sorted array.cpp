#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Find kth largest element of 2 sorted array

T.C = O(log(min(n,m)))
S.C = O(1)

Input - 4 7 9 (K=9)
1 4 5 13
4 6 9 10 12 14 15

Output - 13 is the 9th element of 2 sorted array

Analysis - Concept is similar to previous question 
           median of 2 sorted array

           Only thing is select low and high wisely
           low=max(0,k-m)
           high=min(k,n);


 */





int kthlargestelement(vector<lli>&arr1,vector<lli>&arr2,lli k)
{

  if(arr2.size()<arr1.size())
  	return kthlargestelement(arr2,arr1,k);

  lli n=arr1.size();
  lli m=arr2.size();

  lli low=max((lli)0,(k-m));
  lli high=min(k,n);

  while(low<=high)
  {
  	lli cut1=(low+high)/2;
  	lli cut2=k-cut1;

  	lli left1=cut1==0?INT_MIN:arr1[cut1-1];
  	lli left2=cut2==0?INT_MIN:arr2[cut2-1];

  	lli right1=cut1==n?INT_MAX:arr1[cut1];
  	lli right2=cut2==m?INT_MAX:arr2[cut2];
    
    if(left1<=right2 && left2<=right1)
    {
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

	lli n,m,i,k;
	cin>>n>>m>>k;

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

lli ans=kthlargestelement(arr1,arr2,k);

cout<<k<<" th largest element of 2 sorted array is\n";
cout<<ans<<"\n";
}