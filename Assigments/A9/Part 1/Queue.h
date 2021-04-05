#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Node {
public:
    Node() : element(), next(nullptr) {}
    Node(const T & e, Node * next0, Node * previous0): element(e), next(next0) {}
    ~Node() { next = nullptr; }

    T element;
    Node<T> * next;
};


template <class T>
class Queue {
public:
    Queue();
    Queue(const Queue<T> & q);
    ~Queue();

    void push(const T & new_element);
    void pop();
    T front() {return head_node_->next->element;}
    int size() {return size_;}
    void clear();
    Queue<T> * operator=(const Queue & other);
private:
    Node<T> * head_node_;
    Node<T> * last_node_;
    int size_;
};

template <class T>
inline Queue<T>::Queue() : size_(0) {
    head_node_ = new Node<T>;
    head_node_->next = head_node_;
    last_node_ =  head_node_;
}
template  <class T>
Queue<T>::Queue(const Queue<T> &q) {
    head_node_ = new Node<T>;
    head_node_->next = head_node_;
    last_node_ =  head_node_;
    auto tmp = q.head_node_;
    for(int x = 0; x < q.size_; x++) {
        tmp = tmp->next;
        push(tmp->element);
    }
    last_node_ = tmp;
    size_ = q.size_;

}
template <class T>
inline Queue<T>::~Queue() {
    while(size_ !=0)
        pop();
    delete head_node_;
}

template <class T>
void Queue<T>::push(const T & new_element) {
    auto new_node = new Node<T>(new_element, head_node_, last_node_);
    last_node_->next = new_node;
    last_node_ =  new_node;
    ++size_;
}

template <class T>
void Queue<T>::pop() {
    auto first_node = head_node_->next;
    auto new_first_node = first_node->next;
    head_node_->next = new_first_node;
    delete first_node;
    --size_;
}

template <class T>
inline void Queue<T>::clear() {
    while(size_ !=0)
        pop();
}

template <class T>
Queue<T> * Queue<T>::operator=(const Queue & other) {
    clear();
    last_node_ =  head_node_;
    auto tmp = other.head_node_;
    for(int x = 0; x < other.size_; x++) {
        tmp = tmp->next;
        push(tmp->element);
    }
    last_node_ = tmp;
    size_ = other.size_;
    return this;
}
#endif
