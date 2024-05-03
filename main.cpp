#include <iostream>
#include <string.h>

void Test_Of_String_New();

#include <limits.h>
#include <string>
#include <array>
#include <algorithm>
#include <vector>

#include "Class11.h"

struct First {
	union FF {
		int a;
		short b;
	};
	bool c : 1;  // 1 bit
	unsigned int : 7;  // 匿名8位不可使用，作为占位符间隔
};

enum class egg { small, big };

void Test_Of_String_New();
void Test_STD_IO();
void Test_Violate_Convert();
void Test_Array(std::array<double, 3>* p);
const double* function_using1(const double arr[], int n = 1);
const double* function_using2(const double arr[], int n = 1);
int& function_using3(int& a, const int& b);
int function_using4(int&, const int&);
const int*& test(const int*& item);

// 注意内联函数应该很小，通过将函数代码在编译时带入代码块加快速度，但是会有很多副本，因而如果调用很多很占地方
inline int square(int x) { return x * x; }
#define SQUARE(X) X*X  // 简单的文本替换

// 模板
template <typename anyType>
void Swap(anyType&, anyType&);  // 隐式实例化

// 显式具体化, 优先级高于隐式实例化
template <> void Swap<First>(First&, First&);
// template <> void Swap(First& a, First& b)  

// 显示实例化，注意和显示具体化在同一单元或文件中使用同一种类型将出错
// template void Swap<double>(double& a, double& b);

typedef const double* (*p_fun)(const double arr[], int n);  // 大大简化了函数指针的使用

namespace A {
	using std::cout;
	using std::cin;

	void a() {}
}
namespace B {
	using namespace A;
	using std::cout;
	using std::cin;

	const int CHARS_NUM = 80;
}


int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	int Test_Init(999);  // C++独特的初始化方式
	int Test_Init2{ 444 };  // C98支持，{}前可以加=, C11称为列表初始化
	// int Test_Init2{99999999};    不允许，该赋值导致了缩窄(narrowing)
	bool Test_Bool = true;
	const int* Test_p(&Test_Init);
	int* Test_p1(&Test_Init);
	egg eggs = egg::small;

	{
		//std::array<double, 3> arr = { 1., 3., 4. };
		//Test_Array(&arr);
	}
	{
		test(Test_p);
		Tst<int, 3>b;
		std::vector<double[3]> asss(3, { 0, 0, 0 });
		asss[1][1] = 1.;
		cout << endl << asss[1][1] << endl;

	}
	/*
	{
		double arr1[3] = { 1., 3., 4. };
		// const double* (*pp1)(const double*, int) = function_using1;
		p_fun pp1 = function_using1;
		std::cout << "address: " << pp1(arr1, 3)
			<< " and value is: " << *pp1(arr1, 3) << std::endl;

		// const double* (*pp2[2])(const double*, int) = { function_using1, function_using2 };
		p_fun pp2[2] = { function_using1, function_using2 };
		std::cout << "address: " << pp2[0](arr1, 3)
			<< " and value is: " << *pp2[0](arr1, 3) << std::endl;
		std::cout << "address: " << pp2[1](arr1, 3)
			<< " and value is: " << *pp2[1](arr1, 3) << std::endl;

		// const double* (*(*pp3)[2])(const double*, int) = &pp2;
		// p_fun (*pp3)[2] = &pp2;
		auto pp3 = &pp2;  // C11
		std::cout << "address: " << pp3[0][0](arr1, 3)
			<< " and value is: " << *pp3[0][0](arr1, 3) << std::endl;
		std::cout << "address: " << (*pp3)[1](arr1, 3)
			<< " and value is: " << *(*pp3)[1](arr1, 3) << std::endl;
	}
	*/


	// Test_STD_IO();
	// Test_Violate_Convert();

	{
		/*int i = 0;
		while (i++ < 30)
			if (i < 12)
				printf("32%d\n", i);*/
	}
	/*
	{
		std::cout << square(3 + 3) << std::endl;  // 36
		std::cout << SQUARE(3 + 3) << std::endl;  // 15
	}
	*/

	/* {
		int a = 4;
		int* p = &a;
		int& r = *p;  // 左值引用
		int&& r1 = *p + 3;  // 有点花里胡哨,右值引用
		// int& r = *p + 3;  // 最好别这么写

		int b = 50;
		p = &b;  // r没动

		// r接近于const *，在初始化时就确定了引用对象，之后无法更改
		// 此时*p=50，r=4，因此r必须初始化
		cout << "*p is " << *p << " reference r is: " << r << endl;
		cout << "p is " << p << " reference &r is: " << &r << endl;

		cout << "after reference a is " << function_using3(a, b)
			<< " reference r is: " << r  << endl;
		function_using3(a, b) = b;
		cout << "after again reference a is " << &function_using3(a, b)
			<< " reference r is: " << r << endl;

		// 当使用function_using3(a, r)时，若a = 4，输出为8，很有趣


		int c = function_using3(a, b);  // 避免了副本拷贝,将a在值直接复制给c
		c = 2;
		cout << "after again change &a is " << &a << "  c is: " << &c << endl;
		int& d = function_using3(a, b);
		cout << "after again change &a is " << &a << "  &d is: " << &d << endl;
	}*/

	/*{
		Swap(Test_Init, Test_Init2);
		Swap<>(Test_Init, Test_Init2);  // 显示实例化,此时不会使用具体函数而是使用模板函数
	}*/

	/*{
		B::CHARS_NUM;
		B::cout << "Now can use B to std::cout"<< std::endl;
	}*/

	/* {
		// Firsts fits = Firsts("Testing company");
		Firsts fits("Testing company");

		fits.show();
		fits = fits + Firsts(" of World scale");
		fits.show();
		cout << int(fits) << endl;
	}*/

	/* {
		SIMULATE::shopping shop1;
		shop1.Setting(20);
		cout << " Arrive:" << shop1.Get_Arr() << " process: " << shop1.Get_Pro() << endl;
	}*/

	/* {
		std::vector<int> a;
		a.push_back(2);
		a.push_back(3);
		cout << a[0];
		a.clear();
		a.push_back(9);
		a.push_back(9);
		a.push_back(8);
		cout << a[0] << a[a.size() - 1];
		int j = 0;
		while (a[j++] != a[a.size() - 1])
			cout << a[j];
	}*/
	return 0;
}

void Test_Array(std::array<double, 3>* p) {
	for (int i = 0; i < 3; i++)
		std::cout << p[0][i] << std::endl;
}

void Test_STD_IO() {
	using std::cout;
	using std::cin;
	using std::endl;

	int n_int = INT_MAX;
	char str1[20];

	cout << "First , hello world" << " and INT_MAX is "
		<< n_int << endl;

	cin.get(str1, 20).get();  // 行读取，会将换行符留在缓冲区；第二个用于读取换行符防止卡死
	cin.getline(str1, 20);  // 行读取，不会将换行符留在缓冲区，会将换行符替换成空字符'\0'
	return;
}

void Test_Violate_Convert() {

	std::cout << "common: " << int('W') << std::endl;  // C++风格的强制转换
	std::cout << "using static_cast: " << static_cast<int> ('S') << std::endl;

	return;
}

void Test_Char() {
	wchar_t ch1 = L'w';  // 对应wcout和wcin输入输出
	char16_t ch2 = u'\u00F3';
	char32_t ch3 = U'\U00000aad';
}

void Test_Of_String_New() {
	using std::string;

	string str1, str2;

	str1 = "WCSNDM";
	str2 = "Q daduantade E a!";

	string str3;

	str3 = str1 + " " + str2;
	str1 += str2;

	return;
}

const double* function_using1(const double arr[], int n) {
	// 感受下函数指针使用的有趣之处
	return arr;
}
const double* function_using2(const double arr[], int n) {
	return arr + 1;
}

int& function_using3(int& a, const int& b) {
	a += b;

	return a;
}

int function_using4(int& a, const int& b) {
	a = a + b;
	return a;
}

template <typename anyType>
void Swap<>(anyType& a, anyType& b) {
	anyType c = a;
	a = b;
	b = c;
	return;
}
template <>
void Swap<First>(First& a, First& b) {
	First c = a;
	a.c = b.c;
	b.c = c.c;
}

const int*& test(const int*& item) {
	std::cout << "the item in is:" << item << std::endl;
	std::cout << "the *item is:" << *item << std::endl;
	return item;
}
