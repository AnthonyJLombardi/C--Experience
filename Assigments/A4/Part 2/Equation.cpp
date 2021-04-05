#include "Equation.h"
using namespace std;

bool Equation::read(istream & in) {
    //@param: takes an input stream passed by reference
    //@return: loads inputted data into an equation object
    in >> param1_;
    in >> operation_;
    in >> param2_;
    string check;
    getline(in, check);
    return check == "";
}

void Equation::print(ostream & out) {
    //@param: takes an output stream passed by reference
    //@return: sends all data from the equation object and sends it to the output stream
    out << param1_ << " " << operation_ << " " << param2_ << " = " << ans_;
}