/*bmp形式のグレースケール画像を読み込んで表示する.*/

#include <stdio.h>
#include "opgls.ft"


#define MAXSIZE 380 				/* 画像の最大サイズ */
unsigned  char grayimage[MAXSIZE][MAXSIZE]; 	/* グレースケール画像 */
int width, height, cm;  			/* 画像の幅, 高さ, カラーかモノクロか */
unsigned  char dat[MAXSIZE*MAXSIZE]; 		/* bmp画像を読み込むための大域変数 */

// プロトタイプ宣言 
void show_pict(void);
void loadgrayimage(void);

int main(void)
{
	loadgrayimage( );
	ginit(1);
	gdisplay(show_pict);
	return 0;
}

void show_pict(void)//画面に描く内容
{
	int x, y;
	unsigned  char	gray;
	glclear( );					// 画面クリア
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			gray = grayimage[y][x];
			glcolor(gray, gray, gray);	//(r, g, b)の色で
			gpnt(x, y);			//(x, y)座標に点を打つ
		}
	}
	glflush();
}

void loadgrayimage(void)
//  bmp形式のグレースケール画像を読み込み
//  配列grayimage[y][x]に格納する
//
//  読み込むbmp形式の画像ファイル名を指定してください
//  以下をグローバル変数で定義してください
//  #define MAXSIZE 380 			/* 画像の最大サイズ */
//  unsigned  char grayimage[MAXSIZE][MAXSIZE]; /* グレースケール画像 */
//  int width, height, cm;  			/* 画像の幅, 高さ, カラーかモノクロか */
//  unsigned  char dat[MAXSIZE*MAXSIZE]; 	/* bmp画像を読み込むための大域変数 */

{
	int	 y, x;
	loadbmpfile ("Lenna(gray).bmp", &cm, &height, &width, dat);
	printf("cm = %d \n", cm);
	printf("hite = %d \n", height);
	printf("wide = %d \n", width);
	for( y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			grayimage[y][x] = dat[ y * width + x ];
		}
	}
}
	
