#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* Function for Flattening a Linked List 

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.


T.C = O(summation of all nodes)
S.C = O(1)

Input- 
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45

Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Analysis - we will consider 2-2 linked list and merge
           them into a single list until we have left with
           single list.
           At first we use recursion and traverse till last
           list and then taking last and second last list
           and merging them and returning root of merged list
           and doing the sam eprocess until get a single merged list


*/

Node*mergelist(Node*a,Node*b)
{
	Node*temp=new Node(0);
	Node*res=temp;


	while(a!=NULL && b!=NULL)
	{
		if(a->data<b->data)
		{
			temp->bottom=a;
			temp=temp->bottpm;
			a=a->bottom;
		}
		else
		{
			temp->bottom=b;
			temp=temp->bottom;
			b=b->bottom;
		}
	}

 if(a!=NULL)
 	temp->bottom=a;
 else
 	temp->bottom=b;


 return res->bottom;


}

 Node* flatten(Node*root)
 {
 	if(root==NULL || root->next==NULL)
 		return root;

 	root->next=flatten(root->next);

    root=mergelist(root,root->next);

    return root;


 }
