/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
	: CGameState(g)
{
	help = false;
}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
	//
	gamestart.LoadBitmap(IDB_GAMESTART);
	helpbar.LoadBitmap(IDB_HELPBAR);
	Sleep(100);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	CAudio::Instance()->Load(AUDIO_HELP, "sounds\\HELP.mp3");
	if (CAudio::Instance()->Load(AUDIO_STARTOST, "sounds\\startost.mp3"))
		CAudio::Instance()->Play(AUDIO_STARTOST, true);
		
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
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
		GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
	}
	else if (nChar == KEY_ESC)								// Demo �����C������k
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//CAudio::Instance()->Stop(AUDIO_STARTOST);
	//GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	//
	// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
	//
	//CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	//fp=pDC->SelectObject(&f);					// ��� font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	//if (ENABLE_GAME_PAUSE)
	//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	//pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	//CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
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
// �o��class���C�����������A(Game Over)
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
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	gameend.LoadBitmap(IDB_ENDMUSIC);
	CAudio::Instance()->Load(AUDIO_END, "sounds\\end.mp3");
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
}
void CGameStateOver::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE) {
		CAudio::Instance()->Stop(AUDIO_END);
		GotoGameState(GAME_STATE_INIT);						// ������GAME_STATE_INIT
	}
}
void CGameStateOver::OnShow()
{
	/*
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240, 210, str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	*/

	gameend.SetTopLeft(0, 0);
	gameend.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g), NUMBALLS(28)
{
	stage = 0;
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
	counter = 0;
	hero.Initialize();
	slime.Initialize();
	counterlazer = 30 * 2; // 5 seconds
	lazeropen = false;
	for (int i = 0; i < 3; i++)/*hero ��m��*/
	{
		gamemap.at(i)->Initialize();
	}
	hp_left.SetInteger(hero.Gethp());
	hp_left.SetTopLeft(565,0);
	for (int i = 0; i != slime.GetHP(); i++)
	{
		heart.push_back(new CMovingBitmap());
		heart.at(i)->LoadBitmap(IDB_HEART, RGB(255, 255, 255));
		heart.at(i)->SetTopLeft(0 + 28 * i, 0);
	}
	CAudio::Instance()->Play(AUDIO_EARTH, true);
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	//
	// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	counter++;
	gamemap.at(stage)->OnMove();//�a��

	counterlazer--; //�p�g�}��
	if (counterlazer < 0) {
		if (lazeropen == true) {
			lazeropen = false;
			counterlazer = 30 * 2;
		}
		else {
			lazeropen = true;
			counterlazer = 30 * 2;
		}
	}
	//�P�_�v�ܩi��q
	if (slime.GetHP() <= 0 || hero.Gethp() <= 0)
	{
		CAudio::Instance()->Stop(AUDIO_KNIFE);
		CAudio::Instance()->Stop(AUDIO_KNIFEHIT);
		CAudio::Instance()->Stop(AUDIO_EARTH);
		GotoGameState(GAME_STATE_OVER);
	}
	hero.OnMove(gamemap.at(stage), &slime);
	slime.OnMove(hero.GetX1(), hero.GetY1(), gamemap.at(stage));
	hero.SetHeal(!hero.CheckCooldown(2, counter, 150));
	// �Ǫ�����
	switch (slime.Skill(counter))
	{
	case 0:
		break;
	case 1:
		slime.MinusHP(-1);
		break;
	case 2:
		monsterSpells.push_back(new FireBall(slime.GetCenterX(), slime.GetCenterY(), counter));
		monsterSpells.back()->LoadBitmap(1);
		monsterSpells.back()->CalculateUnitVector(hero.GetX1(), hero.GetY1());
		monsterSpells.push_back(new FireBall(slime.GetCenterX(), slime.GetCenterY(), counter));
		monsterSpells.back()->LoadBitmap(1);
		monsterSpells.back()->CalculateUnitVector(hero.GetX2(), hero.GetY2());
		break;
	default:
		break;
	}

	// �ޯಾ��
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

	// �P�_�ޯ�O�_�����Ǫ�

	for (auto it = heroSpells.begin(); it != heroSpells.end();) {
		if ((*it)->HitSomething(&slime) && slime.GetHP() > 0)
		{
			//delete *it;
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

	// �P�_�ޯ�O�_�����^��
	for (auto it = monsterSpells.begin(); it != monsterSpells.end();) {
		if ((*it)->HitSomething(&hero) && hero.Gethp() > 0)
		{
			//delete *it;
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

	// �Ǫ���q
	heart.clear();
	for (int i = 0; i < slime.GetHP(); i++)
	{
		heart.push_back(new CMovingBitmap());
		heart.at(i)->LoadBitmap(IDB_HEART, RGB(255, 255, 255));
		heart.at(i)->SetTopLeft(0 + 28 * i, 0);
	}

	//	�^����q
	hp_left.SetInteger(hero.Gethp());
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
	//
	// �}�l���J���
	//
	// ��������Loading�ʧ@�A�����i��
	//
	ShowInitProgress(50);
	Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �~����J��L���
	//

	hero.LoadBitmap();
	/*gamemap*/
	gamemap.push_back(new CGameMap());
	gamemap.push_back(new CGameMap2());
	gamemap.push_back(new CGameMap3());
	for (int i = 0; i < 3; i++)
	{
		gamemap.at(i)->LoadBitmap();	//�a��
	}
	slime.LoadBitmap();
	hp_left.LoadBitmap();
	lazer.LoadBitmap(IDB_lazer, RGB(255, 255, 255));
	smallhero.LoadBitmap(IDB_hphero, RGB(255, 255, 255));
	store.LoadBitmap(IDB_store, RGB(255, 255, 255));
	storebus.LoadBitmap(IDB_bus, RGB(255, 255, 255));
	storemazu.LoadBitmap(IDB_mazu, RGB(255, 255, 255));
	storemoney.LoadBitmap(IDB_money, RGB(255, 255, 255));
	storeoil.LoadBitmap(IDB_oil, RGB(255, 255, 255));
	storezing.LoadBitmap(IDB_zingping, RGB(255, 255, 255));

	CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// ���J�s��0���n��ding.wav
	CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// ���J�s��1���n��lake.mp3
	CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// ���J�s��2���n��ntut.mid
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
	// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
	//
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	const char KEY_Z = 0x5A; //keyboard Z
	const char KEY_SHIFT = 0x10; // keyboard Shift �[�t
	const char KEY_SPACE = 0x20; //keyboard Space ���y
	const char KEY_W = 0x57; //�a�ϴ��ե�
	const char KEY_X = 0x58; //keyboard X ����

	if (nChar == KEY_W)
	{
		stage = (stage + 1) % 3;
		gamemap.at(stage)->Initialize();
		hero.SetXY(1000,1750);
	}

	if (nChar == KEY_X)
	{
		Sleep(200);
		hero.Teleport();
	}

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
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	const char KEY_SHIFT = 0x10; // keyboard SHIFT �[�t
	const char KEY_Z = 0x5A; //keyboard Z ���q����
	const char KEY_SPACE = 0x20; //keyboard Space �v��

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
		if (hero.CheckCooldown(2, counter, 150))
		{
			hero.SetCastTime(2, counter);
			if (hero.Gethp() == 9)
				hero.Sethp(-1);
			else if (hero.Gethp() < 9)
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
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	if (hero.CheckCooldown(1, counter, 30))
	{
		hero.SetCastTime(1, counter);
		heroSpells.push_back(new FireBall(hero.GetCenterX(), hero.GetCenterY(), counter));
		heroSpells.back()->LoadBitmap(0);
		heroSpells.back()->CalculateUnitVector(point.x + gamemap.at(stage)->GetSX(), point.y + gamemap.at(stage)->GetSY());
		//TRACE("HeroX: %d", hero.GetCenterX());
		//TRACE("HeroY: %d", hero.GetCenterY());
		//TRACE("X: %d", point.x);
		//TRACE("Y: %d", point.y);
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnShow()
{
	gamemap.at(stage)->OnShow();				//�a��
	hero.OnShow(gamemap.at(stage));// �D��
	//�ө�//
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
			for (int i = 0; i < 5; i++) {
				lazer.SetTopLeft(gamemap.at(stage)->ScreenX(1200), gamemap.at(stage)->ScreenY(500 + (i * 200)));
				lazer.ShowBitmap();
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				lazer.SetTopLeft(gamemap.at(stage)->ScreenX(1500), gamemap.at(stage)->ScreenY(600 + (i * 200)));
				lazer.ShowBitmap();
			}
		}

	}
	
	gamemap.at(stage)->OnShowonhero();


	slime.OnShow(hero.GetX1(), hero.GetY1(), gamemap.at(stage),& hero);

	for (auto it = heart.begin(); it != heart.end(); it++)
	{
		(*it)->ShowBitmap();
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
	hp_left.ShowBitmap();
	smallhero.SetTopLeft(615, 0);
	smallhero.ShowBitmap();
}
}