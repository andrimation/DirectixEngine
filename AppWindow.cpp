#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get()->init();
	m_swap_chain = GraphicsEngine::get()->createSwapChain();

	RECT window_rect = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd, window_rect.right-window_rect.left, window_rect.bottom-window_rect.top);
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(m_swap_chain,1.0,0.3,0.2,1.0);
	m_swap_chain->present(false);
}

void AppWindow::onDestroy()
{
	// Wywo³anie funkcji z klasy nadrzêdnej.
	Window::onDestroy();

	m_swap_chain->release();
	GraphicsEngine::get()->release();
}
