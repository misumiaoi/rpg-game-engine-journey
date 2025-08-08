#pragma once
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <thread>
#include <type_traits>


template <typename type>
static void print(type input) {std::cout << input << std::endl;}


template <typename type>
static void pause() {std::cin.read();}

class UIActions
{
public:

    UIActions() : eng(rd()) {}
	
    void pauseFor(int ms);
	void countDown(int start, int end = 0, int step = 1, int timeperiod = 500);

	template <typename type>
	type generateBetween(type start, type end)
	{
        // 使用 if constexpr 在编译期进行判断
        if constexpr (std::is_integral_v<type>)
        {
            // 如果 type 是一个整数类型 (int, long, short...)
            // 我们就使用“整数”分布器
            std::uniform_int_distribution<type> distr(start, end);
            return distr(eng); // 使用我们类成员的那个 eng 生成器
        }
        else if constexpr (std::is_floating_point_v<type>)
        {
            // 如果 type 是一个浮点数类型 (float, double...)
            // 我们就使用“浮点数”分布器
            std::uniform_real_distribution<type> distr(start, end);
            return distr(eng); // 使用我们类成员的那个 eng 生成器
        }
        // 如果传入了不支持的类型，这段代码会在编译时报错，非常安全

	}

	void typeText(std::string& text, int delay_ms = 500);
	void clearScreen();
	void drawProgress(int totalsteps, int current, int width = 50);
	void pauseForEnter();

private:
    std::random_device rd;
    std::mt19937 eng;

};