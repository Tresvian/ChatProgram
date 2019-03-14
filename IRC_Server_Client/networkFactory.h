#pragma once
#include <thread>
#include <atomic>
#include <vector>
#include <string>


void StartListening(const int& tickRate, std::atomic<bool>& endProgramIndicator, std::atomic<bool>& endProgramIndicatorResult);