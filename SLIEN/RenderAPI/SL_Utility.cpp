#include "SL_Utility.h"
#include <vulkan.h>
SLIEN_Vk::SLIEN_Vk() {

}
void SLIEN_Vk::SLIEN_SURFACE(int Height, int Width, char * Title) {

	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);//no glfw api,i will continuely use it in opengl struct because it is very good

	SL_Window = glfwCreateWindow(Width, Height, Title, 0, 0);
	vkEnumerateInstanceExtensionProperties(nullptr, &ExtentCount, nullptr);


}

int SLIEN_Vk::DESURFACE() {
	vkDestroyInstance(SLV_INSTANCE,nullptr);
	glfwDestroyWindow(SL_Window);
	glfwTerminate();
	return 1;
}

void SLIEN_Vk::SLIEN_FRAME() {
	while (!glfwWindowShouldClose(SL_Window)) {
		glfwPollEvents();

	}
}
int SLIEN_Vk::SLV_APPINFO(VkStructureType TYPE, char * APPNAME) {
	SLV_APP_INFO.sType = TYPE;
	if (APPNAME != nullptr) {
		SLV_APP_INFO.pApplicationName = APPNAME;
	}
	SLV_APP_INFO.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	SLV_APP_INFO.pEngineName = "SLIEN ENGINE";
	SLV_APP_INFO.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	SLV_APP_INFO.apiVersion = VK_API_VERSION_1_3;


	return 1;

}
void SLIEN_Vk::SLV_CERT_INFO() {
	
	SLV_C_INFO.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	SLV_C_INFO.pApplicationInfo = &SLV_APP_INFO;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	SLV_C_INFO.enabledExtensionCount = glfwExtensionCount;
	SLV_C_INFO.ppEnabledExtensionNames = glfwExtensions;
	SLV_C_INFO.enabledLayerCount = 0;/////////////////////

}
