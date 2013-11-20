/*
 *Author: Yuchao Zhou
 *Time: 11/18/2013
 */
#ifndef WORKSPACE_HASHENTRY_H
#define WORKSPACE_HASHENTRY_H

#include <string>

using namespace std;

class HashEntry {
private:
      int key;
      string value;
	  bool exist;
public:
      HashEntry(int key, string value, bool exist) {
            this->key = key;
            this->value = value;
			this->exist = exist;
      }
 
      int getKey() 
	  {
            return key;
      }
 
      string getValue() 
	  {
            return value;
      }

	  bool getExist()
	  {
		  return exist;
	  }

};
#endif