#ifndef TREE_H
#define TREE_H
#include<stdio.h>
struct node{
	int key;
	node* l;
	node* r;
};

typedef node* tree;

node* create_node(int key)
{
	node* new_node = new node();
	new_node->key = key;
	new_node->l = NULL;
	new_node->r = NULL;
	return new_node;
}

void connect_node(node* parent,node* left,node* right)
{
	if(parent != NULL)
	{
		parent->l = left;
		parent->r = right;
	}
}

void simple_build(tree& my_tree)
{
	my_tree = create_node(6);
	node* l = create_node(4);
	node* r = create_node(5);
	connect_node(my_tree,l,r);

	l = create_node(3);
	connect_node(my_tree->l,l,NULL);
	r = create_node(2);
	connect_node(my_tree->l->l,NULL,r);

}

int depth(tree& my_node)
{	
	if(my_node == NULL)
		return 0;
	int left = depth(my_node->l);
	int right = depth(my_node->r);
	return (left>right)?(left+1):(right+1);
}

#endif
