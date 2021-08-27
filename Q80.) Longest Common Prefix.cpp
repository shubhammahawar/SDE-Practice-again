 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

T.C = O(N*Length of smallest string)
S.C= O(1)

Input - 
5
apple app apps appap app

Output- app

Anlysis - we will run the outer loop to length of 1 string
          and inner loop for all the strings
          and compare every character of every string
          and if it not matched came out of the loop 
          and return the substring of longest common prefix



*/



void LongestCommonPrefix(vector<string>str)
{

  lli c=0;
	for(lli i=0;i<str[0].length();i++)
	{
		lli flag=1;
		for(lli j=0;j<str.size();j++)
		{
			if(str[0][i]!=str[j][i])
				{  flag=0;
				break;
			}
		}

		if(flag==0)
			break;
		c++;
	}

	cout<<"Longest Common prefix from given list of strings is\n";
	cout<<str[0].substr(0,c);
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

vector<string>str;

lli n,i;
cin>>n;


	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		str.push_back(s);
	}


//cout<<str<<"\n";
    LongestCommonPrefix(str);



}
