#ifndef HTMLEND_H
#define HTMLEND_H

#include "HtmlExpression.h"

class HtmlEnd : public HtmlExpression {
public:
	HtmlEnd(value end);
	value evaluate() const;
	int infer_type() const;
	bool valid_type() const;
private:
	value const_val;

};
#endif