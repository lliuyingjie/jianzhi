#include<assert.h>
#include<iostream>
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;

struct BNode{
	int key;
	BNode* l_child;
	BNode* r_child;
};

typedef BNode* BTree;

BTree create()
{
	BNode* tree = new BNode();
	tree->key = 6;
	tree->l_child = NULL;
	tree->r_child = NULL;
}

BNode* new_node(int key)
{
	BNode* my_node = new BNode();
	my_node->key = key;
	my_node->l_child = NULL;
	my_node->r_child = NULL;
}

void jiagong(BTree& my_tree)
{
	my_tree->l_child = new_node(3);
	my_tree->r_child = new_node(4);
	my_tree->l_child->l_child = new_node(2);
	my_tree->l_child->r_child = new_node(4);
	my_tree->l_child->r_child->r_child = new_node(5);
	my_tree->r_child->l_child = new_node(7);
	my_tree->r_child->r_child = new_node(8);
}

void jiagong2(BTree& my_tree)
{
	my_tree->key = 3;
	my_tree->r_child = new_node(4);
	my_tree->r_child->r_child = new_node(5);
}

void pre_travel(BTree my_tree)
{
	stack<BNode*> nodes;
	if(my_tree != NULL) nodes.push(my_tree);
	BNode* x = NULL;
	while(!nodes.empty())
	{
		x = nodes.top();
		cout<<x->key<<" ";
		nodes.pop();
		if( x->r_child != NULL ) nodes.push(x->r_child);
		if( x->l_child != NULL ) nodes.push(x->l_child);

	}
	cout<<endl;
}

void printnode(int c, int h)
{
	int i;
	for(i = 0; i<h; i++) cout<<"   ";
	cout<<c<<endl;
}

void printnode(char c, int h)
{
	int i;
	for(i = 0; i<h; i++) cout<<"   ";
	cout<<c<<endl;
}

void show(BNode* x, int h)
{
	if(x == NULL)
	{
		printnode('*',h);
		return;
	}
	show(x->r_child,h+1);
	printnode(x->key,h);
	show(x->l_child,h+1);
}

void cen_travel(BTree my_tree)
{
	deque<BNode*> nodes;
	nodes.push_back(my_tree);
	BNode* p = NULL;
	while(!nodes.empty())
	{
		p = nodes.front();
		cout<<p->key<<" ";
		nodes.pop_front();
		if(p->l_child != NULL) nodes.push_back(p->l_child);
		if(p->r_child != NULL) nodes.push_back(p->r_child);
	}
	cout<<endl;

}

void in_travel(BTree& my_tree)
{
	if(my_tree == NULL) return;
	stack<BNode*> nodes;
	BNode* p = my_tree;
	while(p != NULL || !nodes.empty())
	{
		while(p != NULL)
		{
			nodes.push(p);
			p = p->l_child;
		}
		
		if(!nodes.empty())
		{
			p = nodes.top();
			cout<<p->key<<" ";
			nodes.pop();
			p = p->r_child;
		}
	}
	cout<<endl;
}

void post_travel(BTree& my_tree)
{
	if(my_tree == NULL) return;
	stack<BNode*> nodes;
	BNode* cur = NULL;
	BNode* pre = NULL;

	nodes.push(my_tree);
	while(!nodes.empty())
	{
		cur = nodes.top();
		if( (cur->l_child == NULL && cur->r_child==NULL) || (pre!=NULL&&( (pre == cur->l_child) ||( pre == cur->r_child) )) )
		{
			cout<<cur->key<<" ";
			nodes.pop();
			pre = cur;
		}
		else
		{
			if(cur->r_child != NULL) nodes.push(cur->r_child);
			if(cur->l_child != NULL) nodes.push(cur->l_child);
		}

	}
	cout<<endl;
}

void image_tree(BTree& my_tree)
{
	if(my_tree == NULL) return;
	BNode* tmp = my_tree->l_child;
	my_tree->l_child = my_tree->r_child;
	my_tree->r_child = tmp;

	if(my_tree->l_child != NULL) image_tree(my_tree->l_child);
	if(my_tree->r_child != NULL) image_tree(my_tree->r_child);
}

bool if_equal(BNode* goal, BNode* me);

bool find_mini(BTree my_tree, BTree mini)
{
	if(mini == NULL) return true;
	if(my_tree == NULL) return false;

	bool result = false;
	if(my_tree->key == mini->key)
		result = if_equal(my_tree->l_child, mini->l_child)&&if_equal(my_tree->r_child, mini->r_child);
	if(!result) result = find_mini(my_tree->l_child, mini);
	if(!result) result = find_mini(my_tree->r_child, mini);

}

bool if_equal(BNode* goal, BNode* me)
{
	if(me == NULL) return true;
	if(goal == NULL) return false;

	if(goal->key == me->key)
		return if_equal(goal->l_child, me->l_child)&&if_equal(goal->r_child, me->r_child);
	else
		return false;
}

void findpath(BNode* my_node, vector<BNode*>& nodes, int goal);

void findpath(BTree my_tree, int sum)
{
	if(my_tree == NULL || (sum < my_tree->key)) return;
	vector<BNode*> nodes;
	findpath(my_tree,nodes,sum);
}

void findpath(BNode* my_node, vector<BNode*>& nodes, int goal)
{
	nodes.push_back(my_node);
	goal -= my_node->key;

	if(goal == 0) 
	{
		for(vector<BNode*>::iterator i = nodes.begin(); i != nodes.end(); i++)
			cout<<(*i)->key<<" ";
		cout<<endl;
	}

	if(goal > 0)
	{
		if(my_node->l_child != NULL)
			findpath(my_node->l_child,nodes,goal);
		if(my_node->r_child != NULL)
			findpath(my_node->r_child,nodes,goal);
	}

	nodes.pop_back();
}

bool isbalanced(BTree my_tree, int& depth)
{
	if(my_tree == NULL)
	{
		depth = 0;
		return true;
	}

	int left,right;
	if(isbalanced(my_tree->l_child,left)&&isbalanced(my_tree->r_child,right))
	{
		int dif = abs(left-right);

		if(dif == 0) 
		{
			depth = left+1;
			return true;
		}
		else
		{
			depth = left>right?(left+1):(right+1);
			return false;
		}
	}

}

void convernode(BNode* node, BNode*& last_node)
{
	if(node==NULL) return;

	if(node->l_child != NULL)
		convernode(node->l_child,last_node);

	if(last_node != NULL)
		last_node->r_child = node;
	node->l_child = last_node;
	last_node = node;

	if(node->r_child != NULL)
		convernode(node->r_child,last_node);
}

BNode* convertlist(BNode* my_tree)
{
	if(NULL == my_tree) return NULL;

	BNode* node_last = NULL;
	
	convernode(my_tree,node_last);

	while(node_last->l_child != NULL)
		node_last = node_last->l_child;

	return node_last;
}

void the_hou_bianli(BNode* tree) //又写了一帮遍
{
	assert(tree!=NULL);
	BNode* pre = tree;
	BNode* cur = tree;
	stack<BNode*> nodes;
	nodes.push(cur);
	while(!nodes.empty())
	{
		cur = nodes.top();
		if( (cur->l_child == NULL && cur->r_child == NULL) || (pre == cur->l_child || pre == cur->r_child) )
		{
			cout<<cur->key<<endl;
			pre = cur;
			nodes.pop();
		}else{

			if(cur->r_child != NULL) nodes.push(cur->r_child);
			if(cur->l_child != NULL) nodes.push(cur->l_child);
		}
	}
}

void the_zhong_bianli(BNode* tree) //又写了一遍
{
	stack<BNode*> nodes;

	BNode* p = tree;
	while( p != NULL || !nodes.empty())
	{
		while( p != NULL)
		{
			nodes.push(p);
			p = p->l_child;
		}

		if( p == NULL)
		{
			p = nodes.top();
			cout<<p->key<<" ";
			p = p->r_child;
			nodes.pop();
		}

	}

}

void convertnode(BNode* node, BNode*& plast)
{

	assert( node!= NULL );

	if(node->l_child != NULL)
		convertnode(node->l_child, plast);

	if(plast != NULL)
	{
		plast->r_child = node;
	}

	node->l_child = plast;

	plast = node;

	if(node->r_child != NULL)
		convertnode(node->r_child, plast);
}

BNode* treeToList(BNode* tree)
{
	assert(tree != NULL);
	BNode* plast = NULL;
	convertnode(tree,plast);

	while(plast->l_child != NULL)
		plast = plast->l_child;

	return plast;
}


void my_print(vector<int>& path)
{
	for(vector<int>::iterator i = path.begin(); i != path.end(); i++)
		cout<<(*i)<<" ";

	cout<<endl;
}
void printpath(BNode* node, vector<int>& path, int goal)
{


	path.push_back(node->key);
	if(goal == node->key) 
	{

		my_print(path);
	}

	if(goal < node->key ) 
	{

		return;
	}
	

	if(node->l_child != NULL)
		printpath(node->l_child, path, goal - node->key);

	if(node->r_child != NULL)
		printpath(node->r_child, path, goal - node->key);

	path.pop_back();

}

void new_findpath(BNode* tree, int goal)
{
	assert(tree!=NULL);
	vector<int> path;
	
	printpath(tree,path,goal);
}

int depth(BNode* tree)
{
}

int main(){

	BTree my_tree = create();
	jiagong(my_tree);
	BTree mini_tree = create();
	jiagong2(mini_tree);

//	pre_travel(my_tree);

	show(my_tree,0);

//	the_hou_bianli(my_tree);

//	the_zhong_bianli(my_tree);
//	cout<<endl;
//	show(mini_tree,0);
//	in_travel(my_tree);
//	post_travel(my_tree);

//	findpath(my_tree,18);

//	cen_travel(my_tree);
//	image_tree(my_tree);
//	show(my_tree,0);

//	BNode* plist = convertlist(my_tree);

	new_findpath(my_tree,18);
	BNode* plist = treeToList(my_tree);
	while(plist != NULL)
	{
		cout<<plist->key<<" ";
		plist = plist->r_child;
	}
	cout<<endl;

	return 0;

}
