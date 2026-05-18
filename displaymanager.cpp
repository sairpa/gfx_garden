/**
   @file displaymanager.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The implementation file for the ftxui wrapper
   @date May 2026   
**/

#include"displaymanager.hpp"
#include<ftxui/component/screen_interactive.hpp>
#include<ftxui/component/component.hpp>


void CDisplayManager::renderGPU(const std::string& gpuName, const SGpuData& gpuData){
    auto screen = ScreenInteractive::TerminalOutput(); // UI Handler loop
    auto renderer = Renderer([&] {
        return window(
            text("GPU Vanguard") | bold | center, // title in the border
            vbox({
                text("GPU: " + gpuName) | bold | color(Color::Orange1),
                separator(),
                hcenter(vbox({
                    text("Core Clocks: " + std::to_string(gpuData.coreClock) + "Mhz") | color(Color::Cyan),
                    text("Memory Clocks: " + std::to_string(gpuData.memoryClock) + "Mhz") | color(Color::Cyan),
                    text("VRAM: " + std::to_string(gpuData.vram) + "MB") | color(Color::Cyan),
                    text("Fan Speed" + std::to_string(gpuData.fanSpeed) + "%") | color(Color::Cyan),
                    text("Temperature: " + std::to_string(gpuData.temperature) + "\u00B0C") | color(Color::Cyan)
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

    screen.Loop(std::move(component));
}
