#include "Image.h"

Image::Image(value file, value width, value height) : imgLoc(file), imgWidth(width), imgHeight(height){
}
value Image::evaluate() const {
	if(valid_type()) 
		return(value("<img src=\""+imgLoc.getStr_val()+"\"width=\""+imgWidth.getStr_val()+"\"height=\""+imgHeight.getStr_val()+"\">",String));
	else
		return(value("ERROR:Image",-1));
}
int Image::infer_type() const {
	if(valid_type())
		return(IMAGE);
	else
		return(-1);
}
bool Image::valid_type() const {
	if(imgLoc.type() == ImageLocation && imgWidth.type() == ImageWidth && imgHeight.type() == ImageHeight)
		return(true);
	else
		return(false);
}