#ifndef HEADER_H
#define HEADER_H

#include "HtmlExpression.h"

class Header : public HtmlExpression {
public:
	Header(value text, value font, value fontSize, value fontColor);

	value evaluate() const;
	int infer_type() const;
	bool valid_type() const;
private:
	value text;
	value font;
	value fontSize;
	value fontColor;
};
#endif// HEADER_H
