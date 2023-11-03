
#include <nmath/.hpp>

using namespace nmath;



int main() {

	F_matrix2x4 a2x4 = F_matrix2x4{

		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f },
		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f }

	};
    
	F_matrix4x4 a4x4 = F_matrix4x4{

		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f },
		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f },
		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f },
		F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f }
	
	};
    
	ncpp::pause_console();

	return 0;
}
