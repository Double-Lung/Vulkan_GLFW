#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>
#include <string>

extern const uint32_t WINDOWWIDTH;
extern const uint32_t WINDOWHEIGHT;
extern const char* WINDOWNAME;
extern const bool enableValidationLayers;
extern const std::vector<const char*> validationLayers;
extern const std::vector<const char*> deviceExtensions;

class VkDraw
{
public:
	void run();
	

private:
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;
		bool isComplete();
	};

	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	std::vector<VkExtensionProperties> getAvailableExtensions();
	std::vector<const char*> getRequiredExtensions();
	bool checkExtensionSupport();
	bool checkValidationLayerSupport();
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void createInstance();
	void initWindow();
	int rateDeviceSuitability(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();
	void createImageViews();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createGraphicsPipeline();
	VkShaderModule createShaderModule(const std::vector<char>& code);

	void initVulkan();
	void createRenderPass();
	void createSurface();
	void mainLoop();
	void cleanup();

#ifdef _DEBUG
	void showExtensionSupportStatus();
	void setupDebugMessenger();
#endif

	static std::vector<char> readFile(const std::string& filename);

	GLFWwindow* window = nullptr;
	VkInstance instance = nullptr;
	VkDebugUtilsMessengerEXT debugMessenger = nullptr;
	VkSurfaceKHR surface = nullptr;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device = nullptr;
	VkQueue graphicsQueue = nullptr;
	VkQueue presentQueue = nullptr;
	VkSwapchainKHR swapChain = nullptr;
	VkRenderPass renderPass = nullptr;
	VkPipelineLayout pipelineLayout = nullptr;
	VkPipeline graphicsPipeline = nullptr;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	
	std::vector<VkImage> swapChainImages;
	std::vector<VkImageView> swapChainImageViews;
};

