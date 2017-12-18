#include "BST.h"
template<class t>
node<t>::node(t v)
{
	value = v;
	left = right = 0;
}
template<class t>
node<t>::node()
{
	value = 0;
	left = right = 0;
}

template<class t>
node<t>::~node()
{
	
}

template<class t>
BST<t>::BST()
{
	root = new node<t>;
	root->value = -1;
	root->left = root->right = 0;
}

template<class t>
void BST<t>::insrt(t v)
{
	node<t>* temp = root;
	node<t>*n = new node<t>(v);
	if (root->value == -1)
	{
		root->value = v;
		return;
	}
	while (temp!=0)
	{
		if (v > temp->value)
		{
			if (temp->right == 0)
			{
				temp->right = n;
				break;
			}
			else temp = temp->right;
		}
		else
		{
			if (temp->left == 0)
			{
				temp->left = n;
				break;
			}
			else  temp = temp->left;
		}
	}
	temp = n;
}

template<class t>
bool BST<t>::contains(t v)
{
	node<t>*temp = root;
	while (temp != 0)
	{
		if (v == temp->value)return 1;
		if (v > temp->value)temp=temp->right;
		else temp = temp->left;
	}
	return 0;
}

template<class t>
node<t>* BST<t>::findnode(t v)
{
	node<t>* temp = root;
	while (temp != 0)
	{
		if (v == temp->value)return temp;
		if (v > temp->value)temp = temp->right;
		else temp = temp->left;
	}
}

template<class t>
node<t>* BST<t>::findparent(t v)
{
	node<t>* temp = root;
	while (temp != 0)
	{
		if ((temp->right!= NULL&&temp->right->value == v) || (temp->left != NULL&&temp->left->value == v))return temp;
		if (v > temp->value)temp = temp->right;
		else temp = temp->left;
	}
}

template<class t>
void BST<t>::remove(t v)
{
	node<t>*nod = findnode(v);
	node<t>*p = findparent(v);
	if (nod == 0)
	{
		cout << "nothing to be done";
		return;
	}
	if(nod->left==0&&nod->right==0)
	{
		if (nod == root)
		{
			root = 0;
			return;
		}
		if (p->left == nod)p->left = 0;
		else p->right = 0;
		delete nod;
	}
	else if (nod->left == 0 && nod->right != 0)
	{
		if (p == 0)root = nod->right;
		if (p->left == nod)p->left = nod->right;
		else p->right = nod->right;
		delete nod;
	}
	else if (nod->left != 0 && nod->right == 0)
	{
		if (p == 0)root = nod->left;
		if (p->left == nod)p->left = nod->left;
		else p->right = nod->left;
		delete nod;
	}
	else
	{
		node<t>*p2,*mn;
		mn = findmin(nod->right);
		nod->value = mn->value;
		p2 = findparent(mn->value);
		if (p2 == nod)nod->right = mn->right;
		else p2->left = mn->right;
		delete mn;
	}
}

template<class t>
node<t>* BST<t>::findmin(node<t>* start)
{
	while (start->left != 0) { start = start->left;}
	return start;
}

template<class t>
void BST<t>::traverse()
{

}

template<class t>
BST<t>::~BST()
{
	delete root;
}
