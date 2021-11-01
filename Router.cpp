#include <iostream>
#include <string.h>
#include <random>
using namespace std;

class Node {
private:
	string addr;
	string device_name;
	Node* next;
	friend class Router;
};

class Router {
private:
	Node* ipTable;//Array of nodes that contain IP Adresses and point to devices
	int size;//IP Address range
	const string& getIPAddress(const string& nm) const;//Get IP Address at specified Index
	void addDevice(const string& nm);
	Router(int n);//Constructor
	~Router();//Destructor

};

Router::Router(int n) {
	ipTable = new Node[n];//Create Array of unused IP Addresses
	size = n;
	for (int i = 1; i <= n; i++) {
		ipTable[i].device_name = "None";//No devices connected when Router is created
		ipTable[i].next = NULL;//Make each IP Address Available
		ipTable[i].addr = "192.168.0." + (i+'0');//Assign IP Adress to corresponding index
	}
}

Router::~Router() {
	delete [] ipTable;//De-allocate memory that was allocated for array of IP Addresses
}

const string& Router::getIPAddress(const string& nm) const {
	for (int i = 0; i < size; i++) {
		if (ipTable[i].device_name.compare(nm) == 0) {//If device is found
			return  ipTable[i].addr;//Return IP Address
		}
	}
	return "NULL";//Device is not found
}

void Router::addDevice(const string& nm) {
	for (int i = 0; i < size; i++) {
		if (ipTable[i].device_name.compare("None") == 0) {//If a device has not been assigned IP Address at index 'i'
			ipTable[i].device_name = nm;//assign device 'nm' to IP Adress at index 'i' 
		}
	}

}
