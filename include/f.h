/*
* ENSICAEN
* 6 boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproducedcd ..
, copied or revised without written
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
* @file f.h
*/

#ifndef _F
#define _F

#include <stdio.h>
#include <math.h>

typedef struct{
  int sed_hn; /* number of sedentary hours of the person  */
  int light_hn; /* number of light exercice hours of the person  */
  int sport_hn; /* number of sport hours of the person  */
} Activity;

typedef struct{
  char sex; /* "m" = male , "f"=femelle */
  int age; /* age of the person  */
  int coeff_age; /* coefficient age of the person  */
  float weight; /* weight of the person */
  float height; /* height of the person */
  int pregnant; /* 0=false 1=true */
  Activity a; /* structural variable regrouping the activity value of the person  */
  float metabolism; /* metabolism index of the person */
} Person;

/**
* Function returning the coefficient corresponding to the age of the person
* @param age age of the person
* @return coefficient corresponding to the right age
*/
int find_age_coefficient(int age);

/**
* Function returning the body surface of a person using weight and height
* @param weight of the person
* @param height of the person
* @return body surface of the person 
*/
float find_body_surface(float weight, float height);

/**
* Function returning the body surface of a person using weight and height
* @param age_coeff of the person
* @param body_surface of the person
* @return metabolism index of the person 
*/
float find_metabolism_index(int age_coeff, int body_surface);

/**
* Correct the metabolism index of the person if it's a woman and if she's pregnant
* @param metabolism index of the person
* @param sex char corresponding of the sex of the person
* @param pregnant boolean : true if pregnant and false if not
* @return the right metabolism index of the person whatever her sex neither her possible pregnancy
*/
float correct_metabolism(float metabolism, char sex, int pregnant);

/**
* Correct the metabolism index of the person if she's pregnant
* @param metabolism index of the person
* @param pregnant boolean : true if pregnant and false if not
* @return the metabolism index of the person whatever if she pregnant or not pregnancy
*/
float correct_metabolism_for_pregancy(float metabolism, int pregnant);

/**
* Find the activity metabolism using the activity datas of the person in a day
* @param metabolism index of the person
* @param number of sedentary hours of the person
* @param number of light exercice hours of the person
* @param number of sport hours of the person
* @return the activity metabolism index of the person 
*/
float find_activity_metabolism_index(int metabolism, int sed_hn, int light_hn, int sport_hn);

#endif