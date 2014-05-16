#include<iostream>
#include"tree.h"
using namespace std;

bool if_balance(tree& node, int& x)
{
	if(node==NULL)
	{
		x = 0;
		return true;
	}

	int left,right;
	if(if_balance(node->l,left)&&if_balance(node->r,right))
	{
		int dif= left-right;
		if( dif<=1&&dif>=-1)
		{
			x = 1+ ((left>right)?left:right);

			cout<<x<<endl;
			return true;
		}

	}

	return false;
}

bool judge_balance(tree& my_tree)
{
	int x = 0;

	return if_balance(my_tree,x);
}

int main(){

	tree my_tree = NULL;
	simple_build(my_tree);

	cout<<depth(my_tree)<<endl;

	if(!judge_balance(my_tree))
		cout<<"fuck"<<endl;

	return 0;
}
