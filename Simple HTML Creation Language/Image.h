//
//  Image.h
//  finalProject
//
//  Created by garreola-gutierrez on 4/30/13.
//  Copyright (c) 2013 Gisela Arreola-Gutierrez. All rights reserved.
//

#ifndef finalProject_Image_h
#define finalProject_Image_h

#include "HtmlExpression.h"
//#include "object.h"
using namespace std;

class Image : public HtmlExpression{
private:
    value imgLoc;
    value imgWidth;
	value imgHeight;
public:
    Image(value file, value width, value height);
    value evaluate() const ;
    bool valid_type() const;
    int infer_type() const;
};

#endif finalProject_Image_h

