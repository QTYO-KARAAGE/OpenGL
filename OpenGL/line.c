/* line.c	�ΐF�̐�����{����*/
#include <stdio.h>
#include "opgls.ft"
void draw_line(void);

int main( void){
	ginit(1);				//��ʂ̏�����
	gdisplay(draw_line);	//draw_line�֐������s����
return 0;
}

void draw_line(void){
	glclear( );				//��ʃN���A
	glcolor(0,255,0);		//�F��ΐF�ɂ���
	gline(0,70,-40,-70);	//�_(0,70)����_(-40,-70)�ɐ�������
	gline(-40,-70,70,20);	//�_(-40,-70)����_(70,20)�ɐ�������
	gline(70,20,-70,20);	//�_(70,20)����_(-70,20)�ɐ�������
	gline(-70,20,40,-70);	//�_(-70,20)����_(40,-70)�ɐ�������
	gline(40,-70,0,70);		//�_(40,-70)����_(0,70)�ɐ�������
	glflush( );				//���ۂɉ�ʂɕ\������
}
