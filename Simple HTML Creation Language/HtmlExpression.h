#ifndef HTMLEXPRESSION_H
#define HTMLEXPRESSION_H

#include "value.h"

class HtmlExpression {
public:
	virtual value evaluate() const = 0;
	virtual int infer_type() const = 0;
	virtual bool valid_type() const = 0;
};
#endif 
