#pragma once

// IntArray.h
class IntArray{
public:
    IntArray(int size);          //��ʼ�����飬����Ϊ size,�Ҹ���ֵΪ 0
    ~IntArray();
    int size() const;            //�������鳤��
    int &Item(int i);            //���� i�±������
    bool equal(IntArray &a);     //���Ⱥ�������ȷ��� True������ False
    void assign(IntArray &a);    //�� a�е����鸳ֵ�� this�У���a���ȴ���this���ȣ�
                                 //����ֹ���� 
    void enlarge(int delta);     //�� this�е������ӳ� Delta����λ��
                                 //������ Delta����λ�����鸳��ֵΪ 0 
    void sort();                 //this�е��������򣬴�С���� 
    void display();              //��ӡ����

private:
    int *array;
    int _size;
};
