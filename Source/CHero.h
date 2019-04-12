#ifndef CHERO_H
#define CHERO_H

#include "CGameMap.h"
#include "CMonster.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
	class CHero
	{
	public:
		CHero();
		void OnMove(CGameMap * m);					// 移動擦子
		void OnShow(CGameMap * m);					// 將擦子圖形貼到畫面
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void what_format_show(int x, int y);		// 顯示哪個方向
		void Set_format_state(int x);		// 設定方向
		void SpeedUp();					// 加速
		void SpeedInit();				// 回到原本
		bool HitMonster(CMonster *monster);
		bool HitSomething(int tx1, int ty1, int tx2, int ty2);	// 是否碰到東西(輸入左上右下座標)
		void SetHit(bool flag);
		void Hit();						// 攻擊
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
		int format_state;			// 靜止方向(1上2下3左4右)
		int x, y;					// 擦子左上角座標
		int speed;					// 移動速度
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isHitting;				// 是否正在攻擊
	};
}

#endif