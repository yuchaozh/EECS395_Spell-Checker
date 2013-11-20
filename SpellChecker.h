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
		oldString.insert(position, letter);
		return oldString;
	}

	string checkDelete(string oldString, int position)
	{
		oldString.erase(position, 1);
		return oldString;
	}

	string checkReplace(string oldString, int position, string letter)
	{
		oldString.replace(position, 1,letter);
		return oldString;
	}
};

#endif
