#pragma once
#include "Window.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	// Odziedziczono za po�rednictwem elementu Window
	void onCreate() override;
	void onUpdate() override;
	void onDestroy() override;

private:
	SwapChain* m_swap_chain;
};

