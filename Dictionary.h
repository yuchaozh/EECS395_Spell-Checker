/*
 *Author: Yuchao Zhou
 *Time: 11/18/2013
 */
#ifndef WORKSPACE_HASHTABLE_H
#define WORKSPACE_HASHTABLE_H

#include "HashEntry.h"

const int TABLE_SIZE = 69997;
const int TABLE_R = 66529;

class Dictionary {
private:
      HashEntry **table;
public:
	  //constructor
      Dictionary() {
            table = new HashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }

	  //destructor
      ~Dictionary() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL)
                        delete table[i];
            delete[] table;
      }

	  //hash function
	  unsigned int hashCode(const char*p, int len)
	  {
		  unsigned int h = 0;
		  for (int i = 0; i < len; i++)
		  {
			  h = (h<<5)||(h>>27);
			  h += (unsigned int) p[i];
		  }
		  return h;
	  }
 
	  //lookup
      bool lookup(string value) {
		  //cout<<"word looking for"<<value;
          int key1 = 0;
		  int key2 = 0;
		  int stringLength = value.size();
		  const char* str = value.c_str();
		  key1 = hashCode(str, stringLength) % TABLE_SIZE;
		  //cout<<"key1: "<<key1<<endl;
		  key2 = TABLE_R - (hashCode(str, stringLength) % TABLE_R);
		  //cout<<table[key1]->getValue()<<endl;
		  while (table[key1] != NULL)
		  {
			  //cout<<(table[key1]!= NULL)<<endl;
			  if (table[key1]->getExist() == false || table[key1]->getValue() != value)
			  {
				 key1 = (key1 + key2) % TABLE_SIZE;
				 //cout<<table[key1]->getValue()<<endl;
			  }
			  else
			  {
				  //cout<<"find it"<<table[key1]->getValue()<<endl;
				  return true;
			  }
		  }
		  return false;
      }
 
	  //insert
      void add(string value) {
		  int key1 = 0;
		  int key2 = 0;
		  int stringLength = value.size();
		  const char* str = value.c_str();
		  key1 = hashCode(str, stringLength) % TABLE_SIZE;
		  //cout<<key1<<endl;
		  key2 = TABLE_R - (hashCode(str, stringLength) % TABLE_R);
		  while (table[key1] != NULL && table[key1]->getValue() != value)
		  {
			  key1 = (key1 + key2) % TABLE_SIZE;
		  }
		  //cout<<key1<<endl;
		  table[key1] = new HashEntry(key1, value, true);
		  //cout<<table[key1]->getValue()<<endl;
      }     

	  void remove(string value)
	  {
		 //cout<<"word looking for"<<value;
          int key1 = 0;
		  int key2 = 0;
		  int stringLength = value.size();
		  const char* str = value.c_str();
		  key1 = hashCode(str, stringLength) % TABLE_SIZE;
		  //cout<<"key1: "<<key1<<endl;
		  key2 = TABLE_R - (hashCode(str, stringLength) % TABLE_R);
		  //cout<<table[key1]->getValue()<<endl;
		  while (table[key1] != NULL)
		  {
			  //cout<<(table[key1]!= NULL)<<endl;
			  if (table[key1]->getExist() == false || table[key1]->getValue() != value)
			  {
				 key1 = (key1 + key2) % TABLE_SIZE;
				 //cout<<table[key1]->getValue()<<endl;
			  }
			  else
			  {
				  //cout<<"delete it"<<table[key1]->getValue()<<endl;
				  table[key1] = NULL;
			  }
		  }
		  //cout<<"can not find the word"<<endl;
	  }
};

#endif