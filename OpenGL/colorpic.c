/*bmp�`���̃J���[�摜��ǂݍ���ŕ\������.*/

#include <stdio.h>
#include "opgls.ft"


#define MAXSIZE 380 				/* �摜�̍ő�T�C�Y */
unsigned  char colorimage[MAXSIZE][MAXSIZE][3]; /* �J���[�摜 */
int width, height, cm;  			/* �摜�̕�, ����, �J���[�����m�N���� */
unsigned  char dat[MAXSIZE*MAXSIZE*3]; 		/* bmp�摜��ǂݍ��ނ��߂̑��ϐ� */

// �v���g�^�C�v�錾 
void show_pict(void);
void loadcolorimage(void);

int main(void)
{
	loadcolorimage( );
	ginit(1);
	gdisplay(show_pict);
	return 0;
}

void show_pict(void)//��ʂɕ`�����e
{
	int x, y;
	unsigned  char	r, g, b;
	glclear( );				// ��ʃN���A
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			b = colorimage[y][x][0];
			g = colorimage[y][x][1];
			r = colorimage[y][x][2];
			glcolor(r, g, b);	//(r, g, b)�̐F��
			gpnt(x, y);		//(x, y)���W�ɓ_��ł�
		}
	}
	glflush();
}

void loadcolorimage(void)
//  bmp�`���̃J���[�摜��ǂݍ���
//  �z��colorimage[y][x][3]�Ɋi�[����
//
//  �ǂݍ���bmp�`���̉摜�t�@�C�������w�肵�Ă�������
//  �ȉ����O���[�o���ϐ��Œ�`���Ă�������
//  #define MAXSIZE 380 				/* �摜�̍ő�T�C�Y */
//  unsigned  char colorimage[MAXSIZE][MAXSIZE][3]; 	/* �O���[�X�P�[���摜 */
//  int width, height, cm;  				/* �摜�̕�, ����, �J���[�����m�N���� */
//  unsigned  char dat[MAXSIZE*MAXSIZE*3]; 		/* bmp�摜��ǂݍ��ނ��߂̑��ϐ� */

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
	
