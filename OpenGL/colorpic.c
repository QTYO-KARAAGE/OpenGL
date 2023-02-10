/*bmp形式のカラー画像を読み込んで表示する.*/

#include <stdio.h>
#include "opgls.ft"


#define MAXSIZE 380 				/* 画像の最大サイズ */
unsigned  char colorimage[MAXSIZE][MAXSIZE][3]; /* カラー画像 */
int width, height, cm;  			/* 画像の幅, 高さ, カラーかモノクロか */
unsigned  char dat[MAXSIZE*MAXSIZE*3]; 		/* bmp画像を読み込むための大域変数 */

// プロトタイプ宣言 
void show_pict(void);
void loadcolorimage(void);

int main(void)
{
	loadcolorimage( );
	ginit(1);
	gdisplay(show_pict);
	return 0;
}

void show_pict(void)//画面に描く内容
{
	int x, y;
	unsigned  char	r, g, b;
	glclear( );				// 画面クリア
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			b = colorimage[y][x][0];
			g = colorimage[y][x][1];
			r = colorimage[y][x][2];
			glcolor(r, g, b);	//(r, g, b)の色で
			gpnt(x, y);		//(x, y)座標に点を打つ
		}
	}
	glflush();
}

void loadcolorimage(void)
//  bmp形式のカラー画像を読み込み
//  配列colorimage[y][x][3]に格納する
//
//  読み込むbmp形式の画像ファイル名を指定してください
//  以下をグローバル変数で定義してください
//  #define MAXSIZE 380 				/* 画像の最大サイズ */
//  unsigned  char colorimage[MAXSIZE][MAXSIZE][3]; 	/* グレースケール画像 */
//  int width, height, cm;  				/* 画像の幅, 高さ, カラーかモノクロか */
//  unsigned  char dat[MAXSIZE*MAXSIZE*3]; 		/* bmp画像を読み込むための大域変数 */

{
	int	 y, x, c;
	loadbmpfile ("Parrots.bmp", &cm, &height, &width, dat);
	printf("cm = %d \n", cm);
	printf("hite = %d \n", height);
	printf("wide = %d \n", width);
	for( c = 0; c < cm; c++){
		for( y = 0; y < height; y++){
			for(x = 0; x < width; x++){
				colorimage[y][x][c] = dat[ ( y * width + x) * cm + c];
			}
		}
	}
}
	
