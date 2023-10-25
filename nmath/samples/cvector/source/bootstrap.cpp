
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
    F_cvector2_f32 v2 = { 1.0f, 2.0f };
    F_cvector3_f32 v3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4_f32 v4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_data2_f32 d2 = v2.data();
    F_data3_f32 d3 = v3.data();
    F_data4_f32 d4 = v4.data();
    
    F_cvector2_f32 dv2 = d2;
    F_cvector3_f32 dv3 = d3;
    F_cvector4_f32 dv4 = d4;
    
    F_cvector2_f32 a2 = { 1.0f, 2.0f };
    F_cvector3_f32 a3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4_f32 a4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_cvector2_f32 b2 = { 1.0f, 2.0f };
    F_cvector3_f32 b3 = { 1.0f, 2.0f, 3.0f };
    F_cvector4_f32 b4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    F_cvector2_f32 c2 = a2 + b2;
    F_cvector3_f32 c3 = a3 + b3;
    F_cvector4_f32 c4 = a4 + b4;

	ncpp::pause_console();

	return 0;
}
