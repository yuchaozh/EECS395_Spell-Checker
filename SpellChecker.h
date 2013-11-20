/*
 *Author: Yuchao Zhou
 *Time: 11/19/2013
 */
#ifndef WORKSPACE_SPELLCHECKER_H
#define WORKSPACE_SPELLCHECKER_H

#include <string>
#include <iostream>

using namespace std;

class SpellChecker
{
public:
	string checkInsert(string oldString, int position, string letter)
	{
		string newString;
		//judge whether the first letter is capital
		if (isupper(oldString[0]) == 1)
		{
			//change the capital letter into lower case
			oldString[0] = tolower(oldString[0]);
		}
		//cout<<"before insert: "<<oldString<<endl;
		oldString.insert(position, letter);
		//cout<<"after insert:  "<<oldString<<endl;
		return oldString;
	}

	string checkDelete(string oldString, int position)
	{
		string newString;
		//judge whether the first letter is capital
		if (isupper(oldString[0]) == 1)
		{
			//change the capital letter into lower case
			oldString[0] = tolower(oldString[0]);
		}
		oldString.erase(position, 1);
		return oldString;
	}

	string checkReplace(string oldString, int position, string letter)
	{
		string newString;
		//judge whether the first letter is capital
		if (isupper(oldString[0]) == 1)
		{
			//change the capital letter into lower case
			oldString[0] = tolower(oldString[0]);
		}
		//cout<<"before replace: "<<oldString<<endl;
		oldString.replace(position, 1,letter);
		//cout<<"after insert:  "<<oldString<<endl;
		return oldString;
	}
};

#endif
