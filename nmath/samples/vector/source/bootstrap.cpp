
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
    F_vector2 a2 = { 1.0f, 2.0f };
    F_vector3 a3 = { 1.0f, 2.0f, 3.0f };
    F_vector4 a4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_vector2 b2 = { 1.0f, 2.0f };
    F_vector3 b3 = { 1.0f, 2.0f, 3.0f };
    F_vector4 b4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_vector2 c2 = a2 + b2;
    F_vector3 c3 = a3 + b3;
    F_vector4 c4 = a4 + b4;
    
    b8 e2 = (c2 == F_vector2{ 2.0f, 4.0f });
    b8 e3 = (c3 == F_vector3{ 2.0f, 4.0f, 6.0f });
    b8 e4 = (c4 == F_vector4{ 2.0f, 4.0f, 6.0f, 8.0f });

	ncpp::pause_console();

	return 0;
}
