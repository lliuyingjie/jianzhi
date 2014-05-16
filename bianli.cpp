void in_travel(BTree tree)
{

	if(tree == NULL) return;
	stack<BNode*> nodes;
	BNode* p = tree;
	while( p != NULL || !nodes.empty())
	{
		while(p != NULL)
		{
			nodes.push(p);
			p = p->left;
		}

	    if(!nodes.empty())
		{
			p = nodes.top();
			cout<<p->key<<endl;
			nodes.pop();
			p = p->right;
		}
	}
}
