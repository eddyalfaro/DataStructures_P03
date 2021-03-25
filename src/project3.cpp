#include<iostream>
using namespace std;

#include "webLinks.h"
#include "myString.h"

// used to empty a given string A of length n
void emptyString (char* A, int n) {
	for (int i=0; i < n; i++) {//runs throught the array of char and places \0 as value
		A[i] = '\0';
	}
}

// get one token from redirected input and return that string (alphanumeric)
char* getNextToken () {
	char* str = new char[30]; //assumes a max token size of 20
	emptyString(str, 30);

	char c;
	int i = 0;
	while (!cin.eof()) {
		cin.get(c);
		if (!cin.eof ()) {
			if ((c != '\n') && (c != ' ')) {
				if ( ((c >= 'a') && (c <= 'z')) ||
					 ((c >= 'A') && (c <= 'Z')) ||
					 ((c >= '0') && (c <= '9'))
					  //|| (c == '.') || (c == '-')
					 )
					str[i++] = c;
			}
			else if ((c == '\n') && (i > 0)) return str;
			else if ((c == ' ') && (i > 0)) return str;
		}
	}
	if (i > 0) return str;
	else return NULL;
}

int main(){

	int numSites;
	int siteNo;
	int numNeighbors;
	int neighbor;

	char* token;
	myString* tokenString;

	cin >> numSites;
	cout << "Number of websites: " << numSites << endl;

	webLinks* myWeb = new webLinks [numSites];

	tokenString = new myString[numSites];

	for (int i=0; i < numSites; i++)
	{
		token = getNextToken();
		tokenString[i] = token;
		//cout << tokenString[i] << endl;

		//cout << "read URL: " << tokenString[i] << endl;

		myWeb[i].setURL(tokenString[i]);
	}

	// store the neighbours/hyperlinks
	//cout << "linking sites to their hyperlinks..." << endl;
	for (int i = 0; i < numSites; i++)
	{
		cin >> siteNo >> numNeighbors;
		//cout << "Site: " << myWeb[i].getURL() << ", has " << numNeighbors << " links" << endl;
		//cout << "Conecting to... " << endl;
		myWeb[i].setNeighbors(numNeighbors);

		for (int j=0; j < numNeighbors; j++)
		{
			cin >> neighbor;
			//cout << (j + 1) << ". " << myWeb[neighbor].getURL() << ".....  ";
			myWeb[siteNo].addNeighbor ((myWeb[neighbor]));
		}

		//cout << endl;
	}

	// display all webLink objects using the overloaded << operator
	cout << "~~~~~WebLinks: " << endl;
	for (int i = 0; i < numSites; i++){
		cout << myWeb[i] << endl;
	}

	int connections;

	cout << "~~~~~Webpages contained as hyperLinks:" << endl;
	// display all the incoming nodes here
	for (int i = 0; i < numSites; i++){
		connections = myWeb[i].getNumOfConections();
		cout << myWeb[i].getURL() << ": " << connections << endl;

		for (int j = 0; j < connections; j ++)
			cout << "** " << myWeb[i].getConnection(j)->getURL() << endl;

		cout << endl;
	}

	delete [] myWeb;

	return 0;
}
