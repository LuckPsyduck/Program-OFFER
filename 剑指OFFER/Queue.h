#pragma once
#include<iostream>
#include <stack>
#include <exception>
#include <queue>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // �ڶ���ĩβ���һ�����
    void appendTail(const T& node);

    // ɾ�����е�ͷ���
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& element)//���������stack1
{
    stack1.push(element);
} 

template<typename T> T CQueue<T>::deleteHead()//stack1װ��stack2
{
    if(stack2.size()<= 0)
    {
        while(stack1.size()>0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw new exception("queue is empty");

    T head = stack2.top();
    stack2.pop();

    return head;
}
