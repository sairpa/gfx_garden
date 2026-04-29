#include<iostream>
#include <webgpu/webgpu.h>

// If using Dawn
#define WEBGPU_BACKEND_DAWN

// If using wgpu-native
// #define WEBGPU_BACKEND_WGPU

// If using emscripten
// #define WEBGPU_BACKEND_EMSCRIPTEN

int main(int, char**){

    std::cout<< "Web GPU fun starts here! :D\n";

    // Descriptor WGPU
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    WGPUInstance instance = wgpuCreateInstance(&desc);

    // Check for instance creation
    if (!instance){
        std::cerr << "WebGPU intialisazation failed!\n";
        return -1;
    }

    // WGPU instance simple pointer
    std::cout << "WebGPU instance: " << instance << "\n";

    return 0;

}

