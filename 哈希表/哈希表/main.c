#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {

    int key;    //��Ӧ��ֵ;
    int value;  //���ֵĴ���;
    struct node* next;  //���ӽڵ�

} Node;

typedef struct hash_table {

    Node* data[MAX_SIZE];   //����һ��100��С�����飬ÿ����Ԫ���������node��

} HashTable;

int hash(int key) {

    return key % MAX_SIZE;  //��sizeȡ�ౣ֤��������ݲ��ᳬ����ϣ��ĳ���
    //����������ԭֵ�������˾ʹ�1�ٿ�ʼ��
}

HashTable* create_hash_table() {

    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));  //�����Ӧ��С�Ŀռ�

    memset(hash_table, 0, sizeof(HashTable));   //������Ԫ��ȫ����Ϊ0����key��value��nextȫΪ0��

    return hash_table;

}

void insert(HashTable* hash_table, int key) {

    int index = hash(key);  //��ȫ����

    Node* p = hash_table->data[index];  //����һ��ָ��ָ��õ�Ԫλ��
    //���ָ���Ӧ��ֵָ�������ﵥԪ��ֵ

    while (p != NULL)   //�����pָ��������Ԫ�Ѿ���ֵ�ˣ�˵�����ǳ��ֹ���
    {

        if (p->key == key)  //����������ֹ���ֵ�ǲ������Ǵ�������ֵ
        {

            p->value++;  //�ǵĻ����������ĳ��ִ�����һ
            return;  //Ȼ�����

        }

        p = p->next;    //�������˵�����ֹ�ϣ��ͻ��ָ��NULL���������ӡ�
        //�����ǽṹ�壬���Ըô����ϣ��ͻ�ķ�ʽ������ַ��
       
    }

    //�ܵ���һ��˵�������ҵ���һ���յ�Ԫ
    Node* new_node = (Node*)malloc(sizeof(Node));   

    new_node->key = key;    //������ڵ��ֵ����Ϊ�������
    new_node->value = 1;    //���ִ���+1
    new_node->next = hash_table->data[index];   //�øýڵ�ָ����Ϊ�գ�

    hash_table->data[index] = new_node; //�Ѹýڵ��滻��ԭ���ĵ�Ԫ ,ʹ�䲻ΪNULL��
   
    /*

     ����ַ����������ֵ�����ж��������ݣ����ݴ���ڽṹ����

     �޳�ͻʱ��������ֱ�ӱ��浽�ṹ���Ȼ���ظ�ֵ��1
     new_node->key = key;
     new_node->value = 1;
     new_node->next = hash_table->data[index]; �޳�ͻʱָ��NULL������Ϊ���г�ͻʱ���в���׼��
     hash_table->data[index] = new_node���ڵ��滻����Ϊ�˱��������

     �г�ͻʱ���ڸó�ͻ���ݺ���ӽڵ㱣���ͻ����
     new_node->key = key;
     new_node->value = 1;
     new_node->next = hash_table->data[index];�г�ͻ˵�����data��Ԫ����ǹ����������ﲻΪNULL
     hash_table->data[index] = new_node;������ѭ��������ԭ����λ�ø�Ϊ��ͻ�ڵ㣬��ͻ�ڵ���ָ��ԭ�ڵ㣻

     */

}

void print_duplicate_elements(int* arr, int n) {

    HashTable* hash_table = create_hash_table();    //������ͷ

    for (int i = 0; i < n; i++)     //�Դ��������a���в��� 
    {   
        insert(hash_table, arr[i]);
    }

    for (int i = 0; i < MAX_SIZE; i++)  //����������ϣ��
    {

        Node* p = hash_table->data[i];  //��һ��ָ��ӽṹ�嵥Ԫ0��ʼ����

        while (p != NULL)   //���ָ���λ�ò�Ϊ0������� 
        {

            if (p->value > 1) {
                printf("%d������%d�� ", p->key,p->value);
            }

            p = p->next;   //�������������λ�����еĽڵ���������
        }
    }
}

int main() {
    int arr[] = { 0,0,0,1,1,2,2,3,3,101,101,5,6,5,5 };

    int n = sizeof(arr) / sizeof(int);

    print_duplicate_elements(arr, n);

    return 0;
}