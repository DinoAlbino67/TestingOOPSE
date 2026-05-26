#pragma once
#include <string>
#include <chrono>
#include <vector>

using namespace std;

template <typename T=short, int N=1024>
struct ADC 
{
    int bits;
    chrono::miliseconds clock_rate;
    double rangeMin, rangeMax;
    double sensitivity;
    double trigger_level;
    vector<T> samples;
public:
    T convert(double voltage){
    
    }


    size_t read_input(vector<double>& inputs){

    }

    double value(size_t){

    }

    vector<double> values(){

    }

    string to_string(){

    }
};
