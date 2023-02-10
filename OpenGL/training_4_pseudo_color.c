/*bmp�`���̃O���[�X�P�[���摜��ǂݍ����
  �^���J���[�摜�֕ϊ�����.*/

#include <stdio.h>
#include "opgls.ft"


#define MAXSIZE 380 				/* �摜�̍ő�T�C�Y */
unsigned  char grayimage[MAXSIZE][MAXSIZE]; 	/* �O���[�X�P�[���摜 */
unsigned  char timage[MAXSIZE][MAXSIZE][3]; /* �ϊ���摜 */
int width, height, cm;  			/* �摜�̕�, ����, �J���[�����m�N���� */
unsigned  char dat[MAXSIZE*MAXSIZE]; 		/* bmp�摜��ǂݍ��ނ��߂̑��ϐ� */



// �v���g�^�C�v�錾 
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

/* �^���J���[�ϊ� */
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
			
			// �����ɒǉ�
			//R �ɂ���
			if (z < a2){
				r = 0;
			}
			else if (z >= a2 && a3 >= z){
				r = 255 - 255 * (z - a2) / (a3 - a2);
			}
			else {
				r = 255;
			}
			//G �ɂ���
			if (z < a1){
				g = 255 - (255 * z) / a1;
			}
			else if (z >= a1 && a3 >= z){
				g = 255;
			}
			else {
				g = 255 - 255 * (z - a3) / (255 - a3);
			}
			//B �ɂ���
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

void show_pict(void)//��ʂɕ`�����e
{
	int x, y;
	unsigned  char	gray,r,g,b;
	glclear( );					// ��ʃN���A
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			gray = grayimage[y][x];
			glcolor(gray, gray, gray);	//(r, g, b)�̐F��
			gpnt(x, y);			//(x, y)���W�ɓ_��ł�
			r = timage[y][x][0];
			g = timage[y][x][1];
			b = timage[y][x][2];
			glcolor(r, g, b);	//(r, g, b)�̐F��
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
	
