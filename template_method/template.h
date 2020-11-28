#ifndef _TEMPLATE_H__
#define _TEMPLATE_H__

#include <iostream>
using namespace std;
/**
 * Template method
 * 动机：
 * 1. 在软件构建过程中，对于某一项任务，它常常有稳定的整体操作结构，
 * 但各个子步骤却有很多改变但需求，或者由于固有的原因（比如框架和应用之间的关系）而无法
 * 和任务的整体结构同时实现。
 * 2. 如何在一个确定稳定操作结构的前提下，来灵活的应对各个子步骤的变化，或者晚期实现需求？
 */

class Library
{
public:
    void run() // 稳定，template method调用
    {
        step1();
        if (step2()) { //支持变化=>虚函数的多态调用
            step3();
        }

        for (int i = 0; i < 4; ++i) {
            step4();   //支持变化=>虚函数的多态调用
        }
        step5();
    }
    virtual ~Library() { }
protected:
    void step1() // 稳定
    {
        cout << "step1" << endl;
    }
    void step3() // 稳定
    {
        cout << "step3" << endl;
    }
    void step5() // 稳定
    {
        cout << "step5" << endl;
    }
    virtual bool step2() = 0;
    virtual void step4() = 0;
};

class Application : public Library
{
public:
    virtual bool step2()
    {
        cout << "step2" << endl;
        return true;
    }

    virtual void step4()
    {
        cout << "step4" << endl;
    }
};


#endif //!_TEMPLATE_H__