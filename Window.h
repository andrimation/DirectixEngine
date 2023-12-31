#pragma once

#include <Windows.h>

class Window
{
public:
	Window();
	// initialize the window
	bool init();
	bool broadcast();
	// release the window
	bool release();
	bool isRun();

	// Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);

	~Window();

protected:
	HWND m_hwnd;
	bool m_is_run;
};

