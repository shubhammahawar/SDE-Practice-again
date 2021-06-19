#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*

Palindrome Partioning-------


Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.


Input - aabb

Output -                

a a b b 
a a bb 
aa b b 
aa bb 


Analysis -- First task we have to check if we are doing
            partition then left string is palindrome
            or not,if yes then take the remaining right
            string and do recursion on the same.
            If not terminate will not go into if condition

            And base condition if partition is reached at the
            end of the string it means we got the partion in such a 
            way that all the strings in partition are palindrome.







*/




bool ispalindrome(string str,lli start,lli end)
{
	while(start<=end)
	{
		if(str[start++]!=str[end--])
			return false;
	}
	return true;
}


void findpartition(lli ind,string str,
	vector<string>&temp,vector<vector<string>>&ans)
{

if(ind==str.size())
{
	ans.push_back(temp);
	return;
	
}

   for(lli i=ind;i<str.size();++i)
   {
   	if(ispalindrome(str,ind,i))
   	{
   	temp.push_back(str.substr(ind,i-ind+1));
   	findpartition(i+1,str,temp,ans);
   	temp.pop_back();

}
   }

}



void paritionpalindrome(string str)
{
	

    vector<string>temp;
    vector<vector<string>>ans;

    findpartition(0,str,temp,ans);

    for(lli i=0;i<ans.size();i++)
    {
    	for(lli j=0;j<ans[i].size();j++)
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

	string str;
	cin>>str;

 paritionpalindrome(str);

}