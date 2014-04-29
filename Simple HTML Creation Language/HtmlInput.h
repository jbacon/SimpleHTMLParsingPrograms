#ifndef HTMLINPUT_H
#define HTMLINPUT_H

#include "HtmlExpression.h"

class HtmlInput : public HtmlExpression {
public:
	HtmlInput(HtmlExpression* x, HtmlExpression* y);
	value evaluate() const;
	int infer_type() const;
	bool valid_type() const;
private:
	HtmlExpression* x;
	HtmlExpression* y;
};
#endif //HTMLINPUT_H