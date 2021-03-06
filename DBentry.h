#ifndef DBENTRY_H
#define	DBENTRY_H

#include <string>
#include <iostream>

using namespace std;

class DBentry{
    
private:
	string name;
	unsigned int IPaddress;
	bool active;
    
public:
	DBentry();
    
	DBentry(string _name, unsigned int _IPaddress, bool _active);    
    
	~DBentry();    
    
	void setName(string _name);    
    
	void setIPaddress(unsigned int _IPaddress);
    
	void setActive(bool _active);    
    
	string getName() const;    
    
	unsigned int getIPaddress() const;    
    
	bool getActive() const;    
    
	void print();
};

#endif	/* DBENTRY_H */
