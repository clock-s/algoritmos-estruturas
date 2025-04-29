#include <stdio.h>
#include <stdlib.h>









int main(int argc, char const *argv[]){

    if(argc < 2){
        printf("Need a number of people!\n");
        return -1;
    }

    int max = atoi(argv[1]);
    int count = 1;
    int people = max;
    int first_death = 0;
    int last = 1;

    while(people != 1){


        if(people & 1 == 1){

            if(!first_death){
                first_death = 1;
                if(max & 1 == 1){
                    last = max;
                }else{
                    last = max - 1;
                }
            }else{
                last = last - count;
            }

        }

        people = people/2 + people%2;

        count *= 2;
        
    }


    printf("%d \n", last);


    
    return 0;
}
