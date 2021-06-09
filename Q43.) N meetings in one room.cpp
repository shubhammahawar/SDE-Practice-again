#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/* N meetings in one room 

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


T.C = O(N)+O(NLOGN)+O(N) =~ O(NLOGN)
  
  O(N) for traversing and storing in data structure
  O(N) for sorting based on end timing of meeting
  O(N) for again traversing and counting no of meeting possible


S.C = O(N)


Input -   
 6
1 3 0 5 8 5
2 4 6 7 9 9

Output - Total 4 meeting accomodate in a room

1 3 5 8
2 4 7 9


Analysis - first we store the data in data structure 
           along with the position
           Then we will sort the data acco to meeting
           whose finishing time is earlier

           Then we will compare the start of next meeting
           with the end of previous meeting 
           if it statisy ,this meeting can be possible and 
           increment the cnt;

      */
      







struct meeting
{
	lli start,end,pos;
};


bool comparator(struct meeting m1,struct meeting m2)
{

if(m1.end<m2.end)
	return true;
else if(m1.end>m2.end)
	return false;
else if(m1.pos<m2.pos)
	return true;

return false;

}


lli Nmeetingsinroom(vector<lli>&str,vector<lli>&end,lli n)
{
  struct meeting data[n];
  lli i,cnt=1;
	for(i=0;i<n;i++)
	{
       data[i].start=str[i];
       data[i].end=end[i];
       data[i].pos=i+1;
	}

  sort(data,data+n,comparator);

  lli lastmeeting=data[0].end;

  for(i=1;i<n;i++)
  {
     if(data[i].start>lastmeeting)
     	{
     		cnt++;
     		lastmeeting=data[i].end;
     	}
  }

  return cnt;

}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,i;
	cin>>n;

	vector<lli>str;
	vector<lli>end;

	for(i=0;i<n;i++)
	{
		lli val;
		cin>>val;
		str.push_back(val);
	}

	for(i=0;i<n;i++)
{
		lli val;
		cin>>val;
		end.push_back(val);
	}

   lli ans=Nmeetingsinroom(str,end,n);

   cout<<"maximum number of meetings that can be accommodated in the meeting room\n";
   cout<<ans<<"\n";
}



