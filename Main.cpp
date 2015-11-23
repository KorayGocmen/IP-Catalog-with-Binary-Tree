#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "TreeDB.h"

using namespace std;

int main() {
    
	string line, command;

	cout << "> ";    
	getline(cin, line);
    
	TreeDB* tree = new TreeDB;
	DBentry *newEntry;
    
	while(!cin.eof()){
 	 
    	stringstream lineStream (line);
   	 
    	lineStream >> command;
   	 
    	if(command == "insert"){
      	 
        	string dbNewName;
        	unsigned int dbNewIP;
        	string dbNewStatusValue;
        	bool dbNewStatus;
       	 
        	//get the values
        	lineStream >> dbNewName;
        	lineStream >> dbNewIP;
        	lineStream >> dbNewStatusValue;
       	 
        	//change the status to boolean
        	if(dbNewStatusValue == "active")
            	dbNewStatus = true;
        	else
            	dbNewStatus = false;
  	 
        	newEntry = new DBentry(dbNewName,dbNewIP,dbNewStatus);
       	 
        	bool ableToAddNode = tree->insert(newEntry);
       	 
        	if(!ableToAddNode){
            	//it already exists
            	cout<<"Error: entry already exists"<<endl;
        	}else{
            	//we added it
            	cout<<"Success"<<endl;
        	}
  	 
    	}//end of insert
   	 
 
    	else if(command == "find"){
       	 
        	string findName;
       	 
        	lineStream >> findName;
       	 
        	DBentry* foundEntry = tree->find(findName);
       	 
        	if(foundEntry == NULL){
            	//entry is not found
            	cout<<"Error: entry does not exist"<<endl;
        	}else{
            	//we found it, we need to print
            	foundEntry->print();           	 
        	}
       	 
        	foundEntry=NULL;
    	}//end of find
   	 
   	 
    	else if(command == "remove"){
   	 
        	string findName;
       	 
        	lineStream >> findName;
       	 
        	DBentry* foundEntry = tree->find(findName);
       	 
        	if(foundEntry == NULL){
            	//entry is not found
            	cout<<"Error: entry does not exist"<<endl;
        	}else{
            	//we found it
            	cout<<"Success"<<endl;
            	tree->remove(findName);
        	}
        	foundEntry=NULL;
    	}//end of remove
   	 
    	else if(command == "printall"){
       	 
        	tree->print();
       	 
    	}//end of printall
   	 
   	 
    	else if (command == "printprobes"){
       	 
        	string findName;
       	 
        	lineStream>>findName;
       	 
        	tree->printProbes(findName);//does the printing for you
    	}//end of printprobes
   	 
    	else if(command == "removeall"){
 
        	tree->clear();
        	cout<<"Success"<<endl;
       	 
    	}//end of removeall
   	 
    	else if(command == "countactive"){
     	 
        	tree->countActive();//does the printing
       	 
    	}//end of countactive
   	 
    	else if(command == "updatestatus"){
       	 
        	string findName;
        	string dbNewStatusValue;
        	bool dbNewStatus;
       	 
        	//get the values
        	lineStream >> findName;
        	lineStream >> dbNewStatusValue;
       	 
        	//change the status to boolean
        	if(dbNewStatusValue == "active")
            	dbNewStatus = true;
        	else
            	dbNewStatus = false;
       	 
        	DBentry* foundEntry = tree->find(findName);
       	 
        	if(foundEntry == NULL){
            	//couldn't find it
            	cout<<"Error: entry does not exist"<<endl;
        	}else{
            	//found it, going to update it
            	foundEntry->setActive(dbNewStatus);
            	cout<<"Success"<<endl;           	 
        	}
        	foundEntry=NULL;
    	}//end of updatestatus
   	 
    	cout << "> ";
    	getline(cin, line);
   	 
	}
    
	delete tree;
	delete newEntry;

	return 0;
}
