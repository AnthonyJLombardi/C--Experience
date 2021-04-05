#ifndef _EQUATION_H
#define _EQUATION_H
#include <iostream>
class Equation {
public:
    bool read(std::istream & in);
    void print(std::ostream & out);
    void set_ans(double ans) {ans_=ans;}
    char operation() {return operation_;}
    double param1() {return param1_;}
    double param2() {return param2_;}
private:
    double param1_, param2_, ans_;
    char operation_;
};
#endif //CS142A402_EQUATION_H
