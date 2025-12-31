#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union
    {
        struct
        {
            float x, y, z, w;   
        };
        struct
        {
            Vector2 a, b;
        };
    };
};

std::ostream& operator<<(std::ostream& stream, const Vector4& other)
{
    stream << other.x << ", " << other.y << ", " << other.z << ", " << other.w;
    return stream;
}

int main()
{
    Vector4 vector;
    vector.x = 1;
    vector.y = 2;
    vector.z = 3;
    vector.w = 4;
    std::cout << vector << std::endl;
    vector.a = { 100, 200 };
    vector.b = { 300, 400 };
    std::cout << vector << std::endl;
}