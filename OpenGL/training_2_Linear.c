/* ���`�ȔZ�x�ϊ��ɂ���ăR���g���X�g���������摜�ƌ��摜��\������ ( Linear density conversion ) */
#include	<stdio.h>
#include	"opgls.ft"

#define MAXSIZE 380 /* �摜�̍ő�T�C�Y */
unsigned  char grayimage[MAXSIZE][MAXSIZE]; /* �摜 */
unsigned  char timage[MAXSIZE][MAXSIZE]; /* �ϊ���摜 */
int width, height, cm;  /* �摜�̕�, ����, �J���[�����m�N���� */
unsigned  char dat[MAXSIZE*MAXSIZE]; /* bmp�摜��ǂݍ��ނ��߂̑��ϐ� */

/* �v���g�^�C�v�錾 */
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

void show_pict(void)//��ʂɕ`�����e
{
	int x, y;
	unsigned  char	gray;
	glclear( );				// ��ʃN���A
	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			gray = grayimage[y][x];
			glcolor(gray, gray, gray);
			gpnt(x, y);		//��1�ی��Ɍ��摜��\��
			
			gray = timage[y][x];
			glcolor(gray, gray, gray);
			gpnt(x-width, y);	//��2�ی��ɕϊ���̉摜��\��
		}
	}
	glflush();
}

void senkei(void)
{
	double tz,z,Zmax,Zmin;
	int x, y;
	Zmax = 200; //���`�Z�x�ϊ����s���Ƃ��̍ő�l
	Zmin = 60; //���`�Z�x�ϊ����s���Ƃ��̍ŏ��l
	
	for (y = 0; y < height; y++){
		for (x = 0; x < width; x++){
			z = grayimage[y][x];
			
			/* �����ɒǉ����ĉ����� */
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
//  bmp�`���̃J���[�摜��ǂݍ���
//  �z��grayimage[y][x]�Ɋi�[����
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
