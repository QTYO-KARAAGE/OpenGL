/* rect.c  �l�p�`��`��	*/
#include <stdio.h>
#include "opgls.ft"
void draw_rect(void);

int main( void){
	ginit(1);
	gdisplay(draw_rect);
}

void draw_rect(void){
	glclear( );
	glcolor(255,255,255);		//���F�ɃZ�b�g
	grect(-100,-70,100,70); 	//�l�p�`�̐���`��
	glcolor(255,0,0);		    //�ԐF�ɃZ�b�g
	grect(50,-10,-50,10);	    //�ԐF�Œ��h�肵���l�p�`��`��
	grect(10,50,-10,-50);		//�ԐF�Œ��h�肵���l�p�`��`��
	glflush( );
}

