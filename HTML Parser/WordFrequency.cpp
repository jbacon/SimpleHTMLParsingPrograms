//Josh Bacon
//CPSC 223
//11/18

//Note: When compiled and ran I get an error (But it does not effect the program)
//"Run-time Check Failure #3 - The variable'found2' (from CropUwantedChars) is being used without being initialized".
//The program runs just as expected and how I visioned it would, and all I do is press continue once.
//I never could figure out how to stop the error message from popping up.
//But it does not affect how my program operates.
//I used Visual C++ 2010 if that makes any difference


#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "BST.h"

//Crops out all non-words  html code from the big string that was created previously
void CropUnwantedChars(string &fileString);
//Determines if a word is in the ignore list
bool InIgnoreList(string word, string ignoreFileName);
//Prints what is in the BST
void PrintBST(BinarySearchTree tree);
//Helps the printing of the BST from the BST class
//I included a freq parameter to determine where or not to print out a particular item.
//freq is a data type in the private data of the BST class and has a public function to set it
//which is called in the main funtion
void visit(TreeItemType& anItem, TreeItemCount& aCount, int freq);

int main()
{
	string cmdLine;
	int freq;
	string word;
	string line;
	string fileString;
	BinarySearchTree theTree;
	string inputFileName, ignoreFileName;
	cout << "# Valid Command line inputs:" << endl;
	cout << "# % WordFrequency/html_file_name.html/3/html_ignore_list.txt" << endl;
	cout << "# % WordFrequency/html_file_name.html/4" << endl;
	cout << "# % WordFrequency/html_file_name.html" << endl;
	cout << "# Invalid Command line inputs:" << endl;
	cout << "# % WordFrequency/html file name.html/html ignore list.txt  <-- No spaces" << endl << endl;
	cout << "% WordFrequency/";
	cin >> cmdLine;
	int count = 1; //This determines the type command line input
	//Reads the command line that is given by the user
	for(int m = 0; m < cmdLine.length(); m++)
	{ 
		if(count == 1) {
			if(cmdLine[m] != '/')
				inputFileName += cmdLine[m];
			if(m+1 < cmdLine.length()){
				if(cmdLine[m+1] == '/')
					count = 2;
			}
		}
		else if(count == 2) {
			if(cmdLine[m] != '/') 
				freq = int(cmdLine[m]) - 48;
			if(m+1 < cmdLine.length()){
				if(cmdLine[m+1] == '/')
					count = 3;
			}
		}
		else if(count == 3) {
			if(cmdLine[m] != '/')
				ignoreFileName += cmdLine[m];
		}
	}
	ifstream inputHTMLFile;
	inputHTMLFile.open(inputFileName);
	while(!inputHTMLFile.eof()) {
		inputHTMLFile >> line;
		fileString += line+' '; //Combines each line from file into a big string with a added space at the end
	}
	CropUnwantedChars(fileString); //Converts all to lowercase aswell
	cout << endl << endl;
	for(int j = 0; j < fileString.length(); j++)  //Removes words that are in the ignore_list.txt file
	{
		if(fileString[j] != ' ') 
		{
			word += fileString[j];
			if(j + 1 < fileString.length()) 
			{
				if(fileString[j+1] == ' ') 
				{
					if(count == 3)
					{
						if(InIgnoreList(word, ignoreFileName) == false) 
						{
						theTree.searchTreeInsert(word);
						}
					}
					else
						theTree.searchTreeInsert(word);
					word.clear();
				}
			}
		}
	}
	if(count != 1) //Determines whether or not to set default frequency of 1.
		theTree.setFreq(freq);
	else
		theTree.setFreq(1);
	PrintBST(theTree);
	return 0;
}


//Prints the binary Search Tree in inorder formate according the the frequency number, 
//which is determined by the user.
void PrintBST(BinarySearchTree tree)
{
	tree.inorderTraverse(visit);
}

void visit(TreeItemType& anItem, TreeItemCount& aCount, int freq)
{
		if(aCount.getKeyCount() >= freq) {
			cout << anItem.getKey() << endl;
		}
}

//Base Idea behind this funtion:
//Pre A massive string is created that holds all the raw data from the html input file
//this is suppose to crop out everything that is not text on the webpage
//It does this by identifying universal HTML code segments and deleteing the necesary
//sections within the string
//Post string is shortened and only the words on the website page are left, not the HTML code.
void CropUnwantedChars(string &fileString)
{
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
		int k = 0;
		while(k < fileString.length()) {
			if((65 <= int(fileString[k]) && int(fileString[k]) <= 90)||(97 <= int(fileString[k]) && int(fileString[k]) <= 122)|| int(fileString[k]) == 32){
				if(65 <= int(fileString[k]) && int(fileString[k]) <= 90) {
					c = fileString[k];
					fileString[k] = c + 32;
				}
				k++;
			}
			else
				fileString.erase(k, 1);
		}
	}
}

//Determines whether or not a particular word is in the ignore list that before entering it into the tree.
bool InIgnoreList(string word, string ignoreFileName)
{
	string ignoreWord;
	ifstream ignoreList;
	ignoreList.open(ignoreFileName);
	while(!ignoreList.eof()) {
		ignoreList >> ignoreWord;
		if(word == ignoreWord)
			return true;
	}
	return false;
	ignoreList.close();
}