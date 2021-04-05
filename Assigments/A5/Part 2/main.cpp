#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
template <typename T>
void print(ostream & out, const vector<T> & v) {
    for(auto x: v)
        out << x << " ";
    out<<endl;
}

int main() {
    vector<int> v1={1,5,7,1,8,5,8,4,4,6,5,4,6,9,2,3};
    vector<string> v2 = {"Bob", "Alex", "Josh", "Spencer", "Anthony", "Bob"};

    //Vector #1 Replace
    cout<<"Vector #1: Before replace"<<endl;
    print(cout,v1);
    replace(v1.begin(), v1.end(), 4, 27);
    cout<<"Vector #1: After replace"<<endl;
    print(cout, v1);

    //Vector #2 Replace
    cout<<"Vector #2: Before replace"<<endl;
    print(cout,v2);
    replace(v2.begin(), v2.end(), "Bob", "Jim");
    cout<<"Vector #2: After replace"<<endl;
    print(cout, v2);

    //Vector #1 max_element
    cout <<"Max Element in Vector #1\n" << *max_element(v1.begin(), v1.end()) << endl;

    //Vector #2 max_element
    cout << "Max Element in Vector #2\n" << *max_element(v2.begin(), v2.end());
}