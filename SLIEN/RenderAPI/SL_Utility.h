#include <vulkan.h>

#include "CBase.h"
#include <vector>
#include <GLFW/glfw3.h>
struct SLIEN_API SLIEN_Vk {
	public://for glfw or something not vk type
		GLFWwindow * SL_Window;
		uint32_t ExtentCount = 0;
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;

	public://Abstract func for SLIEN especiall glfw and vulkan packed things
		SLIEN_Vk();
		~SLIEN_Vk();
		void SLIEN_SURFACE(int Height, int Width, char * Title);//create windows
		int DESURFACE();
		void SLIEN_INIT();
		void SLIEN_FRAME();

	public://vulkan init func and process func
		int SLV_APPINFO(VkStructureType TYPE = VK_STRUCTURE_TYPE_APPLICATION_INFO, char * APPNAME = nullptr);
		void SLV_CERT_INFO();
		int SLV_CERT_INS(){
	
			SLV_RESULT = vkCreateInstance(&SLV_C_INFO,nullptr,&SLV_INSTANCE);
			
			if(&SLV_INSTANCE != nullptr){
				return 1;
			}
			if (vkCreateInstance(&SLV_C_INFO, nullptr, &SLV_INSTANCE) != VK_SUCCESS) {
			    throw std::runtime_error("failed to create instance!");
			    return 0;
			}
			return 0;
		}
		void SLV_FINISH(){
			vkEnumerateInstanceExtensionProperties(nullptr, &ExtentCount, nullptr);
			
			vkEnumerateInstanceExtensionProperties(nullptr, &ExtentCount, SLV_EXT.data());
			for (const auto& SLV_EXT : SLV_EXT) {
			    std::cout << '\t' << SLV_EXT.extensionName << '\n';
			    
			}
		}
	public://vk vars
		VkInstance SLV_INSTANCE;
		VkInstanceCreateInfo SLV_C_INFO;
		VkApplicationInfo SLV_APP_INFO;
		VkResult SLV_RESULT;
		std::vector<VkExtensionProperties> SLV_EXT;
		const std::vector<const char*> validationLayers = {
		    "VK_LAYER_KHRONOS_validation"
		};
		
		#ifdef NDEBUG
		    const bool enableValidationLayers = false;
		#else
		    const bool enableValidationLayers = true;
		#endif
};
VkResult vkCreateInstance(
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* instance) {

    if (pCreateInfo == nullptr || instance == nullptr) {
        printf("Null pointer passed to required parameter!");
        
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    return vkCreateInstance(pCreateInfo, pAllocator, instance);
}
