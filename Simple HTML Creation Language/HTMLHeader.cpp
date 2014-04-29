#include "HTMLHeader.h"

HTMLHeader::HTMLHeader(HtmlExpression* x) : x(x){
}
value HTMLHeader::evaluate() const {
	if(valid_type())
		return(value("<!DOCTYPE html><html><body>"+x->evaluate().getStr_val()+"</body></html>", String));
	else
		return(value("ERROR:HTMLHeader", -1));
}
int HTMLHeader::infer_type() const {
	if(valid_type()) 
		return(String);
	else
		return(-1);
}
bool HTMLHeader::valid_type() const {
	if(x->valid_type())
		return true;
	else
		return false;
}