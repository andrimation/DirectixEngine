#pragma once
#include <d3d11.h>

// W tym miejscu robimy forward declaration DeviceContext po to aby móc dodaæ je do klasy SwapChain jako friend class, ale ¿eby nie musieæ includeowaæ.
class DeviceContext;

class SwapChain
{
public:
	SwapChain();
	//Initialize
	bool init(HWND hwnd,UINT width, UINT height);

	bool present(bool vsync);

	//Release
	bool release();
	~SwapChain();

private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_rtv;
private:
	friend class DeviceContext;

};

