#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "HtmlExpression.h"

class Paragraph : public HtmlExpression {
public:
	Paragraph(value text, value font, value fontSize, value fontColor);
	value evaluate() const;
	int infer_type() const;
	bool valid_type() const;
private:
	value text;
	value font;
	value fontSize;
	value fontColor;
};
#endif //PARAGRAPH_H