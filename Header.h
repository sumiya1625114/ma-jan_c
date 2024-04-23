#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <algorithm>

//����� kokushi
//�ԃh��
//�v�ɐF
//�|��


/*�w�b�_�t�@�C��*/

// �ݎq�F11,12,13,14,15,16,17,18,19
//���q�F21,22,23,24,25,26,27,28,29
//���q�F31,32,33,34,35,36,37,38,39
//���v�F41,42,43,44
//�O���v�F51,52,53
//34�큖4�@136��
//x,y = 120,30 �\���̈�

//���O��� std
using namespace std;

//�ϐ��̐錾
int wanpai[136] = { 0 }; //���v�̔z��
const int w_size = 136; //���v�z��̃T�C�Y
int w_cursor = 0; //���v�̈ʒu
const int t_size = 13; //��z�̃T�C�Y
int d_cursor = 0; //�V�h���̈ʒu
int dora[4] = { 0 }; //�h���\���v
int p_cursor = 13; //�v���C���[�̃J�[�\���̈ʒu
int state_key = 0; //�L�[���
string hai_data1; //�ꎞ�f�[�^�ɕۑ�����Ă���v
string hai_data2; //����2
int d_posx = 94; //�h���\���ʒu
int d_posy = 0; //�h���\���ʒu
int oya = 0; //�e
int m_posx = 20; //�҂��\���ʒu
int m_posy = 0; //�҂��\���ʒu
int sellct_posx = 90; //�I��\���ʒu
int sellct_posy = 25; //�I��\���ʒu


//�񋓌^�̐錾
enum state_key {
	LEF = 0, //��
	RIG = 1, //�E
	ENT = 2, //����
	UP = 3, //��
	DWN = 4 //��
};

enum furo_type
{
	PON = 0,
	TII = 1,
	KAN = 2
};

//�֐��̐錾
void message_reset();
void w_reset();
void shuffle();
void RandReset();
void haipai();
void d_open();
int insert_key();
void game_kyoku();
void henkan(int x);
void disp_kawa();
void disp_tehai();
void disp_dora();
void disp_machi();
void disp_oya();


//�N���X�̐錾
class Player            
{
public:

	int tehai[14] = {999,999,999,999,999,999,999,999,999,999,999,999,999,999}; //��z�z��
	int tumo_hai; //�c���v
	int machi[13] = {999,999,999,999,999,999,999,999,999,999,999,999,999}; //�҂��v�z��
	int m_cursor = 0; //�҂��v�J�[�\��
	int m_size = 13; //�҂��v�z��T�C�Y
	int kawa[18] = { 0 }; //�͔z��
	int k_cursor = 0; //�͔z��̈ʒu
	int k_posx; //�͕\���ʒux
	int k_posy; //�͕\���ʒuy
	int t_posx; //��z�\���ʒux
	int t_posy; //��z�\���ʒuy
	int naki[12] = { 999,999,999,999,999,999,999,999,999,999,999,999 }; //���z��
	int n_cursor = 0; //���z��J�[�\��
	int n_cnt = 0; //���J�E���g
	bool naki_flg = false; //���t���O
	int n_posx; //���\���ʒux
	int n_posy; //���\���ʒuy

	bool tenpai_flg = false; //�e���p�C�t���O
	bool chitoi_flg = false; //���Ύq�t���O
	int m_type = 0;
	enum m_type {
		NON = 0, //�҂��Ȃ�
		TAN = 1, //�P�R�҂�
		RYA = 2, //���ʑ҂�
		SYA = 3, //�V���{�҂�
		KAN = 4, //�Ԓ��҂�
		PEN = 5 //�Ӓ��҂�
	};

	void tumo_junction(); //�c���t���[����
	void ptumo_flow(); //player�̃c���t���[
	void ctumo_flow(); //cpu�̃c���t���[
	bool tenpai_ju(); //�e���p�C����
	int player_no = 0; //�v���C���[�i���o�[
	void reach_sellect(); //���[�`�I��
	bool reach_flg = false; //���[�`�t���O
	void tumoagari_check(); //�c��������̊m�F
	void tumo_select(); //�c���I��
	bool tumo_flg = false; //�c���t���O
	void disp_tumo(); //���b�Z�[�W�@�c��
	bool ron_flg = false; //�����t���O
	void ronagari_check(); //����������`�F�b�N
	void ron_select(); //�����I��
	void disp_ron(); //���b�Z�[�W�@����
	bool pon_flg = false; //�|���t���O
	bool tii_flg = false; //�`�[�t���O
	void pontii_check(); //�|���E�`�[�`�F�b�N
	void pontii_select(int ponf,int tiif,int p1,int p2,int t1,int t2,int t3,int t4,int t5,int t6,int pn); //�|���E�`�[�I�� �����F����ꏊ ����̃v���C���[
	void disp_pon(); //���b�Z�[�W�@�|��
	void disp_tii(); //���b�Z�[�W�@�`�[
    int fc = 0; //���I�̉�

	class Furo //���I�N���X
	{
	public:
		int naki[4] = { 999,999,999,999 }; 
		int n_saki = 0;
		
	}furo[4];

private:

	int tehaij[14] = { 999,999,999,999,999,999,999,999,999,999,999,999,999,999 }; //�`�F�b�N�p�z�� �����D��
	int tehaim[14] = { 999,999,999,999,999,999,999,999,999,999,999,999,999,999 }; //�����c���ɑ������z�� �����D��
	int tm_cursor = 0;
    bool atama_flg = false; //�����t���O
	bool tenpai_juflg = false; //�e���p�C�t���O(�߂�l)

	void ko_check(); //���q�`�F�b�N
	void sy_check(); //���q�`�F�b�N
	void he_check(); //�����`�F�b�N
	void ko_checkrev(); //���q�`�F�b�N�t��
	void sy_checkrev(); //���q�`�F�b�N�t��
	void he_checkrev(); //�����`�F�b�N�t��
	void ma_check(); //�҂��`�F�b�N
	void check_order(int a,int b,int c); //���Ƀ`�F�b�N �����F1�@���q�F2�@���q�F3�@
	void chitoi_check(); //���Ύq�`�F�b�N

}player[4]; //4�l��player�I�u�W�F�N�g([0]������v���C���[)

// �J�[�\���ʒu�w�� for Windows Console
void setCursorPos(int x, int y)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}

