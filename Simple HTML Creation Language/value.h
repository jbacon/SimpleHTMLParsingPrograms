//
//  value.h
//  finalProject
//
//  Created by garreola-gutierrez on 4/25/13.
//  Copyright (c) 2013 Gisela Arreola-Gutierrez. All rights reserved.
//

#ifndef VALUE_H
#define VALUE_H
#include "token.h"
#include <string>

using namespace std;
class value{
private:
    string str_val;
	int val_type;
public:
	value(int type);
    value(string val, int type);
    int type() const;
    string getStr_val() const;
};


#endif
