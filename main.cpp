/**
   @file main.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The main class which takes responsibility of going through the system, note the gpus present, and orchestrate the whole flow!
   @date May 2026   
**/

#include<filesystem>
#include"displaymanager.hpp"
#include"intelparser.hpp"
#include"nvidiaparser.hpp"

constexpr std::string defaultSysFsPath = "/sys/class/drm/";

// using namespace Logger;

int main(int argc, char** argv){
    Logger::init(Logger::Mode::File, "gv.txt");
    Logger::info("Start of GPU Vanguard!");

    std::vector<std::unique_ptr<IBaseParser>> gpuParsers;

    // Doing a parse of all the cards in the pc...
    auto recurse_dir_iter = std::filesystem::directory_iterator(defaultSysFsPath);
    for (const std::filesystem::directory_entry& entry: recurse_dir_iter){
        Logger::info(entry.path());
        if(entry.path().string().find("card") != std::string::npos){
            Logger::info("\nFound a possible card!\n");
            std::optional<std::string> cardInfo = parseCardInfo(entry.path().string());
            if(!cardInfo.has_value()){
                Logger::error("Possible peripherals like the DP or HDMI ports are being detected as cards, skipping them...");
                continue;
            }else{
                
                if(std::string device = cardInfo.value();device == "intel_gpu" || device == "i915" || device == "xe"){
                    Logger::info("Found an Intel GPU!");
                    
                    CIntelParser intelParser(entry.path().string());
                    if(std::optional<SGpuData> gpuData = intelParser.parseData();gpuData.has_value()){
                        // std::cout << "GPU Data for the intel card at path: " << entry.path() << "\n";
                        // std::cout << "Core clock: " << gpuData->coreClock << "Mhz\n";
                        gpuParsers.push_back(std::make_unique<CIntelParser>(entry.path().string()));
                    }
                    else{
                        Logger::error("Something wrong in parsing the gpu data for the intel gpu :/");
                    }
                }// else for amd and nvidia
                else if(device == "nvidia" || device == "nouveau" || device == "nouveau_modeset"){
                    Logger::info("Found an nVidia GPU!");
                    CNvidiaParser nvidiaParser{CNvidiaParser()};
                    if(std::optional<SGpuData> gpuData = nvidiaParser.parseData(); gpuData.has_value()){
                        // std::cout << "GPU Data for the nVidia card at path: " << entry.path().string() << "\n";
                        // showGpuData(gpuData.value());
                        if (gpuData.has_value()) {
                            // CDisplayManager ui;
                            // ui.renderGPU(device, gpuData.value()); 
                            gpuParsers.push_back(std::make_unique<CNvidiaParser>());
                        }
                    }else{
                        Logger::error("Something wrong in paring the nVidia gpu!");
                    }
                }
            }
        }
    }

    // Render the ui now!

    if(gpuParsers.size() != 0){
        CDisplayManager ui;
        ui.renderGPU(gpuParsers);
    }else{
        Logger::error("No possible gpu's parsed :/");
    }

    return 0;
}