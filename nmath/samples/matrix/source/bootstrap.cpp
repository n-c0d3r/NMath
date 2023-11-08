
#include <nmath/.hpp>

using namespace nmath;



int main() {

	F_matrix2x2 a2x2 = F_matrix2x2{

		F_vector2{ 1.0f, 2.0f },
		F_vector2{ 3.0f, 4.0f }

	};
    
	F_matrix4x4 a4x4 = F_matrix4x4{

		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f },
		F_vector4{ 2.0f, 3.0f, 4.0f, 5.0f },
		F_vector4{ 3.0f, 4.0f, 5.0f, 6.0f },
		F_vector4{ 4.0f, 5.0f, 6.0f, 7.0f }
	
	};

    F_matrix4x4 a4x4_dbac = a4x4.dbac();
	F_matrix2x2 a2x2_dbxy = a4x4.dbac().tl2x2();
    
    F_matrix4x4 b4x4 = a4x4 + a4x4_dbac;
    b4x4 *= -1.0f;
    
	ncpp::pause_console();

	return 0;
}
