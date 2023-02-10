/* 線形な濃度変換によってコントラスト強調した画像と元画像を表示する ( Linear density conversion ) */
#include	<stdio.h>
#include	"opgls.ft"

#define MAXSIZE 380 /* 画像の最大サイズ */
unsigned  char grayimage[MAXSIZE][MAXSIZE]; /* 画像 */
unsigned  char timage[MAXSIZE][MAXSIZE]; /* 変換後画像 */
int width, height, cm;  /* 画像の幅, 高さ, カラーかモノクロか */
unsigned  char dat[MAXSIZE*MAXSIZE]; /* bmp画像を読み込むための大域変数 */

/* プロトタイプ宣言 */
void show_pict(void);
void loadgrayimage(void);
void senkei(void);

int main(void)
{
	loadgrayimage( );
	ginit(1);
	senkei();
	gdisplay(show_pict);
	return 0;
}

void show_pict(void)//画面に描く内容
{
	int x, y;
	unsigned  char	gray;
	glclear( );				// 画面クリア
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			gray = grayimage[y][x];
			glcolor(gray, gray, gray);
			gpnt(x, y);		//第1象限に元画像を表示
			
			gray = timage[y][x];
			glcolor(gray, gray, gray);
			gpnt(x-width, y);	//第2象限に変換後の画像を表示
		}
	}
	glflush();
}

void senkei(void)
{
	double tz,z,Zmax,Zmin;
	int x, y;
	Zmax = 200; //線形濃度変換を行うときの最大値
	Zmin = 60; //線形濃度変換を行うときの最小値
	
	for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			z = grayimage[y][x];
			
			/* ここに追加して下さい */
			tz = 255 * (z - Zmin)/(Zmax - Zmin);
			tz = (int)tz;
			
			if(tz < 0){
				timage[y][x] = 0;
			}
			else if (tz > 255){
				timage[y][x] = 255;
			}
			else {
				timage[y][x] = tz;
			}

		}
	}
}

void loadgrayimage(void)
//  bmp形式のカラー画像を読み込み
//  配列grayimage[y][x]に格納する
{
	int	 y, x, c;
	loadbmpfile ("Lenna(gray).bmp", &cm, &height, &width, dat);
	printf("hite = %d \n", height);
	printf("wide = %d \n", width);
	for( y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			grayimage[y][x] = dat[ y * width + x ];
		}
	}
}
