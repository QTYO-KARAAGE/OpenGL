/* line.c	緑色の線を一本引く*/
#include <stdio.h>
#include "opgls.ft"
void draw_line(void);

int main( void){
	ginit(1);				//画面の初期化
	gdisplay(draw_line);	//draw_line関数を実行する
return 0;
}

void draw_line(void){
	glclear( );				//画面クリア
	glcolor(0,255,0);		//色を緑色にする
	gline(0,70,-40,-70);	//点(0,70)から点(-40,-70)に線を引く
	gline(-40,-70,70,20);	//点(-40,-70)から点(70,20)に線を引く
	gline(70,20,-70,20);	//点(70,20)から点(-70,20)に線を引く
	gline(-70,20,40,-70);	//点(-70,20)から点(40,-70)に線を引く
	gline(40,-70,0,70);		//点(40,-70)から点(0,70)に線を引く
	glflush( );				//実際に画面に表示する
}
