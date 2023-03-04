#pragma once

/*
1. Starting threads, and various ways of specifying code to run on a new thread 
2. Waiting for a thread to finish versus leaving it to run
3. Uniquely identifying threads
*/

#include <thread>

class Inc
{
public:
	void operator()()
	{
		std::cout << ++num << '\n';
	}
	int num = 1;
};

void main_chapter2()
{
	Inc i;
	std::thread t( // Copy instead of Refer !!! (May use std::move())
		[&] {
			i(); 
			i(); }
	);
	std::cout << "Current Thread: " << std::this_thread::get_id() << '\n';
	std::cout << "Associated Thread: " << t.get_id() << '\n';
	t.join();
	std::cout << i.num << " < \n";

	auto cnt_thread_cores = std::thread::hardware_concurrency();
	if (!cnt_thread_cores) cnt_thread_cores = 2;
	std::cout << "\n Hardware Concurrency: " << cnt_thread_cores << '\n';
}