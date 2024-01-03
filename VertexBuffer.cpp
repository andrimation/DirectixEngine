#include "VertexBuffer.h"
#include "GraphicsEngine.h"

// odc 5    17:49 

VertexBuffer::VertexBuffer(): m_layout(0),m_buffer(0)
{
}

// W funkcji load b�dziemy otrzymywa� informacje z GraphicsEngine i pos�u�� one do utworzenia bufora wierzcho�k�w
bool VertexBuffer::load(void* list_vertices, UINT size_vertex, UINT size_list, void* shader_byte_code, UINT size_byte_shader)
{
	if (m_buffer)
	{
		m_buffer->Release();
	}
	if (m_layout)
	{
		m_layout->Release();
	}

	D3D11_BUFFER_DESC buff_desc = {};
	buff_desc.Usage = D3D11_USAGE_DEFAULT; //<- usage dafault oznacza �e bufor b�dzie do zapisu i odczytu przez GPU
	buff_desc.ByteWidth = size_vertex * size_list; //<- ByteWidth czyli wielko�� bufora to ilo�� vertex�w ( czyli rozmiar ich listy) * rozmiar pojedynczego vertexa ( w zale�no�ci od tego jakie info b�dzie zawiera� )
	buff_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;  //<- tu wskazujemy DX �e to jest bufor vertex�w a nie jaki� inny
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;
	
	D3D11_SUBRESOURCE_DATA init_data = {};
	init_data.pSysMem = list_vertices; //<- tu wskazujemy na miejsce w pami�ci gdzie zlokalizowana jest lista vertex�w

	m_size_vertex = size_vertex;
	m_size_list = size_list;

	HRESULT hr = GraphicsEngine::get()->m_d3d_device->CreateBuffer(&buff_desc,&init_data,&m_buffer);
	if (FAILED(hr))
	{
		return false;
	}

	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		// SEMANTIC NAME - SEMANTIC INDEX - FORMAT                          - INPUT SLOT - ALIGNED BYTE OFFSET - INPUT SLOT CLASS           - INSTNCE DATA STEP RATE
		{"POSITION",         0,             DXGI_FORMAT_R32G32B32A32_FLOAT,    0,          0,                    D3D11_INPUT_PER_VERTEX_DATA ,  0                  },
	};

	UINT size_layout = ARRAYSIZE(layout);

	hr = GraphicsEngine::get()->m_d3d_device->CreateInputLayout(layout, size_layout, shader_byte_code, size_byte_shader,&m_layout);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool VertexBuffer::release()
{
	m_layout->Release();
	m_buffer->Release();

	return true;
}
