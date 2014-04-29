#include "HtmlInput.h"

HtmlInput::HtmlInput(HtmlExpression* x, HtmlExpression* y) : x(x),y(y){
}
value HtmlInput::evaluate() const {
	if(valid_type())
		return(value(x->evaluate().getStr_val()+y->evaluate().getStr_val(), String));
	else
		return(value("ERROR:HtmlInput",-1));
}
int HtmlInput::infer_type() const {
	if(valid_type())
		return(String);
	else
		return(-1);
}
bool HtmlInput::valid_type() const {
	if(x->valid_type() && y->valid_type())
		return true;
	else
		return false;
}