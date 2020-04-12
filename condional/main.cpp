#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <vector>

std::mutex readyMutex;
bool ready = false;
std::condition_variable readyVariable;

void threadProc(const int& num) {
	std::unique_lock<std::mutex> t1(readyMutex);
	while (!ready)
	{
		readyVariable.wait(t1);
	}
	std::cout << "num: " << num << std::endl;
}

void go() {
	std::unique_lock<std::mutex> t1(readyMutex);
	ready = true;
	readyVariable.notify_all();
}

int main() {
	std::vector<std::thread> threadBox;
	for (auto i = 0;i< 10;i++)
	{
		threadBox.push_back(std::thread(threadProc, i));
	}
	go();
	for (auto& th:threadBox)
	{
		th.join();
	}
}