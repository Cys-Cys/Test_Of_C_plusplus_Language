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
	unsigned int : 7;  // ����8λ����ʹ�ã���Ϊռλ�����
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

// ע����������Ӧ�ú�С��ͨ�������������ڱ���ʱ��������ӿ��ٶȣ����ǻ��кܶั�������������úܶ��ռ�ط�
inline int square(int x) { return x * x; }
#define SQUARE(X) X*X  // �򵥵��ı��滻

// ģ��
template <typename anyType>
void Swap(anyType&, anyType&);  // ��ʽʵ����

// ��ʽ���廯, ���ȼ�������ʽʵ����
template <> void Swap<First>(First&, First&);
// template <> void Swap(First& a, First& b)  

// ��ʾʵ������ע�����ʾ���廯��ͬһ��Ԫ���ļ���ʹ��ͬһ�����ͽ�����
// template void Swap<double>(double& a, double& b);

typedef const double* (*p_fun)(const double arr[], int n);  // �����˺���ָ���ʹ��

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

	int Test_Init(999);  // C++���صĳ�ʼ����ʽ
	int Test_Init2{ 444 };  // C98֧�֣�{}ǰ���Լ�=, C11��Ϊ�б��ʼ��
	// int Test_Init2{99999999};    �������ø�ֵ��������խ(narrowing)
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
		int& r = *p;  // ��ֵ����
		int&& r1 = *p + 3;  // �е㻨�����,��ֵ����
		// int& r = *p + 3;  // ��ñ���ôд

		int b = 50;
		p = &b;  // rû��

		// r�ӽ���const *���ڳ�ʼ��ʱ��ȷ�������ö���֮���޷�����
		// ��ʱ*p=50��r=4�����r�����ʼ��
		cout << "*p is " << *p << " reference r is: " << r << endl;
		cout << "p is " << p << " reference &r is: " << &r << endl;

		cout << "after reference a is " << function_using3(a, b)
			<< " reference r is: " << r  << endl;
		function_using3(a, b) = b;
		cout << "after again reference a is " << &function_using3(a, b)
			<< " reference r is: " << r << endl;

		// ��ʹ��function_using3(a, r)ʱ����a = 4�����Ϊ8������Ȥ


		int c = function_using3(a, b);  // �����˸�������,��a��ֱֵ�Ӹ��Ƹ�c
		c = 2;
		cout << "after again change &a is " << &a << "  c is: " << &c << endl;
		int& d = function_using3(a, b);
		cout << "after again change &a is " << &a << "  &d is: " << &d << endl;
	}*/

	/*{
		Swap(Test_Init, Test_Init2);
		Swap<>(Test_Init, Test_Init2);  // ��ʾʵ����,��ʱ����ʹ�þ��庯������ʹ��ģ�庯��
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

	cin.get(str1, 20).get();  // �ж�ȡ���Ὣ���з����ڻ��������ڶ������ڶ�ȡ���з���ֹ����
	cin.getline(str1, 20);  // �ж�ȡ�����Ὣ���з����ڻ��������Ὣ���з��滻�ɿ��ַ�'\0'
	return;
}

void Test_Violate_Convert() {

	std::cout << "common: " << int('W') << std::endl;  // C++����ǿ��ת��
	std::cout << "using static_cast: " << static_cast<int> ('S') << std::endl;

	return;
}

void Test_Char() {
	wchar_t ch1 = L'w';  // ��Ӧwcout��wcin�������
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
	// �����º���ָ��ʹ�õ���Ȥ֮��
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
