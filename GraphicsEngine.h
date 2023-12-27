#pragma once
#include <d3d11.h>

class GraphicsEngine
{
public:
	GraphicsEngine();
	//Initialize the GraphicsEngine and DirectX Device
	bool init();
	// Release all the resources loaded
	bool release();
	~GraphicsEngine();
};

