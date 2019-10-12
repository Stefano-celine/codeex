#include <iostream>
#include "Stock.hpp"
#include "Observer.hpp"

using namespace std;
using namespace design_patterns;

// there is a stock named Tfosorcim
// in other places in this program
// the stock specifically points to this one
Stock Tfosorcim("Tfosorcim", 2000);

// there are three inverstors
Investor XiaoMin("XiaoMin"),
         DaXiong("DaXiong"),
         Michael("Michael");

// print price of the stock
void showStock()
{
    cout << "Tfosorcim's price is " \
    << Tfosorcim.getPrice() << endl;
}

// suspend transactions, update the price
// and print the helpful descriptive text
// param num: just represents which round
void round(int num)
{
    cout << "This is Round " << num << "!" << endl;
    // go to the next state
    Tfosorcim.nextRound();
    showStock(); cout << endl;
}

// the main control function
int main(int argc, char *argv[])
{
// helpful macro for a single deal which buys shares with a range
// range can be change by execute `Name.changeRange(&Stock, range)`
#define DEAL(Name, Num, Range)\
    cout << #Name " buys " #Num " shares of Tfosorcim" << endl;\
    Name.buyStock(&Tfosorcim, Num, Range)

    showStock();
    cout << "Then the stock market is starting to work" << endl;
    // XiaoMin buys 80 shares of the stock and set 0.1 as the range
    DEAL(XiaoMin, 80, 0.1);
    // DaXiong buys 60 shares of the stock and set 0.2 as the range
    DEAL(DaXiong, 60, 0.2);
    // Michael buys 40 shares of the stock and set 0.3 as the range
    DEAL(Michael, 40, 0.3);
    cout << endl;

    // just run 10 rounds for testing
    for (int i = 1; i <= 10; ++i)
    {
        round(i);
    }

    return 0;
}
