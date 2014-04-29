#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<queue>
#include<list>
#include "URLContent.h"

using namespace std;


//Note there is some sort of problem when trying to assign priority to a specific URL.
//I could not figure it out, and was unable to problem solve beyond that point.

int main() 
{
	//User inputs
	string input;
	cout << "May take awhile to search" << endl;
	cout << "Enter a query or -1 to quit" << endl;
	cout << "Search for: ";
	getline(cin, input);
	if(input == "-1") {
			return 0;
	}

	//Converts search terms into lower case;
	int k = 0;
	char c;
	while(k < input.length()) {
		if((65 <= int(input[k]) && int(input[k]) <= 90)||(97 <= int(input[k]) && int(input[k]) <= 122)|| int(input[k]) == 32)
		{
			if(65 <= int(input[k]) && int(input[k]) <= 90) 
			{
				c = input[k];
				input[k] = c + 32;
			}
			k++;
		}
		else
			input.erase(k, 1);
	}

	//Creates a list of  strings that are taken from the user input as the desired search terms.
	string word;
	list<int> countList;
	list<string> wordSearchList;
	string ignoreWord;
	ifstream ignoreList;
	for(int j = 0; j < input.length(); j++) 
	{
			if(input[j] != ' ') 
			{
				word += input[j];
				if(j + 1 < input.length()) 
				{
					if(input[j+1] == ' ') 
					{
						ignoreList.open("ignore_list.txt");
						while(!ignoreList.eof() || word == ignoreWord) 
						{
							ignoreList >> ignoreWord;
						}
						if(word != ignoreWord) 
						{
							wordSearchList.push_back(word);
						}
						ignoreList.close();
						word.clear();
					}
				}
				else
					wordSearchList.push_back(word);
			}
	}

	//Creates a List of URLContent classes.
	TableItemCount count;
	list<URLContent> urlList;
	string UrlFileline;
	fstream URLFile;
	URLFile.open("urlListFile.txt");
	while(!URLFile.eof())
	{
		URLFile >> UrlFileline;
		URLContent aURL(UrlFileline);
		urlList.push_back(aURL);
	}

	//Assigns priority to each URL in the urlList which contains all the UrlContent classes
	//According to how many occurances of each word the user searches for from the list of words
	//created earlier.
	int countUp = 0;
	int z;
	for(int y = 0; y < urlList.size(); y++)
	{
		for(z = 0; z < wordSearchList.size(); z++)
		{

			//This is where the problem occurs
			//Some how this if statement still occurs even when passed as false
			//I have no idea how but when entering a word that does not exist in any file
			//it IS passed as FALSE but still enters the if statement
			//then it is trying to find a count of a null searchKey
			if(urlList.front().IsItemInTable(wordSearchList.front())) 
			{
				urlList.front().RetrieveCount(wordSearchList.front(), count); //Problem right in here
				countUp = countUp+count.getKeyCount();
			}
			urlList.front().setPriorityPoints(countUp);
			wordSearchList.push_back(wordSearchList.front());
			wordSearchList.pop_front();
		}
		countUp = 0;
		z = 0;
		urlList.push_back(urlList.front());
		urlList.pop_front();
	}

	//Creates a new list from the URLContents of urlList that is sorted in terms of priority
	list<URLContent> urlSortedList;
	urlSortedList.push_front(urlList.front());
	urlList.pop_front();
	for(int m = 0; m < urlList.size(); m++)
	{
		if(urlList.front().RetrievePriorityPoints() < urlSortedList.front().RetrievePriorityPoints())
		{
			urlSortedList.push_front(urlList.front());
			urlList.pop_front();
		}
		else if(urlList.front().RetrievePriorityPoints() > urlSortedList.back().RetrievePriorityPoints())
		{
			urlSortedList.push_back(urlList.front());
			urlList.pop_front();
		}
		else if(urlList.back().RetrievePriorityPoints() < urlSortedList.front().RetrievePriorityPoints())
		{
			urlSortedList.push_front(urlList.back());
			urlList.pop_back();
		}	
		else if(urlList.back().RetrievePriorityPoints() > urlSortedList.back().RetrievePriorityPoints())
		{
			urlSortedList.push_back(urlList.front());
			urlList.pop_back();
		}
		else
		{
			while(urlList.front().RetrievePriorityPoints() > urlSortedList.front().RetrievePriorityPoints())
			{
				urlSortedList.push_back(urlSortedList.front());
				if(urlList.front().RetrievePriorityPoints() <= urlSortedList.front().RetrievePriorityPoints())
				{
					urlSortedList.push_front(urlList.front());
				}
			}
			while(urlSortedList.front().RetrievePriorityPoints() >= urlSortedList.back().RetrievePriorityPoints())
			{
				urlSortedList.push_back(urlList.front());
			}
		}
	}

	//This is the output after each URLContent is assigned a priority number.
	cout << "Relevant pages:" << endl;
	if(urlSortedList.back().RetrievePriorityPoints() != 0)
	{
		cout << urlSortedList.back().RetrieveWebSite() << setw(20) << "(priority = " << urlSortedList.back().RetrievePriorityPoints() << ")" << endl;
	}	
	return 0;
}