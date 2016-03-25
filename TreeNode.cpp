#include "TreeNode.h"
#include "TreeDB.h"

class TreeNode;

TreeNode::TreeNode() {}

TreeNode::TreeNode(DBentry* _entryPtr){
	entryPtr = _entryPtr;
	left = NULL;
	right = NULL;
}

TreeNode::~TreeNode(){
    
	if(entryPtr != NULL){
    		delete entryPtr;
	}
	entryPtr = NULL;
    
	if(left != NULL){
    		delete left;
	}
	left = NULL;
    
	if(right != NULL){
    		delete right;
	}
	right = NULL;
    
}

void TreeNode::setLeft(TreeNode* newLeft){
	left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight){
	right = newRight;
}

TreeNode* TreeNode::getLeft() const{
	return left;
}

TreeNode* TreeNode::getRight() const{
	return right;
}

DBentry* TreeNode::getEntry() const{
	return entryPtr;
}

bool TreeNode::insertNode(TreeNode* &root, DBentry* newEntry){
    
	if((root->getEntry()->getName()) > newEntry->getName()){
	    	//go left
	    	if(left != NULL)
	        	left->insertNode(left, newEntry);
	    	else{
	        	TreeNode* newNode = new TreeNode(newEntry);
	        	root->setLeft(newNode);
	        	return true;
	        	//////////////////
	        	delete newNode;
	    	}
	}
	else if((root->getEntry()->getName()) < newEntry->getName()){
    	//go right
	    	if(right != NULL)
	        	right->insertNode(right, newEntry);
	    	else{
	        	TreeNode* newNode = new TreeNode(newEntry);
	        	root->setRight(newNode);
	        	return true;
	        	//////////////////
	        	delete newNode;
	    	}
	}
	else{
	    	//already exists
	    	return false;
	}
}

DBentry* TreeNode::searchNode(TreeNode* root, string name){
    
	if((root->getEntry()->getName()) == name){
	    	//found it
	    	return (root->getEntry());
	}
    
    
	if((root->getEntry()->getName()) > name){
	    	//go left
	    	if(left != NULL)
	        	return(left->searchNode(left, name));
	    	else
	        	return NULL;
	}
	else if((root->getEntry()->getName()) < name){
	    	//go right
	    	if(right != NULL)
	        	return(right->searchNode(right, name));
	    	else
	        	return NULL;
	}
    
}

TreeNode* TreeNode::findMax(){
    
	if(this->right!=NULL){
    		this->right->findMax();
	}
	else{
    		return(this);
	}
}

bool TreeNode::removeNode(TreeNode* &root, string name){
    
	if((root->getEntry()->getName()) > name){
	    	if(left!=NULL){
	        	left->removeNode(left, name);
	    	}
    		return false; //couldn't find him
	}
	else if((root->getEntry()->getName()) < name){
	    	if(right!=NULL){
	        	right->removeNode(right, name);
	    	}
	    	return false;
	}

	//we found the key
	if(left==NULL && right==NULL){
	    	//it is a leaf
	    	root = NULL;
	    	this->deleteNode();
	    	return true;
	}
	if(left==NULL && right!=NULL){
	    	//it has only one child
	    	root=right;
	    	this->deleteNode();
	    	return true;
	    	right=NULL;
	}
	if(left!=NULL && right==NULL){
	    	//it has only one child
	    	root=left;
	    	this->deleteNode();
	    	return true;
	    	left=NULL;
	}

	//it has two child
    
	TreeNode* leftMax = left->findMax();
	DBentry* leftMaxEntry = leftMax->getEntry();
	string nameOfLeftMax = leftMaxEntry->getName();
    
	this->copyDBentry(leftMaxEntry);
    
	//we need to delete the left max node
	left->removeNode(left, nameOfLeftMax);
    
	return true;
    
	leftMax=NULL;
	leftMaxEntry=NULL;
    
}

int TreeNode::countActive(TreeNode* root){
    
	int countRight=0, countLeft=0;
    
	if(left!=NULL){
    		countLeft=left->countActive(left);
	}
	if(right!=NULL){
    		countRight=right->countActive(right);
	}
    
	if(this->getEntry()->getActive())
    		return (1+countRight+countLeft);
	else
    		return(countRight+countLeft);
}

void TreeNode::printProbesNode(TreeNode* root, string name, int count){
    
	if((root->getEntry()->getName()) == name){
	    	cout<<count<<endl;
	    	return;
	}
	else if((root->getEntry()->getName()) > name){
	    	//go left
	    	count++; //we used a probe
	    	if(left!=NULL){
	        	left->printProbesNode(left, name, count);
	    	}else{
	        	//couldn't find him
	        	cout<<"Error: entry does not exist"<<endl;
	        	return;
	    	}	 
	}
	else if((root->getEntry()->getName()) < name){
	    	//go right
	    	count++; //we used a probe
	    	if(right!=NULL){
	        	right->printProbesNode(right, name,count);
	    	}else{
	        	//couldn't find him
	        	cout<<"Error: entry does not exist"<<endl;
	        	return;
	    	}
	}
}

void TreeNode::clearNodes(TreeNode* &root){
    
	delete root;
    
	return;
}

void TreeNode::printNodes(){
    
	if(left!=NULL)
    		left->printNodes();
    
	this->getEntry()->print();
    
	if(right!=NULL)
    		right->printNodes();
    
}

void TreeNode::copyDBentry(DBentry* newEntry){
	
	this->getEntry()->setName(newEntry->getName());
	this->getEntry()->setIPaddress(newEntry->getIPaddress());
	this->getEntry()->setActive(newEntry->getActive());
	return;
}

void TreeNode::deleteNode(){
    
	if(entryPtr!=NULL)
    		delete entryPtr;
	entryPtr=NULL;
	
	return;
}
