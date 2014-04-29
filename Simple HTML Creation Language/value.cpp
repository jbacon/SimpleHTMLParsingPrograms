
#include "value.h"

value::value(int type) {
	val_type = type;
}

value::value(string val, int type){
    if (val == "") val_type = 13;
    else val_type = type;
    str_val = val;
}
int value::type() const { 
	return val_type;
}
string value::getStr_val() const{
	return str_val;
}
