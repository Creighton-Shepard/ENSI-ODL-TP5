/*
* ENSICAEN
* 6 boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproduced, copied or revised without written
* permission of the authors
*/

/**
* @author Christophe Génard <christophe.genard@ecole.ensicaen.fr>
* @version 1.0.0 - 2018-10-17
*
* @todo Nothing Known
* @bug Nothing Known
*/

/**
* @file main.c
*/

#include "../include/f.h"

/**
* Main functon used to run the calorical ratio program
* @param argc integer number of char argument put in the call of this function
* @param argv char_list regrouping the char argument put in the call of this function  
* @return integer indicating if the program raise an error or not
*/
int main(){
    Person i; /* regroups person datas  */
    
    printf("What's your gender ?(male=m // female=f)\n");
    scanf("%c", &(i.sex));
    if (i.sex == 'f'){
        printf("Are you pregnant / (0=no, 1=yes)\n");
        scanf("%d",&(i.pregnant));
    } else {
        i.pregnant=0;
    }
    printf("How old are you ?\n");
    scanf("%d", &(i.age));
    printf("What's your weight ?(in kilograms)\n");
    scanf("%f", &(i.weight));
    printf("What's your height ?(in meters)\n");
    scanf("%f", &(i.height));

    i.coeff_age = find_age_coefficient(i.age);
    if (i.coeff_age == -1 || i.coeff_age == -2){
        perror("Error when finding the age coefficient\n");
        return 1;
    }
    i.metabolism = find_metabolism_index(i.coeff_age, find_body_surface(i.weight, i.height));
    /* inferior to 0 because if it's find_body_surface who has the problem i.metabolism will be negaative but not equal to -1*/
    if (i.metabolism <= 0){
        perror("Error when finding the metabolism index\n");
        return 1;
    }
    i.metabolism = correct_metabolism(i.metabolism, i.sex, i.pregnant);
    if (i.metabolism == -1 || i.metabolism == -2 || i.metabolism == -3 || i.metabolism == -4){
        perror("Error when correcting the metabolism index\n");
        return 1;
    }

    printf("Standard  Metabolism : %f\n", i.metabolism);

    printf("How many hour of sedentary activity ?\n");
    scanf("%d", &(i.a.sed_hn));
    printf("How many hour of light exercise ?\n");
    scanf("%d", &(i.a.light_hn));
    printf("How many hour of intense sport ?\n");
    scanf("%d", &(i.a.sport_hn));

    i.metabolism=find_activity_metabolism_index(i.metabolism, i.a.sed_hn, i.a.light_hn, i.a.sport_hn);
    if (i.metabolism == -1 || i.metabolism == -2 || i.metabolism == -3 || i.metabolism == -4){
        perror("Error when finding the activity metabolism index\n");
        return 1;
    }

    printf("Metabolism of activity : %f\n", i.metabolism);
    
    return 0;
}
