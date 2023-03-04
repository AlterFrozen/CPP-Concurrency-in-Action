#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
using namespace std::chrono_literals;

/*
1. Problems with sharing data between threads
2. Protecting data with mutexes
3. Alternative facilities for protecting shared data
*/

class Game
{
public:
	void fill_one_to_sides()
	{
		std::lock_guard _guard{ m_mutex_deque }; // C++17: class template argument deduction
		m_nums.push_front(1);
		m_nums.push_back(1);
	}

	void fill_two_to_sides()
	{
		std::this_thread::sleep_for(0.1s);
		std::scoped_lock _guard{ m_mutex_deque };
		m_nums.push_front(2);
		m_nums.push_back(2);
	}

	void print_game_state()
	{
		for (auto& num : m_nums)
			std::cout << num << ' ';
		std::cout << std::endl;
	}

private:
	std::mutex m_mutex_deque;
	std::deque<int> m_nums;
};

void main_chapter3()
{
	Game game{};

	auto thr1 = std::thread([&game]()
		{
			game.fill_one_to_sides();
		});
	auto thr2 = std::thread([&game]()
		{
			game.fill_two_to_sides();
		});

	thr1.join();
	thr2.join();
	game.print_game_state();
}
