#include "Header.h"

Header::Header(value text, value font, value fontSize, value fontColor) : text(text), font(font), fontSize(fontSize), fontColor(fontColor){
}
value Header::evaluate() const {
	if(valid_type()) {
		if(font.type() == EMPTY && fontSize.type() == EMPTY && fontColor.type() == EMPTY)
			return(value("<h1>"+text.getStr_val()+"</h1>", HEADER));
		else if(font.type() == EMPTY && fontSize.type() == EMPTY)
			return(value("<h1 style=\"color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</h1>", HEADER));
		else if(font.type() == EMPTY && fontColor.type() == EMPTY)
			return(value("<h1 style=\"font-size:"+fontSize.getStr_val()+"%\">"+text.getStr_val()+"</h1>", HEADER));
		else if(fontSize.type() == EMPTY && fontColor.type() == EMPTY)
			return(value("<h1 style=\"font-family:"+font.getStr_val()+"\">"+text.getStr_val()+"</h1>", HEADER));
		else if(fontSize.type() == EMPTY)
			return(value("<h1 style=\"font-family:"+font.getStr_val()+";color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</h1>", HEADER));
		else if(font.type() == EMPTY)
			return(value("<h1 style=\"font-size:"+fontSize.getStr_val()+"%;color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</h1>", HEADER));
		else if(fontColor.type() == EMPTY)
			return(value("<h1 style=\"font-size:"+fontSize.getStr_val()+"%;font-family:"+font.getStr_val()+"\">"+text.getStr_val()+"</h1>", HEADER));
		else
			return(value("<h1 style=\"font-family:"+font.getStr_val()+";font-size:"+fontSize.getStr_val()+"%;color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</h1>", HEADER));
	}
	else
		return(value("ERROR:Header",-1));
}
int Header::infer_type() const {
	if(valid_type())
		return(HEADER);
	else
		return(-1);
}
bool Header::valid_type() const {
	if(text.type() == Text && (font.type() == FontType || font.type() == EMPTY)  && (fontSize.type() == FontSize || fontSize.type() == EMPTY) && (fontColor.type() == FontColor || fontColor.type() == EMPTY))
		return(true);
	else
		return(false);
}
