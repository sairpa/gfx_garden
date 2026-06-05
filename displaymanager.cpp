/**
   @file displaymanager.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The implementation file for the ftxui wrapper
   @date May 2026   
**/

#include"displaymanager.hpp"

void CDisplayManager::renderGPU(const std::vector<std::unique_ptr<IBaseParser>>& gpuParsers){
    std::vector<SGpuData> gpuList(gpuParsers.size());
    std::mutex dataMutex;
    auto screen = ScreenInteractive::Fullscreen(); // UI Handler loop
    auto renderer = Renderer([&] {
        Elements gpuPanels;
        std::lock_guard<std::mutex> lock(dataMutex);

        for(auto i=0; i < gpuList.size(); i++){
            gpuPanels.push_back(
                window(
                    text("GPU: " + std::string(gpuList[i].name ? gpuList[i].name : "Loading...")) | bold | center,
                    hcenter(vbox({
                        text("Core Clocks: " + std::to_string(gpuList[i].coreClock) + "Mhz") | color(Color::Cyan),
                        text("Memory Clocks: " + std::to_string(gpuList[i].memoryClock) + "Mhz") | color(Color::Cyan),
                        text("VRAM: " + std::to_string(gpuList[i].vram) + "MB") | color(Color::Cyan),
                        text("Fan Speed" + std::to_string(gpuList[i].fanSpeed) + "%") | color(Color::Cyan),
                        text("Temperature: " + std::to_string(gpuList[i].temperature) + "\u00B0C") | color(Color::Cyan)
                    }))
                ) | flex
            );
        }


        return window(
            text("GPU Vanguard") | bold | center, // title in the border
            vbox({
                hbox(std::move(gpuPanels)),
                filler(),
                text("Press 'q' to exit") | dim | center
            })            
        );
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

            std::vector<SGpuData> freshDataList(gpuParsers.size());
            for(size_t i =0; i < gpuParsers.size(); i++){
                auto freshData = gpuParsers[i]->parseData();
                if(freshData.has_value()){
                    freshDataList[i] = freshData.value();
                }
            }

            {
                std::lock_guard<std::mutex> lock(dataMutex);
                gpuList = std::move(freshDataList);
            }
            
            screen.Post(Event::Custom);
        }
    });

    screen.Loop(std::move(component));
    refresh_ui = false;
    refresh_thread.join();
}


