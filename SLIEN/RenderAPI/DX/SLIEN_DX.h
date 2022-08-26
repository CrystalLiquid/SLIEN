

#define GLFW_EXPOSE_NATIVE_WIN32 1 //暴露出win32相关的原生接口

#include "CBase.h"
#include "glfw3native.h"


class SLIEN_API SLIEN_DX {
	public:
		GLFWwindow * SL_Window;
		uint32_t ExtentCount = 0;
		int Height;
		int Width;
	public:

	public:

		HRESULT InitD3D(HWND OutputWindow, int BufferCount, BOOL WindowSW, int RefreshRate);
		void Render() {
			// 清理 back buffer
			float ClearColor[4] = { 0.0f, 0.0f, 0.75f, 1.0f };

		}





};
