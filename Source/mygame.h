/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CHero.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include <vector>
#include "CGameMap.h"
#include "CHero.h"
#include "CBall.h"
#include "CMonster.h"
#include "CSpell.h"
#include "CBouncingBall.h"

//法術
#include "FireBall.h"
#include "Maneuver.h"
#include "Wizard.h"

//怪物
#include "Slime.h"
#include "Cow.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_DING,				
		AUDIO_LAKE,				
		AUDIO_NTUT,				
		AUDIO_STARTOST,			
		AUDIO_HELP,
		AUDIO_END,
		AUDIO_EARTH,
		AUDIO_STEP,
		AUDIO_RUN,
		AUDIO_KNIFE,
		AUDIO_KNIFEHIT,
		AUDIO_WIN,
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap gamestart;								// mainpage
		CMovingBitmap helpbar;									// help
		bool help;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap	background;	
		CMovingBitmap	help;		
		vector<CSpell*> heroSpells;		// 英雄法術陣列
		vector<CSpell*> monsterSpells;	// 怪物法術陣列
		vector<Gamemap*>gamemap;		// 背景圖
		CMovingBitmap	corner;			// 角落圖
		vector<CMovingBitmap*> heart;	// 生命
		CHero			hero;
		CInteger		hits_left;	// 剩下的撞擊數
		CInteger        hp_left;	// 英雄血量
		CMovingBitmap   smallhero;  // 示意
		CBouncingBall   bball;		// 反覆彈跳的球
		vector<CMonster*> monsters; // 怪物二維陣列
		Slime           slime;		// 史萊姆
		/*商店*/
		CMovingBitmap   store;		
		CMovingBitmap   storemoney;		
		CMovingBitmap   storezing;		
		CMovingBitmap   storeoil;		
		CMovingBitmap   storebus;		
		CMovingBitmap   storemazu;		
		/*卡牌*/
		CMovingBitmap   storemoneycard;
		CMovingBitmap   storezingcard;
		CMovingBitmap   storeoilcard;
		CMovingBitmap   storebuscard;
		CMovingBitmap   storemazucard;
		int buy;
		bool showdescription;
		CMovingBitmap   lazer;			//lazer
		int				counterlazer;
		bool            lazeropen;
		int				counter;	//計時器
		int				stage;		//第幾張地圖/第幾隻怪物
		/*stage2 shield heart trapzone*/
		CMovingBitmap   shield;
		CMovingBitmap   heart2;
		CMovingBitmap   trapzone;
		bool			shieldon;
		bool			heart2on;
		bool			trapzoneon;
		bool			zattack;
		/*stage 3*/
		int             attacktrap;
		bool            shift;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap gameend;

	};

	class CGameStateOver2 : public CGameState {
	public:
		CGameStateOver2(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap gamewin;

	};

}