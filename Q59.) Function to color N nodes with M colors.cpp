#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* Function to solve M- Coloring node 

The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color

T.C = O(N^m) // i.e for N nodes we are trying M colors.

S.C = O(N)+O(N)

O(N)// for colorbox array and 
O(N)// for auxiliary space m=1,2,3,,,,


Analysis - We will traverse through all the colors starting
           from col=1 ...to...col=m and if there is possibility
           to color any node with col color it.
           and traverse through next node and if reached node==N
           it means in the given path we traverse all the nodes and
           color them such that no adjacent nodes have same color
           But if do not reaches to N it means unable to color nodes
           with different colors.
           




*/

bool colornode(lli node,lli graph[101][101],lli m,lli V,lli col)
{
	for(lli k=0;k<V;k++)
	{
		if(k!=node && graph[k][node]==1 && color[k]==col)
			return false;
	}
	return true;
}




bool solve(lli node,bool graph[101][101],lli m,lli V,lli colorbox[])
{
	if(node==V)
		return true;
 
 for(lli col=1;col<=m;col++)
 {
 	if(colornode(node,graph,m,V,colorbox,col))
 	{
 		colorbox[node]=col;

 		if(solve(node+1,graph,m,V,colorbox)==true)
 			return true;

 		colorbox[node]=0;
 	}
 }
 return false;

}



bool graphColoring(bool graph[101][101], lli m, lli V)
{
	lli colorbox[V]=0;

	if(solve(0,graph,m,V,colorbox))
		return true;

	return false;
}
