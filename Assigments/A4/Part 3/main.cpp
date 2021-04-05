#include <iostream>
#include <vector>
using namespace std;
void append(vector<int> & v1, const vector<int> & v2) {
    //@param: the method takes two int vectors
    //@return: v2 is added onto the back of v1
    for(int x=0; x<v2.size(); x++) {
        v1.push_back(v2.at(x));
    }
}

int main() {
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,7,8,9,10};
    append(v1,v2);
    for(int x : v1) {
        cout << x << " ";
    }
}