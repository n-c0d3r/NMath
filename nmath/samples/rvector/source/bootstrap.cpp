
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
    F_rvector2 a2 = { 1.0f, 2.0f };
    F_rvector3 a3 = { 1.0f, 2.0f, 3.0f };
    F_rvector4 a4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_rvector2 b2 = { 1.0f, 2.0f };
    F_rvector3 b3 = { 1.0f, 2.0f, 3.0f };
    F_rvector4 b4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_rvector2 c2 = a2 + b2;
    F_rvector3 c3 = a3 + b3;
    F_rvector4 c4 = a4 + b4;
    
    b8 e2 = (c2 == F_rvector2 { 2.0f, 4.0f });
    b8 e3 = (c3 == F_rvector3 { 2.0f, 4.0f, 6.0f });
    b8 e4 = (c4 == F_rvector4 { 2.0f, 4.0f, 6.0f, 8.0f });

	ncpp::pause_console();

	return 0;
}
