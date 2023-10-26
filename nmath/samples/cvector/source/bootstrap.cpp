
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
    F_cvector2 a2 = { 1.0f, 2.0f };
    F_cvector3 a3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4 a4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_cvector2 b2 = { 1.0f, 2.0f };
    F_cvector3 b3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4 b4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_cvector2 c2 = a2 + b2;
    F_cvector3 c3 = a3 + b3;
    F_cvector4 c4 = a4 + b4;
    
    b8 e2 = (c2 == F_cvector2{ 2.0f, 4.0f });
    b8 e3 = (c3 == F_cvector3{ 2.0f, 4.0f, 6.0f });
    b8 e4 = (c4 == F_cvector4{ 2.0f, 4.0f, 6.0f, 8.0f });

    std::cout << a4.x << std::endl;

	ncpp::pause_console();

	return 0;
}
