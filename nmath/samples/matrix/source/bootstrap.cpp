
#include <nmath/.hpp>

using namespace nmath;



int main() {

    F_vector3 right = { 1, 2, 3 };
    F_vector3 up = { 1, 2, 3 };
    F_vector3 forward = { 1, 2, 3 };
    F_vector3 translation = { 1, 2, 3 };

    F_matrix4x4 transform;
    transform.right = { right, 0 };
    transform.up = { up, 0 };
    transform.forward = { forward, 0 };
    transform.translation = { translation, 1 };

	ncpp::pause_console();

	return 0;
}
