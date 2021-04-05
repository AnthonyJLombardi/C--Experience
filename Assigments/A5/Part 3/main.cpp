#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class Iterator, class T>
void increment(Iterator start, Iterator stop, const T & x) {
    for(Iterator it = start; it < stop; ++it)
        *it += x;
}

template <typename T>
void print_vector(ostream & out, const vector<T> & v) {
    for (auto x: v)
        out << x << " ";
    out << endl;
}

int main() {
    vector<int> v={1,5,7,1,8,5,8,4,4,6,5,4,6,9,2,3};
    vector<string> v2 = {"Bob", "Alex", "Josh", "Spencer", "Anthony", "Bob"};

    //Vector of ints
    cout<<"Vector of Ints"<<endl;
    print_vector(cout, v);
    increment(v.begin(), v.end(), 5);
    print_vector(cout, v);

    //Vector of Strings
    cout << "List of Strings" << endl;
    print_vector(cout, v2);
    increment(v2.begin(), v2.end(), " V.");
    print_vector(cout, v2);
}