#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {

    int key;    //对应的值;
    int value;  //出现的次数;
    struct node* next;  //链接节点

} Node;

typedef struct hash_table {

    Node* data[MAX_SIZE];   //创立一个100大小的数组，每个单元包含上面的node；

} HashTable;

int hash(int key) {

    return key % MAX_SIZE;  //对size取余保证输入的数据不会超过哈希表的长度
    //不超过还是原值，超过了就从1再开始；
}

HashTable* create_hash_table() {

    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));  //申请对应大小的空间

    memset(hash_table, 0, sizeof(HashTable));   //将组内元素全设置为0，即key，value，next全为0；

    return hash_table;

}

void insert(HashTable* hash_table, int key) {

    int index = hash(key);  //安全处理

    Node* p = hash_table->data[index];  //定义一个指针指向该单元位置
    //这个指针对应的值指向数组里单元的值

    while (p != NULL)   //即如果p指向的这个单元已经有值了，说明它是出现过的
    {

        if (p->key == key)  //看看这个出现过的值是不是我们传进来的值
        {

            p->value++;  //是的话我们让它的出现次数加一
            return;  //然后结束

        }

        p = p->next;    //如果不是说明出现哈希冲突，指向NULL，进行链接。
        //由于是结构体，所以该处理哈希冲突的方式是链地址法
       
    }

    //能到这一步说明我们找到了一个空单元
    Node* new_node = (Node*)malloc(sizeof(Node));   

    new_node->key = key;    //把这个节点的值设置为传入的数
    new_node->value = 1;    //出现次数+1
    new_node->next = hash_table->data[index];   //让该节点指针置为空；

    hash_table->data[index] = new_node; //把该节点替换成原来的单元 ,使其不为NULL。
   
    /*

     链地址法：即数组值是来判断有无数据，数据存放在结构体里

     无冲突时：将数据直接保存到结构体里，然后重复值加1
     new_node->key = key;
     new_node->value = 1;
     new_node->next = hash_table->data[index]; 无冲突时指向NULL，这是为了有冲突时进行插入准备
     hash_table->data[index] = new_node；节点替换，是为了标记有数据

     有冲突时：在该冲突数据后添加节点保存冲突数据
     new_node->key = key;
     new_node->value = 1;
     new_node->next = hash_table->data[index];有冲突说明这个data单元被标记过，所以这里不为NULL
     hash_table->data[index] = new_node;类似于循环链表，将原数组位置改为冲突节点，冲突节点再指向原节点；

     */

}

void print_duplicate_elements(int* arr, int n) {

    HashTable* hash_table = create_hash_table();    //创立表头

    for (int i = 0; i < n; i++)     //对传入的数组a进行插入 
    {   
        insert(hash_table, arr[i]);
    }

    for (int i = 0; i < MAX_SIZE; i++)  //遍历整个哈希表
    {

        Node* p = hash_table->data[i];  //让一个指针从结构体单元0开始遍历

        while (p != NULL)   //如果指向的位置不为0则输出； 
        {

            if (p->value > 1) {
                printf("%d出现了%d次 ", p->key,p->value);
            }

            p = p->next;   //这样会检查该数组位置所有的节点进行输出；
        }
    }
}

int main() {
    int arr[] = { 0,0,0,1,1,2,2,3,3,101,101,5,6,5,5 };

    int n = sizeof(arr) / sizeof(int);

    print_duplicate_elements(arr, n);

    return 0;
}