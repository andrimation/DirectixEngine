#pragma once
#include "Window.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	// Odziedziczono za poœrednictwem elementu Window
	void onCreate() override;
	void onUpdate() override;
	void onDestroy() override;
};

