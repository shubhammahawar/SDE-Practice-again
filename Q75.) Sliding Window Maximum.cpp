 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*

Sliding Window Maximum

T.C= O(N)+O(N)
S.C =O(K)

Example - 
nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]


Analysis- We will use a Deque here that is push and pop
          occur at both ends.

          We will use the concept of NEXT GREATER ELEMENT
          if element at ith index is greater than the dequeu
          back element then pop it
          if it is smaller then push it into back of deque
          We are maintaining the decreasing array element in dequeu

          and if i>=k means insert the front element of queu in ans



*/


void Slidingwindowmaximum(vector<lli>&arr,lli k)
{
	lli n=arr.size();

	deque<lli>dq;
	vector<lli>ans;

  for(lli i=0;i<n;i++)
  {
  	if(!dq.empty() && i-k==dq.front())
  		dq.pop_front();

  	while(!dq.empty() && arr[dq.back()]<=arr[i])
  		dq.pop_back();

    dq.push_back(i);

  	if(i>=k-1)
  		ans.push_back(arr[dq.front()]);


  }
cout<<"maximum element of a sliding window of size k subarray\n";
  for(int i=0;i<ans.size();i++)
  {
  	cout<<ans[i]<<" ";
  }


}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vector<lli>arr;

	lli n,i,k;
	cin>>n>>k;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		arr.push_back(val);
	}

Slidingwindowmaximum(arr,k);
}