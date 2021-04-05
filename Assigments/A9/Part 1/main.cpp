#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> q;
    cout<< q.size() << endl << q.front() <<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "------------" << endl;
    cout << q.size() << endl << q.front() << endl;
    q.pop();
    cout << "------------" << endl;
    cout << q.size() << endl << q.front() << endl;
    Queue<int> q2(q);
    q.clear();
    cout << "------------" << endl;
    cout << q2.size() << endl << q2.front() << endl;
    cout << "------------" << endl;
    cout<< q.size() << endl << q.front() <<endl;
    Queue<int> q3;
    q3.push(100);
    q3.push(200);
    q3.push(300);
    q3.push(400);
    cout << "------------" << endl;
    cout << q3.size() << endl << q3.front() << endl;
    q3 = q2;
    q2.clear();
    cout << "------------" << endl;
    cout << q3.size() << endl << q3.front() << endl;

}