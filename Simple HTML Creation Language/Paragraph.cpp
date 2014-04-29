#include "Paragraph.h"

Paragraph::Paragraph(value text, value font, value fontSize, value fontColor) : text(text), font(font), fontSize(fontSize), fontColor(fontColor){
}
value Paragraph::evaluate() const {
	if(valid_type()) {
        if(font.type() == EMPTY && fontSize.type() == EMPTY && fontColor.type() == EMPTY)
            return(value("<p>"+text.getStr_val()+"</p>", PARAGRAPH));
        else if(font.type() == EMPTY && fontSize.type() == EMPTY)
            return(value("<p style=\"color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</p>", PARAGRAPH));
        else if(font.type() == EMPTY && fontColor.type() == EMPTY)
            return(value("<p style=\"font-size:"+fontSize.getStr_val()+"%\">"+text.getStr_val()+"</p>", PARAGRAPH));
        else if(fontSize.type() == EMPTY && fontColor.type() == EMPTY)
            return(value("<p style=\"font-family:"+font.getStr_val()+"\">"+text.getStr_val()+"</p>", PARAGRAPH));
        else if(fontSize.type() == EMPTY)
            return(value("<p style=\"font-family:"+font.getStr_val()+";color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</p>", PARAGRAPH));
        else if(font.type() == EMPTY)
            return(value("<p style=\"font-size:"+fontSize.getStr_val()+"%;color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</p>", PARAGRAPH));
        else if(fontColor.type() == EMPTY)
            return(value("<p style=\"font-size:"+fontSize.getStr_val()+"%;font-family:"+font.getStr_val()+"\">"+text.getStr_val()+"</p>", PARAGRAPH));
        else
            return(value("<p style=\"font-family:"+font.getStr_val()+";font-size:"+fontSize.getStr_val()+"%;color:"+fontColor.getStr_val()+"\">"+text.getStr_val()+"</p>", PARAGRAPH));
	}
	else
		return(value("ERROR:Paragraph", -1));
}
int Paragraph::infer_type() const {
	if(valid_type())
		return(PARAGRAPH);
	else
		return(-1);
}
bool Paragraph::valid_type() const {
	if(text.type() == Text && (font.type() == FontType || font.type() == EMPTY)  && (fontSize.type() == FontSize || fontSize.type() == EMPTY) && (fontColor.type() == FontColor || fontColor.type() == EMPTY))
		return(true);
	else
		return(false);
}