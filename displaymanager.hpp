/**
   @file displaymanager.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The header file for the ftxui wrapper
   @date May 2026   
**/

#pragma once
#include"baseparser.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/color.hpp>
#include<ftxui/component/screen_interactive.hpp>
#include<ftxui/component/component.hpp>
#include<string>
#include<thread>
#include<atomic>
#include<chrono>
#include<mutex>

using namespace ftxui;

class CDisplayManager{
    public:
        CDisplayManager() = default;
        ~CDisplayManager() = default;
        void renderGPU(const std::vector<std::unique_ptr<IBaseParser>>& gpuParser);
};