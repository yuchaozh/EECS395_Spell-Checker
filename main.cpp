/*
 *Purpose: Implement the dictionary
 *Author: Yuchao Zhou
 *Time: 11/18/2013
 */
#include <fstream>
#include <iostream>
#include <string>

#include "Dictionary.h"
#include "SpellChecker.h"

using namespace std;

int main(int argc, char *argv[])
//int main()
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
			//cout<<input<<endl;
			dic.add(input);
		}
	}
	wordlist.close();

	int wordSize  = 0;
	string content;
	SpellChecker checker;
	string turn;
	string newWords;
	context.open(argv[1]);
	//context.open("test1.txt");

	cout<<endl;
	cout<<"INPUT: ";
	while (getline(context, content))
    {
		cout<<content;
	}
	cout<<endl<<endl;
	context.close();
	//context.open("test1.txt");
	context.open(argv[1]);
	while(!context.eof())
	{
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
			cout<<"word not found: "<<words<<endl;
			cout<<"perhaps you meant: "<<endl;
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
						cout<<"        "<<newWords<<endl;
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
						cout<<"        "<<newWords<<endl;
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
						cout<<"        "<<newWords<<endl;
					}
				}
			}
			cout<<endl;
		}
		//cout<<endl<<endl;
	}
	context.close();
	return 0;
}
