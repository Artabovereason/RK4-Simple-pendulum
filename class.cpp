#include <stdio.h>
#include"Header.h"
#include <iostream>
#include <cmath>
using namespace  std ;
double g=-9.81 ;

pendule::pendule(int NUM,double TIME,double THETA,double OMEGA,double DOMEGA,double LONG,double MASSE)
{
    num=NUM;
    t=TIME;
    theta=THETA;
    omega=OMEGA;
    domega=DOMEGA;
    longueur=LONG;
    masse=MASSE;
}

void pendule::init(int NUM,double TIME,double THETA,double OMEGA,double DOMEGA,double LONG,double MASSE)
{
    num=NUM;
    t=TIME;
    theta=THETA;
    omega=OMEGA;
    domega=DOMEGA;
    longueur=LONG;
    masse=MASSE;
}

void pendule::coordonnee()
{
    y=longueur*cos(theta);
    x=longueur*sin(theta);
    dy=-omega*longueur*sin(theta);
    dx=omega*longueur*cos(theta);
    ddy=-longueur*(domega*sin(theta)+pow(omega,2)*cos(theta));
    ddx=longueur*(domega*cos(theta)-pow(omega,2)*sin(theta));
}
