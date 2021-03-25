/*
 * webLinks.h
 *
 *  Created on: Mar 22, 2021
 *      Author: eddy_
 */

#ifndef WEBLINKS_H_
#define WEBLINKS_H_
#include "myString.h"

namespace std {

class webLinks {

	friend ostream& operator << (ostream& s, webLinks& A);

		protected:
			myString URL;
			int numOutLinks;
			int numIncomingLinks;

			const int MAX_VAL_OF_CONNECTIONS = 20;

			webLinks** hyperLinks;
			webLinks** incomingLinks;

		public:
			webLinks ();//default constructor
			webLinks (myString& x, int n);//construct a link to a site
			~webLinks ();//deletes all the references to links and hyperlink

			int getNumLinks();//returns the number of links of a given site
			int compareTo(webLinks* site);//compares two websites by their URL
			int getNumOfConections();//returns the number of incoming connections to this site

			bool isEqual(webLinks* site);//compares two websites by their location in memory

			webLinks* getHyperLink(int i);//returns the hyperlink in position i of the current site
			webLinks* getConnection(int i);//returns the site that has this site has a hyperlink in position i
			myString& getURL();//returns the URL of the current site

	        void addSite(myString& t);//adds a site to the list of sites listed
			void addNeighbor(webLinks& link);//adds the hyperlinks present in the current site
	        void setNeighbors(int nei);//sets the size of the numbers of hyperlinks referenced in the current site
	        void setURL(myString& url); //sets the URL for the given link
	        void pingConnection(webLinks* link); //pings the hyperlink if it is no from the same site that it is being called and increments the number of incomming conections

};

} /* namespace std */

#endif /* WEBLINKS_H_ */
