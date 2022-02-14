#include "VkDraw.h"
#include <stdexcept>
#include <iostream>

const uint32_t WINDOWWIDTH = 800;
const uint32_t WINDOWHEIGHT = 600;
const char* WINDOWNAME = "Vulkan Window";

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

int main() {
	VkDraw app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}