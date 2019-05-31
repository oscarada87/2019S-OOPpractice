#ifndef CHERO_H
#define CHERO_H

#include "CGameMap.h"
//#include "CMonster.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
	class CHero
	{
	public:
		CHero();
		void OnMove(Gamemap * m, vector<int> monsterloc);					// 移動英雄
		void OnShow(Gamemap * m);					// 將英雄圖形貼到畫面
		int  GetX1();					// 英雄左上角 x 座標
		int  GetY1();					// 英雄左上角 y 座標
		int  GetX2();					// 英雄右下角 x 座標
		int  GetY2();					// 英雄右下角 y 座標
		int  GetCenterX();					// 英雄中心 x 座標
		int  GetCenterY();					// 英雄中心 y 座標
		int	 Get_format_state();		// 靜止方向(1上2下3左4右)
		void Initialize();				// 設定英雄為初始值
		void LoadBitmap();				// 載入圖形
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定英雄左上角座標
		void what_format_show(int x, int y);		// 顯示哪個方向
		void Set_format_state(int x);		// 設定方向
		void SpeedUp();					// 加速
		void SpeedInit();				// 回到原本
		bool HitMonster(vector<int> monsterloc);
		bool HitSomething(int tx1, int ty1, int tx2, int ty2);	// 是否碰到東西(輸入左上右下座標)
		void SetHit(bool flag);
		bool GetHit();						// 設定攻擊型態
		void Sethp(int attack);				// 扣多少血
		void SetHeal(bool flag);			// 設定是否正在回血
		int  Gethp();						// 得到血量
		void Teleport(Gamemap * m, vector<int> monsterloc);					//順移
		void SetCastTime(int number, int time);		//設定冷卻時間 (1基本攻擊 2技能A 3技能B 4技能C)
		bool CheckCooldown(int number, int counter, int cooldown);	//檢查冷卻時間 (1基本攻擊 2技能A 3技能B 4技能C)
	protected:
		CAnimation animation1;		// 擦子的動畫
		CAnimation animation2;		// 擦子的動畫
		CAnimation animation3;		// 擦子的動畫
		CAnimation animation4;		// 擦子的動畫
		CMovingBitmap down_format;  // 開始人物位置
		CMovingBitmap right_format;  // 右靜止位置
		CMovingBitmap left_format;	// 左靜止位置
		CMovingBitmap up_format;		// 上靜止位置
		CAnimation up_hit_format;// 上攻擊位置
		CAnimation down_hit_format;// 下攻擊位置
		CAnimation left_hit_format;// 左攻擊位置
		CAnimation right_hit_format;// 右攻擊位置
		CAnimation heal_format;		// 回血動畫
		int format_state;			// 靜止方向(1上2下3左4右)
		int x, y;					// 擦子左上角座標
		int speed;					// 移動速度
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isHitting;				// 是否正在攻擊
		vector <int> castTime;		// 冷卻時間 (1基本攻擊 2技能A 3技能B 4技能C)
		int  hp;					// 血量
		bool heal;
		bool monsterIsEmpty(int x, int y, vector<int> monsterloc, Gamemap *map);
	};
}

#endif