//2012��
//��������Ϊ Node *list_sort(Node *h); hָ�������ͷ��㣬
//Ҫ��� hָ��ĵ������ڽ��ֵ����������Ȼ�󷵻������ĵ�����ͷ���ָ�롣
//���������list_sort.cpp����Դ��벻���ύ��
#include <iostream>

struct Node{
    int value;
    Node *next;
};

Node *list_sort(Node *h){
    //ʹ�ò�������:������h���׽������ժ��,���������������s��;
    if(NULL==h) return NULL;

    Node *s=h,                   //sΪ�����������,��ʼ��h���׽��
        *hp=NULL, *sp=NULL;      //������ʱ������ 
    h=h->next;                   //��hΪʣ����
    s->next=NULL;                //!
    while(NULL!=h){
        if(h->value <= s->value){//hӦ����sǰ��
            hp=h;    h=h->next;  //ժ��h          
            hp->next=s;    s=hp; //�嵽s֮ǰ,������s
        } else {
            sp=s;
            while(NULL!=sp->next && 
                h->value > sp->next->value){//Ѱ�Ҳ���λ��
                    sp=sp->next;
            }
            hp=h;    h=h->next;  //ժ��h
            hp->next=sp->next;   //�˴�����sp->next==NULLҲ����
            sp->next=hp;         //������
        }
    }
    return s;
}


//test
/*
using namespace std;

void print(Node *h){
    if (h==NULL) {
        cout<<endl;
        return;
    }
    for (; h->next!=0; h=h->next)    {
        cout<<h->value<<", ";
    }
    cout<<h->value<<endl;
}

Node* initList(int a[], int len){
    Node *h=new Node, *p=h;
    h->value=a[0];    h->next=NULL;
    for(int i=1;i<len;i++){
        Node *t=new Node;
        t->value=a[i];    t->next=NULL;
        p->next=t;        p=p->next;
    }
    return h;
}

void list_sort_test(){
    int a[]={1,0,1,2,3,2,1};
    Node *h=initList(a, 7 );
    cout<<"h \t:";
    print(h);
    cout<<"�����\t:";
    print(list_sort(h));
}

int main() {
    list_sort_test();
    return 0;
}
/**/