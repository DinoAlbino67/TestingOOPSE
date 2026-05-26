#pragma once 

#include "ADC.h"

template <typename T=short, int N=1024>
class Channel{
    ADC<T, N>& adc;
public:
    Channel(ADC<T, N>&& adc) : adc(adc){

    }
    virtual ~Channel() = default;
    virtual size_t run(vector<double>& inputs);
    virtual vector<double> get_values();
    virtual ADC<T, N>& get_adc(){
        return adc;
    }
};

#include "Chanel.cpp"