#ifndef QUEUE_TESTING_H_
#define QUEUE_TESTING_H_
/*
用于实现模拟队列，此次模拟为超市队列收银时间
*/
namespace SIMULATE{
    typedef class Custom{
      /*
      表示超市收银等待客户客户
      */
      private:
        int arriving_time;
        int processing_time;  // 处理时间
        int iterms = 0;  // 总共买了多少物品
      public:
        Custom() {arriving_time = processing_time = 0;}
        ~Custom();
        void Setting(int n);
        int Get_Arr() const { return arriving_time;}
        int Get_Pro() const { return processing_time;}
    }shopping;

    class QUEUE_T{
      /*
        队列实现采用数组方式,链表方式同理
      */
      private:
        static const int Q_number = 20; // 默认长度
        const int numbers;  // 队列长度
        int iterms = 0;  // 队列里的物品
        int front;  // 队首指针
        int rear;  // 队尾指针
        shopping *Queue; // 队列
         
      public:
        QUEUE_T(): numbers(Q_number){}
        QUEUE_T(int n): numbers(n){}
        QUEUE_T(const QUEUE_T& a): numbers(a.numbers){}
        ~QUEUE_T();
        bool Enter(const shopping &);
        bool Out(shopping &);
        int GetItermNum() const{ return iterms;}
        bool isEmpty() const{return (iterms == 0) ? true : false;}
        bool isFull() const{return (iterms == numbers) ? true : false;}
    };

}

#endif
