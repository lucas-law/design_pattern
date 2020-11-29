#pragma once
#include <iostream>

/**
 * Strategy 模式
 * 动机：
 * 1.在软件构建过程中，某些对象使用的算法可能多种多样，经常改变，如果将这些算法都
 * 编码到对象中，将会使对象变得异常复杂，而且有时候支持不使用的算法也是一个性能负担。
 * 2.如何在运行时根据需要透明的更改对象的算法？将算法与对象本身解偶，从而避免上述问题？
 */

/**
 * 例如一个计算税率的例子，如果用传统的方式计算各个国家的税率，实现方式如下：
 */

using namespace std;

class SalesOrder
{
public:

enum TaxBase
{
    US,
    CH,
    EN,
    GE //新增，更改
};

public:
    double calculate_tax()
    {
        if (tax == US) {
            cout << "calculate US tax" << endl;
            return 0.01;
        } else if (tax == EN) {
            cout << "calculate EN tax" << endl;
            return 0.02;
        } else if (tax == CH) {
            cout << "calculate CH tax" << endl;
            return 0.03;
        } else if (tax == GE) { // 新增，更改
            cout << "calculate GE tax" << endl;
            return 0.04;
        } else {
            return 0.001;
        }
    }
    void set_tax(TaxBase ta) { tax = ta; }
private:
    TaxBase tax;
};

/**
 * 上面的设计破坏了开闭原则，如何以扩展的方式实现上述功能呢？
 * 我们不用枚举类型来实现，先定义一个抽象的基类接口，实现税法策略的计算。
 * 其中用到了算法上下文。
 */
class Context
{

};

class TaxStrategy
{
public:
    virtual double calculate_tax(const Context &context) = 0;
    virtual ~TaxStrategy() { }
};

class USTax : public TaxStrategy
{
public:
    virtual double calculate_tax(const Context &context)
    {
        cout << "calculate us tax" << endl;
        return 0.01;
    }
};

class ENTax : public TaxStrategy
{
public:
    virtual double calculate_tax(const Context &context)
    {
        cout << "calculate en tax" << endl;
        return 0.02;
    }
};

class CHTax : public TaxStrategy
{
public:
    virtual double calculate_tax(const Context &context)
    {
        cout << "calculate ch tax" << endl;
        return 0.03;
    }
};

class GETax : public TaxStrategy
{
public:
    virtual double calculate_tax(const Context &context)
    {
        cout << "calculate ge tax" << endl;
        return 0.04;
    }
};

class StrategyFactory
{
public:
    TaxStrategy *create() {
        return new USTax();
    }
};
/**
 * SalesOrder 就可以重新设计如下：
*/

class SalesOrderNew
{
public:
    SalesOrderNew(StrategyFactory *fac)
    {
        p_strategy_ = fac->create();
    }

    ~SalesOrderNew()
    {
        delete this->p_strategy_;
    }
    double calculate_tax()
    {
        return this->p_strategy_->calculate_tax(Context());
    }
private:
    TaxStrategy *p_strategy_;
};


