#include "SwapChain.h"
#include "GraphicsEngine.h"

SwapChain::SwapChain()
{
}

bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{
	ID3D11Device* device = GraphicsEngine::get()->m_d3d_device;

	// Swap chain desc jest to struktura zawieraj�ca opis swap chaina -> np ile bufer�w, jaki rozmiar okna itp
	DXGI_SWAP_CHAIN_DESC  desc;
	// Zero memory powoduje �e ca�a pami�� zaj�ta przez utworzony obiekt tej klasy wype�niana jest zerami.
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1; // podajemy �e 1 bufer, bo nasze okno jest "windowed" wi�c ju� jeden bufor ( front buffer ) jest w ramach managera okien
	desc.BufferDesc.Width = width;
	desc.BufferDesc.Height = height;
	desc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hwnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;

	HRESULT hr = GraphicsEngine::get()->m_dxgi_factory->CreateSwapChain(device,&desc,&m_swap_chain);

	if (FAILED(hr))
	{
		return false;
	}

	ID3D11Texture2D* buffer=NULL;
	hr = m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

	if (FAILED(hr))
	{
		return false;
	}

	hr = device->CreateRenderTargetView(buffer, NULL,&m_rtv);
	buffer->Release();

	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool SwapChain::present(bool vsync)
{
	m_swap_chain->Present(vsync, NULL);
	return true;
}

bool SwapChain::release()
{
	m_swap_chain->Release();
	delete this;
	return true;
}

SwapChain::~SwapChain()
{
}
