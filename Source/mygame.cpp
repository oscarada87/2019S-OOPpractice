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
	ShowInitProgress(0);	// 一開始的loading進度為0%
	gamestart.LoadBitmap(IDB_GAMESTART);
	helpbar.LoadBitmap(IDB_HELPBAR);
	Sleep(100);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	CAudio::Instance()->Load(AUDIO_HELP, "sounds\\HELP.mp3");
	if (CAudio::Instance()->Load(AUDIO_STARTOST, "sounds\\startost.mp3"))
		CAudio::Instance()->Play(AUDIO_STARTOST, true);
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
}

void CGameStateInit::OnShow()
{
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
}

void CGameStateOver::OnBeginState()
{
	CAudio::Instance()->Play(AUDIO_END, true);
}

void CGameStateOver::OnInit()
{
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	gameend.LoadBitmap(IDB_ENDMUSIC);
	CAudio::Instance()->Load(AUDIO_END, "sounds\\end.mp3");
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	ShowInitProgress(100);
}
void CGameStateOver::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE) {
		CAudio::Instance()->Stop(AUDIO_END);
		GotoGameState(GAME_STATE_INIT);						// 切換至GAME_STATE_INIT
	}
	else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
}
void CGameStateOver::OnShow()
{
	gameend.SetTopLeft(0, 0);
	gameend.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g)
{
	stage = 0;
	buy = 0;
	attacktrap = 0;
	showdescription = false;
	zattack = true;
	shift = false;
}

CGameStateRun::~CGameStateRun()
{
	heroSpells.clear();
	heroSpells.shrink_to_fit();
	monsterSpells.clear();
	monsterSpells.shrink_to_fit();
	heart.clear();
	heart.shrink_to_fit();
	gamemap.clear();
	gamemap.shrink_to_fit();
}

void CGameStateRun::OnBeginState()
{
	hero.SetXY(1000, 1750);
	stage = 0;
	gamemap.at(0)->Initialize();
	counter = 0;
	monsters.clear();
	monsters.push_back(new Slime(5));
	monsters.push_back(new Cow(10));
	monsters.push_back(new Wizard(30));

	for (int i = 0; (size_t)i < monsters.size(); i++) {
		monsters[i]->LoadBitmap();
	}

	for (int i = 0; (size_t)i < monsters.size(); i++) {
		monsters[i]->Initialize();
	}
	hero.Initialize();
	counterlazer = 30 * 2; // 2 seconds
	lazeropen = false;
	shieldon = true;
	heart2on = true;
	trapzoneon = false;
	for (int i = 0; i < 3; i++)
	{
		gamemap.at(i)->Initialize();
	}
	hp_left.SetInteger(hero.Gethp());
	hp_left.SetTopLeft(565,0);
	heart.clear();
	for (int i = 0; i != monsters[stage]->GetHP(); i++)
	{
		heart.push_back(new CMovingBitmap());
		heart.at(i)->LoadBitmap(IDB_HEART, RGB(255, 255, 255));
		heart.at(i)->SetTopLeft(0 + 28 * i, 0);
	}
	CAudio::Instance()->Play(AUDIO_EARTH, true);
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	gamemap.at(stage)->OnMove();//地圖
	if (stage == 0) {
		counterlazer--; //雷射開關
		if (lazeropen == true && (hero.HitSomething(1200, 500, 1600, 501) || hero.HitSomething(1200, 750, 1600, 751)
			|| hero.HitSomething(1200, 1000, 1600, 1001) || hero.HitSomething(1200, 1250, 1600, 1251))) {
			counterlazer = 0;
			hero.Sethp(1);
		}
		else if (lazeropen == false && (hero.HitSomething(1500, 600, 1900, 601) || hero.HitSomething(1500, 850, 1900, 851)
			|| hero.HitSomething(1500, 1100, 1900, 1101) || hero.HitSomething(1500, 1350, 1900, 1351))) {
			counterlazer = 0;
			hero.Sethp(1);
		}
		if (counterlazer <= 0) {
			if (lazeropen == true) {
				lazeropen = false;
				counterlazer = 30 * 2;
			}
			else {
				lazeropen = true;
				counterlazer = 30 * 2;
			}
		}
	}
	if (stage == 1) {
		counterlazer--; //借用計時器
		if (hero.HitSomething(600, 200, 625, 230) && shieldon == true) {
			shieldon = false;//防禦
		}
		if (hero.HitSomething(1700, 1850, 1725, 1880) && heart2on == true) {
			heart2on = false;
			hero.Sethp(-1);
		}
		if (hero.HitSomething(monsters[stage]->GetX1(), monsters[stage]->GetY1()
			, monsters[stage]->GetX2(), monsters[stage]->GetY2()) && trapzoneon == true) {
			zattack = false;
		}
		else {
			zattack = true;
		}
		if (counterlazer <= 0) {
			if (trapzoneon) {
				trapzoneon = false;
				counterlazer = 30 * 2;
			}
			else {
				trapzoneon = true;
				counterlazer = 30 * 2;
			}
		}
		if (gamemap.at(stage)->Istrap(hero.GetX1(), hero.GetY1())) {
			hero.Speeddown();
			zattack = false;
		}else if (shift) {
			hero.SpeedUp();
		}else {
			hero.SpeedInit();
			zattack = true;
		}
	}
	if (stage == 2) {
		if (gamemap.at(stage)->Istrap(hero.GetX1(), hero.GetY1())) {
			attacktrap = attacktrap + 5;
			hero.Speeddown();
		}else if(shift){
			hero.SpeedUp();
		}else {
			hero.SpeedInit();
		}
		if (attacktrap == 100) {
			hero.Sethp(1);
			attacktrap = 0;
		}
	}
	counter++;
	//判斷史萊姆血量
	if (monsters[stage]->GetHP() <= 0 && stage < 2)
	{
		//怪物死亡動畫
		gamemap.at(stage)->Initialize();
		hero.SetXY(1000, 1750);
		stage++;
	}
	else if (monsters[stage]->GetHP() <= 0 && stage == 2)
	{
		CAudio::Instance()->Stop(AUDIO_KNIFE);
		CAudio::Instance()->Stop(AUDIO_KNIFEHIT);
		CAudio::Instance()->Stop(AUDIO_EARTH);
		GotoGameState(GAME_STATE_OVER);
	}
	else if (hero.Gethp() <= 0) 
	{
		CAudio::Instance()->Stop(AUDIO_KNIFE);
		CAudio::Instance()->Stop(AUDIO_KNIFEHIT);
		CAudio::Instance()->Stop(AUDIO_EARTH);
		GotoGameState(GAME_STATE_OVER);
	}
	vector <int> monsterloc;
	monsterloc.push_back(monsters[stage]->GetX1());
	monsterloc.push_back(monsters[stage]->GetY1());
	monsterloc.push_back(monsters[stage]->GetX2());
	monsterloc.push_back(monsters[stage]->GetY2());
	hero.OnMove(gamemap.at(stage), monsterloc);
	monsters[stage]->OnMove(hero.GetX1(), hero.GetY1(), gamemap.at(stage), counter);
	// 怪物攻擊
	if (stage == 0) {
		switch (monsters[stage]->Skill(counter))
		{
		case 0:
			break;
		case 1:
			monsters[stage]->MinusHP(-1);
			break;
		case 2:
			monsterSpells.push_back(new FireBall(monsters[0]->GetCenterX(), monsters[0]->GetCenterY(), counter));
			monsterSpells.back()->LoadBitmap(1);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			monsterSpells.push_back(new FireBall(monsters[0]->GetCenterX(), monsters[0]->GetCenterY(), counter));
			monsterSpells.back()->LoadBitmap(1);
			monsterSpells.back()->CalculateUnitVector(hero.GetX2(), hero.GetY2());
			break;
		default:
			break;
		}
	}
	else if (stage == 1) {
		switch (monsters[stage]->Skill(counter)) 
		{
		case 0:
			break;
		case 1:
			monsterSpells.push_back(new FireBall(monsters[1]->GetCenterX() + 50, monsters[1]->GetCenterY() + 50, counter));
			monsterSpells.back()->LoadBitmap(1);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			break;
		case 2:
			monsterSpells.push_back(new Maneuver(monsters[1]->GetCenterX(), monsters[1]->GetCenterY(), counter));
			monsterSpells.back()->LoadBitmap(0);
			break;
		default:
			break;
		}
	}
	else if (stage == 2) {
		switch (monsters[stage]->Skill(counter))
		{
		case 0:
			break;
		case 1:
			monsterSpells.push_back(new FireBall(monsters[2]->GetCenterX() + 50, monsters[2]->GetCenterY() + 50, counter));
			monsterSpells.back()->LoadBitmap(2);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			monsterSpells.push_back(new FireBall(monsters[2]->GetCenterX() + 150, monsters[2]->GetCenterY() + 150, counter));
			monsterSpells.back()->LoadBitmap(2);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			monsterSpells.push_back(new FireBall(monsters[2]->GetCenterX(), monsters[2]->GetCenterY(), counter));
			monsterSpells.back()->LoadBitmap(2);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			monsterSpells.push_back(new FireBall(monsters[2]->GetCenterX()-150, monsters[2]->GetCenterY(), counter));
			monsterSpells.back()->LoadBitmap(2);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			monsterSpells.push_back(new FireBall(monsters[2]->GetCenterX(), monsters[2]->GetCenterY() + 100, counter));
			monsterSpells.back()->LoadBitmap(2);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			monsterSpells.push_back(new FireBall(monsters[2]->GetCenterX() - 50, monsters[2]->GetCenterY() - 50, counter));
			monsterSpells.back()->LoadBitmap(2);
			monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
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
		if ((*it)->HitSomething(monsters[stage]) && monsters[stage]->GetHP() > 0)
		{
			it = heroSpells.erase(it);
			try
			{
				monsters[stage]->SetHitted(1, counter);
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
	monsters[stage]->HitAnimation(counter);

	// 判斷技能是否打中英雄
	for (auto it = monsterSpells.begin(); it != monsterSpells.end();) {
		if ((*it)->HitSomething(&hero) && hero.Gethp() > 0)
		{
			it = monsterSpells.erase(it);
			try
			{
				hero.Sethp(1);
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

	// 怪物血量
	while ((size_t)monsters[stage]->GetHP() != heart.size())
	{
		if ((size_t)monsters[stage]->GetHP() > heart.size())
		{
			heart.push_back(new CMovingBitmap());
			heart.back()->LoadBitmap(IDB_HEART, RGB(255, 255, 255));
			heart.back()->SetTopLeft(0 + 28 * ((int)heart.size()-1), 0);
		}
		else if ((size_t)monsters[stage]->GetHP() < heart.size())
		{
			heart.erase(heart.end() - 1);
		}
	}
	//	英雄血量
	hp_left.SetInteger(hero.Gethp());
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
	ShowInitProgress(50);
	Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep

	hero.LoadBitmap();

	/*gamemap*/
	gamemap.push_back(new CGameMap());
	gamemap.push_back(new CGameMap2());
	gamemap.push_back(new CGameMap3());
	for (int i = 0; i < 3; i++)
	{
		gamemap.at(i)->LoadBitmap();	//地圖
	}
	hp_left.LoadBitmap();
	lazer.LoadBitmap(IDB_lazer, RGB(255, 255, 255));
	trapzone.LoadBitmap(IDB_trapzone, RGB(255, 255, 255));
	heart2.LoadBitmap(IDB_stage2heart, RGB(255, 255, 255));
	shield.LoadBitmap(IDB_shield, RGB(255, 255, 255));
	smallhero.LoadBitmap(IDB_hphero, RGB(255, 255, 255));
	store.LoadBitmap(IDB_store, RGB(255, 255, 255));
	storebus.LoadBitmap(IDB_bus, RGB(255, 255, 255));
	storemazu.LoadBitmap(IDB_mazu, RGB(255, 255, 255));
	storemoney.LoadBitmap(IDB_money, RGB(255, 255, 255));
	storeoil.LoadBitmap(IDB_oil, RGB(255, 255, 255));
	storezing.LoadBitmap(IDB_zingping, RGB(255, 255, 255));
	storebuscard.LoadBitmap(IDB_buscard, RGB(255, 255, 255));
	storemazucard.LoadBitmap(IDB_mazucard, RGB(255, 255, 255));
	storemoneycard.LoadBitmap(IDB_moneycard, RGB(255, 255, 255));
	storeoilcard.LoadBitmap(IDB_oilcard, RGB(255, 255, 255));
	storezingcard.LoadBitmap(IDB_zingpingcard, RGB(255, 255, 255));

	CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
	CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
	CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
	CAudio::Instance()->Load(AUDIO_STEP, "sounds\\step.mp3");
	CAudio::Instance()->Load(AUDIO_RUN, "sounds\\run.mp3");
	CAudio::Instance()->Load(AUDIO_KNIFE, "sounds\\knife.mp3");
	CAudio::Instance()->Load(AUDIO_KNIFEHIT, "sounds\\knifehit.mp3");
	CAudio::Instance()->Load(AUDIO_EARTH, "sounds\\earth.mp3");
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
	const char KEY_W = 0x57; //地圖測試用
	const char KEY_X = 0x58; //keyboard X 順移
	const char KEY_B = 0x42; //buy
	if (nChar == KEY_B)
	{
		if (stage == 0) {
			if (250 <= hero.GetX2() && hero.GetX2() <= 350 && 200 <= hero.GetY2() && hero.GetY2() < 300) {
				buy = 1;
			}
			else if (250 <= hero.GetX2() && hero.GetX2() <= 350 && 300 <= hero.GetY2() && hero.GetY2() < 400) {
				buy = 2;
			}
			else if (350 < hero.GetX2() && hero.GetX2() <= 500 && 350 <= hero.GetY2() && hero.GetY2() < 450) {
				buy = 3;
			}
			else if (500 < hero.GetX1() && hero.GetX1() <= 600 && 300 <= hero.GetY2() && hero.GetY2() < 400) {
				buy = 4;
			}
			else if (500 < hero.GetX1() && hero.GetX1() <= 600 && 200 <= hero.GetY2() && hero.GetY2() < 300) {
				buy = 5;
			}
		}
		showdescription = true;
	}
	if (nChar == KEY_W)
	{
		stage = (stage + 1) % 3;
		gamemap.at(stage)->Initialize();
		hero.SetXY(1000,1750);
		//monsters[stage]->setactive();要讓怪物靜止的話(把active共用)
	}

	if (nChar == KEY_X)
	{
		vector<int> monsterloc;
		monsterloc.push_back(monsters[stage]->GetX1());
		monsterloc.push_back(monsters[stage]->GetY1());
		monsterloc.push_back(monsters[stage]->GetX2());
		monsterloc.push_back(monsters[stage]->GetY2());
		hero.Teleport(gamemap.at(stage), monsterloc);
	}

	if (nChar == KEY_Z && zattack == true)
	{
		CAudio::Instance()->Play(AUDIO_KNIFE, true);
		hero.SetHit(true);
		vector<int> monsterloc;
		monsterloc.push_back(monsters[stage]->GetX1());
		monsterloc.push_back(monsters[stage]->GetY1());
		monsterloc.push_back(monsters[stage]->GetX2());
		monsterloc.push_back(monsters[stage]->GetY2());
		if (hero.HitMonster(monsterloc) && monsters[stage]->GetHP() > 0)
		{
			CAudio::Instance()->Play(AUDIO_KNIFEHIT, true);
			monsters[stage]->SetHitted(1, counter);
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
		shift = true;
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_SHIFT = 0x10; // keyboard SHIFT 加速
	const char KEY_Z = 0x5A; //keyboard Z 普通攻擊
	const char KEY_SPACE = 0x20; //keyboard Space 治療
	const char KEY_B = 0x42; //buy
	if (nChar == KEY_B)
	{
		showdescription = false;
	}
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
		if (hero.CheckCooldown(2, counter, 20))
		{
			hero.SetCastTime(2, counter);
			if (hero.Gethp() < 95 && hero.Gethp() >= 85)
				hero.Sethp(-1);
			else if (hero.Gethp() < 85)
				hero.Sethp(-2);
			hero.SetHeal(true);
		}
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
		shift = false;
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if (hero.CheckCooldown(1, counter, 30))
	{
		hero.SetCastTime(1, counter);
		heroSpells.push_back(new FireBall(hero.GetCenterX(), hero.GetCenterY(), counter));
		heroSpells.back()->LoadBitmap(0);
		heroSpells.back()->CalculateUnitVector(point.x + gamemap.at(stage)->GetSX(), point.y + gamemap.at(stage)->GetSY());
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnShow()
{
	gamemap.at(stage)->OnShow();//地圖
	
	//商店//
	if (stage == 0) {
		if (250 <= hero.GetX2() && hero.GetX2() <= 350 && 200 <= hero.GetY2() && hero.GetY2() < 300) {
			storebus.SetTopLeft(gamemap.at(stage)->ScreenX(300), gamemap.at(stage)->ScreenY(0));
			storebus.ShowBitmap();
		}
		else if (250 <= hero.GetX2() && hero.GetX2() <= 350 && 300 <= hero.GetY2() && hero.GetY2() < 400) {
			storezing.SetTopLeft(gamemap.at(stage)->ScreenX(300), gamemap.at(stage)->ScreenY(0));
			storezing.ShowBitmap();
		}
		else if (350 < hero.GetX2() && hero.GetX2() <= 500 && 350 <= hero.GetY2() && hero.GetY2() < 450) {
			storemazu.SetTopLeft(gamemap.at(stage)->ScreenX(300), gamemap.at(stage)->ScreenY(0));
			storemazu.ShowBitmap();
		}
		else if (500 < hero.GetX1() && hero.GetX1() <= 600 && 300 <= hero.GetY2() && hero.GetY2() < 400) {
			storeoil.SetTopLeft(gamemap.at(stage)->ScreenX(300), gamemap.at(stage)->ScreenY(0));
			storeoil.ShowBitmap();
		}
		else if (500 < hero.GetX1() && hero.GetX1() <= 600 && 200 <= hero.GetY2() && hero.GetY2() < 300) {
			storemoney.SetTopLeft(gamemap.at(stage)->ScreenX(300), gamemap.at(stage)->ScreenY(0));
			storemoney.ShowBitmap();
		}
		else {
			store.SetTopLeft(gamemap.at(stage)->ScreenX(300), gamemap.at(stage)->ScreenY(0));
			store.ShowBitmap();
		}
		if (lazeropen == true) {
			for (int i = 0; i < 4; i++) {
				lazer.SetTopLeft(gamemap.at(stage)->ScreenX(1200), gamemap.at(stage)->ScreenY(500 + (i * 250)));
				lazer.ShowBitmap();
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				lazer.SetTopLeft(gamemap.at(stage)->ScreenX(1500), gamemap.at(stage)->ScreenY(600 + (i * 250)));
				lazer.ShowBitmap();
			}
		}

	}
	if (stage == 1) {
		if (shieldon) {
			shield.SetTopLeft(gamemap.at(stage)->ScreenX(600), gamemap.at(stage)->ScreenY(200));
			shield.ShowBitmap();
		}
		if (heart2on) {
			heart2.SetTopLeft(gamemap.at(stage)->ScreenX(1700), gamemap.at(stage)->ScreenY(1850));
			heart2.ShowBitmap();
		}
		if (trapzoneon) {
			trapzone.SetTopLeft(gamemap.at(stage)->ScreenX(monsters[stage]->GetX1()-50)
				, gamemap.at(stage)->ScreenY(monsters[stage]->GetY1()-50));
			trapzone.ShowBitmap();
		}
	}
	for (auto it = heroSpells.begin(); it != heroSpells.end(); it++) {
		try
		{
			(*it)->OnShow(gamemap.at(stage));
		}
		catch (...)
		{

		}
	}
	for (auto it = monsterSpells.begin(); it != monsterSpells.end(); it++) {
		try
		{
			(*it)->OnShow(gamemap.at(stage));
		}
		catch (...)
		{

		}
		
	}
	hero.OnShow(gamemap.at(stage));// 主角
	gamemap.at(stage)->OnShowonhero();
	monsters[stage]->OnShow(hero.GetX1(), hero.GetY1(), gamemap.at(stage), &hero);

	for (auto it = heart.begin(); it != heart.end(); it++)
	{
		(*it)->ShowBitmap();
	}
	hp_left.ShowBitmap();
	smallhero.SetTopLeft(615, 0);
	smallhero.ShowBitmap();
	if (showdescription == true) {
		if (buy == 1) {
			storebuscard.SetTopLeft(116, 0);
			storebuscard.ShowBitmap();
		}
		else if (buy == 2) {
			storezingcard.SetTopLeft(116, 0);
			storezingcard.ShowBitmap();
		}
		else if (buy == 3) {
			storemazucard.SetTopLeft(116, 0);
			storemazucard.ShowBitmap();
		}
		else if (buy == 4) {
			storeoilcard.SetTopLeft(116, 0);
			storeoilcard.ShowBitmap();
		}
		else if (buy == 5) {
			storemoneycard.SetTopLeft(116, 0);
			storemoneycard.ShowBitmap();
		}
	}
}
}