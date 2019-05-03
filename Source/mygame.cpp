/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
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
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CHero.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include <vector>
namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
	: CGameState(g)
{
	help = false;
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0);	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	gamestart.LoadBitmap(IDB_GAMESTART);
	helpbar.LoadBitmap(IDB_HELPBAR);
	Sleep(100);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	CAudio::Instance()->Load(AUDIO_HELP, "sounds\\HELP.mp3");
	if (CAudio::Instance()->Load(AUDIO_STARTOST, "sounds\\startost.mp3"))
		CAudio::Instance()->Play(AUDIO_STARTOST, true);
		
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}
void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_W = 0x57;
	if (nChar == KEY_W)
	{
		CAudio::Instance()->Play(AUDIO_HELP, true);
		if (help) {
			help = false;
		}
		else {
			help = true;
		}
	}
}
void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	const char KEY_W = 0x57;

	if (nChar == KEY_W)
		CAudio::Instance()->Stop(AUDIO_HELP);
	if (nChar == KEY_SPACE) {
		CAudio::Instance()->Stop(AUDIO_STARTOST);
		GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
	}
	else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//CAudio::Instance()->Stop(AUDIO_STARTOST);
	//GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	//
	// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
	//
	//CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	//fp=pDC->SelectObject(&f);					// 選用 font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	//if (ENABLE_GAME_PAUSE)
	//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	//pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	//CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	//
	//gamestart
	//
	gamestart.SetTopLeft(0, 0);
	gamestart.ShowBitmap();
	if (help) {
		helpbar.SetTopLeft(0, 80);
		helpbar.ShowBitmap();
	}
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
	: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	/*
	counter--;
	if (counter < 0)
		GotoGameState(GAME_STATE_INIT);
	*/
}

void CGameStateOver::OnBeginState()
{
	//counter = 30 * 5; // 5 seconds
	CAudio::Instance()->Play(AUDIO_END, true);
}

void CGameStateOver::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	gameend.LoadBitmap(IDB_ENDMUSIC);
	CAudio::Instance()->Load(AUDIO_END, "sounds\\end.mp3");
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
}
void CGameStateOver::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE) {
		CAudio::Instance()->Stop(AUDIO_END);
		GotoGameState(GAME_STATE_INIT);						// 切換至GAME_STATE_INIT
	}
}
void CGameStateOver::OnShow()
{
	/*
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240, 210, str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	*/

	gameend.SetTopLeft(0, 0);
	gameend.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g), NUMBALLS(28)
{
}

CGameStateRun::~CGameStateRun()
{
	heroSpells.clear();
	heroSpells.shrink_to_fit();
	heart.clear();
	heart.shrink_to_fit();
}

void CGameStateRun::OnBeginState()
{
	counter = 0;
	hero.Initialize();
	slime.Initialize();
	gamemap.Initialize();
	for (int i = 0; i != slime.GetHP(); i++)
	{
		heart.push_back(new CMovingBitmap());
		heart.at(i)->LoadBitmap(IDB_HEART, RGB(255, 255, 255));
		heart.at(i)->SetTopLeft(0 + 28 * i, 0);
	}
	CAudio::Instance()->Play(AUDIO_EARTH, true);
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//
	// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	counter++;
	gamemap.OnMove();//地圖

	//判斷史萊姆血量
	if (slime.GetHP() <= 0)
	{
		CAudio::Instance()->Stop(AUDIO_KNIFE);
		CAudio::Instance()->Stop(AUDIO_KNIFEHIT);
		CAudio::Instance()->Stop(AUDIO_EARTH);
		GotoGameState(GAME_STATE_OVER);
	}

	hero.OnMove(&gamemap, &slime);
	slime.OnMove(hero.GetX1(), hero.GetY1(), &gamemap);
	// 怪物攻擊
	switch (slime.Skill(counter))
	{
	case 0:
		break;
	case 1:
		slime.MinusHP(-1);
		break;
	case 2:
		monsterSpells.push_back(new FireBall(slime.GetCenterX(), slime.GetCenterY(), counter));
		monsterSpells.back()->LoadBitmap();
		monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
		monsterSpells.push_back(new FireBall(slime.GetCenterX(), slime.GetCenterY(), counter));
		monsterSpells.back()->LoadBitmap();
		monsterSpells.back()->CalculateUnitVector(hero.GetX2(), hero.GetY2());
		monsterSpells.push_back(new FireBall(slime.GetCenterX(), slime.GetCenterY(), counter));
		monsterSpells.back()->LoadBitmap();
		monsterSpells.back()->CalculateUnitVector(hero.GetX2(), hero.GetY2());
		monsterSpells.push_back(new FireBall(slime.GetCenterX(), slime.GetCenterY(), counter));
		monsterSpells.back()->LoadBitmap();
		monsterSpells.back()->CalculateUnitVector(hero.GetX2(), hero.GetY2());
		break;
	default:
		break;
	}

	// 技能移動
	for (auto it = heroSpells.begin(); it != heroSpells.end();) {
		if ((*it)->CheckDuration(counter))
		{
			(*it)->OnMove();
			it++;
		}
		else 
		{
			delete *it;
			it = heroSpells.erase(it);
		}
	}

	for (auto it = monsterSpells.begin(); it != monsterSpells.end();) {
		if ((*it)->CheckDuration(counter))
		{
			(*it)->OnMove();
			it++;
		}
		else
		{
			delete *it;
			it = monsterSpells.erase(it);
		}
	}

	// 判斷技能是否打中怪物

	for (auto it = heroSpells.begin(); it != heroSpells.end();) {
		if ((*it)->HitSomething(&slime) && slime.GetHP() > 0)
		{
			delete *it;
			it = heroSpells.erase(it);
			try 
			{
				slime.SetHitted(1, counter);
				//heart.pop_back();
			}
			catch (...) 
			{

			}
		}
		else 
		{
			it++;
		}
	}
	slime.HitAnimation(counter);

	// 怪物血量
	for (int i = heart.size(); i <= slime.GetHP(); i++)
	{
		heart.push_back(new CMovingBitmap());
		heart.at(i)->LoadBitmap(IDB_HEART, RGB(255, 255, 255));
		heart.at(i)->SetTopLeft(0 + 28 * i, 0);
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
	//
	// 開始載入資料
	//
	// 完成部分Loading動作，提高進度
	//
	ShowInitProgress(50);
	Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 繼續載入其他資料
	//

	hero.LoadBitmap();
	gamemap.LoadBitmap();	//地圖
	slime.LoadBitmap();

	store.LoadBitmap(IDB_store, RGB(255, 255, 255));
	storebus.LoadBitmap(IDB_bus, RGB(255, 255, 255));
	storemazu.LoadBitmap(IDB_mazu, RGB(255, 255, 255));
	storemoney.LoadBitmap(IDB_money, RGB(255, 255, 255));
	storeoil.LoadBitmap(IDB_oil, RGB(255, 255, 255));
	storezing.LoadBitmap(IDB_zingping, RGB(255, 255, 255));

	CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
	CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
	CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
	CAudio::Instance()->Load(AUDIO_STEP, "sounds\\step.mp3");
	CAudio::Instance()->Load(AUDIO_RUN, "sounds\\run.mp3");
	CAudio::Instance()->Load(AUDIO_KNIFE, "sounds\\knife.mp3");
	CAudio::Instance()->Load(AUDIO_KNIFEHIT, "sounds\\knifehit.mp3");
	CAudio::Instance()->Load(AUDIO_EARTH, "sounds\\earth.mp3");
	
	/*
	for (auto it = heroSpells.begin(); it != heroSpells.end(); it++) {
		(*it)->LoadBitmap();
	}
	*/

	//
	// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
	//
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_Z = 0x5A; //keyboard Z
	const char KEY_SHIFT = 0x10; // keyboard Shift 加速
	const char KEY_SPACE = 0x20; //keyboard Space 火球


	if (nChar == KEY_Z)
	{
		CAudio::Instance()->Play(AUDIO_KNIFE, true);
		hero.SetHit(true);
		if (hero.HitMonster(&slime) && slime.GetHP() > 0)
		{
			CAudio::Instance()->Play(AUDIO_KNIFEHIT, true);
			slime.SetHitted(1, counter);
			//heart.pop_back();	
		}	
	}

	if (nChar == KEY_LEFT)
	{
		hero.Set_format_state(3);
		CAudio::Instance()->Play(AUDIO_STEP, true);
		hero.SetMovingLeft(true);
	}
	if (nChar == KEY_RIGHT)
	{
		hero.Set_format_state(4);
		CAudio::Instance()->Play(AUDIO_STEP, true);
		hero.SetMovingRight(true);
	}
	if (nChar == KEY_UP)
	{
		hero.Set_format_state(1);
		CAudio::Instance()->Play(AUDIO_STEP, true);
		hero.SetMovingUp(true);
	}
	if (nChar == KEY_DOWN)
	{
		hero.Set_format_state(2);
		CAudio::Instance()->Play(AUDIO_STEP, true);
		hero.SetMovingDown(true);
	}
	if (nChar == KEY_SHIFT)
	{
		CAudio::Instance()->Play(AUDIO_RUN, true);
		hero.SpeedUp();
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_SHIFT = 0x10; // keyboard SHIFT
	const char KEY_Z = 0x5A; //keyboard Z
	const char KEY_SPACE = 0x20; //keyboard Space 火球

	if (nChar == KEY_Z)
	{
		CAudio::Instance()->Stop(AUDIO_KNIFE);
		CAudio::Instance()->Stop(AUDIO_KNIFEHIT);
		if (hero.GetHit()) 
		{
			hero.SetHit(false);
		}
	}

	if (nChar == KEY_SPACE)
	{
		/*
		if (hero.CheckCooldown(2, counter, 150))
		{
			hero.SetCastTime(2, counter);
			heroSpells.push_back(new FireBall(hero.GetX1(), hero.GetY1(), counter));
			heroSpells.back()->LoadBitmap();
		}
		*/
	}

	if (nChar == KEY_LEFT)
	{
		CAudio::Instance()->Stop(AUDIO_STEP);
		hero.SetMovingLeft(false);
		hero.Set_format_state(3);
	}
	if (nChar == KEY_RIGHT)
	{
		CAudio::Instance()->Stop(AUDIO_STEP);
		hero.SetMovingRight(false);
		hero.Set_format_state(4);
	}
	if (nChar == KEY_UP)
	{
		CAudio::Instance()->Stop(AUDIO_STEP);
		hero.SetMovingUp(false);
		hero.Set_format_state(1);
	}
	if (nChar == KEY_DOWN)
	{
		CAudio::Instance()->Stop(AUDIO_STEP);
		hero.SetMovingDown(false);
		hero.Set_format_state(2);
	}
	if (nChar == KEY_SHIFT)
	{
		CAudio::Instance()->Stop(AUDIO_RUN);
		hero.SpeedInit();
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if (hero.CheckCooldown(2, counter, 30))
	{
		hero.SetCastTime(2, counter);
		heroSpells.push_back(new FireBall(hero.GetCenterX(), hero.GetCenterY(), counter));
		heroSpells.back()->LoadBitmap();
		heroSpells.back()->CalculateUnitVector(point.x + gamemap.GetSX(), point.y + gamemap.GetSY());
		//TRACE("HeroX: %d", hero.GetCenterX());
		//TRACE("HeroY: %d", hero.GetCenterY());
		//TRACE("X: %d", point.x);
		//TRACE("Y: %d", point.y);
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnShow()
{
	gamemap.OnShow();				//地圖

	//商店//
	if (250 <= hero.GetX2() && hero.GetX2() <= 350 && 200 <= hero.GetY2() && hero.GetY2() < 300) {
		storebus.SetTopLeft(gamemap.ScreenX(300), gamemap.ScreenY(0));
		storebus.ShowBitmap();
	}
	else if(250 <= hero.GetX2() && hero.GetX2() <= 350 && 300 <= hero.GetY2() && hero.GetY2() < 400){
		storezing.SetTopLeft(gamemap.ScreenX(300), gamemap.ScreenY(0));
		storezing.ShowBitmap();
	}
	else if (350 < hero.GetX2() && hero.GetX2() <= 500 && 350 <= hero.GetY2() && hero.GetY2() < 450) {
		storemazu.SetTopLeft(gamemap.ScreenX(300), gamemap.ScreenY(0));
		storemazu.ShowBitmap();
	}
	else if (500 < hero.GetX1() && hero.GetX1() <= 600 && 300 <= hero.GetY2() && hero.GetY2() < 400) {
		storeoil.SetTopLeft(gamemap.ScreenX(300), gamemap.ScreenY(0));
		storeoil.ShowBitmap();
	}
	else if (500 < hero.GetX1() && hero.GetX1() <= 600 && 200 <= hero.GetY2() && hero.GetY2() < 300) {
		storemoney.SetTopLeft(gamemap.ScreenX(300), gamemap.ScreenY(0));
		storemoney.ShowBitmap();
	}
	else {
		store.SetTopLeft(gamemap.ScreenX(300), gamemap.ScreenY(0));
		store.ShowBitmap();
	}
	hero.OnShow(&gamemap);// 主角
	gamemap.OnShowonhero();


	slime.OnShow(hero.GetX1(), hero.GetY1(), &gamemap,& hero);

	for (auto it = heart.begin(); it != heart.end(); it++)
	{
		(*it)->ShowBitmap();
	}
	for (auto it = heroSpells.begin(); it != heroSpells.end(); it++) {
		try
		{
			(*it)->OnShow(&gamemap);
		}
		catch (...)
		{

		}
	}
	for (auto it = monsterSpells.begin(); it != monsterSpells.end(); it++) {
		try
		{
			(*it)->OnShow(&gamemap);
		}
		catch (...)
		{

		}
	}
}
}