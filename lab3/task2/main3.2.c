/*
#include <stdio.h>
#include <stdarg.h>

#define va_startt(p, c) (p) = (char*)(&c + 1)
#define va_argt(p, type) ((type*)(char*)(p) += sizeof(type))[-1]

int Sum(int c, ...){
    va_list p;
    va_start(p, c);
    int s = 0;
    for(int i = 0; i < c; i++){
        s += va_arg(p, int);
    }
    va_end(p);
    return s;
}

int main(){
    printf("%d\n", Sum(3, 1, 2, 3));
    return 0;
}*/


/* односвязный список
#include <stdio.h>
#include <stdlib.h>

// Структура узла
struct Node {
    int data;
    struct Node* next;
};

// Добавление элемента в начало списка
struct Node* push(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Вставка элемента в середину (по позиции, начиная с 0)
struct Node* insertAt(struct Node* head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // Вставка в начало
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Если позиция выходит за пределы списка
    if (temp == NULL) {
        printf("Позиция вне диапазона!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Удаление элемента по значению
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Если удаляемый элемент — первый
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Поиск элемента
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Если элемент не найден
    if (temp == NULL) return head;

    // Удаление узла
    prev->next = temp->next;
    free(temp);

    return head;
}

// Вывод списка
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Добавляем элементы
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    printList(head); // 1 -> 2 -> 3 -> NULL

    // Вставка в середину (на позицию 1)
    head = insertAt(head, 99, 1);
    printList(head); // 1 -> 99 -> 2 -> 3 -> NULL

    // Удаление элемента (99)
    head = deleteNode(head, 99);
    printList(head); // 1 -> 2 -> 3 -> NULL

    return 0;
} */

/*#include <stdio.h>

#include <stdio.h>

int Pow(int n, int step){
    int res = 1;
    while(step > 0){
        if(step & 1){
            res *= n;
            step -= 1;
        }
        n *= n;
        step /= 2;
    }
    return res;
}


int main(){
    char *n;
    sscanf(n, "%d");
    printf("%d", Pow(2, 5));

    return 0;
}*/

/*
#include <stdio.h>
#include <ctype.h>

int ch_dig(char c){
    if(isdigit(c)){
        return c - '0';
    }
    if(isalpha(c)){
        return toupper(c) - 'A' + 10;
    }
    return -1;
}

int Str_to_dig(char *s, int base){
    int res = 0;
    for(int i = 0; s[i] != '\0'; i++){
        int digit = ch_dig(s[i]);
        if(digit < 0 || digit >= base){
            return -1;
        }
        res = res * base + digit;
    }
    return res;
}


int main(){
    char *s = "1A3F";
    printf("%d\n", Str_to_dig(s, 16));

    return 0;
}*/

/*#include <stdio.h>

int main(int argc, char* argv[]){

    char path1[BUFSIZ];
    char path2[BUFSIZ];
    if(!realpath(argv[1], path1) || !(realpath(argv[2], path2))){
        return 1;
    }
    if(!strcmp(path1, path2)){
        return 1;
    }

    FILE* f1 = fopen(argv[1], "r");
    FILE* f2 = fopen(argv[1], "w");

    if(f1 == NULL || f2 == NULL){
        return 1;
    }
}*/



/*#include <stdio.h>
#include <string.h>

int main(){
    char s[] = "Hello, world! Its C";
    char *token = strtok(s, " !");
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " !");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int Comp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr[] = {1, 6, 8, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), Comp);
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Bin(int arr[], int n, int r){
    int low = 0, hight = n - 1;
    //int mid = (hight - low) / 2;
    while(low <= hight){
        int mid = low + (hight - low) / 2;
        if(arr[mid] == r){
            return mid;
        }
        if(arr[mid] < r){
            low = mid + 1;

        }
        if(arr[mid] > r){
            hight = mid - 1;

        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 4, 5,7, 8};
    int n = 6;
    int r = 5;
    int pos = Bin(arr, n, r);
    printf("%d", pos);
}*/

#include <stdio.h>
#include <string.h>

int h(char *s, int size){
    int t = 0;
    for(int i = 0; s[i] != '\0'; i++){
        t += (int)s[i];
    }
    return t % size;
}

int main(){
    char *s = "example";
    int size = 10;
    int pos = h(s, size);
    printf("%d", pos);
}