
#include <nmath/.hpp>

using namespace nmath;



int main() {

    NCPP_INFO()
        << "Hello "
        << E_log_color::V_FOREGROUND_BRIGHT_GREEN
        << "NMath "
        << E_log_color::V_FOREGROUND_BRIGHT_YELLOW
        << NMATH_VERSION_STR
        << E_log_color::RESET;

	ncpp::pause_console();

	return 0;
}
