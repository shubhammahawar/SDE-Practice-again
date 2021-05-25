#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Longest Substring Without Repeating Characters 


T.C = O(N)
S.C= O(N)

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "abcdcebffg"
Output: 5
Explanation: The answer is "abdcebf", with the length of 5.


Analysis - We will use the map and store the updated position o every 
           caharacter,and if character is already presnet in map
           it means it is repeating chaarcter and we will found 
           out the length of the current substring and compare it.


           */







lli LongestSubstringwithoutrepchar(string str)
{
	lli l=str.length(),i;
	unordered_map<char,lli>mp;
	lli pos=0,len=0;

	for(i=0;i<l;i++)
	{
         if(mp.find(char(str[i]))!=mp.end() )
         {
         
            pos=max(mp[char(str[i])]+1,pos);

        }
        mp[char(str[i])]=i;
        len=max(len,i-pos+1);



	}

	



	return len;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string str;
	cin>>str;

	lli ans=LongestSubstringwithoutrepchar(str);

	cout<<"Longest Substring without repeating character "<<"\n";
	cout<<ans<<"\n";
}