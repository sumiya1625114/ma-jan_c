#include <iostream>
#include <time.h>
#include <windows.h>
#include"Header.h"
#include <algorithm>



/*���C���֐�*/
int main() {

	

	//��z�E�͕\���ʒu�̐ݒ�
	player[0].k_posx = 55;
	player[0].k_posy = 19;
	player[0].t_posx = 31;
	player[0].t_posy = 28;

	player[1].k_posx = 70;
	player[1].k_posy = 11;
	player[1].t_posx = 116;
	player[1].t_posy = 8;

	player[2].k_posx = 55;
	player[2].k_posy = 8;
	player[2].t_posx = 48;
	player[2].t_posy = 0;

	player[3].k_posx = 48;
	player[3].k_posy = 11;
	player[3].t_posx = 0;
	player[3].t_posy = 8;

	//���\���ʒu�̐ݒ�
	player[0].n_posx = 1;
	player[0].n_posy = 28;

	//�v���C���[����
	player[0].player_no = 0;
	player[1].player_no = 1;
	player[2].player_no = 2;
	player[3].player_no = 3;

	//�Q�[������

	setCursorPos(0, 0);
	cout << "����" ;
		
	//setCursorPos(0, 5);
	//cout << "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";

	//�e����
	RandReset();
	oya = rand() % 4;

	
	//�����̕\��
	setCursorPos(53, 18);
	cout << "�\�\�\�\�\�\�\�\";
	setCursorPos(53, 10);
	cout << "�\�\�\�\�\�\�\�\";
	for (int i = 0; i <= 6; i++) {
		setCursorPos(52, 11+i);
		cout << "|";
	}
	for (int i = 0; i <= 6; i++) {
		setCursorPos(69, 11 + i);
		cout << "|";
	}


	//�΋Ǐ���
	w_reset();
	shuffle();
	haipai();
	d_open();

	//���b�Z�[�W�̈� x=8 y=2 ���� �S�p20����
	setCursorPos(0, 2);
	cout << "message:";

	//�J�n���b�Z�[�W
	setCursorPos(8, 2);
	cout << "�΋ǊJ�n���܂��B";
	setCursorPos(8, 3);
	system("pause");
	message_reset();

	//�΋ǊJ�n
	game_kyoku();
	

	setCursorPos(8, 2);
	return 0;
	}

//���b�Z�[�W�̈�̏�����
void message_reset() {
	setCursorPos(8, 2);
	cout << "�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
	setCursorPos(8, 3);
	cout << "�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
}

/*���v�̏�����*/
void w_reset() {
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;

	//���v
	for (int x = 1; x < 4; x++) {
		j = x * 100;
			for (int y = 1; y < 10; y++) {
				k = j;
				k += y * 10;
				for (int z = 1; z < 5; z++) {
					l = k;
					wanpai[i] = l + z;
					i++;
				}
			}
	 }
	//���v
	for (int x = 1; x < 5; x++) {
		j = 400;
		j += x * 10;
		for (int y = 1; y < 5; y++) {
			k = j;
			wanpai[i] = k + y;
			i++;
		}
	}
	//�O���v
	for (int x = 1; x < 4; x++) {
		j = 500;
		j += x * 10;
		for (int y = 1; y < 5; y++) {
			k = j;
			wanpai[i] = k + y;
			i++;
		}
	}


}

/*���v�̃V���b�t��*/
void shuffle(){
	RandReset();
	for (int i = 0; i < w_size; i++)
		{
			int j = rand() % w_size;
			int t = wanpai[i];
			wanpai[i] = wanpai[j];
		wanpai[j] = t;
		}
}

/*�����̏�����*/
inline void RandReset()
{
	srand((unsigned int)time(NULL));
}

/*�c��*/
int tumo() {
	int i = wanpai[w_cursor];
	w_cursor++;
	return i;
}


/*�z�v*/
void haipai() {
	//player�̔z�v
	for (int i = 0; i < t_size; i++) {
		player[0].tehai[i] = tumo();
	}
	sort(player[0].tehai, player[0].tehai + t_size + 1);
	//cpu1�̔z�v
	for (int i = 0; i < t_size; i++) {
		player[1].tehai[i] = tumo();
	}
	sort(player[1].tehai, player[1].tehai + t_size + 1);
	//cpu2�̔z�v
	for (int i = 0; i < t_size; i++) {
		player[2].tehai[i] = tumo();
	}
	sort(player[2].tehai, player[2].tehai + t_size + 1);
	//cpu3�̔z�v
	for (int i = 0; i < t_size; i++) {
		player[3].tehai[i] = tumo();
	}
	sort(player[3].tehai, player[3].tehai + t_size + 1);
}

/*�h���߂���*/
void d_open() {
	dora[d_cursor] = tumo();
	d_cursor++;
}

/*��ǂ̗���*/
void game_kyoku() {

	int x = oya; //x�ɐe�̃v���C���[No����

	while (w_cursor < 123 ) { //���ǂ܂�

		disp_oya();
		disp_dora();
		disp_kawa();
		disp_tehai();
		disp_machi();
		
		player[x].tumo_junction();
		player[x].ronagari_check();
		player[x].pontii_check();
		
		if (player[x].tumo_flg == true) { //�c��������m�F
			player[x].disp_tumo();
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (player[i].ron_flg == true) { //����������m�F
				player[i].disp_ron();
				return;
			}
		}


		Sleep(500); //�Q�[�����x����
		
		if (x < 3) {
			x++;
		}
		else {
			x = 0;
		}
	}
}

/*�����L�[�̓���*/
int insert_key() {
	int i = 0;
	while (1) {
		if (GetKeyState(VK_LEFT) < 0) {
			i = LEF;
			return(i);
			break;
		}
		else if (GetKeyState(VK_RIGHT) < 0) {
			i = RIG;
			return(i);
			break;
		}
		else if (GetKeyState(VK_RETURN) < 0){
			i = ENT;
			return(i);
			break;
		}
		else if (GetKeyState(VK_UP) < 0) {
			i = UP;
			return(i);
			break;
		}
		else if (GetKeyState(VK_DOWN) < 0) {
			i = DWN;
			return(i);
			break;
		}
		Sleep(1);
	}
}

void henkan(int x) {

	
	int i = 0;
	int keta1;
	int keta2;
	int tmp;

	 keta1 = x / 100;
	 tmp = x % 100;
	 keta2 = tmp / 10;

	 //�S�̈ʂ̏���
	 if (keta1 == 1 || keta1 == 2 || keta1 == 3) {
		 if (keta2 == 1)
			 hai_data1 = "��";
		 if (keta2 == 2)
			 hai_data1 = "��";
		 if (keta2 == 3)
			 hai_data1 = "�O";
		 if (keta2 == 4)
			 hai_data1 = "�l";
		 if (keta2 == 5)
			 hai_data1 = "��";
		 if (keta2 == 6)
			 hai_data1 = "�Z";
		 if (keta2 == 7)
			 hai_data1 = "��";
		 if (keta2 == 8)
			 hai_data1 = "��";
		 if (keta2 == 9)
			 hai_data1 = "��";
	 }
	 if (keta1 == 4 ) {
		 if (keta2 == 1)
			 hai_data1 = "��";
		 if (keta2 == 2)
			 hai_data1 = "��";
		 if (keta2 == 3)
			 hai_data1 = "��";
		 if (keta2 == 4)
			 hai_data1 = "�k";
	 }
	 if (keta1 == 5) {
		 if (keta2 == 1)
			 hai_data1 = "��";
		 if (keta2 == 2)
			 hai_data1 = "�";
		 if (keta2 == 3)
			 hai_data1 = "��";
		 
	 }

	 //�\�̈ʂ̏���
	 if (keta1 == 1) {
		 hai_data2 = "��";
	 }
	 if (keta1 == 2) {
		 hai_data2 = "��";
	 }
	 if (keta1 == 3) {
		 hai_data2 = "��";
	 }
	 if (keta1 == 4) {
		 hai_data2 = "�@";
	 }
	 if (keta1 == 5) {
		 hai_data2 = "�@";
	 }

	 //��̔v�̕\��
	 if (keta1 == 9) {
		 hai_data1 = "�@";
		 hai_data2 = "�@";
	 }
	
}

//�h���\���v�̕\��
void disp_dora() {
	for (int i = 0, j = 0; i < d_cursor; i++, j += 2) {
		setCursorPos(d_posx, d_posy);
		cout << "�h���F";
		henkan(dora[i]);
		setCursorPos(d_posx + 6 + j, d_posy);
		cout << hai_data1;
		setCursorPos(d_posx + 6 + j, d_posy + 1);
		cout << hai_data2;
	}
}

//�e�̕\��
void disp_oya() {
	setCursorPos(80, 0);
	if (oya == 0) {
		cout << "�e�F" << "player";
	}
	else {
		cout << "�e�F" << "cpu" << oya << "  ";
	}
}

//�S�̂̉͂̕\��
void disp_kawa() {

	//�v���C���[
		if (player[0].k_cursor != 0) {
			for (int i = 0, j = 0,k = 0; i < player[0].k_cursor; i++, j += 2) {
				henkan(player[0].kawa[i]);
				setCursorPos(player[0].k_posx + j, player[0].k_posy + k);
				cout << hai_data1;
				setCursorPos(player[0].k_posx + j, player[0].k_posy + 1 + k);
				cout << hai_data2;
				if (i != 0 && (i+1) % 6 == 0) {
					k += 2;
					j = -2;
				}
			}
		}

	//����
		if (player[1].k_cursor != 0) {
			for (int i = 0, j = 0, k = 0; i < player[1].k_cursor; i++, j += 1) {
				henkan(player[1].kawa[i]);
				setCursorPos(player[1].k_posx + k, player[1].k_posy + j);
				cout << hai_data1;
				setCursorPos(player[1].k_posx + k +2, player[1].k_posy + j);
				cout << hai_data2;
				if (i != 0 && (i + 1) % 6 == 0) {
					k += 4;
					j = -1;
				}
			}
		}

	//�Ζ�
		if (player[2].k_cursor != 0) {
			for (int i = 0, j = 0, k = 0; i < player[2].k_cursor; i++, j += 2) {
				henkan(player[2].kawa[i]);
				setCursorPos(player[2].k_posx + j, player[2].k_posy + k);
				cout << hai_data1;
				setCursorPos(player[2].k_posx + j, player[2].k_posy + k + 1);
				cout << hai_data2;
				if (i != 0 && (i + 1) % 6 == 0) {
					k -= 2;
					j = -2;
				}
			}
		}

	//���
		if (player[3].k_cursor != 0) {
			for (int i = 0, j = 0, k = 0; i < player[3].k_cursor; i++, j += 1) {
				henkan(player[3].kawa[i]);
				setCursorPos(player[3].k_posx + k, player[3].k_posy + j);
				cout << hai_data1;
				setCursorPos(player[3].k_posx + k + 2, player[3].k_posy + j);
				cout << hai_data2;
				if (i != 0 && (i + 1) % 6 == 0) {
					k -= 4;
					j = -1;
				}
			}
		}
}

//�S�̂̎�z�̕\��
void disp_tehai() {
	for (int i = 0, j = 4; i < t_size; i++, j += 4) { //�v���C���[
		henkan(player[0].tehai[i]);
		setCursorPos(player[0].t_posx + j, player[0].t_posy);
		cout << hai_data1;
		setCursorPos(player[0].t_posx + j, player[0].t_posy + 1);
		cout << hai_data2;
	}

	for (int i = 0, j = 0; i < t_size; i++, j += 1) { //����
		setCursorPos(player[1].t_posx, player[1].t_posy + j);
		cout << "��";
		setCursorPos(player[1].t_posx + 2, player[1].t_posy + j);
		cout << "��";
	}

	for (int i = 0, j = 0; i < t_size; i++, j += 2) { //�Ζ�
		setCursorPos(player[2].t_posx + j, player[2].t_posy);
		cout << "��";
		setCursorPos(player[2].t_posx + j, player[2].t_posy + 1);
		cout << "��";
	}

	for (int i = 0, j = 0; i < t_size; i++, j += 1) { //���
		setCursorPos(player[3].t_posx, player[3].t_posy + j);
		cout << "��";
		setCursorPos(player[3].t_posx + 2, player[3].t_posy + j);
		cout << "��";
	}

	//���v�̕\��
	for (int i = 0, j = 0; i < player[0].n_cursor; i++, j += 3) { //�v���C���[
		henkan(player[0].naki[i]);
		setCursorPos(player[0].n_posx + j, player[0].n_posy);
		cout << hai_data1;
		setCursorPos(player[0].n_posx + j, player[0].n_posy + 1);
		cout << hai_data2;
	}

}

//�҂��v�̕\��
void disp_machi() {
	for (int i = 0,j = m_posx; i < player[0].m_size; i++,j += 2) {
		setCursorPos(j, m_posy);
		cout << "�@";
		setCursorPos(j, m_posy + 1);
		cout << "�@";
	}

	for (int i = 0,j = m_posx; i < player[0].m_cursor; i++,j += 2) {
		henkan(player[0].machi[i]);
		setCursorPos(j, m_posy);
		cout << hai_data1;
		setCursorPos(j, m_posy + 1);
		cout << hai_data2;
	}
}

//==================================================
void Player::disp_tumo() {
	//�c�����b�Z�[�W
	setCursorPos(8, 2);
	cout << "�c��";
	setCursorPos(8, 3);
	system("pause");
	message_reset();
}
//==================================================
void Player::disp_ron() {
	//�������b�Z�[�W
	setCursorPos(8, 2);
	cout << "����";
	setCursorPos(8, 3);
	system("pause");
	message_reset();
}
//=============================================================
void Player::disp_pon() {
	//�|�����b�Z�[�W
	setCursorPos(8, 2);
	cout << "�|��";
	setCursorPos(8, 3);
	Sleep(500);
	message_reset();
}
//=============================================================
void Player::disp_tii() {
	//�`�[���b�Z�[�W
	setCursorPos(8, 2);
	cout << "�`�[";
	setCursorPos(8, 3);
	Sleep(500);
	message_reset();
}
//=============================================================
void Player::ptumo_flow() {

	p_cursor = t_size; //player�J�[�\���̏�����
	tumo_hai = tumo();
	tehai[t_size] = tumo_hai; //player�̃c��

	//�c���v�̕\��
	henkan(tehai[t_size]);
	setCursorPos(t_size * 4 + 4 + t_posx, t_posy);
	cout << hai_data1;
	setCursorPos(t_size * 4 + 4 + t_posx, t_posy + 1);
	cout << hai_data2;

	//�c��������̊m�F
	tumoagari_check();
	if (tumo_flg == true) {
		return;
	}

	while (1) { //�Ŕv����܂ŌJ��Ԃ�


		//�c���v�̕\��
		henkan(tehai[t_size]);
		setCursorPos(t_size * 4 + 4 + t_posx , t_posy);
		cout << hai_data1;
		setCursorPos(t_size * 4 + 4 + t_posx , t_posy + 1);
		cout << hai_data2;

		//�J�[�\���̍폜
		for (int i = 0, j = 4; i < t_size + 1; i++, j += 4) {
			setCursorPos(t_posx + j - 1, t_posy);
			cout << " ";
			setCursorPos(t_posx + j - 1, t_posy + 1);
			cout << " ";
		}
		
		//�J�[�\���̕\��
		setCursorPos(p_cursor * 4 + 3 + t_posx, t_posy);
		cout << "*";
		setCursorPos(p_cursor * 4 + 3 + t_posx, t_posy + 1);
		cout << "*";


		

		Sleep(200);

		state_key = insert_key();

		if (state_key == LEF) {
			if (p_cursor > 0) {
				p_cursor--;
			}

		}
		else if (state_key == RIG) {
			if (p_cursor < 13) {
				p_cursor++;
			}
		}
		else if (state_key == ENT) {
			break;
		}


	}

	//�Ŕv
	kawa[k_cursor] = tehai[p_cursor];
	k_cursor++;
	tehai[p_cursor] = 999;
	sort(tehai, tehai + t_size + 1);

	//���[�`�m�F
    tenpai_flg = tenpai_ju();

	//���[�`�I��
	if (player[0].reach_flg != true && tenpai_flg == true) {
		player[0].reach_sellect();
	}

	if (reach_flg == true) {
		setCursorPos(m_posx - 8, 0);
		cout << "���[�`�F";
	}
	else if (tenpai_flg == true) {
		setCursorPos(m_posx - 8,0);
		cout << "�҂��v�F";
	}
	else {
		setCursorPos(m_posx - 8,0);
		cout << "�@�@�@�@";
	}

	//��z�̕\���X�V
	disp_tehai();

	//�͂̕\���X�V
	disp_kawa();

	//�҂��v�̕\���X�V
	disp_machi();

	//�J�[�\���̍폜
	for (int i = 0, j = 4; i < t_size + 1; i++, j += 4) {
		setCursorPos(t_posx + j - 1, t_posy);
		cout << " ";
		setCursorPos(t_posx + j - 1, t_posy + 1);
		cout << " ";
	}
	//�c���v�̍폜
	henkan(tehai[t_size]);
	setCursorPos(t_size * 4 + 4 + t_posx, t_posy);
	cout << "�@";
	setCursorPos(t_size * 4 + 4 + t_posx, t_posy + 1);
	cout << "�@";


}
//==================================================
bool Player::tenpai_ju() {

	tenpai_juflg = false;
	m_cursor = 0;

	for (int i = 0; i < m_size; i++) { //�҂��z��̏�����
		machi[i] = 999;
	}


	
	//����1�����q2�����q3 �i��z�����珈���j
	check_order(1 ,2, 3);
	check_order(1, 3, 2);
	check_order(2, 1, 3);
	check_order(2, 3, 1);
	check_order(3, 1, 2);
	check_order(3, 2, 1);
	//����4�����q5�����q6�i��z�E���珈���j
	check_order(4, 5, 6);
	check_order(4, 6, 5);
	check_order(5, 4, 6);
	check_order(5, 6, 4);
	check_order(6, 4, 5);
	check_order(6, 5, 4);
	chitoi_check();


	return tenpai_juflg;
}


//==================================================
void Player::he_check() {
	for (int i = 0; i < t_size - 1; i++) { //�����`�F�b�N
		if (tehaij[i] != 999 && tehaij[i] / 10 == tehaij[i + 1] / 10) {
			for (int j = 0; j < 2; j++) {
				tehaim[tm_cursor] = tehaij[i + j];
				tm_cursor++;
				tehaij[i + j] = 999;
			}
			atama_flg = true;
			sort(tehaij, tehaij + t_size + 1);
			break;
		}
	}
}

void Player::sy_check() {
	for (int i = 0; i < t_size - 1; i++) { //���q�`�F�b�N
		int tmp = 999;
		for (int j = i + 1; j < t_size + 1; j++) {
			if (tehaij[i] / 10 + 1 == tehaij[j] / 10 && tehaij[i] /100 != 4 && tehaij[i] / 100 != 5) { //���v������
				tmp = j;
			}
			if (tmp != 999 && tehaij[i] / 10 + 2 == tehaij[j] / 10) {
				tehaim[tm_cursor] = tehaij[i];
				tehaim[tm_cursor + 1] = tehaij[tmp];
				tehaim[tm_cursor + 2] = tehaij[j];
				tm_cursor += 3;
				tehaij[i] = 999;
				tehaij[tmp] = 999;
				tehaij[j] = 999;
				break;
			}
		}
	}
	sort(tehaij, tehaij + t_size + 1);
}

void Player::ko_check() {
	for (int i = 0; i < t_size - 1; i++) { //���q�`�F�b�N
		if (tehaij[i] != 999 && tehaij[i] / 10 == tehaij[i + 1] / 10 && tehaij[i] / 10 == tehaij[i + 2] / 10) {
			for (int j = 0; j < 3; j++) { 
				tehaim[tm_cursor] = tehaij[i + j];
				tehaij[i + j] = 999;
				tm_cursor++;
			}
		}
	}
	sort(tehaij, tehaij + t_size + 1);
}
//==================================================
void Player::ma_check() {
	bool sameflg = false;
	
		if (m_type == SYA) { //�V���{
			for (int i = 0; i < m_size; i++) {
				if (machi[i] / 10 == tehaij[0] / 10) {
					sameflg = true;
					break;
				}
			}
			if (sameflg == false) {
				machi[m_cursor] = tehaij[0];
				m_cursor++;
			}
		}
		else if (m_type == PEN || m_type == RYA) { //���q(�Ӓ��܂�)
			if ((tehaij[0] /10) % 10 != 1) {
				for (int i = 0; i < m_size; i++) {
					if (machi[i] / 10 == tehaij[0] / 10 - 1) {
						sameflg = true;
						break;
					}
				}
				if (sameflg == false) {
					machi[m_cursor] = tehaij[0] - 10;
					m_cursor++;
				}
			}
			if ((tehaij[1] / 10) % 10 != 9) {
				sameflg = false;
				for (int i = 0; i < m_size; i++) {
					if (machi[i] / 10 == tehaij[1] / 10 + 1) {
						sameflg = true;
						break;
					}
				}
				if (sameflg == false) {
					machi[m_cursor] = tehaij[1] + 10;
					m_cursor++;
				}
			}
		}
		else if (m_type == KAN) { //�Ԓ�
			for (int i = 0; i < m_size; i++) {
				if (machi[i] / 10 == tehaij[0] / 10 + 1) {
					sameflg = true;
					break;
				}
			}
			if (sameflg == false) {
				machi[m_cursor] = tehaij[0] + 10;
				m_cursor++;
			}
		}
		else if (m_type == TAN) { //�P�R
			for (int i = 0; i < m_size; i++) {
				if (machi[i] / 10 == tehaij[0] / 10) {
					sameflg = true;
					break;
				}
			}
			if (sameflg == false) {
				machi[m_cursor] = tehaij[0];
				m_cursor++;
			}
		}
		sort(machi, machi + m_size);
}
//==================================================
void Player::check_order(int a, int b, int c) {

	//int tehai2[14] = { 131,141,151,161,171,211,212,231,241,251,321,331,341,999 };

	atama_flg = false;
	tm_cursor = 0;

	for (int i = 0; i < t_size + 1; i++) { //�`�F�b�N�p�z��Ɏ�z���i�[
		tehaij[i] = tehai[i];
	}

	//�ʎq�̃`�F�b�N
	if(a == 1) he_check();
	else if(a == 2) sy_check();
	else if(a == 3) ko_check();
	else if (a == 4) he_checkrev();
	else if (a == 5) sy_checkrev();
	else if (a == 6) ko_checkrev();

	if (b == 1) he_check();
	else if (b == 2) sy_check();
	else if (b == 3) ko_check();
	else if (b == 4) he_checkrev();
	else if (b == 5) sy_checkrev();
	else if (b == 6) ko_checkrev();

	if (c == 1) he_check();
	else if (c == 2) sy_check();
	else if (c == 3) ko_check();
	else if (c == 4) he_checkrev();
	else if (c == 5) sy_checkrev();
	else if (c == 6) ko_checkrev();

	sort(tehaij, tehaij + t_size + 1);

	if (tehaij[2] == 999 && atama_flg == true) { //�s�v�v����̏ꍇ
		if (tehaij[0] / 10 == tehaij[1] / 10) {
			tenpai_juflg = true;
			m_type = SYA;
		}
		else if (tehaij[0] / 10 + 1 == tehaij[1] / 10 && tehaij[0] / 100 != 4 && tehaij[0] / 100 != 5) { //���v������
			if ((tehaij[0] / 10) % 10 == 1 || (tehaij[0] / 10) % 10 == 9) {
				tenpai_juflg = true;
				m_type = PEN;
			}
			else {
				tenpai_juflg = true;
				m_type = RYA;
			}
		}
		else if (tehaij[0] / 10 + 2 == tehaij[1] / 10 && tehaij[0] / 100 != 4 && tehaij[0] / 100 != 5 && (tehaij[0] / 10) % 10 != 9) { //���v�Ǝ�ނ��ׂ��v������
			tenpai_juflg = true;
			m_type = KAN;
		}
		else {
			m_type = NON;
		}
	}
	else if (tehaij[1] == 999 && atama_flg == false) { //�s�v�v����̏ꍇ
		tenpai_juflg = true;
		m_type = TAN;
	}
	else {
		m_type = NON;
	}

	//�����ő҂��v�i�[
	if (m_type != NON) {
		ma_check();
	}
}
//==================================================
void Player::he_checkrev() {
	for (int i = t_size; 0 < i; i--) { //�����`�F�b�N�t��
		if (tehaij[i] != 999 && tehaij[i] / 10 == tehaij[i - 1] / 10) {
			for (int j = 0; j < 2; j++) {
				tehaim[tm_cursor] = tehaij[i - j];
				tm_cursor++;
				tehaij[i - j] = 999;
			}
			atama_flg = true;
			sort(tehaij, tehaij + t_size + 1);
			break;
		}
	}
}

void Player::sy_checkrev() {
	for (int i = t_size; 1 < i; i--) { //���q�`�F�b�N�t��
		int tmp = 999;
		for (int j = i - 1; 0 <= j; j--) {
			if (tehaij[i] / 10 - 1 == tehaij[j] / 10 && tehaij[i] / 100 != 4 && tehaij[i] / 100 != 5) { //���v������
				tmp = j;
			}
			if (tmp != 999 && tehaij[i] / 10 - 2 == tehaij[j] / 10) {
				tehaim[tm_cursor] = tehaij[i];
				tehaim[tm_cursor + 1] = tehaij[tmp];
				tehaim[tm_cursor + 2] = tehaij[j];
				tm_cursor += 3;
				tehaij[i] = 999;
				tehaij[tmp] = 999;
				tehaij[j] = 999;
				break;
			}
		}
	}
	sort(tehaij, tehaij + t_size + 1);
}

void Player::ko_checkrev() {
	for (int i = t_size; 1 < i; i--) { //���q�`�F�b�N�t��
		if (tehaij[i] != 999 && tehaij[i] / 10 == tehaij[i - 1] / 10 && tehaij[i] / 10 == tehaij[i - 2] / 10) {
			for (int j = 0; j < 3; j++) {
				tehaim[tm_cursor] = tehaij[i - j];
				tehaij[i - j] = 999;
				tm_cursor++;
			}
		}
	}
	sort(tehaij, tehaij + t_size + 1);
}
//==================================================
void Player::tumo_junction() {
	if (player_no == 0){ 
		ptumo_flow(); //player�̏ꍇ
	}
	else {
		ctumo_flow(); //cpu�̏ꍇ
	}
}
//==================================================
void Player::ctumo_flow() {

	tumo_hai = tumo();
	tehai[t_size] = tumo_hai; //cpu�̃c��

	//�Ŕv
	kawa[k_cursor] = tehai[t_size]; //�c���؂�
	k_cursor++;
	tehai[t_size] = 999;
	sort(tehai, tehai + t_size + 1);

	
	//�͂̕\���X�V
	disp_kawa();

}
//==================================================
void Player::chitoi_check() {

	//int tehai2[14] = { 121,122,141,142,171,172,211,213,241,242,321,323,341,999 };

	atama_flg = false;
	tm_cursor = 0;
	chitoi_flg = false;

	for (int i = 0; i < t_size + 1; i++) { //�`�F�b�N�p�z��Ɏ�z���i�[
		tehaij[i] = tehai[i];
	}

	//�����c�̃`�F�b�N
	for (int i = 0; i < t_size; i++) { //���Ύq
		if (tehaij[i] != 999 && tehaij[i] / 10 == tehaij[i + 1] / 10) {
			for (int j = 0; j < 2; j++) {
				tehaim[tm_cursor] = tehaij[i + j];
				tehaij[i + j] = 999;
				tm_cursor++;
			}
		}
	}
	sort(tehaij, tehaij + t_size + 1);

	if (tehaij[1] == 999) { //�s�v�v����̏ꍇ
		tenpai_juflg = true;
		chitoi_flg = true;
		m_type = TAN;
	}
	else {
		m_type = NON;
	}

	//�����ő҂��v�i�[
	if (m_type != NON) {
		ma_check();
	}
}
//==================================================
void Player::reach_sellect() {
	
	int s_cursor = 0;

	while (1) {

		//�J�[�\���̍폜
		setCursorPos(sellct_posx - 1, sellct_posy);
		cout << " ";
		setCursorPos(sellct_posx - 1, sellct_posy + 1);
		cout << " ";

		//���[�`�I��\��
		setCursorPos(sellct_posx, sellct_posy);
		cout << "���[�`";
		setCursorPos(sellct_posx, sellct_posy + 1);
		cout << "���s";

		//�J�[�\���̕\��
		setCursorPos(sellct_posx - 1, sellct_posy + s_cursor);
		cout << "*";

		Sleep(200);

		state_key = insert_key();

		if (state_key == UP && s_cursor != 0) {
			s_cursor--;
		}
		else if (state_key == DWN && s_cursor != 1) {
			s_cursor++;
		}
		else if (state_key == ENT) {
			break;
		}
	}

	if (s_cursor == 0) {
		reach_flg = true;
	}
	
	//�J�[�\���̍폜
	setCursorPos(sellct_posx - 1, sellct_posy);
	cout << " ";
	setCursorPos(sellct_posx - 1, sellct_posy + 1);
	cout << " ";

	//���[�`�I��\���폜
	setCursorPos(sellct_posx, sellct_posy);
	cout << "�@�@�@";
	setCursorPos(sellct_posx, sellct_posy + 1);
	cout << "�@�@";

}
//==================================================
void Player::tumoagari_check() {

	for (int i = 0; i < m_size; i++) {
		if (machi[i] / 10 == tumo_hai / 10) {
			if (player_no == 0) {
				tumo_select();
				break;
			}
			else {
				tumo_flg = true;
			}
		}
	}

}
//==================================================
void Player::tumo_select() {

	int s_cursor = 0;

	while (1) {

		//�J�[�\���̍폜
		setCursorPos(sellct_posx - 1, sellct_posy);
		cout << " ";
		setCursorPos(sellct_posx - 1, sellct_posy + 1);
		cout << " ";

		//���[�`�I��\��
		setCursorPos(sellct_posx, sellct_posy);
		cout << "�c��";
		setCursorPos(sellct_posx, sellct_posy + 1);
		cout << "���s";

		//�J�[�\���̕\��
		setCursorPos(sellct_posx - 1, sellct_posy + s_cursor);
		cout << "*";

		Sleep(200);

		state_key = insert_key();

		if (state_key == UP && s_cursor != 0) {
			s_cursor--;
		}
		else if (state_key == DWN && s_cursor != 1) {
			s_cursor++;
		}
		else if (state_key == ENT) {
			break;
		}
	}

	//�J�[�\���̍폜
	setCursorPos(sellct_posx - 1, sellct_posy);
	cout << " ";
	setCursorPos(sellct_posx - 1, sellct_posy + 1);
	cout << " ";

	//���[�`�I��\���폜
	setCursorPos(sellct_posx, sellct_posy);
	cout << "�@�@�@";
	setCursorPos(sellct_posx, sellct_posy + 1);
	cout << "�@�@";

	if (s_cursor == 0) {
		tumo_flg = true;
	}
}
//==================================================
void Player::ronagari_check() {

	for (int pn = 0; pn < 4; pn++) {
		if (pn != player_no) { //�����ȊO
			for (int i = 0; i < m_size; i++) {
				if (player[pn].machi[i] / 10 == kawa[k_cursor - 1] / 10) {
					if (pn == 0) {
						player[pn].ron_select();
						break;
					}
					else {
						player[pn].ron_flg = true;
					}
				}
			}
		}
	}
}
//==================================================
void Player::ron_select() {

	int s_cursor = 0;

	while (1) {

		//�J�[�\���̍폜
		setCursorPos(sellct_posx - 1, sellct_posy);
		cout << " ";
		setCursorPos(sellct_posx - 1, sellct_posy + 1);
		cout << " ";

		//�����I��\��
		setCursorPos(sellct_posx, sellct_posy);
		cout << "����";
		setCursorPos(sellct_posx, sellct_posy + 1);
		cout << "���s";

		//�J�[�\���̕\��
		setCursorPos(sellct_posx - 1, sellct_posy + s_cursor);
		cout << "*";

		Sleep(200);

		state_key = insert_key();

		if (state_key == UP && s_cursor != 0) {
			s_cursor--;
		}
		else if (state_key == DWN && s_cursor != 1) {
			s_cursor++;
		}
		else if (state_key == ENT) {
			break;
		}
	}

	//�J�[�\���̍폜
	setCursorPos(sellct_posx - 1, sellct_posy);
	cout << " ";
	setCursorPos(sellct_posx - 1, sellct_posy + 1);
	cout << " ";

	//�����I��\���폜
	setCursorPos(sellct_posx, sellct_posy);
	cout << "�@�@�@";
	setCursorPos(sellct_posx, sellct_posy + 1);
	cout << "�@�@";

	if (s_cursor == 0) {
		ron_flg = true;
	}
}
//==================================================
void Player::pontii_check() {

	int ponf = 0; //�|���t���O
	int tiif = 0; //�`�[�t���O
	int p1, p2; //�|���ꏊ
	int t1, t2, t3, t4, t5, t6; //�`�[�ꏊ
	p1 = p2 = t1 = t2 = t3 = t4 = t5 = t6 = 999; //������

	//�|���`�F�b�N
	// for (int pn = 0; pn < 4; pn++) {
		if (player_no != 0) { //�����ȊO
			for (int i = 0; i < t_size - 1; i++) {
				if (player[0].tehai[i] / 10 == kawa[k_cursor - 1] / 10 && player[0].tehai[i] / 10 == player[0].tehai[i + 1] / 10) {
					
						ponf = 1;
						p1 = i;
						p2 = i + 1;
						break;
					
					//else { //cpu�̃|��
					//	player[pn].pon_flg = true;
					//}
				}
			}
		}
	// }

	//�`�[�`�F�b�N
	// for (int pn = 0; pn < 4; pn++) {
		if (kawa[k_cursor - 1] / 100 == 4 || kawa[k_cursor - 1] / 100 == 5) { //���v�͔�����
			return;
		}

		if (player_no == 3) { //��Ƃ̂�
			for (int i = 0; i < t_size - 1; i++) {
				if (player[0].tehai[i] / 10 + 2 == kawa[k_cursor - 1] / 10 && t1 == 999) { //�O
					for (int j = 0; j < t_size; j++) {
						if (player[0].tehai[i] / 10 + 1 == player[0].tehai[j] / 10 && t1 == 999) {
							tiif = 1;
							t1 = i;
							t2 = j;
						}
					}
					
				}
				if (player[0].tehai[i] / 10 - 2 == kawa[k_cursor - 1] / 10 && t3 == 999) { //��
					for (int j = 0; j < t_size; j++) {
						if (player[0].tehai[i] / 10 - 1 == player[0].tehai[j] / 10 && t3 == 999) {
							tiif = 1;
							t3 = i;
							t4 = j;
						}
					}

				}
				if (player[0].tehai[i] / 10 + 1 == kawa[k_cursor - 1] / 10 && t5 == 999) { //��
					for (int j = 0; j < t_size; j++) {
						if (player[0].tehai[i] / 10 + 2 == player[0].tehai[j] / 10 && t5 == 999) {
							tiif = 1;
							t5 = i;
							t6 = j;
						}
					}

				}
			}
	    }
	// }

	if (ponf == 1 || tiif == 1) {
		player[0].pontii_select(ponf, tiif, p1, p2, t1, t2, t3, t4, t5, t6,player_no);
	}
	
}
//==================================================
void Player::pontii_select(int ponf, int tiif, int p1, int p2, int t1, int t2, int t3, int t4, int t5, int t6,int pn) {

	int s_cursor = 0;
	int ponc = 999; //�|������J�[�\���ʒu
	int tiic = 999; //�`�[����J�[�\���ʒu
	int conc = 999; //���s����J�[�\���ʒu
	int n_type = 0;
	enum n_type {
		PON = 0, //�|���̂�
		TII = 1, //�`�[�̂�
		DUB = 2  //�|���`�[
	};

	if (ponf == 1 && tiif == 0) {
		n_type = PON;
		ponc = 0;
		conc = 1;
	}
	else if(ponf == 0 && tiif == 1){
		n_type = TII;
		tiic = 0;
		conc = 1;
	}
	else if (ponf == 1 && tiif == 1) {
		n_type = DUB;
		ponc = 0;
		tiic = 1;
		conc = 2;
	}

	while (1) {

		//�J�[�\���̍폜
		setCursorPos(sellct_posx - 1, sellct_posy);
		cout << " ";
		setCursorPos(sellct_posx - 1, sellct_posy + 1);
		cout << " ";
		if (n_type == DUB) {
			setCursorPos(sellct_posx - 1, sellct_posy + 2);
			cout << " ";
		}

		//�|���E�`�[�I��\��
		if (ponf == 1) {
			setCursorPos(sellct_posx, sellct_posy);
			cout << "�|��";
		}
		if (tiif == 1) {
			setCursorPos(sellct_posx, sellct_posy + tiic);
			cout << "�`�[";
		}
		setCursorPos(sellct_posx, sellct_posy + conc);
		cout << "���s";

		//�J�[�\���̕\��
		setCursorPos(sellct_posx - 1, sellct_posy + s_cursor);
		cout << "*";

		Sleep(200);

		state_key = insert_key();

		if (state_key == UP && s_cursor != 0) {
			s_cursor--;
		}
		else if (state_key == DWN && s_cursor != conc) {
			s_cursor++;
		}
		else if (state_key == ENT) {
			break;
		}
	}

	//�J�[�\���̍폜
	setCursorPos(sellct_posx - 1, sellct_posy);
	cout << " ";
	setCursorPos(sellct_posx - 1, sellct_posy + 1);
	cout << " ";
	if (n_type == DUB) {
		setCursorPos(sellct_posx - 1, sellct_posy + 2);
		cout << " ";
	}

	//�|���`�[�I��\���폜
	setCursorPos(sellct_posx, sellct_posy);
	cout << "�@�@";
	setCursorPos(sellct_posx, sellct_posy + 1);
	cout << "�@�@";
	if (n_type == DUB) {
		setCursorPos(sellct_posx - 1, sellct_posy + 2);
		cout << "�@�@";
	}

	//�|���`�[�t���O
	if (s_cursor == ponc) {
		pon_flg = true;
	}
	else if(s_cursor == tiic) {
		tii_flg = true;
	}

	//�|������
	if (pon_flg == true) {
		//���v�i�[
		naki[n_cursor] = tehai[p1];
		n_cursor++;
		tehai[p1] = 999;
		naki[n_cursor] = tehai[p2];
		n_cursor++;
		tehai[p2] = 999;
		naki[n_cursor] = player[pn].kawa[player[pn].k_cursor - 1];
		n_cursor++;
		n_cnt++;

		//����̉͂���폜
		player[pn].kawa[player[pn].k_cursor - 1] = 999;
		player[pn].k_cursor--;

		sort(tehai, tehai + t_size + 1);

		//��z�E�͕\���X�V
		disp_tehai();
		disp_kawa();
		disp_pon();

	}



	//�`�[�ꏊ�I��
	if (tii_flg == true) {

		int tc[6] = { t1,t2,t3,t4,t5,t6 };
		int ts = 6;
		sort(tc, tc + ts);

		int tcnt;
		if (tc[2] == 999)
			tcnt = 0;
		else if (tc[4] == 999)
			tcnt = 1;
		else
			tcnt = 2;

		int tc_cursor = 0;
		int tcnt_cursor = 0;

		while (1) {

			//�J�[�\���̍폜
			for (int i = 0, j = 4; i < t_size + 1; i++, j += 4) {
				setCursorPos(t_posx + j - 1, t_posy);
				cout << " ";
				setCursorPos(t_posx + j - 1, t_posy + 1);
				cout << " ";
			}

			//�J�[�\���̕\��
			setCursorPos(tc[tc_cursor] * 4 + 3 + t_posx, t_posy);
			cout << "*";
			setCursorPos(tc[tc_cursor] * 4 + 3 + t_posx, t_posy + 1);
			cout << "*";
			setCursorPos(tc[tc_cursor + 1] * 4 + 3 + t_posx, t_posy);
			cout << "*";
			setCursorPos(tc[tc_cursor + 1] * 4 + 3 + t_posx, t_posy + 1);
			cout << "*";

			Sleep(200);

			//�L�[����
			state_key = insert_key();

			if (state_key == LEF) {
				if (tcnt_cursor > 0) {
					tcnt_cursor--;
					tc_cursor -= 2;
				}

			}
			else if (state_key == RIG) {
				if (tcnt_cursor < tcnt) {
					tcnt_cursor++;
					tc_cursor += 2;
				}
			}
			else if (state_key == ENT) {
				break;
			}


		}

		//���v�i�[
		naki[n_cursor] = tehai[tc[tc_cursor]];
		n_cursor++;
		tehai[tc[tc_cursor]] = 999;
		naki[n_cursor] = tehai[tc[tc_cursor + 1]];
		n_cursor++;
		tehai[tc[tc_cursor + 1]] = 999;
		naki[n_cursor] = player[pn].kawa[player[pn].k_cursor - 1];
		n_cursor++;
		n_cnt++;

		//����̉͂���폜
		player[pn].kawa[player[pn].k_cursor - 1] = 999;
		player[pn].k_cursor--;

		sort(tehai, tehai + t_size + 1);

		//��z�E�͕\���X�V
		disp_tehai();
		disp_kawa();
		disp_tii();


		//�J�[�\���̍폜
		for (int i = 0, j = 4; i < t_size + 1; i++, j += 4) {
			setCursorPos(t_posx + j - 1, t_posy);
			cout << " ";
			setCursorPos(t_posx + j - 1, t_posy + 1);
			cout << " ";
		}
	}
}
//==================================================