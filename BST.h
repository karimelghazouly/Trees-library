#pragma once
template<class t>
class node
{
	public:
		t value;
		node<t>* left, *right;
		node();
		node(t);
		~node();
	
};

template<class t>
class BST
{
	node<t> * root;
	public:
		BST();
		bool contains(t);
		void remove(t);
		void insrt(t);
		void traverse();
		~BST();
	private:
		node<t> *findnode(t);
		node<t> *findparent(t);
		node<t> *findmin(node<t>*);
};

