#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* 

Job sequencing Problem---------

Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

T.C = O(nlogn)+O(N*M)
S.C = O(N)


Input - 
4
Deadline - 3 2 1 2
Profit -   27 15 10 20


Output - 62  ( job 4th -> job 2nd -> job 1st in this order
               will execute)


Analysis-- First we will sort the structure in decreasing
           order of profit.
           Then our aim is to put the job in their last time
           Suppose job 1 has deadline 3 so our aim is to execute it
           as last as possible within 3 seconds.
           and accordingly we accomodate the res vector and
           earn the maximum profit.


  */         





struct job
{
	int id,dead,profit;
};


bool comparator(struct job a ,struct job b)
{
  return (a.profit>b.profit);
}

lli Jobscheduling(vector<lli>&deadline,vector<lli>&profit)
{
	lli n= deadline.size(),i,j;
	struct job data[n];
	lli maxdead=0;

for(i=0;i<n;i++)
{
	data[i].id=i+1;
	data[i].dead=deadline[i];
	data[i].profit=profit[i];
	maxdead=max(maxdead,deadline[i]);
}
vector<lli>res(maxdead+1,-1);
lli earn=0;

sort(data,data+n,comparator);

for(i=0;i<n;i++)
{
	for(j=data[i].dead;j>0;j--)
	{
		if(res[j]==-1)
		{
           earn+=data[i].profit;
           res[j]=i+1;
           break;
		}
	}
}
return earn;

}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i;
	cin>>n;

	vector<lli>deadline;
	vector<lli>profit;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		deadline.push_back(val);
	}

	for(i=0;i<n;i++)
{
		lli val;
		cin>>val;
		profit.push_back(val);
	}


 int ans=Jobscheduling(deadline,profit);

 cout<<"Maximum no of jobs that can be schedule\n";
 cout<<ans<<"\n";




}