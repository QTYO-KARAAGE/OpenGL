/*bmp�`���̃O���[�X�P�[���摜��ǂݍ���ŕ\������.*/

#include <stdio.h>
#include "opgls.ft"


#define MAXSIZE 380 				/* �摜�̍ő�T�C�Y */
unsigned  char grayimage[MAXSIZE][MAXSIZE]; 	/* �O���[�X�P�[���摜 */
int width, height, cm;  			/* �摜�̕�, ����, �J���[�����m�N���� */
unsigned  char dat[MAXSIZE*MAXSIZE]; 		/* bmp�摜��ǂݍ��ނ��߂̑��ϐ� */

// �v���g�^�C�v�錾 
void show_pict(void);
void loadgrayimage(void);

int main(void)
{
	loadgrayimage( );
	ginit(1);
	gdisplay(show_pict);
	return 0;
}

void show_pict(void)//��ʂɕ`�����e
{
	int x, y;
	unsigned  char	gray;
	glclear( );					// ��ʃN���A
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			gray = grayimage[y][x];
			glcolor(gray, gray, gray);	//(r, g, b)�̐F��
			gpnt(x, y);			//(x, y)���W�ɓ_��ł�
		}
	}
	glflush();
}

void loadgrayimage(void)
//  bmp�`���̃O���[�X�P�[���摜��ǂݍ���
//  �z��grayimage[y][x]�Ɋi�[����
//
//  �ǂݍ���bmp�`���̉摜�t�@�C�������w�肵�Ă�������
//  �ȉ����O���[�o���ϐ��Œ�`���Ă�������
//  #define MAXSIZE 380 			/* �摜�̍ő�T�C�Y */
//  unsigned  char grayimage[MAXSIZE][MAXSIZE]; /* �O���[�X�P�[���摜 */
//  int width, height, cm;  			/* �摜�̕�, ����, �J���[�����m�N���� */
//  unsigned  char dat[MAXSIZE*MAXSIZE]; 	/* bmp�摜��ǂݍ��ނ��߂̑��ϐ� */

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
	
