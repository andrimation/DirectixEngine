#pragma once
#include "Window.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	// Odziedziczono za po�rednictwem elementu Window
	void onCreate() override;
	void onUpdate() override;
	void onDestroy() override;
};

