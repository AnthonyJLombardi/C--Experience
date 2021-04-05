#include "String.h"
#include <string>
using namespace std;

int main() {
    String s;
    cout <<"String s: " << s << endl;

    char cs[] = "Hello World!";
    String s1(cs);
    cout <<"String s1: "<< s1 << endl;

    s = s1;
    s1.clear();
    cout << "String s1: " << s1 << endl <<"String s: "<< s << endl;

    cout << "String s length: "<< s.length() << endl;
    cout << "String s1 length: " << s1.length() << endl;

    String s2(" This should be added.");
    String s3(" And this too!");
    cout << "String s+s2+s3: " << s+s2+s3 << endl;

    char* cs2 = s.c_str();
    for(int x = 0; x<12; x++ )
        cout << cs2[x];
}