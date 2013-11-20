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

int main()
{
	string input;
	string words;
	ifstream wordlist;
	//FILE* context;
	ifstream context;
	Dictionary dic;
	int line = 1;
	wordlist.open("Program3Fall2013wordlist .txt");
	//wordlist.open("test.txt");
	while (getline(wordlist, input))
	{
		//judge whether the string is a number
		if (isdigit(input[0]) == 0)
		{
			cout<<input<<"   "<<endl;
			if (isupper(input[0]) == 1)
			{
				input[0] = tolower(input[0]);
				cout<<input<<endl;
			}
			//cout<<input<<endl;
			dic.add(input);
		}
	}
	//dic.lookup("computer");
	//cout<<dic.lookup("computer")<<endl;
	wordlist.close();

	cout<<"~~~~~~~~~~~~~~"<<endl;
	int wordSize  = 0;

	/*
	* @TODO:There is a bug. the last word will read twice. 
	*/
	string content;
	SpellChecker checker;
	string turn;
	string newWords;
	context.open("Program3Fall2013input.txt");
	//context.open("test1.txt");

	cout<<"INPUT: ";
	while (getline(context, content))
    {
		cout<<content;
	}
	cout<<endl<<endl;
	context.close();
	//context.open("test3.txt");
	context.open("Program3Fall2013input.txt");
	while(!context.eof())
	{
		context>>words;
		wordSize = words.size();
		if (words[wordSize-1]=='.' || words[wordSize - 1]==',')
		{
			words.erase(wordSize - 1);
			wordSize = words.size();
		}
		if (isupper(words[0]) == 1)
		{
			//change the capital letter into lower case
			words[0] = tolower(words[0]);
		}
		cout<<"here: "<<words<<endl;
		if (dic.lookup(words) != true)
		{
			cout<<"word not found: "<<words<<endl;
			cout<<"perhaps you meant: "<<endl;
		
			//cout<<"word size:  "<<wordSize<<endl;

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
						cout<<"insert        "<<newWords<<endl;
					}
				}
			}
			//cout<<"insert is ok"<<endl;
			//delete or replace
			//cout<<"~~~~~~~~~~~~~~~~~~delete and replace~~~~~~~~~~~~~~~~~~~~~"<<endl;
			for (int i = 0; i <= wordSize - 1; i++)
			{
				//delete
				newWords = checker.checkDelete(words, i);
				if (dic.lookup(newWords) == true)
					{
						cout<<"delete        "<<newWords<<endl;
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
						cout<<"replace        "<<newWords<<endl;
					}
				}
			}
			//cout<<"delete and replace is ok"<<endl;
		}
		cout<<endl<<endl;
		//cout<<words<<endl;
	}
	context.close();
	system("pause");
	return 0;





		/*context = fopen("Program3Fall2013input.txt", "r");*/

	//while (fscanf(context, "%s", words) != EOF)
 //   {
	//	wordSize = words.size();
	//	cout<<"word size:  "<<wordSize<<endl;
	//	//if (words[wordSize-1]=='.' || words[wordSize - 1]==',')
	//	//{
	//	//	words.erase(wordSize - 1);
	//	//}
	//	printf("%s\n", words);
	//}
	//fclose(context);

}