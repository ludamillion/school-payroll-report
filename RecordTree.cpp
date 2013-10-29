// Implementation file for RecordTree class
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010
//

#include "RecordTree.h"

void RecordTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if (newNode->record < nodePtr->record)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

void RecordTree::insertNode(Payroll record)
{
	TreeNode *newNode;

	newNode = new TreeNode;
	newNode->record = record;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

void RecordTree::deleteNode(Payroll record, TreeNode *&nodePtr)
{
	if (record < nodePtr->record)
		deleteNode(record, nodePtr->left);
	else if (record > nodePtr->record)
		deleteNode(record, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

void RecordTree::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode* tempNodePtr;

	if (nodePtr == NULL)
		exit(1);
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		
		tempNodePtr->left = nodePtr->left;

		tempNodePtr = nodePtr;

		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

void RecordTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

// This takes care of most of the output for the report printing
void RecordTree::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << setprecision(2) << fixed;
		displayInOrder(nodePtr->left);
		cout << left << setw(5) << nodePtr->record.getID();
		cout << setw(11) << nodePtr->record.getLastName();
		cout << setw(10) << nodePtr->record.getFirstName();
		cout << right << nodePtr->record.getGross();
		cout << setw(9) << nodePtr->record.getFICA();
		cout << setw(9) << nodePtr->record.getFedTax();
		cout << setw(9) << nodePtr->record.getStateTax();
		cout << setw(9) << setfill(' ') << nodePtr->record.getInsurence();
		cout << setw(9) << nodePtr->record.getNetPay();
		cout << endl;
		displayInOrder(nodePtr->right);
	}
}

// This accumulates the total net pay for the department represented
// by the tree which represents the departments subtotal for each
// department in the final report
void RecordTree::accumulate(double &netTotal, TreeNode *nodePtr)
{
	if (nodePtr)
	{
		accumulate(netTotal, nodePtr->left);
		netTotal += nodePtr->record.getNetPay();
		accumulate(netTotal, nodePtr->right);
	}
}
