/*
 *Purpose: Implement the dictionary
 *Author: Yuchao Zhou
 *Time: 11/18/2013
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

#include "Dictionary.h"
#include "SpellChecker.h"

using namespace std;

int main(int argc, char *argv[])
{
	string input;
	string words;
	ifstream wordlist;
	ifstream context;
	Dictionary dic;
	wordlist.open("Program3Fall2013wordlist .txt");
	while (wordlist>>input)
	{
		if (isdigit(input[0]) == 0)
		{
			if (isupper(input[0]) == 0)
			{
				input[0] = tolower(input[0]);
			}
			dic.add(input);
		}
	}
	wordlist.close();

	int wordSize  = 0;
	string content;
	SpellChecker checker;
	string turn;
	string newWords;
	string capitalWord;
	context.open(argv[1]);

	cout<<endl;
	cout<<"INPUT: ";
	while (getline(context, content))
    {
		cout<<content;
	}
	cout<<endl<<endl;
	context.close();
	context.open(argv[1]);
	while(!context.eof())
	{
		string suggest[50]={""};
		string suggested[50]={""};
		int number = 0;
		context>>words;
		wordSize = words.size();
		if (ispunct(words[wordSize-1]))
		{
			words.erase(wordSize - 1);
			wordSize = words.size();
		}
		if (isupper(words[0]) == 256)
		{
			//change the capital letter into lower case
			words[0] = tolower(words[0]);
		}
		if (dic.lookup(words) != true)
		{
			cout<<"word not found: ";
			transform(words.begin(), words.end(), words.begin(), ::toupper);
			cout<<words<<endl;
			cout<<"perhaps you meant: "<<endl;
			transform(words.begin(), words.end(), words.begin(), ::tolower);
			//insert
			for (int i = 0; i <= wordSize; i++)
			{
				for (int a = 97; a <= 122; a++)
				{
					//turn ascii into char
					char c = (char)a;
					//turn char into string
					turn = c;
					newWords = checker.checkInsert(words, i, turn);
					if (dic.lookup(newWords) == true)
					{
						transform(newWords.begin(), newWords.end(), newWords.begin(), ::toupper);
						suggest[number] = newWords;
						number++;
						//cout<<"        "<<newWords<<endl;
					}
				}
			}
			for (int i = 0; i <= wordSize - 1; i++)
			{
				if (i>0 && (words[i] == words[i-1]))
				{
					
				}
				else
				{
					//delete
					newWords = checker.checkDelete(words, i);
					if (dic.lookup(newWords) == true)
					{
						transform(newWords.begin(), newWords.end(), newWords.begin(), ::toupper);
						suggest[number] = newWords;
						number++;
						//cout<<"        "<<newWords<<endl;
					}
				}
				//replace
				for (int a = 97; a <= 122; a++)
				{
					//turn ascii into char
					char c = (char)a;
					//turn char into string
					turn = c;
					newWords = checker.checkReplace(words, i, turn);
					if (dic.lookup(newWords) == true)
					{
						transform(newWords.begin(), newWords.end(), newWords.begin(), ::toupper);
						suggest[number] = newWords;
						number++;
						//cout<<"        "<<newWords<<endl;
					}
				}
			}
			for (int c = 0; c < number; c++)
			{
				int order = 0;
				for (int d = 0; d < number; d++)
				{
					if (suggest[c] > suggest [d])
					{
						order++;
					}
				}
				suggested[order] = suggest[c];
			}
			for (int e = 0; e < number; e++)
			{
				cout<<"        "<<suggested[e]<<endl;
			}
		cout<<endl;
		}
	}
	context.close();
	return 0;
}
