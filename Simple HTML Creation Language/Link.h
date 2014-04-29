//
//  Link.h
//  finalProject
//

#ifndef LINK_H
#define LINK_H

#include "HtmlExpression.h"

class Link : public HtmlExpression {
private:
    value url;
	value text;
	value font;
	value fontSize;
	value fontColor;
public:
    Link(value url, value text, value font, value fontSize, value fontColor);
	value evaluate() const;
    bool valid_type() const;
    int infer_type() const;
};

#endif 