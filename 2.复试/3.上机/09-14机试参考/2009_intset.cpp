#include "2009_intset.h"
#include <iostream>

IntSet::IntSet(){
    value=0;
    next=NULL;
}

IntSet::~IntSet(){
    delete next; //�ݹ��ͷ�
}

IntSet::IntSet(const IntSet& s){//�������캯��
    clone(s);
}

IntSet& IntSet::operator=(const IntSet& s){
    if(&s==this) return *this;
	
    delete next;
    clone(s); 
    return *this;
}

void IntSet::clone(const IntSet& s){
    this->value=s.value;
    this->next=NULL;//!ע��:���������캯������cloneʱ,this��δ��ʼ��,
    // ���˴�����next��NULL,��this->next����
    // �ɿ������캯�������Ķ�����ʹ��nextʱ���޷��ж�����β,���·ô����
    IntSet *ps=s.next, *p=this;
    while(NULL!=ps){
        IntSet *temp=new IntSet;
        temp->value=ps->value;        temp->next=NULL;
        p->next=temp;                 p=p->next;

        ps=ps->next;
    }
}

//����Ԫ��
void IntSet::insert(const int value)  {
    IntSet *p=this;
    while(NULL!=p->next){
        if (value>p->next->value)     { //�����С��������,���Ҳ���λ��
            p=p->next;
        } else {
            if (value==p->next->value){ //�����в��������ظ���Ԫ��
                return;
            } 
        }
    }
	
    //��p֮�������Ԫ��
    IntSet *temp=new IntSet();
    temp->value=value;  
    temp->next=p->next;
    p->next=temp;
    this->value++;    //ע��ֻά��ͷ����value(��Ԫ�ظ���)��
}

//�Ƚ���s�Ƿ����
bool IntSet::IsEqual(IntSet& s){
    if(s.value!=this->value) return false;

    IntSet *s1=this,*s2=&s;
    while (NULL!=s1->next && 
           s1->next->value==s2->next->value){//ǰ���Ѿ�ȷ��2�����ϵ�Ԫ�ظ�����ͬ
           s1=s1->next;
           s2=s2->next;
    }
    return NULL==s1->next;					 //ѭ�����������һ��Ԫ��,˵�������
}

//�� s1�� s2�Ĳ�
IntSet IntSet::union2(IntSet& s1, IntSet& s2){
    IntSet *ps1=&s1, *ps2=&s2;
    IntSet s;
    for(;NULL!=ps1->next;ps1=ps1->next){
        s.insert(ps1->next->value);
    }
    for(;NULL!=ps2->next;ps2=ps2->next){
        s.insert(ps2->next->value);
    }
    return s;  //�˴����Զ����ÿ������캯��
}

//�� s1�� s2�Ľ�
IntSet IntSet::incorporate2(IntSet& s1,IntSet& s2){
    IntSet *ps1=&s1, *ps2=&s2;
    IntSet s;
    while(NULL!=ps1->next && NULL!=ps2->next){
        if(ps1->next->value == ps2->next->value){    
            s.insert(ps1->next->value);
            ps1=ps1->next;
            ps2=ps2->next;
        } else { //���������������н������,ÿ�ζ����ƶ���С�Ǹ�
            if(ps1->next->value < ps2->next->value){
                ps1=ps1->next;
            } else { // >
                ps2=ps2->next;
            }
        }
    }
    return s;  //ͬ��,�˴�Ҳ���Զ����ÿ������캯��
}

//���Ԫ��
void IntSet::print(){
    IntSet *temp=this;
    while(NULL!=temp->next){
        std::cout<<temp->next->value<<", ";
        temp=temp->next;
    }
    std::cout<<" Ԫ�ظ���:"<<this->value<<std::endl;
}

//2009��
//Ҫ��дһ���������ϵ��࣬�ֱ���� intset.h�� intset.cpp�У�ʵ�����г����ܡ�
//test
//ע:�����s1,s2��Ϊ�ա���1��Ϊ�ա��н������޽�������ȵ����

/*
using namespace std;

int main(){
    IntSet s1, s2, s3, s4;
    int x;

    for(cin >> x; x != 0; cin >> x)    //�� s1�в���Ԫ��
        s1.insert(x); 
    for(cin >> x; x != 0; cin >> x)    //�� s2�в���Ԫ��
        s2.insert(x); 
    if(s1.IsEqual(s2))                 //�Ƚ� s1�� s2�Ƿ����
        cout << "s1 is equal s2 \n";
    s3 = s3.union2(s1, s2);            //�� s1�� s2�Ľ�(ע:��Ӧ�÷���һ������!
                                       //������Ҫ����=,��ʵ�ֿ������캯��,��ͬ)
    s4 = s4.incorporate2(s1, s2);      //�� s1�� s2�Ĳ�(ע:������ӦΪintersection)
    cout << "\ns1:";    s1.print();    //��� s1�е�Ԫ��
    cout << "\ns2:";    s2.print();
    cout << "\ns3:";    s3.print();
    cout << "\ns4:";    s4.print();

    return 0;
}
/**/