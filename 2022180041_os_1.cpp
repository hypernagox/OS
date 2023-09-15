#include <thread>
#include <chrono>
#include <iostream>
#include <Windows.h>

PROCESS_INFORMATION CreateNotePad()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess(
		L"C:\\Windows\\System32\\notepad.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);
	return pi;
}

int main()
{
	//std::chrono::nanoseconds accTime{ 0 };
	//for (int i = 0; i < 100; ++i)
	//{
	//	const auto cur = std::chrono::high_resolution_clock::now();
	//	//std::this_thread::yield();
	//	printf("Hello World.\n");
	//	accTime += std::chrono::high_resolution_clock::now() - cur;
	//}
	//std::cout << (accTime / 100).count() << '\n';

	HANDLE handle[2];
	PROCESS_INFORMATION pi1 = CreateNotePad();
	PROCESS_INFORMATION pi2 = CreateNotePad();
	handle[0] = pi1.hProcess;
	handle[1] = pi2.hProcess;
	WaitForMultipleObjects(2, handle, true, INFINITE);
	CloseHandle(pi1.hProcess);
	CloseHandle(pi2.hProcess);
	CloseHandle(pi1.hThread);
	CloseHandle(pi2.hThread);
}