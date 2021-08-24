 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Longest Palindrome Substring-

T.C = O(N*N)
S.C= O(1)

Example - 
I/p- aaaabbaa
O/p - aabbaa

Analysis - We will separatly handle the even and odd length
           substring
           first we consider a substring and check if 
           it is palindrome then we will expland its left and right
           using left-- & right++ and caluclate the maximum length



*/


void LongestPalindrome(string str)
{
	lli l=str.length(),i,low,high,pos=0,len=1;


	for(i=1;i<l;i++)
	{
		low=i-1;
		high=i;

		while(low>=0 && high<l && str[low]==str[high])
		{
			if((high-low+1)>len)
			{
				len=high-low+1;
				pos=low;
			}
			low--;
			high++;
		}

		low=i-1;
		high=low+1;

		while(low>=0 && high<l && str[low]==str[high])
		{
			if( (high-low+1)>len)
			{
				len=high-low+1;
				pos=low;
			}
			low--;
			high++;
		}
	}
    
//cout<<"sas";
   cout<<"longest palindromic string\n";
    cout<<str.substr(pos,len);

}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string str;
	
    cin>>str;
//cout<<str<<"\n";
    LongestPalindrome(str);

}