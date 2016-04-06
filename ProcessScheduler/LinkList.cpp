#include "LinkList.h"
//��ʼ��
template<typename T>
inline NodeList<T>::NodeList() {
    first = NULL;
    length = 0;
}

//����
template<typename T>
NodeList<T>::~NodeList() {
    while(first != NULL) {
        Node<T> *p = first;
        first = first->pNext;
        //cout<<p<<endl;
        delete p;
        length--;
    }
}

//���룬����ʱ�Ƿ�����
template<typename T>
NodeList<T>& NodeList<T>::Insert(const int x, const T& value, const bool sort) {
    if(x < 1 || x > length + 1)
        return *this;
    Node<T> *p = first;
    for(int i = 2; i < x; i++)
        p = p->pNext;
    Node<T> *newp = new Node<T>;
    newp->data = value;
    newp->pNext = NULL;
    if(first == NULL || length == 0) {
        newp->pNext = NULL;
        first = newp;
    } else if(x == 1) {
        newp->pNext = first;
        first = newp;
    } else if(p != NULL) {
        newp->pNext = p->pNext;
        p->pNext = newp;
    }
    length++;
    if(sort)
        Sort();
    return *this;
}

//�Ƿ�Ϊ��
template<typename T>
bool NodeList<T>::IsEmpty() const {
    return length == 0 || first == NULL;;
}

//��ȡ����
template<typename T>
int NodeList<T>::GetLength() const {
    return length;
}

//���ص�x��Ԫ��
template<typename T>
bool NodeList<T>::Find(int x, T& ret) const {
    if(x < 1 || x > length + 1)
        return false;
    Node<T> *p = first;
    for(int i = 1; i < x; i++)
        p = p->pNext;
    ret = p->data;
    return true;
}

//����������������
template<typename T>
int NodeList<T>::Search(const T& value) const {
    Node<T> *p = first;
    for(int i = 0; i < length && p != NULL; i++)
        if(p->data - value == 0)
            return i + 1;
        else
            p = p->pNext;
    return -1;
}

//ɾ����x������
template<typename T>
NodeList<T>& NodeList<T>::Delete(const int x) {
    if(x < 1 || x > length)
        return *this;
    Node<T> *p = first;
    for(int i = 2; i < x; i++)
        p = p->pNext;
    Node<T> *temp;
    if(x == 1) {
        temp = first;
        first = first->pNext;
        delete temp;
    } else {
        temp = p->pNext;
        p->pNext = temp == NULL ? NULL : temp->pNext;
        delete temp;
    }
    length--;
    return *this;
}

//��ӡ��
template<typename T>
std::ostream& NodeList<T>::Print(std::ostream& out) const {
    Node<T> *p = first;
    for(int i = 0; i < length && p != NULL; i++) {
        out << p->data << ' ';
        p = p->pNext;
    }
    return out;
}

//����
template<typename T>
NodeList<T>& NodeList<T>::Sort(int(*sortFunction)(T&, T&)) {
    Node<T> *p = first;
    bool finish = false;
    for(int i = 0; i < length - 1; i++) {
        finish = true;
        Node<T> *temp = p;
        for(int j = 0; j < length - 1 - i; j++) {
            if((*sortFunction)(temp->data, temp->pNext->data) > 0) {
                T ii;
                ii = temp->data;
                temp->data = temp->pNext->data;
                temp->pNext->data = ii;
                finish = false;
            }
            temp = temp->pNext;
        }
        if(finish)
            break;
    }
    return *this;
}

//����ϲ�
template<typename T>
NodeList<T>& NodeList<T>::AddNodeList(const NodeList& Source, const bool sort) {
    T value;
    for(int i = 1; i <= Source.length; i++) {
        Source.Find(i, value);
        this->Insert(this->length + 1, value, false);
    }
    if(sort)
        this->Sort();
    return *this;
}
