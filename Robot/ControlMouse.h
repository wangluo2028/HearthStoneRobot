#pragma once
#include<Windows.h>
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
	void touchPosition(double x, double y)//�������λ��
	{
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x / screenWidth * 65535, y / screenHeight * 65535, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
	void playCard(double x, double y)//����
	{
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE , x / screenWidth * 65535, y / screenHeight * 65535, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(1000);
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 500.0 / screenWidth * 65535, 400.0 / screenHeight * 65535, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(1000);
	}
	void playCardToPlayer(double x, double y)
	{
		touchPosition(x, y);
		Sleep(500);
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 520.0 / screenWidth * 65535, 180.0 / screenHeight * 65535, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(500);
	}
	void moveToPosition(double x, double y)//�������λ��
	{
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x / screenWidth * 65535, y / screenHeight * 65535, 0, 0);
	}
	void fightMonster(double x, double y, double x1, double y1)
	{
		touchPosition(x, y);
		Sleep(500);
		touchPosition(x1, y1);
		Sleep(500);
	}
private:
	HWND hWnd;
	int screenWidth;
	int screenHeight;
	static ControlMouse* self;
	ControlMouse()
	{
		hWnd = ::FindWindow("UnityWndClass", ("¯ʯ��˵"));
		screenWidth = GetSystemMetrics(SM_CXSCREEN);
		screenHeight = GetSystemMetrics(SM_CYSCREEN);
		SetForegroundWindow(hWnd);
		//::SetActiveWindow(hWnd);
		RECT rc;
		::GetWindowRect(hWnd, &rc);

		::MoveWindow(hWnd, 0, 0, rc.right - rc.left, rc.bottom - rc.top, true);
	}
};
ControlMouse *ControlMouse::self = NULL;