
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
    F_cvector2 v2 = { 1.0f, 2.0f };
    F_cvector3 v3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4 v4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_data2 d2 = v2.data();
    F_data3 d3 = v3.data();
    F_data4 d4 = v4.data();
    
    F_cvector2 dv2 = d2;
    F_cvector3 dv3 = d3;
    F_cvector4 dv4 = d4;
    
    F_cvector2 a2 = { 1.0f, 2.0f };
    F_cvector3 a3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4 a4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_cvector2 b2 = { 1.0f, 2.0f };
    F_cvector3 b3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4 b4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_cvector2 c2 = a2 + b2;
    F_cvector3 c3 = a3 + b3;
    F_cvector4 c4 = a4 + b4;

	ncpp::pause_console();

	return 0;
}
