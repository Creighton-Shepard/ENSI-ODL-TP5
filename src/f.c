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
* @file f.c
*/

#include "../include/f.h" 

/**
* Function returning the coefficient corresponding to the age of the person
* @param age age of the person
* @return coefficient corresponding to the right age
*/
int find_age_coefficient(int age){
    if (age >= 10 && age < 15){
        return 45;
    } else if (age >= 15 && age < 20){
        return 40;
    } else if(age >= 20 && age < 60){
        return 35;
    } else if(age >= 60){
        return 40;
    } else{
        return -1;
    }
}

/**
* Function returning the body surface of a person using weight and height
* @param weight of the person
* @param height of the person
* @return body surface of the person 
*/
float find_body_surface(float weight, float height){
    if(weight < 10 || weight > 500){
        return -1;
    }
    if(height < 0.5 || height > 3.0){
        return -2;
    }
    return 0.2 * pow(weight, 0.4) * pow(height, 0.7);
}

/**
* Function returning the body surface of a person using weight and height
* @param age_coeff of the person
* @param body_surface of the person
* @return metabolism index of the person 
*/
float find_metabolism_index(int age_coeff, int body_surface){
    if (age_coeff != 45 || age_coeff != 40 || age_coeff != 35){
        return -1;
    }
    if (body_surface <= 0){
        return -2;
    }
    return 24 * age_coeff * body_surface;
}


/**
* Correct the metabolism index of the person if it's a woman and if she's pregnant
* @param metabolism index of the person
* @param sex char corresponding of the sex of the person
* @param pregnant boolean : true if pregnant and false if not
* @return the right metabolism index of the person whatever her sex neither her possible pregnancy
*/
float correct_metabolism(float metabolism, char sex, int pregnant){
    if (metabolism < 0){
        return -1;
    }
    if (sex != 'm' && sex != 'f'){
        return -2;
    }
    if (pregnant !=0 && pregnant != 1){
        return -3;
    }
    if (pregnant == 1 && sex == 'm'){
        return -4;
    }
    if (sex == 'f'){
        metabolism *= 0.9;
        metabolism = correct_metabolism_for_pregancy(metabolism, pregnant);
    }
    return metabolism;
}

/**
* Correct the metabolism index of the person if she's pregnant
* @param metabolism index of the person
* @param pregnant boolean : true if pregnant and false if not
* @return the metabolism index of the person whatever if she pregnant or not pregnancy
*/
float correct_metabolism_for_pregancy(float metabolism, int pregnant){
    if (metabolism < 0){
        return -1;
    }
    if (pregnant != 0 && pregnant != 1){
        return -2;
    }
    if (pregnant == 1){
        metabolism += 600;
    }
    return metabolism;
}

/**
* Find the activity metabolism using the activity datas of the person in a day
* @param metabolism index of the person
* @param number of sedentary hours of the person
* @param number of light exercice hours of the person
* @param number of sport hours of the person
* @return the activity metabolism index of the person 
*/
float find_activity_metabolism_index(int metabolism, int sed_hn, int light_hn, int sport_hn){
    if (metabolism < 0){
        return -1;
    }
    if (sed_hn < 0){
        return -2;
    }
    if (light_hn < 0){
        return -3;
    }
    if (sport_hn < 0){
        return -4;
    }
    if(sed_hn + light_hn + sport_hn > 24){
        return -5;
    }
    return metabolism + 50 * sed_hn + 100 * light_hn + 200 * sport_hn;
}

