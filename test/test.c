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
* @file testf.c
*/

#include "../include/f.h"
#include <assert.h>

/* Prototype of next function */
void test_f_a_c();
void test_f_b_s();
void test_f_m_i();
void test_c_m_f_p();
void test_c_m();
void test_f_a_m_i();

/**
* Main functon used to run all the tests at once
* @param argc integer number of char argument put in the call of this function
* @param argv char_list regrouping the char argument put in the call of this function  
* @return
*/
void main(int argc, char * argv[]){
    if (argc>1){
        printf("WARNING ! Ce programme n'a pas besoin d'argument au lancement : %d arguments trouvé(s). \nCeci resteront inutilisés !\n",argc);
    }

    /* Appel de tous les tests */
    test_f_a_c();
    test_f_b_s();
    test_f_m_i();
    test_c_m_f_p();
    test_c_m();
    test_f_a_m_i();
}

/*
* Function testing the function : find_age_coefficient
*/
void test_f_a_c(){
    int age=0;
    
    /* ERROR : wrong age value */
    age=-4;
    assert(find_age_coefficient(age)==-1);
    age=0;
    assert(find_age_coefficient(age)==-1);
    age=9;
    assert(find_age_coefficient(age)==-1);

    /* FINE : age between 10 and 14 */
    age=10;
    assert(find_age_coefficient(age)==45);
    age=12;
    assert(find_age_coefficient(age)==45);
    age=14;
    assert(find_age_coefficient(age)==45);

    /* FINE : age between 15 and 19 */
    age=15;
    assert(find_age_coefficient(age)==40);
    age=17;
    assert(find_age_coefficient(age)==40);
    age=19;
    assert(find_age_coefficient(age)==40);

    /* FINE : age between 20 and 60 */
    age=20;
    assert(find_age_coefficient(age)==45);
    age=40;
    assert(find_age_coefficient(age)==45);
    age=60;
    assert(find_age_coefficient(age)==45);

    /* FINE : age superior to 60 */
    age=60;
    assert(find_age_coefficient(age)==45);
    age=125;
    assert(find_age_coefficient(age)==45);
}

/*
* Function testing the function : find_body_surface
*/
void test_f_b_s(){
    float weight; 
    float height;
    float body_surface;

    /* ERROR : wrong value of weight and height */
    weight=-1.6;
    height=-1.3;
    assert(find_body_surface(weight, height)==-1);

    /* ERROR : wrong value of weight */
    height=1.3;
    assert(find_body_surface(weight, height)==-1);

    /* ERROR : wrong value of height */
    weight=60;
    height=-1.3;
    assert(find_body_surface(weight, height)==-2);

    /* FINE : normal case */
    height=1.3;
    body_surface=0.2*pow(weight,0.4)*pow(height,0.7);
    assert(find_body_surface(weight, height)==body_surface);
  
}

/*
* Function testing the function : find_metabolism_index
*/
void test_f_m_i(){
    float age_coeff;
    float body_surface;
    float metabolism;

    /* ERROR : wrong age value */
    age_coeff=34;
    body_surface=63;
    assert(find_metabolism_index(age_coeff, body_surface)==-1);

    /* ERROR : wrong body surface value */
    age_coeff=35;
    body_surface=-56;
    assert(find_metabolism_index(age_coeff, body_surface)==-2);

    /* FINE : normal case */
    age_coeff=40;
    body_surface=63;
    metabolism=24*age_coeff*body_surface;
    assert(find_metabolism_index(age_coeff, body_surface)==metabolism);
}

/*
* Function testing the function : correct_metabolism_for_pregnancy
*/
void test_c_m_f_p(){
    float metabolism; 
    int pregnant;
    float result;

    /* ERROR : wrong metabolism value */
    metabolism=-500;  
    pregnant=0;
    assert(correct_metabolism_for_pregnancy(metabolism, pregnant)==-1);

    /* ERROR : wrong pregnant value */
    metabolism=500;  
    pregnant=3;
    assert(correct_metabolism_for_pregnancy(metabolism, pregnant)==-2);
  
    /* FINE : no pregnant woman case */
    pregnant=0;
    assert(correct_metabolism_for_pregnancy(metabolism, pregnant)==metabolism);

    /* FINE : pregnant woman case */
    pregnant=1;
    result=metabolism+600;
    assert(correct_metabolism_for_pregnancy(metabolism, pregnant)==result);
}

/*
* Function testing the function : correct_metabolism_for_pregnancy
*/
void test_c_m(){
    float metabolism; 
    char sex; 
    int pregnant;
    float result;

    /* ERROR : wrong metabolism */
    metabolism=-500; 
    sex='m'; 
    pregnant=0;
    assert(correct_metabolism(metabolism, sex, pregnant)==-1);

    /* ERROR : wrong sex char value */
    metabolism=500; 
    sex='s'; 
    assert(correct_metabolism(metabolism, sex, pregnant)==-2);

    /* ERROR : wrong pregnancy value */
    sex='m'; 
    pregnant=3;
    assert(correct_metabolism(metabolism, sex, pregnant)==-3);

    /* ERROR : male pregnant case*/
    metabolism=500; 
    sex='m'; 
    pregnant=1;
    assert(correct_metabolism(metabolism, sex, pregnant)==-4);

    /* FINE : male metabolism */
    metabolism=500; 
    sex='m'; 
    pregnant=0;
    assert(correct_metabolism(metabolism, sex, pregnant)==metabolism);

    /* FINE : woman metabolism */
    metabolism=500; 
    sex='f'; 
    pregnant=0;
    result=metabolism*0.9;
    assert(correct_metabolism(metabolism, sex, pregnant)==result);

    /* FINE : pregnant woman metabolism */
    metabolism=500; 
    sex='f'; 
    pregnant=1;
    result=metabolism*0.9+600;
    assert(correct_metabolism(metabolism, sex, pregnant)==result);

}

/*
* Function testing the function : find_activity_metabolism_index
*/
void test_f_a_m_i(){
    int metabolism;
    int sed_hn; 
    int light_hn;
    int sport_hn;
    float result;

    /* ERROR : wrong metabolism value */
    metabolism=-500;
    sed_hn=-2;
    light_hn=-3;
    sport_hn=-5;
    assert(find_activity_metabolism_index(metabolism, sed_hn, light_hn, sport_hn)==-1);

    /* ERROR : wrong sedentary exercice hour number value */
    metabolism=500;
    assert(find_activity_metabolism_index(metabolism, sed_hn, light_hn, sport_hn)==-2);

    /* ERROR : wrong light exercice hour number value */
    sed_hn=2;
    assert(find_activity_metabolism_index(metabolism, sed_hn, light_hn, sport_hn)==-3);
    
    /* ERROR : wrong sport hour number value */
    light_hn=5;
    assert(find_activity_metabolism_index(metabolism, sed_hn, light_hn, sport_hn)==-4);
    
    /* ERROR : too many activity hours */
    sport_hn=24;
    assert(find_activity_metabolism_index(metabolism, sed_hn, light_hn, sport_hn)==-5);

    /* FINE : normal case */
    sport_hn=5;
    result=metabolism+50*sed_hn+100*light_hn+200*sport_hn;
    assert(find_activity_metabolism_index(metabolism, sed_hn, light_hn, sport_hn)==result);
}