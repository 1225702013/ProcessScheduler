#pragma once
#include <iostream>
template <typename T>
struct Node {
    T data;
    Node *pNext;
};
template <typename T>
class NodeList {
private:
    //ͷ�ڵ�
    Node<T> *first;
    //��ǰ���ݳ���
    int length;
    //�ȽϺ���
    int(*compare)(T& left, T& right);
public:
    //��ʼ��
    NodeList();
    //�������캯��
    NodeList(const NodeList<T>&);
    //����
    ~NodeList();
    //���룬����ʱ�Ƿ�����
    NodeList& Insert(int x, const T &value, const bool sort = false);
    //�Ƿ�Ϊ��
    bool IsEmpty() const;
    //��ȡ����
    int GetLength() const;
    //���ص�x��Ԫ��
    bool Find(int x, T &ret) const;
    //����������������
    int Search(const T& value) const;
    //ɾ����x������
    NodeList& Delete(const int x);
    //��ӡ��
    std::ostream& Print(std::ostream& out) const;
    //����
    NodeList& Sort();
    //����ϲ�
    NodeList& AddNodeList(const NodeList& Source, const bool sort = false);
    //���ñȽϺ���
    void SetCompareFunction(int(*function)(T& left, T&right));
};
