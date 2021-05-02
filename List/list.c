#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *array;
    size_t size;
} ;

void Create(struct Array *);
void append(struct Array * ,int);
void Insert(struct Array * ,int, int);
void Remove(struct Array * ,int);
void Traverse(struct Array *);


void Create(struct Array *array) {
    int *int_pointer = (int *)malloc(sizeof(int));
    if (int_pointer == NULL) {       
        printf("Unable to allocate memory, exiting.\n");
        free(int_pointer);
        exit(0);
    }
    else {
        array->array = int_pointer; 
        array->size = 0;
    }
}

void append(struct Array *array, int item) {
    array->size += 1;
    int *int_pointer = (int *)realloc(array->array, array->size * sizeof(int));
    array->array = int_pointer;
    array->array[array->size-1] = item;
}

void Remove(struct Array *array, int index) {
    struct Array temp;
    int *int_pointer;
    Create(&temp);
    for(int ind=index; ind<array->size;ind++) {
        array->array[ind] = array->array[ind + 1];
    }
    array->size -= 1;
    for (int ind=0;ind < array->size;ind++) {
        append(&temp, array->array[ind]);
    }
    int_pointer = (int *)realloc(temp.array, temp.size * sizeof(int));
    array->array = int_pointer; 
}

void printAll(struct Array *array){
    for (int index = 0; index < array->size; index++) 
        printf("%d, ", array->array[index]);
    printf("\n");
}

void insert(struct Array *array, int data, int index) {
    if(index > array->size){
        printf("INDEX OUT OF BOUND\n");
        exit(1);
    }
    array->size += 1;
    int *int_pointer = (int *)realloc(array->array, array->size * sizeof(int));
    array->array = int_pointer;
    for(int ind=array->size; ind>=index; ind--) {
        array->array[ind] = array->array[ind-1];
    }
    array->array[index] = data;
}
int main() {
    struct Array arr ;
    int Choose, data, index;
    Create(&arr);
    printf("Choose ...\n");
    printf("1)Append\n");
    printf("2)Remove\n");    
    printf("3)Traverse\n");
    printf("4)Insert\n");
    printf("5)exit.\n");
    while(1){
        scanf("%d" , &Choose);
        switch(Choose){
            case 1:
                printf("Enter the data to be added\n");
                scanf("%d" , &data);
                append(&arr, data);
                break;
            case 2:
                printf("Enter the position of the data to be deleted\n");
                scanf("%d" , &index);
                Remove(&arr, index);
                break;
            case 3:
                printAll(&arr);
                break;
            case 4:
                printf("Enter the data to be added\n");
                scanf("%d", &data);
                printf("Enter the position to be Inserted\n");
                scanf("%d", &index);
                insert(&arr, data, index);
                break;
            case 5:
                return 0;
                break;
            default :
                printf("Pleace Enter Right choise .\n");
        }
    }

    return 0;
}