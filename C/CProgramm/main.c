#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "message.h"

#define NAMELEN 20 /* highest car name length */
#define NUMBER 10 /* Number of car im car*/
#define FILENAME "test.txt"
#define BUFLEN 80

/************************************************************
 Function prototypes
*************************************************************/
short input(struct car *item, short len);

void printCar(struct car *item);

/************************************************************
 Struct definition
 ************************************************************/
struct car {
    char name[NAMELEN]; /* car name */
    float speed;        /* car speed */
    short power;        /* car power in ps */
    short cylender;     /* car cylender */
    char fuel;          /* car fuel ( 'D' , 'N' or 'S')*/
};

/**********************************************************
 * main programm
 **********************************************************/
int main() {

 struct car car_arr[NUMBER + 1]; /* array from car */
 struct car *pt;                 /* pointer to a car struct */
 short numOfCar;                       /* number of car*/
/* Data injection */
numOfCar = input(car_arr,NUMBER);
 car_arr[numOfCar].cylender = -1;
  /* Data output */
//  printCar(&car_arr[numOfCar],numOfCar);
 for(pt = car_arr; pt->cylender != -1; pt++ ) {
     printCar(pt);
  }
 /*   message m;
    m.printMessage();
    FILE *file;
    char buf[BUFLEN];
    file = fopen(FILENAME, "w");
    if (!file) {
        printf("file opening doesn't work !!!");
        return 0;
    }
    fprintf(file, "first line");
    fprintf(file, "second line");
    fprintf(file, "third line");
    fclose(file);

    file = fopen(FILENAME, "r");
    if (!file) {
        printf("file opening doesn't work !!!");
        return 0;
    }
    for(;;){
//        int ret = ;
        if(fscanf(file ,"%s",buf) == EOF) break;
        printf(buf);
    }
//    fscanf (file,"%s",buf);
//    printf(buf);
    fclose(file);*/
    return 0;
}

/* input of Data in car struct array with the number of item
 * added as return value*/
short input(struct car *item, short len) {
    short index;
    for (index = 0; index < len; index++) {
        printf("Car-Name : \n");
        scanf("%s", item[index].name);
        if (item[index].name[0] == '*') {
            break;
        }
        printf("speed power cylender fuel : \n");
        scanf("%g %d %d %c", &item[index].speed, &item[index].power,
              &item[index].cylender, &item[index].fuel);
    }
    return index;
}

/* print the data in the car struct */
void printCar(struct car *item) {
//    printf("Number of car : %d\n",num);
    printf("%g %d %d %c\n", item->name,
           item->speed, item->power, item->cylender,
           item->fuel);
};

