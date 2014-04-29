#include "HtmlEnd.h"

HtmlEnd::HtmlEnd(value end) : const_val(end){
	}
value HtmlEnd::evaluate() const {
		return const_val;
	}
int HtmlEnd::infer_type() const {
		return(EMPTY);
	}
bool HtmlEnd::valid_type() const {
		return(true);
	}