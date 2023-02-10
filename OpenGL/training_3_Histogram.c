/* グレースケール画像の濃淡ヒストグラムを画像と共に表示する	*/
/* Display the grayscale histogram of the grayscale image */

#include	<stdio.h>
#include	"opgls.ft"

#define MAXSIZE 380 
unsigned  char grayimage[MAXSIZE][MAXSIZE];
int width, height, cm;
unsigned  char dat[MAXSIZE*MAXSIZE];

int hist[256];		/* histogram */

/* プロトタイプ宣言 */
void show_pict(void);
void loadgrayimage(void);
void	calc_hist (void);
void	normalize (void);

int main(void)
{
	loadgrayimage( );
	calc_hist ( );
	normalize ( );
	ginit(1);
	gdisplay(show_pict);
	return 0;
}


/* ヒストグラムの作成 */
void	calc_hist (void)
{
	int		j, x, y, br;
	
	for (j = 0; j < 256; j++){
		hist[j] = 0;			/* 度数用配列の初期化 */
	}
	for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			j = grayimage[y][x];
			hist[j]++;
		}
	}	
}

/* ヒストグラム表示のための正規化 */
void	normalize (void)
{
	int		j, gmax = 0;			/* 最大度数計算の初期値として0を設定 */
	float   histmax = 246.0;	/* 棒グラフの最大の高さ*/
	float	fgmax;
	
  	for (j = 0; j < 256; j++){
  		if (hist[j] > gmax){
			gmax = hist[j];	/* 最大度数の計算 */
  		}
  	}
  	printf ("Normalized by %d\n", gmax);
	   									/* 最大度数をhistmaxにする正規化の計算 */
	for (j = 0; j < 256; j++){
		fgmax = histmax * hist[j] / gmax;  /* 各度数を正規化する */
		hist[j] = fgmax;
	}
}
	
void	show_pict (void) 
// ヒストグラムと画像の表示
{	
	unsigned  char	c;
	int				j, x, y;
	glclear( );
	
	glcolor(255,255,255);		/* 白でヒストグラムを表示 */
  	for ( j = 0; j < 256; j++){
		gline (j, 10, j, hist[j] + 10);
  	}
	for (j = 0; j < 256; j++){
		glcolor(j, j, j);		/* ヒストグラムの下に濃淡を表示 */
		gline(j, 0, j, 9);
	}
    for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			c = grayimage[y][x];
			glcolor (c, c, c);
			gpnt (x-width, y);		/* 第２象限に原画像を表示 */
		}
 	}
	glflush ( );
}


void loadgrayimage(void)
{
	int	 y, x;
	loadbmpfile ("Lenna(gray).bmp", &cm, &height, &width, dat);
	printf("cm = %d \n", cm);
	printf("height = %d \n", height);
	printf("width = %d \n", width);
	for( y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			grayimage[y][x] = dat[ y * width + x ];
		}
	}
}
