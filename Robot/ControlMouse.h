#pragma once
#include<Windows.h>
#include <dwmapi.h>
class ControlMouse
{
public:
	static ControlMouse *getInstance()
	{
		if (self == NULL)
		{
			self = new ControlMouse();
		}
		return self;
	}
	void touchPosition(double x, double y)//点击坐标位置
	{
		mouseEventByGameWindow(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x, y, 0, 0);
		mouseEventByGameWindow(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(1000);
	}
	void playCard(double x, double y)//出牌
	{
		mouseEventByGameWindow(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE , x, y, 0, 0);
		mouseEventByGameWindow(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(1000);
		mouseEventByGameWindow(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 500.0, 400.0, 0, 0);
		mouseEventByGameWindow(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(1000);
	}
	void playCardToPlayer(double x, double y)
	{
		touchPosition(x, y);
		Sleep(1000);
		double stepx = 800.0 -x;
		double stepy = 180.0 - y;
		for (int i = 0; i < 20;++i)
		{
			x += stepx / 20;
			y += stepy / 20;
			mouseEventByGameWindow(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x, y, 0, 0);
			Sleep(100);
		}
		mouseEventByGameWindow(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 800.0, 180.0, 0, 0);
		Sleep(500);
		mouseEventByGameWindow(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(500);
	}
	void moveToPosition(double x, double y)//移动到坐标位置
	{
		mouseEventByGameWindow(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x, y, 0, 0);
		Sleep(500);
	}
	void fightMonster(double x, double y, double x1, double y1)
	{
		touchPosition(x, y);
		Sleep(500);
		touchPosition(x1, y1);
		Sleep(500);
	}
private:
	void mouseEventByGameWindow(DWORD dwFlags, double dx, double dy, DWORD dwData, ULONG_PTR dwExtraInfo)
	{
		dx += m_gameRect.left;
		dy += m_gameRect.top;
		mouse_event(dwFlags, dx / m_screenWidth * 65535, dy / m_screenHeight * 65535, dwData, dwExtraInfo);
	}

	HWND m_gameHwnd;
	RECT m_gameRect;
	int m_screenWidth;
	int m_screenHeight;
	static ControlMouse* self;
	ControlMouse()
	{
		m_gameHwnd = ::FindWindow("UnityWndClass", CARDGAME);
		m_screenWidth = GetSystemMetrics(SM_CXSCREEN);
		m_screenHeight = GetSystemMetrics(SM_CYSCREEN);
		SetForegroundWindow(m_gameHwnd);
		::SetActiveWindow(m_gameHwnd);
		//RECT clientRect;
		//::GetClientRect(m_gameHwnd, &clientRect);
		//POINT clientTopLeft;
		//clientTopLeft.x = clientRect.left;
		//clientTopLeft.y = clientRect.top;
		//::ClientToScreen(m_gameHwnd, &clientTopLeft);
		//POINT clientBottomRight;
		//clientBottomRight.x = clientRect.right;
		//clientBottomRight.y = clientRect.bottom;
		//::ClientToScreen(m_gameHwnd, &clientBottomRight);
		//m_gameRect.left = clientTopLeft.x;
		//m_gameRect.top = clientTopLeft.y;
		//m_gameRect.right = clientBottomRight.x;
		//m_gameRect.bottom = clientBottomRight.y;
		::DwmGetWindowAttribute(m_gameHwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &m_gameRect, sizeof(m_gameRect));
	}
};
ControlMouse *ControlMouse::self = NULL;