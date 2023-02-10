/* �O���[�X�P�[���摜�̔Z�W�q�X�g�O�������摜�Ƌ��ɕ\������	*/
/* Display the grayscale histogram of the grayscale image */

#include	<stdio.h>
#include	"opgls.ft"

#define MAXSIZE 380 
unsigned  char grayimage[MAXSIZE][MAXSIZE];
int width, height, cm;
unsigned  char dat[MAXSIZE*MAXSIZE];

int hist[256];		/* histogram */

/* �v���g�^�C�v�錾 */
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


/* �q�X�g�O�����̍쐬 */
void	calc_hist (void)
{
	int		j, x, y, br;
	
	for (j = 0; j < 256; j++){
		hist[j] = 0;			/* �x���p�z��̏����� */
	}
	for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			j = grayimage[y][x];
			hist[j]++;
		}
	}	
}

/* �q�X�g�O�����\���̂��߂̐��K�� */
void	normalize (void)
{
	int		j, gmax = 0;			/* �ő�x���v�Z�̏����l�Ƃ���0��ݒ� */
	float   histmax = 246.0;	/* �_�O���t�̍ő�̍���*/
	float	fgmax;
	
  	for (j = 0; j < 256; j++){
  		if (hist[j] > gmax){
			gmax = hist[j];	/* �ő�x���̌v�Z */
  		}
  	}
  	printf ("Normalized by %d\n", gmax);
	   									/* �ő�x����histmax�ɂ��鐳�K���̌v�Z */
	for (j = 0; j < 256; j++){
		fgmax = histmax * hist[j] / gmax;  /* �e�x���𐳋K������ */
		hist[j] = fgmax;
	}
}
	
void	show_pict (void) 
// �q�X�g�O�����Ɖ摜�̕\��
{	
	unsigned  char	c;
	int				j, x, y;
	glclear( );
	
	glcolor(255,255,255);		/* ���Ńq�X�g�O������\�� */
  	for ( j = 0; j < 256; j++){
		gline (j, 10, j, hist[j] + 10);
  	}
	for (j = 0; j < 256; j++){
		glcolor(j, j, j);		/* �q�X�g�O�����̉��ɔZ�W��\�� */
		gline(j, 0, j, 9);
	}
    for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			c = grayimage[y][x];
			glcolor (c, c, c);
			gpnt (x-width, y);		/* ��Q�ی��Ɍ��摜��\�� */
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
