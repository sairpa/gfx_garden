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
#include<string>

using namespace ftxui;

class CDisplayManager{
    public:
        CDisplayManager() = default;
        ~CDisplayManager() = default;
        void renderGPU(const std::string& gpuName, const SGpuData& gpuData);
};