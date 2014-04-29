
#include "Link.h"

Link::Link(value url, value text, value font, value fontSize, value fontColor) : url(url), text(text), font(font), fontSize(fontSize), fontColor(fontColor) 
{	
}
value Link::evaluate() const {
	if(valid_type()) {
		if(font.type() == EMPTY && fontSize.type() == EMPTY && fontColor.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+">"+text.getStr_val()+"</a>", LINK));
		else if(font.type() == EMPTY && fontSize.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+"\" color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</a>", LINK));
		else if(font.type() == EMPTY && fontColor.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+"\" font-size:"+fontSize.getStr_val()+"%\">"+text.getStr_val()+"</a>", LINK));
		else if(fontSize.type() == EMPTY && fontColor.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+"\" font-family:"+font.getStr_val()+"\">"+text.getStr_val()+"</a>", LINK));
		else if(fontSize.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+"\" font-family:"+font.getStr_val()+";color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</a>", LINK));
		else if(font.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+"\" font-size:"+fontSize.getStr_val()+"%;color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</a>", LINK));
		else if(fontColor.type() == EMPTY)
			return(value("<a href=\""+url.getStr_val()+"\" font-size:"+fontSize.getStr_val()+"%;font-family:"+font.getStr_val()+"\">"+text.getStr_val()+"</a>", LINK));
		else
			return(value("<h1 style=\"font-family:"+font.getStr_val()+";font-size:"+fontSize.getStr_val()+"%;color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</a>", LINK));
	}
	else
		return(value("ERROR:Link",-1));
}

int Link::infer_type() const {
	if(valid_type())
		return(LINK);
	else
		return(-1);
}
bool Link::valid_type() const {
	if(url.type() == URL && text.type() == Text && (font.type() == FontType || font.type() == EMPTY)  && (fontSize.type() == FontSize || fontSize.type() == EMPTY) && (fontColor.type() == FontColor || fontColor.type() == EMPTY))
		return(true);
	else
		return(false);
}