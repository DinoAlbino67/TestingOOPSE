#pragma once

#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <sstream>

template <typename T = short, int N = 1024>
struct ADC
{
    int bits;
    std::chrono::milliseconds clock_rate;
    double rangeMin;
    double rangeMax;
    double sensitivity;
    double trigger_level;
    std::vector<T> samples;

public:
    T convert(double voltage) {
        double clamped = std::max(rangeMin, std::min(rangeMax, voltage));
        return static_cast<T>(clamped * sensitivity);
    }

    size_t read_input(std::vector<double>& inputs) {
        size_t added = 0;
        for (double v : inputs) {
            if (samples.size() >= N) {
                break;
            }
            if (v >= trigger_level) {
                samples.push_back(convert(v));
                added++;
            }
        }
        return added;
    }

    double value(size_t i) {
        if (i >= samples.size()) {
            return 0.0;
        }
        return static_cast<double>(samples[i]) / sensitivity;
    }

    std::vector<double> values() {
        std::vector<double> res;
        for (size_t i = 0; i < samples.size(); ++i) {
            res.push_back(value(i));
        }
        return res;
    }

    std::string to_string() {
        std::ostringstream oss;
        oss << "ADC[bits=" << bits
            << ", samples=" << samples.size()
            << ", trigger=" << trigger_level << "]";
        return oss.str();
    }
};