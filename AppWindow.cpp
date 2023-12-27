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
	// Wywo³anie funkcji z klasy nadrzêdnej.
	Window::onDestroy();
}
