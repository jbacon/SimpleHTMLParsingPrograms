#include "program.h"

string program :: scan(string fileName) {
    ifstream FileOpen;
    string fileText, line;
    FileOpen.open(fileName);
    while (!FileOpen.eof()) 
    {
           getline(FileOpen, line);
		   fileText = fileText + line;
    }
    FileOpen.close();
	return(fileText);
}

string program :: getOutput(string file) {
	HTMLHeader fullTree = HTMLHeader(createParseTree(file));
	return(fullTree.evaluate().getStr_val());
}

HtmlExpression* program :: createParseTree(string myfile) {
    string s  = myfile;
    int tokenNum = 0;
    string delimiters = ":";
    int startpos = 0;
    int endpos = 0;
    string word = "";
	string restOfString = "";
    endpos = s.find_first_of(delimiters, startpos);
    word = s.substr(startpos, endpos - startpos);
	restOfString = s.substr(endpos+1,s.length());
	if(word == "Header") {
			value t(EMPTY);
			value ft(EMPTY);
			value fs(EMPTY);
			value fc(EMPTY);
			if(restOfString.substr(0,5) == "Text=") {
				t = value(restOfString.substr(5,restOfString.find_first_of(":",5) - 5), Text);
				restOfString=restOfString.substr(restOfString.find_first_of(":",5)+1, restOfString.length());
			}
			if(restOfString.substr(0,9) == "FontType=") {
				ft = value(restOfString.substr(9,restOfString.find_first_of(":",9) - 9), FontType);
				restOfString=restOfString.substr(restOfString.find_first_of(":",9)+1, restOfString.length());
			}
			if(restOfString.substr(0,9) == "FontSize=") {
				fs = value(restOfString.substr(9,restOfString.find_first_of(":",9) - 9), FontSize);
				restOfString=restOfString.substr(restOfString.find_first_of(":",9)+1, restOfString.length());
			}
			if(restOfString.substr(0,10) == "FontColor=") {
				fc = value(restOfString.substr(10,restOfString.find_first_of(":",10) - 10), FontColor);
				restOfString=restOfString.substr(restOfString.find_first_of(":",10)+1, restOfString.length());
			}
			HtmlExpression* header = new Header(t,ft,fs,fc);
			if(header->valid_type())
				return(new HtmlInput(header,createParseTree(restOfString)));
			else
				return(new HtmlEnd(value("ERROR:createParseTree:Paragraph", EMPTY)));
	}
	else if(word == "Paragraph") {
			value t(EMPTY);
			value ft(EMPTY);
			value fs(EMPTY);
			value fc(EMPTY);
			if(restOfString.substr(0,5) == "Text=") {
				t = value(restOfString.substr(5,restOfString.find_first_of(":",5) - 5), Text);
				restOfString=restOfString.substr(restOfString.find_first_of(":",5)+1, restOfString.length());
			}
			if(restOfString.substr(0,9) == "FontType=") {
				ft = value(restOfString.substr(9,restOfString.find_first_of(":",9) - 9), FontType);
				restOfString=restOfString.substr(restOfString.find_first_of(":",9)+1, restOfString.length());
			}
			if(restOfString.substr(0,9) == "FontSize=") {
				fs = value(restOfString.substr(9,restOfString.find_first_of(":",9) - 9), FontSize);
				restOfString=restOfString.substr(restOfString.find_first_of(":",9)+1, restOfString.length());
			}
			if(restOfString.substr(0,10) == "FontColor=") {
				fc = value(restOfString.substr(10,restOfString.find_first_of(":",10) - 10), FontColor);
				restOfString=restOfString.substr(restOfString.find_first_of(":",10)+1, restOfString.length());
			}
			HtmlExpression* paragraph = new Paragraph(t,ft,fs,fc);
			if(paragraph->valid_type())
				return(new HtmlInput(paragraph,createParseTree(restOfString)));
			else 
				return(new HtmlEnd(value("ERROR:createParseTree:Paragraph", EMPTY)));
	}
	else if(word == "Link") {
			value url(EMPTY);
			value t(EMPTY);
			value ft(EMPTY);
			value fs(EMPTY);
			value fc(EMPTY);
			if(restOfString.substr(0,4) == "URL=") {
				url = value(restOfString.substr(4,restOfString.find_first_of(":",4) - 4), URL);
				restOfString=restOfString.substr(restOfString.find_first_of(":",4)+1, restOfString.length());
			}
			if(restOfString.substr(0,5) == "Text=") {
				t = value(restOfString.substr(5,restOfString.find_first_of(":",5) - 5), Text);
				restOfString=restOfString.substr(restOfString.find_first_of(":",5)+1, restOfString.length());
			}
			if(restOfString.substr(0,9) == "FontType=") {
				ft = value(restOfString.substr(9,restOfString.find_first_of(":",9) - 9), FontType);
				restOfString=restOfString.substr(restOfString.find_first_of(":",9)+1, restOfString.length());
			}
			if(restOfString.substr(0,9) == "FontSize=") {
				fs = value(restOfString.substr(9,restOfString.find_first_of(":",9) - 9), FontSize);
				restOfString=restOfString.substr(restOfString.find_first_of(":",9)+1, restOfString.length());
			}
			if(restOfString.substr(0,10) == "FontColor=") {
				fc = value(restOfString.substr(10,restOfString.find_first_of(":",10) - 10), FontColor);
				restOfString=restOfString.substr(restOfString.find_first_of(":",10)+1, restOfString.length());
			}
			HtmlExpression* link = new Link(url,t,ft,fs,fc);
			if(link->valid_type())
				return(new HtmlInput(link, createParseTree(restOfString)));
			else
				return(new HtmlEnd(value("ERROR:createParseTree:Link", EMPTY)));
	}
	else if(word == "Image") {
			value f(EMPTY);
			value w(EMPTY);
			value h(EMPTY);
			if(restOfString.substr(0,14) == "ImageLocation=") {
			f = value(restOfString.substr(14,restOfString.find_first_of(":",14) - 14), ImageLocation);
			restOfString=restOfString.substr(restOfString.find_first_of(":",14)+1, restOfString.length());
			}
			if(restOfString.substr(0,11) == "ImageWidth=") {
				w = value(restOfString.substr(11,restOfString.find_first_of(":",11) - 11), ImageWidth);
				restOfString=restOfString.substr(restOfString.find_first_of(":",11)+1, restOfString.length());
			}
			if(restOfString.substr(0,12) == "ImageHeight=") {
				h = value(restOfString.substr(12,restOfString.find_first_of(":",12) - 12), ImageHeight);
				restOfString=restOfString.substr(restOfString.find_first_of(":",12)+1, restOfString.length());
			}
			HtmlExpression* image = new Image(f, w, h);
			if(image->valid_type())
				return(new HtmlInput(image,createParseTree(restOfString)));
			else {
				return(new HtmlEnd(value("ERROR:createParseTree:Image", EMPTY)));
			}
	}
	else if(word == "END") 
		return(new HtmlEnd(value("", EMPTY)));
	else 
		return(new HtmlEnd(value("ERROR:createParseTree", EMPTY)));
}

void program::writeToFile(string htmlCode) {
	ofstream outputFile("outputFile.txt");
	outputFile << htmlCode;
}

int main() {
    string file = "testFile.txt";
	program prog;
    string fileText = prog.scan(file);
	string htmlCode = prog.getOutput(fileText);
	prog.writeToFile(htmlCode);
    return 0;
}