#include "Class11.h"
#include <time.h>
#include <stdlib.h>



Firsts::Firsts() {
	com = "";
	std::cout << "This is a default call" << std::endl;
}

Firsts::Firsts(const std::string& a) {
	com = a;
	std::cout << "This is a " << com << " call" << std::endl;
}

Firsts::~Firsts() {

}

void Firsts::show() const {
	std::cout << "now call the private function" << std::endl;
	Test();
}

std::string Firsts::GetCompany() const {
	return com;
}

/*
Firsts Firsts::operator+(const Firsts& a) const{
	Firsts temp;
	temp.com = com + a.GetCompany();

	return temp;
}
*/

// 友元方式
// 当一个string输入时，类可以隐式构造一个临时类a存储string，前提是有相应的构造函数
Firsts operator+(const Firsts& a, const Firsts& b) {
	Firsts temp;
	temp.com = a.GetCompany() + b.GetCompany();

	return temp;
}

// 要求显示转换而非隐式转换避免问题
Firsts::operator int() const {
	return int(com.size());
}

Firsts::operator std::string() const {
	return com;
}

// 可用于new与delete防止微妙的后果
Firsts& Firsts::operator =(const Firsts& a) {
	com = a.com;

	return *this;
}

// 复制构造函数
Firsts::Firsts(const Firsts& a) {
	com = a.com;
}

namespace SIMULATE {
	// 如果使用shopping::Custom，visual studio 2022会发出警告
	Custom::Custom(int arriving_times) {
		arriving_time = arriving_times;
		processing_time = 0;
	}

	Custom::Custom(const Custom& a) {
		arriving_time = a.arriving_time;
		processing_time = a.processing_time;
		iterms = a.iterms;
	}

	Custom::~Custom() {

	}

	void Custom::Setting(int n) {
		srand(unsigned int(time(0)));
		processing_time = rand() % 4;
		arriving_time = n;
	}

	Custom& Custom::operator =(const Custom& a) {
		arriving_time = a.arriving_time;
		processing_time = a.processing_time;
		iterms = a.iterms;
		return *this;
	}
}

namespace SIMULATE {

	QUEUE_T::QUEUE_T() :numbers(Q_number) {
		Queue = new shopping[numbers];
		front = 0;
		rear = 0;
		iterms = 0;

		for (int i = 0; i < numbers; i++) {
			Queue[i] = 0;
		}
	}

	QUEUE_T::QUEUE_T(int n) :numbers(n) {
		Queue = new shopping[numbers];
		front = 0;
		rear = 0;
		iterms = 0;
	}

	QUEUE_T::QUEUE_T(const QUEUE_T& a) : numbers(a.numbers) {
		front = a.front;
		rear = a.rear;
		Queue = new shopping[numbers];
		iterms = a.iterms;

		for (int i = 0; i < numbers; i++)
			Queue[i] = a.Queue[i];

	}

	QUEUE_T::~QUEUE_T() {
		delete[] Queue;
	}

	bool QUEUE_T::Out(shopping& a) {
		if (!iterms) {
			std::cout << "warning, queue is empty" << std::endl;
			return false;
		}

		iterms--;
		rear = (rear + 1) % (numbers - 1);
		return true;
	}

	bool QUEUE_T::Enter(const shopping& a) {
		if (iterms == numbers) {
			std::cout << "warning, queue is Full" << std::endl;
			return false;
		}

		iterms++;
		front = (front + 1) % (numbers - 1);
		return true;
	}
}