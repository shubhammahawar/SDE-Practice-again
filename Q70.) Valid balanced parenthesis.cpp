#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Check string having balanced parenthesis or not

T.C = O(N)
S.C = O(N)

Example -

Input - {([])}
Output - Blanced parenthesis.

Input- [()
Output - Unbalanced parenthesis.


ANALYSIS - We will be using Stack for this.
           if its a opening bracket we simply push into the
           stack
           If its a closed bracket we will check if the top of the
           stack has its opposite bracket and if it is then its ok
           otherwise unbalanced.
           ALSO at the end check if stack is empty or not to return true
                      


*/

bool isValid(string s) {
        
        stack<lli>st;
        
        for(lli i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]== '{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            
            else
            {
                if(st.empty())
                    return false;
                
                else
                {
                    char c=st.top();
                    
                    if ( (s[i]==')' && c=='(' ) || (s[i]=='}' && c=='{' ) ||
                        (s[i]==']' && c=='[' ) )
                    {
                        st.pop();
                    }
                    else
                        return false;
                }
            }
        }
        if(st.empty())
            return true;
        
        return false;           

    }


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	cin>>s;


	lli ans=isValid(s);

	if(ans)
		cout<<"string is balanced parenthesis\n";
	else
		cout<<"string is not balanced parenthesis\n";

}

