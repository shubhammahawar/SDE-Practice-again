#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

T.C = O(N^3)+O(NLOGN) i.e O(N^3) for 3 loops
S.C = O(1)

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Analyis 
take two loop on i ,j and then put one pointer at ahead of j
and one pointer at last to sum up the target value

*/









void foursum(vector<lli>&nums,lli n,lli target)
{
	lli i,j;
	vector<vector<lli>> res;
	sort(nums.begin(),nums.end());

	for(i=0;i<n-3;i++)
	{
		if(i>0 && nums[i]==nums[i-1])
			continue;

		for(j=i+1;j<n-2;j++)
		{
           
           if(j>1 && nums[j]==nums[j-1] && (j-i)>1)
           	continue;

			lli left =j+1;
			lli right=n-1;

			while(left<right)
			{
				if(nums[i]+nums[j]+nums[left]+nums[right]==target)
				{
					res.push_back({nums[i],nums[j],nums[left],nums[right]});

					while(left+1<right-1 && nums[left]==nums[left+1]
						&& nums[right]==nums[right-1])
					{
						left++;
					    right--;
					}
					left++;
					right--;
				}

				else if( (nums[i]+nums[j]+nums[left]+nums[right])>target)
					right--;
				else
					left++;
			}


		}
	}
//	cout<<"size"<<res.size();
cout<<"Unique Quadruple of array equal to target value"<<"\n";
	for(i=0;i<res.size();i++)
	{
       for(j=0;j<res[i].size();j++)
       	cout<<res[i][j]<<" ";

       cout<<"\n";
	}

}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,tar,i;
	cin>>n>>tar;

	vector<lli>arr;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

	foursum(arr,n,tar);

}