#pragma once

class IntSet {
//����Ԫ��������,��ʹ�ô�ͷ���ĵ�����ʵ��. ʵ��ʱû�е���������ṹ.
//��Ϊֻ���ṩ����Ԫ�صĲ���,�����б����������򣨴�С����,���Լ���;
//ע�⣺�����в������ظ���Ԫ�أ�
//����,����û�е���������ṹ(struct Node), IntSet������ǽ��
public:
    IntSet();
    IntSet(const IntSet& s);
    virtual ~IntSet();
    
    //����Ԫ��
    void insert(const int value);

    //�Ƚ��� s�Ƿ����
    bool IsEqual(IntSet& s);

    //�� s1�� s2�Ĳ�
    IntSet union2(IntSet& s1, IntSet& s2);

    //�� s1�� s2�Ľ�
    IntSet incorporate2(IntSet& s1,IntSet& s2);

    //����=,ʵ�����
    IntSet& operator=(const IntSet& s);

    //���Ԫ��
    void print();

private:
    int value;//ע��ͷ����value��ʾԪ�ظ�����
    void clone(const IntSet& s);
    IntSet* next;
};