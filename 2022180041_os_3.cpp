#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
int main()
{
	std::chrono::nanoseconds accTime{ 0 };
	for (int i = 0; i < 100; ++i)
	{
		const auto cur = std::chrono::high_resolution_clock::now();
		std::this_thread::yield();
		//printf("Hello World.\n");
		accTime += std::chrono::high_resolution_clock::now() - cur;
	}
	printf("%lld", (accTime / 100).count());
}