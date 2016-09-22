#include <stdio.h>
#include <stdlib.h>

void scan(char *toScan, char *scanInto);
int getLength(char *scanInto);
void resize(int newSize, char *array);

int main(){
    char *name = malloc(200*sizeof(char));
    printf("Enter your name: ");
    scan("%s", name);
    printf("You entered %s\n", name);
    return 0;
}

void scan(char *toScan, char *scanInto){
    int size;
    scanf(toScan, scanInto);
    size = getLength(scanInto);
    resize(size, scanInto);
}

int getLength(char *scanInto){
    int i;
    for(i = 0; i < 200; i++){
        if (scanInto[i] == '\0')
            break;
    }
    printf("The size of the entry is %d\n", i);
    return i;
}

void resize(int newSize, char *array){
    char *temp = malloc(newSize * sizeof(char));
    int i;
    for (i = 0; i < newSize; i++){
        temp[i] = array[i];
    }
    free(array);
    array = malloc(newSize*sizeof(char));
    for (i = 0; i < newSize; i++){
        array[i] = temp[i];
    }
    free(temp);
}