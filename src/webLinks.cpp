/*
 * webLinks.cpp
 *
 *  Created on: Mar 22, 2021
 *      Author: eddy_
 */

#include "webLinks.h"

namespace std {

	ostream& operator << (ostream& s, webLinks& A)
	{
		s << A.URL << ": " << endl;
		for (int i = 0; i < A.numOutLinks; i++){
			s << "** " << A.hyperLinks[i]->URL << endl;
		}
		return s;
	}

	int webLinks::compareTo(webLinks* site){
		return this->URL.compareTo(site->URL);
	}

	int webLinks::getNumOfConections() {
		return this->numIncomingLinks;
	}

	webLinks* webLinks::getConnection(int i){
		return this->incomingLinks[i];
	}

	bool webLinks::isEqual(webLinks* site){
		return (&(*this) == &(*site));
	}

	webLinks::webLinks(){
		//cout << "entered default constructor for webLinks" << endl;
		hyperLinks = NULL;
		numOutLinks = 0;
		numIncomingLinks = 0;

		incomingLinks = new webLinks *[MAX_VAL_OF_CONNECTIONS];
		for (int i = 0; i < MAX_VAL_OF_CONNECTIONS; i ++) incomingLinks[i] = nullptr;
	}

	webLinks::webLinks(myString& x, int n){
		URL = x;
		numOutLinks = n;

		hyperLinks = new webLinks *[numOutLinks];
		for (int i = 0; i < n; i ++) hyperLinks[i] = nullptr;

		incomingLinks = new webLinks *[MAX_VAL_OF_CONNECTIONS];
		for (int i = 0; i < MAX_VAL_OF_CONNECTIONS; i ++) incomingLinks[i] = nullptr;

		numIncomingLinks = 0;
	}

	void webLinks::setURL(myString& url){
		//cout << "setting URL: " << url << endl;
		URL = url;
		//cout << URL << " SET...." << endl << endl;
	}

	myString& webLinks::getURL(){
		return URL;
	}

	int webLinks::getNumLinks()	{
		return numOutLinks;
	}

	webLinks* webLinks::getHyperLink(int i)	{
		return hyperLinks[i];
	}

	webLinks::~webLinks()	{
		//cout << "Deleting... " << endl;

			if (hyperLinks != NULL){
				//cout << "	Unlinking hyperlinks...." << endl;
				hyperLinks = NULL;
			}

			if (hyperLinks != NULL){
				//cout << "	Unlinking connections...." << endl;
				incomingLinks = NULL;
			}

			numIncomingLinks = 0;
			numOutLinks = 0;

			URL.~myString();

	}

	void webLinks::addSite(myString& t)	{
		setURL(t);
	}

	void webLinks::setNeighbors(int nei){
		numOutLinks = nei;
		hyperLinks = new webLinks *[numOutLinks];

		for (int i = 0; i < nei; i ++) hyperLinks[i] = nullptr;
	}

	void webLinks::pingConnection(webLinks*	link){
		//cout << "	Pinging: " << link->URL << "...." << endl;
		link->incomingLinks[link->numIncomingLinks] = this;
		link->numIncomingLinks += 1;
		//cout << " 	Succesfull connection" << endl;
	}

	void webLinks::addNeighbor(webLinks& link){
		for (int i = 0; i < numOutLinks; i++){
			//cout << "checking for space within the list... ";
			if (hyperLinks[i] == NULL){
				hyperLinks[i] = &link;
				//cout << "COMPLETE." << endl;

				pingConnection(hyperLinks[i]);

				break;
			}
		}

	}

} /* namespace std */
