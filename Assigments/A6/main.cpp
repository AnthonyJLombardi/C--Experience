#include <iostream>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


//Part 1:
template <typename T>
T total(initializer_list<T> init_list) {
    T sum;
    for(T x: init_list) {
        sum += x;
    }
    return sum;
}

//Part 2:
template <class Iterator, class UnaryPredicate>
void print_if(Iterator start, Iterator stop, UnaryPredicate f, ostream & out ) {
    for(Iterator it = start; it != stop; ++it) {
        if(f(*it))
            out << *it << endl;
    }
}

bool longer(string s) {
    return s.length() > 3;
}

//Part 3:
class StartsWith {
    public:
        StartsWith(char c) : c_(c) {}
        bool operator() (string name) {return name.front() == c_;}
    private:
        char c_;
    };

//Part 4:
template <typename T>
void print(const list<T> & ls, const int & n) {
    if(ls.size()<n) {
        for(auto x: ls)
            cout << x << endl;
    } else {
        auto end = ls.begin();
        advance(end, n);
        for(auto it = ls.begin(); it != end; ++it)
            cout << *it << endl;
    }
}
int main() {
    cout << "Part 1:" << endl;
    cout << total({5,6,7,8,9,9,6,3,4,6,7,8,3,4,6,7,5,3,5,6,5,5,78,4,3}) << endl;
    initializer_list<string> init_list = {"John", "Alex", "Josh", "Anthony", "Spencer"};
    cout << total(init_list) << endl;

    cout << "\n" << "Part 2:" << endl;
    vector<string> v = {"Jon", "Alex", "Josh", "AJ", "Spencer"};
    print_if(v.begin(), v.end(), longer, cout);

    cout << "\n" << "Part 3:" << endl;
    cout << count_if(v.begin(), v.end(), StartsWith('A')) << endl;

    cout << "\n" << "Part 4:" << endl;
    list<int> ls = {5,8,2,9,4,9,4,8,5};
    print(ls, 23); //n is larger than the ls.size()
    cout << "-----------\n";
    print(ls, 3); //n is smaller than ls.size()
    cout << "-----------\n";
    print(ls, 0); //n is 0

}