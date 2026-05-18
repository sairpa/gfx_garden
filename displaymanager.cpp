/**
   @file displaymanager.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The implementation file for the ftxui wrapper
   @date May 2026   
**/

#include"displaymanager.hpp"
#include<ftxui/component/screen_interactive.hpp>
#include<ftxui/component/component.hpp>


void CDisplayManager::renderGPU(const std::vector<std::unique_ptr<IBaseParser>>& gpuParsers){
    std::vector<SGpuData> gpuList(gpuParsers.size());
    std::string gpuName{curGpu.name};
    auto screen = ScreenInteractive::TerminalOutput(); // UI Handler loop
    auto renderer = Renderer([&] {
        return window(
            text("GPU Vanguard") | bold | center, // title in the border
            vbox({
                text("GPU: " + gpuName ) | bold | color(Color::Orange1),
                separator(),
                hcenter(vbox({
                    text("Core Clocks: " + std::to_string(curGpu.coreClock) + "Mhz") | color(Color::Cyan),
                    text("Memory Clocks: " + std::to_string(curGpu.memoryClock) + "Mhz") | color(Color::Cyan),
                    text("VRAM: " + std::to_string(curGpu.vram) + "MB") | color(Color::Cyan),
                    text("Fan Speed" + std::to_string(curGpu.fanSpeed) + "%") | color(Color::Cyan),
                    text("Temperature: " + std::to_string(curGpu.temperature) + "\u00B0C") | color(Color::Cyan)
                }))
                ,
                filler(),
                text("Press 'q' to exit") | center | color(Color::Orange4) | dim
            })
        ) | flex;
    });

    auto component = CatchEvent(renderer, [&](Event event){
        if(event == Event::Character('q') || event == Event::Escape) {
            screen.Exit();
            return true;
        }
        return false;
    });

    std::atomic<bool> refresh_ui = true;
    std::thread refresh_thread([&]{
        while(refresh_ui){
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s);
            
        }
    });

    screen.Loop(std::move(component));
}


