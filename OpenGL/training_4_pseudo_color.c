/*bmp形式のグレースケール画像を読み込んで
  疑似カラー画像へ変換する.*/

#include <stdio.h>
#include "opgls.ft"


#define MAXSIZE 380 				/* 画像の最大サイズ */
unsigned  char grayimage[MAXSIZE][MAXSIZE]; 	/* グレースケール画像 */
unsigned  char timage[MAXSIZE][MAXSIZE][3]; /* 変換後画像 */
int width, height, cm;  			/* 画像の幅, 高さ, カラーかモノクロか */
unsigned  char dat[MAXSIZE*MAXSIZE]; 		/* bmp画像を読み込むための大域変数 */



// プロトタイプ宣言 
void show_pict(void);
void loadgrayimage(void);
void pseudo_color(void);

int main(void)
{
	loadgrayimage( );
	ginit(1);
	pseudo_color();
	gdisplay(show_pict);
	return 0;
}

/* 疑似カラー変換 */
void pseudo_color(void)
{
	double r,g,b,z,a1,a2,a3;
	int x, y;
	a1 = 64;
	a2 = 128;
	a3 = 192;
	
	for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			z = grayimage[y][x];
			
			// ここに追加
			//R について
			if (z < a2){
				r = 0;
			}
			else if (z >= a2 && a3 >= z){
				r = 255 - 255 * (z - a2) / (a3 - a2);
			}
			else {
				r = 255;
			}
			//G について
			if (z < a1){
				g = 255 - (255 * z) / a1;
			}
			else if (z >= a1 && a3 >= z){
				g = 255;
			}
			else {
				g = 255 - 255 * (z - a3) / (255 - a3);
			}
			//B について
			if (z < a1){
				b = 255;
			}
			else if (z >= a1 && z <= a2) {
				b = 255 - 255 * (z - a1) / (a2 - a1);
			}
			else {
				b = 0;
			}
			
			timage[y][x][0] = r;
			timage[y][x][1] = g;
			timage[y][x][2] = b;
		}
	}
}

void show_pict(void)//画面に描く内容
{
	int x, y;
	unsigned  char	gray,r,g,b;
	glclear( );					// 画面クリア
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			gray = grayimage[y][x];
			glcolor(gray, gray, gray);	//(r, g, b)の色で
			gpnt(x, y);			//(x, y)座標に点を打つ
			r = timage[y][x][0];
			g = timage[y][x][1];
			b = timage[y][x][2];
			glcolor(r, g, b);	//(r, g, b)の色で
			gpnt(x-width, y);	
			
		}
	}
	glflush();
}

void loadgrayimage(void){
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
	
