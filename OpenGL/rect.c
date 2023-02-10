/* rect.c  四角形を描く	*/
#include <stdio.h>
#include "opgls.ft"
void draw_rect(void);

int main( void){
	ginit(1);
	gdisplay(draw_rect);
}

void draw_rect(void){
	glclear( );
	glcolor(255,255,255);		//白色にセット
	grect(-100,-70,100,70); 	//四角形の線を描く
	glcolor(255,0,0);		    //赤色にセット
	grect(50,-10,-50,10);	    //赤色で中塗りした四角形を描く
	grect(10,50,-10,-50);		//赤色で中塗りした四角形を描く
	glflush( );
}

