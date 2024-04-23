#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <algorithm>

//特殊役 kokushi
//赤ドラ
//牌に色
//ポン


/*ヘッダファイル*/

// 萬子：11,12,13,14,15,16,17,18,19
//索子：21,22,23,24,25,26,27,28,29
//筒子：31,32,33,34,35,36,37,38,39
//風牌：41,42,43,44
//三元牌：51,52,53
//34種＊4　136枚
//x,y = 120,30 表示領域

//名前空間 std
using namespace std;

//変数の宣言
int wanpai[136] = { 0 }; //王牌の配列
const int w_size = 136; //王牌配列のサイズ
int w_cursor = 0; //王牌の位置
const int t_size = 13; //手配のサイズ
int d_cursor = 0; //新ドラの位置
int dora[4] = { 0 }; //ドラ表示牌
int p_cursor = 13; //プレイヤーのカーソルの位置
int state_key = 0; //キー状態
string hai_data1; //一時データに保存されている牌
string hai_data2; //その2
int d_posx = 94; //ドラ表示位置
int d_posy = 0; //ドラ表示位置
int oya = 0; //親
int m_posx = 20; //待ち表示位置
int m_posy = 0; //待ち表示位置
int sellct_posx = 90; //選択表示位置
int sellct_posy = 25; //選択表示位置


//列挙型の宣言
enum state_key {
	LEF = 0, //左
	RIG = 1, //右
	ENT = 2, //決定
	UP = 3, //上
	DWN = 4 //下
};

enum furo_type
{
	PON = 0,
	TII = 1,
	KAN = 2
};

//関数の宣言
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


//クラスの宣言
class Player            
{
public:

	int tehai[14] = {999,999,999,999,999,999,999,999,999,999,999,999,999,999}; //手配配列
	int tumo_hai; //ツモ牌
	int machi[13] = {999,999,999,999,999,999,999,999,999,999,999,999,999}; //待ち牌配列
	int m_cursor = 0; //待ち牌カーソル
	int m_size = 13; //待ち牌配列サイズ
	int kawa[18] = { 0 }; //河配列
	int k_cursor = 0; //河配列の位置
	int k_posx; //河表示位置x
	int k_posy; //河表示位置y
	int t_posx; //手配表示位置x
	int t_posy; //手配表示位置y
	int naki[12] = { 999,999,999,999,999,999,999,999,999,999,999,999 }; //鳴き配列
	int n_cursor = 0; //鳴き配列カーソル
	int n_cnt = 0; //鳴きカウント
	bool naki_flg = false; //鳴きフラグ
	int n_posx; //鳴き表示位置x
	int n_posy; //鳴き表示位置y

	bool tenpai_flg = false; //テンパイフラグ
	bool chitoi_flg = false; //七対子フラグ
	int m_type = 0;
	enum m_type {
		NON = 0, //待ちなし
		TAN = 1, //単騎待ち
		RYA = 2, //両面待ち
		SYA = 3, //シャボ待ち
		KAN = 4, //間張待ち
		PEN = 5 //辺張待ち
	};

	void tumo_junction(); //ツモフロー分岐
	void ptumo_flow(); //playerのツモフロー
	void ctumo_flow(); //cpuのツモフロー
	bool tenpai_ju(); //テンパイ判定
	int player_no = 0; //プレイヤーナンバー
	void reach_sellect(); //リーチ選択
	bool reach_flg = false; //リーチフラグ
	void tumoagari_check(); //ツモあがりの確認
	void tumo_select(); //ツモ選択
	bool tumo_flg = false; //ツモフラグ
	void disp_tumo(); //メッセージ　ツモ
	bool ron_flg = false; //ロンフラグ
	void ronagari_check(); //ロンあがりチェック
	void ron_select(); //ロン選択
	void disp_ron(); //メッセージ　ロン
	bool pon_flg = false; //ポンフラグ
	bool tii_flg = false; //チーフラグ
	void pontii_check(); //ポン・チーチェック
	void pontii_select(int ponf,int tiif,int p1,int p2,int t1,int t2,int t3,int t4,int t5,int t6,int pn); //ポン・チー選択 引数：鳴ける場所 鳴き先のプレイヤー
	void disp_pon(); //メッセージ　ポン
	void disp_tii(); //メッセージ　チー
    int fc = 0; //副露の回数

	class Furo //副露クラス
	{
	public:
		int naki[4] = { 999,999,999,999 }; 
		int n_saki = 0;
		
	}furo[4];

private:

	int tehaij[14] = { 999,999,999,999,999,999,999,999,999,999,999,999,999,999 }; //チェック用配列 雀頭優先
	int tehaim[14] = { 999,999,999,999,999,999,999,999,999,999,999,999,999,999 }; //メンツ毎に揃えた配列 雀頭優先
	int tm_cursor = 0;
    bool atama_flg = false; //雀頭フラグ
	bool tenpai_juflg = false; //テンパイフラグ(戻り値)

	void ko_check(); //刻子チェック
	void sy_check(); //順子チェック
	void he_check(); //雀頭チェック
	void ko_checkrev(); //刻子チェック逆順
	void sy_checkrev(); //順子チェック逆順
	void he_checkrev(); //雀頭チェック逆順
	void ma_check(); //待ちチェック
	void check_order(int a,int b,int c); //順にチェック 雀頭：1　順子：2　刻子：3　
	void chitoi_check(); //七対子チェック

}player[4]; //4人のplayerオブジェクト([0]が操作プレイヤー)

// カーソル位置指定 for Windows Console
void setCursorPos(int x, int y)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}

