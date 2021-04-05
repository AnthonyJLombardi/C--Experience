#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
T* subarray(const T* a,int i,int m) {
    T* da = new T[m-i];
    copy(a+i, a+m, da);
    return da;
}

int main() {
    int* a = new int[10]{10,20,30,40,50,60,70,80,90,100};
    int* da = subarray(a, 5, 8);
    for(int x = 0; x < 3; x++)
        cout << da[x] << endl;

}