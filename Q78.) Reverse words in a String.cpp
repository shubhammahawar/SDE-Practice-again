 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/*

Reverse Words in a String

T.C= O(N)
S.C= O(1) // Inplace

Example--

Input: s = "  hello   world   "
Output: "world hello"


Analysis - First we will remove the leading sppaces
           Second will remove the trailing spaces
           Third will removed the inbetween spaces

           Then reverse the string and start from 0 and if 
           any space is encountered then its a word and reverse it
           At last apply reverse function one more time to reverse the last word


*/

void Reversewords(string str)
{

	cout<<"start str"<<str<<"\n";
	lli i,start,end,len=0,j=0;

	for(i=0;i<str.length();i++) // just increment i to ignore the leading spaces
	{
		if(str[i]!=' ')
			break;
	}
    start=i;

    for(i=str.length()-1;i>=0;i--) // just decrement i to ignore the trailing spaces
	{
    {
    	if(str[i]!=' ')
    		break;
    }
    end=i;

    for(i=start;i<=end;i++)
    {
    	if(str[i]==' ' && str[i-1]==' ') // removing the inbetween spaces
    		continue;

    	str[len++]=str[i];
    }
str.erase(str.begin()+len,str.end()); // erase anything after len cz that will be trailing spaces only

reverse(str.begin(),str.end());


for(i=0;i<str.length();i++)
{
    if(str[i]==' ')  // encountered a word so reverse it
    {
    	reverse(str.begin()+j,str.begin()+i);
    	j=i+1;
    }
}
reverse(str.begin()+j,str.end()); // to revers ethe last word
cout<<"String after the words are reversed "<<str<<"\n";





}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string str;
	getline(cin,str);

	Reversewords(str);
}