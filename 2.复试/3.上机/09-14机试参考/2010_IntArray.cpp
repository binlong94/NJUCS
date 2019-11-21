// IntArray.cpp
#include "2010_IntArray.h"
#include <iostream>

IntArray::IntArray(int size){
    size=size>0? size:0;  //���sizeΪ����,���޷���������,��Ϊ0����
    array = new int[size];
    _size = size;
    for(int i=0; i< size; i++) {
        array[i] = 0;
    }
}

IntArray::~IntArray(){
    delete []array;
}

int IntArray::size() const {
    return _size;
}

int &IntArray::Item(int i){
    return array[i];      //��ϮC++���������Խ��Ĵ�ͳ
}

bool IntArray::equal(IntArray &a) { 
    if(a._size != _size) return false;

    for(int i=0; i<_size; i++) {
        if(a.array[i] != this->array[i]) {
                return false;
        }
    }
    return true;
}

void IntArray::assign(IntArray &a){
    if(a._size > _size) { //��a�Ĵ�С������ǰ��С,ֱ���˳�
        exit(0);        
    }

    int i=0;
    for(; i<a._size; i++){//ע��: a.size <= this->size;
        array[i] = a.array[i];
    }
    //ע:��Ŀ��δ˵��this->size����a�Ĳ���������δ���,һ��Ӧ��0
    for(;i<this->_size;i++){
        array[i]=0;
    }
    //Ҳ�����Ϊ��a._size = this->_size; 
    //����Ҫ deleted[] array; array=new int[a._size];Ȼ���ٿ�������; 
    //����ǿ������캯��,��Ӧ���������;
}

void IntArray::enlarge(int delta){
    if(delta<=0) return;

    int newSize = _size + delta;
    int *newArray = new int[newSize];

    int i=0;
    for(; i<_size; i++){
        newArray[i] = array[i];
    }
    for(; i<newSize; i++){
        newArray[i] = 0;
    }
    _size = newSize; 
    delete []array;    
    array = newArray;
}

void IntArray::sort(){    //������ò�������
    int temp;
    for(int i=1; i<_size; i++) {
        temp=array[i];
        int j=i-1;
        for(; j>=0 && temp<array[j]; j--) {
            array[j+1] = array[j];
        }
        array[j+1] = temp;
    }    
}

void IntArray::display(){
    if(_size>0) {
        int len=_size-1;
        for(int i=0; i<len; i++) {
            std::cout << array[i] << ", ";
        }
        std::cout<<array[len];
    }
    std::cout<<std::endl;
}

//2010��
//Ҫ��ʵ��һ�����������࣬�������IntArray.h�У�ʵ�ַ�intArray.cpp�С�
//ʵ�����г�����
//class IntArray{
//public:
//    IntArray(int size);          //��ʼ�����飬����Ϊ size,�Ҹ���ֵΪ 0 
//    ~IntArray();
//    int size() const;            //�������鳤��
//    int &Item(int i);            //���� i�±������
//    bool equal(IntArray &a);     //���Ⱥ�������ȷ��� True������ False
//    void assign(IntArray &a);    //�� a�е����鸳ֵ�� this�У���a���ȴ���this���ȣ�
//                                 //����ֹ���� 
//    void enlarge(int delta);     //�� this�е������ӳ� Delta����λ��
//                                 //������ Delta����λ�����鸳��ֵΪ 0 
//    void sort();                 //this�е��������򣬴�С���� 
//    void display();              //��ӡ����
//};

//test
/*
using namespace std;

void IntArray_copy(IntArray& array, int a[], int len){
    if(len<=array.size()){
        for(int i=0;i<len;i++){
            array.Item(i)=a[i];
        }
    }
}

void IntArray_test(){
    cout<<"���캯�� & display()\n";
    IntArray a(10), b(-10), aa(10);
    a.display();
    b.display();
    aa.display();

    cout<<"\na Item()\n";
    int t[] = {5, 4, 7, 8, 3, 1, 5};
    IntArray_copy(a,t, 7);
    a.display();

    cout<<"\na size(): "<< a.size()<<endl;

    cout<< "\na sort()\n";
    a.sort();
    a.display();

    cout<< "\na enlarge(-1) & enlarge(5)\n";
    a.enlarge(-1);
    a.display();
    a.enlarge(5);
    a.display();

    cout<< "\nb.equal(a)? " << b.equal(a)<<
           ", aa.equal(a)? "<<aa.equal(a)<<endl;

    cout<< "\nassign()\n";
    IntArray_copy(aa,t,7);
    aa.enlarge(5);
    aa.assign(a);
    aa.display();
    cout<< "\naa.equal(a)?  "<<aa.equal(a)<<endl;
}

int main(){
    IntArray_test();
    return 0;
}
/**/
