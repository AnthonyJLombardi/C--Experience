#include "Equation.h"
using namespace std;
bool evaluate() {
    Equation e;
    if(e.read(cin)) {
        switch (e.operation()) {
            case '+':
                e.set_ans(e.param1() + e.param2());
                break;
            case '-':
                e.set_ans(e.param1() - e.param2());
                break;
            case '*':
                e.set_ans(e.param1() * e.param2());
                break;
            case '/':
                e.set_ans(e.param1() / e.param2());
                break;
            default:
                cout << "invalid expression: invalid operator"; return false;
                break;
        }
        e.print(cout);
        return true;
    } else {
        cout << "invalid expression: invalid input";
        return false;
    }
}
int main() {
    if(evaluate())
        return 0;
    else return 1;
}