#include <iostream> //#define NULL    0
#pragma once

//2013��
//��дһ�� C++���� sorted_list_insert 
//�ú����ܹ���һ���Ѱ����ֵ��С���������˫������hΪ��һ������ָ�룩
//�в���һ�����ֵΪ i�Ľ�㣬
//Ҫ����������������Ȼ����С��������ġ�
//�������ز����������ĵ�һ��Ԫ�ص�ָ�롣

//������� Node 
struct Node { 
    int value;  //����ֵ 
    Node *prev; //������ǰһ������ָ�룻�Ե�һ����㣬  ��Ϊ 0 
    Node *next; //��������һ������ָ�룻�����һ����㣬��Ϊ 0 
};

Node *sorted_list_insert(Node *h, int i){
    if (NULL==h) return NULL;

    Node *n=h;
    Node *temp=new Node;
    temp->value=i;    temp->prev=0;    temp->next=0;

    if (i<=n->value){//i���׽���ֵ��С,�轫��嵽������
        temp->next=n;    n->prev=temp;
        h=temp;
        return h;
    }
    //else i>n->value; ��ʣ��Ľ�㣬ȷ������λ�ã�Ӧ����n�ĺ���
    //��ʱ�����㲻��Ӱ��h
    while (NULL!=n->next&&i>n->next->value){
        n=n->next;
    }

    temp->prev=n;    temp->next=n->next;
    n->next=temp;
    if (NULL!=temp->next){ //����������β
        temp->next->prev=temp;
    } 

    return h;
}

//test
/*
using namespace std;

void print(Node *n){
    if(NULL==n) {
        cout<<endl;
        return;
    }

    for (; n->next!=NULL; n=n->next)    {
        cout<<n->value<<", ";
    }
    cout<<n->value<<endl;
}

Node* initList(int a[],int len){
    Node *h=new Node;
    h->value=a[0];
    h->prev=NULL;
    h->next=NULL;//��ʼ��ָ���Ǳ�Ҫ�ģ�����������ʱ�����

    for (int i = 1; i < len; i++)    {
        h=sorted_list_insert(h,a[i]);//����Ҳ�������
    }
    return h;
}

void sorted_list_insert_test(){
    int a[]={-1, 0,2};

    Node* h=initList(a,3);
    cout<<"��ʼ����\t";
    print(h);

    h=sorted_list_insert(h,-1);//�ײ�
    cout<<"����-1\t\t";
    print(h);

    h=sorted_list_insert(h,1);//�в�
    cout<<"����1\t\t";
    print(h);

    h=sorted_list_insert(h,2);//β��
    cout<<"����2\t\t";
    print(h);
}

int main(){
    sorted_list_insert_test();
    return 0;
}
/**/