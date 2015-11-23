#include "TreeDB.h"

class TreeDB;

TreeDB::TreeDB(){
	root = NULL;
	probesCount = 0;
}

TreeDB::~TreeDB(){
	if(root!=NULL)
    	delete root;
	root = NULL;
}

TreeNode* TreeDB::getRoot(){
	return root;
}

void TreeDB::setRoot(TreeNode* _root){
	root = _root;
}

bool TreeDB::insert(DBentry* newEntry){
	if(root==NULL){
    	TreeNode *newNode = new TreeNode(newEntry);
    	root = newNode;
    	return true;
    	//////////////////
    	delete newNode;
	}else{
    	return (root->insertNode(root, newEntry));
	}
}

DBentry* TreeDB::find(string name){
	if(root==NULL)
    	return NULL;
	else{
    	DBentry* returner = root->searchNode(root, name);
    	return(returner);
   	 
    	returner=NULL;
	}
}

bool TreeDB::remove(string name){
	if(root==NULL)
    	return false;
	else{
    	return(root->removeNode(root, name));
	}
}

void TreeDB::clear(){
	if(root==NULL)
    	return;
	else{
    	root->clearNodes(root);
    	root=NULL;
    	return;
	}
    
}

void TreeDB::printProbes(string name) const{
	if(root==NULL){
    	cout<<"Error: entry does not exist"<<endl;
    	return;
	}else{
    	root->printProbesNode(root, name, 1);
    	return;
	}
}

void TreeDB::countActive() const{
	if(root==NULL){
    	cout<<"0"<<endl;
    	return;//empty
	}else{
    	//not empty
    	int activeNum = root->countActive(root);
    	cout<<activeNum<<endl;
    	return;
	}
}

void TreeDB::print(){
    
	if(root == NULL){
    	return;
	}else{
    	root->printNodes();
	}
}
