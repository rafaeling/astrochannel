#include <iostream>

using namespace std;

#include "astrochannel.hpp"

int main()
{
    std::cout << "Astro Channel Test" << std::endl;

    auto channelArray = astrochannel::channelarray<double, 1>({1.0, 2.0, 3.0});

    return 0;
}