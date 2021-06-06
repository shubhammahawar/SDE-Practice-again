#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



void ThreeSUM(vector<lli>&arr,lli n)
{
	sort(arr.begin(),arr.end());
	vector<vector<lli>>ans;

	lli i,j;

	for(i=0;i<n-2;i++)
	{
		if(i>0 && arr[i]==arr[i-1])
			continue;

		lli left=i+1;
		lli right=n-1;

      while(left<right)
      {
      	if(arr[i]+arr[left]+arr[right]==0)
      	{
      		ans.push_back({arr[i],arr[left],arr[right]});

      		while(left+1<right-1 && arr[left]==arr[left+1] &&
      			arr[right]==arr[right-1])
      		{
      			left++;
      			right--;
      		}
      		left++;
      		right--;
      	}

       else if(arr[i]+arr[left]+arr[right]<0)
       	left++;
       else
       	right--;


      }

	}

 cout<<"Unique triplet whose summation equal to 0"<<"\n";

for(i=0;i<ans.size();i++)
{
	for(j=0;j<ans[i].size();j++)
		cout<<ans[i][j]<<" ";

	cout<<"\n";
}

	

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

	ThreeSUM(arr,n);

}