#include <string>
#include <cstring>
#include <fstream>
#include "TableB.h"


class URLContent
{
public:
	//contructor
	//Constructs a Table of words from an html file, words html coding, considers ignore word list
	//
	URLContent(const string fileName) 
	{
		theTable;
		string fileString;
		string line;
		inputFile = fileName;
		string word;
		//Inputs file into a big string
		ifstream inputHTMLFile;
		inputHTMLFile.open(inputFile);
		while(!inputHTMLFile.eof()) 
		{
			inputHTMLFile >> line;
			fileString += line+' '; //Combines each line from file into a big string with a added space at the end
		}
		inputHTMLFile.close();
		//Crops all unwanted chars from string.
		int found;
		int found2 = 0;
		char c;
		if(!fileString.empty()) {
			while(found2 != string::npos) {
				found = fileString.find("<script");
				found2 = fileString.find("</script> ");
				if(found2 != string::npos) {
					fileString.erase(fileString.begin() + int(found), fileString.begin() + (int)found2 + 9);
				}
			}
			while(found2 != string::npos) 
			{
				found = fileString.find("<style");
				found2 = fileString.find("</style> ");
				if(found2 != string::npos) {
					fileString.erase(fileString.begin() + int(found), fileString.begin() + (int)found2 + 8);
				}
			}
			while(found2 != string::npos){ 
				found = fileString.find("<!--");
				found2 = fileString.find("-->");
				if(found2 != string::npos) 
				{
					fileString.erase(fileString.begin() + int(found), fileString.begin() + (int)found2 + 2);
				}
			}
			while(found2 != string::npos) {
				found = fileString.find("/*");
				found2 = fileString.find("*/");
				if(found2 != string::npos) {
					fileString.erase(fileString.begin() + int(found), fileString.begin() + (int)found2 + 1);
				}
			}
			int i = 0;
			while(i < fileString.length()) {
				if(fileString[i] == '<') {
					while(fileString[i] != '>'){
						fileString.erase(i, 1);
					}
					if(i+1 < fileString.length()) {
						if(fileString[i+1] != '<') {
							fileString.insert(i+1, " ");
						}
					}
					fileString.erase(i, 1);

				}
				else 
					i++;
			}
			//Converts to lowercase
			int k = 0;
			while(k < fileString.length()) {
				if((65 <= int(fileString[k]) && int(fileString[k]) <= 90)||(97 <= int(fileString[k]) && int(fileString[k]) <= 122)|| int(fileString[k]) == 32)
				{
					if(65 <= int(fileString[k]) && int(fileString[k]) <= 90) 
					{
						c = fileString[k];
						fileString[k] = c + 32;
					}
					k++;
				}
				else
					fileString.erase(k, 1);
			}
		}
		string ignoreWord;
		ifstream ignoreList;
		for(int j = 0; j < fileString.length(); j++)  //Removes words that are in the ignore_list.txt file
		{
			if(fileString[j] != ' ') 
			{
				word += fileString[j];
				if(j + 1 < fileString.length()) 
				{
					if(fileString[j+1] == ' ') 
					{
							ignoreList.open("ignore_list.txt");
							while(!ignoreList.eof() || word == ignoreWord) 
							{
								ignoreList >> ignoreWord;
							}
							if(word != ignoreWord) 
							{
								theTable.tableInsert(word);
							}
							ignoreList.close();
							word.clear();
					}
				}
			}
		}
		fileString.clear();
	}

	bool IsItemInTable(KeyType searchKey) 
	{
		return(theTable.tableIsItemInTable(searchKey));
	}

	//Retrieve's item from tree
	void RetrieveItem(KeyType searchKey, TableItemType& tableItem) const 
	{
		theTable.tableRetrieve(searchKey, tableItem);
	}


	//Retrieve's a item's count from the tree
	void RetrieveCount(KeyType searchKey,TableItemCount& tableItemCount) const 
	{
		theTable.tableRetrieveCount(searchKey, tableItemCount);
	}

	void setPriorityPoints(int points) 
	{
		totalPriorityPoints = points;
	}

	int RetrievePriorityPoints()
	{
		return(totalPriorityPoints);
	}
	string RetrieveWebSite()
	{
		return(inputFile);
	}

private:
	int totalPriorityPoints;
	Table theTable;
    string inputFile;
}; // end KeyedItem
