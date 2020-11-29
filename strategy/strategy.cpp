#include "strategy.h"

int main(int, char **)
{
    /*旧的实现方式*/
    SalesOrder order;
    order.set_tax(SalesOrder::TaxBase::CH);
    double s = order.calculate_tax();
    cout << "result:" << s << endl;

    /*新的方式*/
    StrategyFactory fac;
    SalesOrderNew order_new(&fac);
    double s_new = order_new.calculate_tax();
    cout << "result:" << s_new << endl;
}