#include "Math.hpp"
#include <iostream>

Vector2f::Vector2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}

Vector2f::Vector2f()
    :x(0.0f), y(0.0f)
    {}

void Vector2f::print()
{
    std::cout << x << ", " << y <<std::endl;
}
