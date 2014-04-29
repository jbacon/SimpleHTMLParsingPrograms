#ifndef HTMLHEADER_H
#define HTMLHEADER_H

#include "HtmlExpression.h"

class HTMLHeader : public HtmlExpression {
public:
	HTMLHeader(HtmlExpression* x);
	value evaluate() const;
	int infer_type() const;
	bool valid_type() const;
private:
	HtmlExpression* x;
};
#endif