// Definition File for the RecordTree class
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010
//
// Comments on code in corresponding implementation file

#ifndef RECORDTREE_H
#define REDORDTREE_H

#include "Payroll.h"

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::left;
using std::right;
using std::setw;
using std::setfill;

class RecordTree
{
	struct TreeNode
	{
		Payroll record;
		TreeNode* left;
		TreeNode* right;
	};

	TreeNode* root;

private:
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(Payroll, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void accumulate(double &, TreeNode *);

public:
	RecordTree()
	{ root = NULL; }
	~RecordTree()
	{ destroySubTree(root); }

	void insertNode(Payroll);
	void displayInOrder() const
	{ displayInOrder(root); }
	void accumulateNet(double &net)
	{ accumulate(net, root); }
};
#endif

