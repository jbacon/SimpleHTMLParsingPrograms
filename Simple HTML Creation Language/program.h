#include <iostream>
#include <cstdlib>
#include <fstream>

#include "HtmlEnd.h"
#include "HtmlInput.h"
#include "Header.h"
#include "Image.h"
#include "Link.h"
#include "Paragraph.h"
#include "HtmlInput.h"
#include "HtmlHeader.h"
using namespace std;

class program {
    private:
    public:
		string scan(string fileName);
        string getOutput(string file);
		HtmlExpression* createParseTree(string fileStr);
		void writeToFile(string htmlCode);
};
