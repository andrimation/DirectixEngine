#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
}

void AppWindow::onUpdate()
{
}

void AppWindow::onDestroy()
{
	// Wywo�anie funkcji z klasy nadrz�dnej.
	Window::onDestroy();
}
