#include <iostream>
#include <array>
#include <string>
using namespace std;

template <class T>
int search(T * array, int start, int stop, const T & e) {
    if(start < stop) {
        if (array[start] == e)
            return start;
        search(array, start + 1, stop, e);
    } else
    return -1;
}

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << search(a,0,10,10) << " " << search(a,0,5,10) << endl;
    string s[3]= {"AJ","Alex","Jake"};
    string test = "Jake";
    cout << search(s,0,3,test) << " " << search(s,0,2,test);
}