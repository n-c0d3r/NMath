
#include <nmath/.hpp>

using namespace nmath;

#include <DirectXMath.h>

using namespace DirectX;



int main() {
    
	F_quaternion q1 = F_quaternion{ 1.0f, 2.0f, 3.0f, 4.0f};
	F_quaternion q2 = F_quaternion{ -1.0f, 6.0f, 0.0f, -2.0f};

	XMVECTOR vq1 = XMVectorSet(1.0f, 2.0f, 3.0f, 4.0f);
	XMVECTOR vq2 = XMVectorSet(-1.0f, 6.0f, 0.0f, -2.0f);

	F_vector4 a1 = F_vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	F_vector4 a2 = F_vector4{ -1.0f, 6.0f, 0.0f, -2.0f };

	F_quaternion q3 = q1 * q2;
	F_vector4 a3 = a1 + a2;

	XMVECTOR vq3 = XMQuaternionMultiply(vq1, vq2);

	{

		NCPP_SCOPED_PROFILER_SAMPLE("NMath: ");

		for (i32 i = 0; i < 10000; ++i)
			a3 = a3 + a2;

	}

	{

		NCPP_SCOPED_PROFILER_SAMPLE("DirectXMath: ");

		for (i32 i = 0; i < 10000; ++i)
			vq3 = vq3 + vq2;

	}

	{

		NCPP_SCOPED_PROFILER_SAMPLE("NMath: ");

		for(i32 i = 0; i < 10000; ++i)
			q3 = multiply(q3, q2);

	}

	{

		NCPP_SCOPED_PROFILER_SAMPLE("DirectXMath: ");

		for (i32 i = 0; i < 10000; ++i)
			vq3 = XMQuaternionMultiply(vq3, vq2);

	}

	std::cout << a3.x << std::endl;
	std::cout << q3.x << std::endl;
	std::cout << vq3.m128_f32[0] << std::endl;

	ncpp::pause_console();

	return 0;
}
