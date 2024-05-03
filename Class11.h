#pragma once
#ifndef CLASS11_H_
#define CLASS11_H_

#include <iostream>
class Firsts {
private:
    std::string com;
    void Test()const { std::cout << "This is a test for " << com << std::endl; }

public:
    Firsts();
    Firsts(const std::string&);
    Firsts(const Firsts&);
    void show() const;
    std::string GetCompany() const;
    ~Firsts();
    // Firsts& operator+(const Firsts &) const;
    friend Firsts operator+(const Firsts&, const Firsts&);
    Firsts& operator =(const Firsts&);
    explicit operator int() const;
    operator std::string() const;
};

namespace SIMULATE {
    typedef class Custom {
        /*
        ��ʾ���������ȴ��ͻ��ͻ�
        */
    private:
        int arriving_time;
        int processing_time;  // ����ʱ��
        int iterms = 0;  // �ܹ����˶�����Ʒ
    public:
        Custom(int arriving_times = 0);
        Custom(const Custom&);
        ~Custom();
        void Setting(int n);
        int Get_Arr() const { return arriving_time; }
        int Get_Pro() const { return processing_time; }
        Custom& operator =(const Custom&);
    }shopping;

    class QUEUE_T {
        /*
          ����ʵ�ֲ������鷽ʽ,����ʽͬ��
        */
    private:
        static const int Q_number = 20; // Ĭ�ϳ���
        const int numbers;  // ���г���
        int iterms;  // ����Ŀǰ����
        int front;  // ����ָ��
        int rear;  // ��βָ��
        shopping* Queue; // ����

    public:
        QUEUE_T();
        QUEUE_T(int n);
        QUEUE_T(const QUEUE_T& a);
        ~QUEUE_T();
        bool Enter(const shopping&);
        bool Out(shopping&);
        int GetItermNum() const { return iterms; }
        bool isEmpty() const { return (iterms == 0) ? true : false; }
        bool isFull() const { return (iterms == numbers) ? true : false; }
    };

}

template <typename T>
class Stack {
    enum { SIZE = 10 };
    int stacksize;
    T* items;
    int top;

public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack& st);
    ~Stack() { delete[]items; }
    bool isempty() { return top == 0; }
    bool isfull() { return top == stacksize; }
    bool push(const T& item);
    bool pop(T& item);
    Stack& operator =(const Stack& st);
};

template <typename T>
Stack<T>::Stack(int ss) :stacksize(ss), top(0) {

}

template <typename T>
Stack<T>::Stack(const Stack& st) {
    stacksize = st.stacksize;
    top = st.top;
    if (!items)
        delete items;
    items = new T[stacksize];
    for (int i = 0; i < top; i++) {
        items[i] = st.items[i];
    }

}

template <typename T>
bool Stack<T>::push(const T& item) {

}

template <typename T>
bool Stack<T>::pop(T& item) {

}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
    if (this == &st)
        return *this;

    delete items;
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];

    for (int i = 0; i < top; i++)
        items[i] = st.items[i];

    return *this;
}

template <typename T1, int n>
class Tst {
    T1 arr[n];
};
#endif

