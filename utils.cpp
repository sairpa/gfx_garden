/**
   @file utils.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief Utils class for the whole project!
   @date May 2026   
**/
#include"utils.hpp"

namespace Logger{
    // hidden defaults but state vars for logger
    static Mode currentMode = Mode::Silent;
    std::ofstream logFile;
    // helper impls
    void init(Mode mode, const std::string& filePath){ // init helper for the whole project modules
        currentMode = mode;
        if(currentMode == Mode::File){
            logFile.open(filePath, std::ios::out | std::ios::trunc);
            if(!logFile.is_open()){
                std::cerr << "[CRITICAL]: Logger failed to open! Filepath: " << filePath << "\n";
                currentMode = Mode::Silent; // Fallback default mode
            }
        }
    }

    void info(const std::string& msg){ // verbose logging
        if(currentMode == Mode::Console){
            std::cout << "[INFO]: " << msg << "\n";
        }else if(currentMode == Mode::File){
            logFile << "[INFO]: " << msg << "\n";
            logFile.flush();
        }
    }

    void error(const std::string& msg){ // error logging
        if(currentMode == Mode::Console){
            std::cerr << "[ERROR]: " << msg << "\n";
        }else if(currentMode == Mode::File){
            logFile << "[ERROR]: " << msg << "\n";
            logFile.flush();
        }
    }
}

std::optional<std::string> parseCardInfo(const std::string& cardPath){
    // readthrough the uevent file as a vector of string
    Logger::info(cardPath);
    std::ifstream ueventFile(cardPath + "/device/uevent");
    if(!ueventFile.is_open()){
        Logger::error("Failed to open uevent file of path: " + cardPath);
        return std::nullopt;
    }
    std::string fileContents;
    std::string device;
    while(getline(ueventFile, fileContents)){
        if(fileContents.find("DRIVER")!= std::string::npos){
            device = fileContents.substr(fileContents.find("=")+1);
            break;
        }
    }
    if(device.empty()){
        Logger::error("Missing contents in the uevent file of path: " + cardPath);
        return std::nullopt;
    }
    return device;
}

std::optional<std::string> runCommand(const char* command) {
    auto pipe = std::unique_ptr<FILE, decltype(&pclose)>(popen(command, "r"), pclose);

    if (!pipe) {
        Logger::error("Unable to create a pipe for the command execution :/");
        return std::nullopt;
    }
    std::vector<char> buffer(128);
    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    if (result.empty()) {
        Logger::error("Didn't get any result from the command :/");
        return std::nullopt;
    }
    return result;
}


void showGpuData(SGpuData gpuData){
    Logger::info( "------------------GPU DATA------------------------\n"    
    "temperature:\t"+ std::to_string(gpuData.temperature) + "\n"
    "fanspeed:\t" + std::to_string(gpuData.fanSpeed) + "\n"
    "coreclock:\t" + std::to_string(gpuData.coreClock) + "\n"
    "memoryclock:\t"+ std::to_string(gpuData.memoryClock) + "\n"
    "gpuutlization:\t"+ std::to_string(gpuData.gpuUtilization) + "\n"
    + "vram:\t"+ std::to_string(gpuData.vram) + "\n"
    "--------------------------------------------------\n");
    return;
}