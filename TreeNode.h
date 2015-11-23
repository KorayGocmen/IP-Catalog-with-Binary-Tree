#ifndef TREENODE_H
#define	TREENODE_H

#include <string>
#include <iostream>

#include "DBentry.h"

using namespace std;

class TreeNode {
    
private:
	DBentry* entryPtr;
	TreeNode* left;
	TreeNode* right;
    
public:
	TreeNode();
    
	TreeNode(DBentry* _entryPtr);    
    
	~TreeNode();    
    
	void setLeft(TreeNode* newLeft);
    
	void setRight(TreeNode* newRight);    
    
	TreeNode* getLeft() const;    
    
	TreeNode* getRight() const;    
    
	DBentry* getEntry() const;
    
	//-------------------MY FUNCTIONS-------------------------
    
	bool insertNode(TreeNode* &root, DBentry* newEntry);
    
	DBentry* searchNode(TreeNode* root, string name);
    
	bool removeNode(TreeNode* &root, string name);
    
	TreeNode* findMax();
    
	int countActive(TreeNode* root);
    
	void printProbesNode(TreeNode* root, string name, int count);
    
	void clearNodes(TreeNode* &root);
    
	void printNodes();
    
	void copyDBentry(DBentry* newEntry);
    
	void deleteNode();

};

#endif	/* TREENODE_H */
