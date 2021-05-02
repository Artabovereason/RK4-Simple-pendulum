#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include "Header.h" // élements de class

using namespace std ;

//angle entre -pi et pi
void angle(double & theta)
{
    while (theta <-M_PI|| theta>M_PI){
        if(theta<-M_PI){theta=2*M_PI+theta;} // Si theta est au dela de -pi (exemple : -3pi alors, on actualise sa valeur par 2pi+théta, donc ça ferais 2pi-3pi => -pi  -pi est bien dans l'intervalle que l'ont veux
        if(theta> M_PI){theta=theta-2*M_PI;} // idem que la ligne au dessus mais ici c'est pour l'autre sens, exemple : 3pi
                                     }
}


//domega1 qui est équivalent à théta1pointpoint
double F(double omega, double theta, double l, double m)
{
    double g=-9.81;
    double domega=(-g*sin(theta)/l);
    return domega;
}

//theta1
double G(double omega)
{
    return omega;
}


//mettre a jour les Èlements de la classe
void coordon(pendule & pend_1) // classe & "sous-classe"
{
    //mis à jour des coordonnées
    pend_1.coordonnee();
}

//deplacer
void deplacement(pendule & pend_1, double h)
{
    double t = pend_1.GetT();
    double const omega=pend_1.GetOmega();
    double const theta=pend_1.GetTheta();
    double const longueur =pend_1.GetLongueur();
    double const masse=pend_1.GetMasse();

    //1er coefficient
    double k1=F(omega,theta,longueur,masse);
    double b1=G(omega);

    //2eme coefficient
    double k2=F(omega+h/2.*k1,theta+h/2*b1,longueur,masse);
    double b2=G(omega+h/2.*b1);

    //3eme coefficient
    double k3=F(omega+h/2.*k2,theta+h/2.*b2,longueur,masse);
    double b3=G(omega+h/2.*b2);

    //4eme coefficient
    double k4=F(omega+h*k3,theta+h*b3,longueur,masse);
    double b4=G(omega+h*b3);

    //valeur
    double Omega=omega+h/6.*(k1+2*k2+2*k3+k4);
    double Theta= theta+h/6.*(b1+2*b2+2*b3+b4);

    double Domega=F(Omega,Theta,masse,longueur);
    angle(Theta);

    pend_1.SetTheta(Theta);
    pend_1.SetOmega(Omega);
    pend_1.SetDomega(Domega);
    pend_1.SetT(t+h);
    coordon(pend_1);
}

int main()
{
    pendule pend_1;
    ifstream initialcondition("initialisation.txt");
    ofstream coordonnee("coordonnee"); // en blocs
    int num;
    double longueur, masse , theta, omega, domega;
    double tmin , tmax , h;

    initialcondition>>num>>longueur>>masse>>theta>>omega>>domega;
    initialcondition>>tmin>>tmax>>h;

    pend_1.init(num,tmin,theta,omega,domega,longueur,masse);
    coordon(pend_1);

    int i=0;
    double t=tmin;
    while(t<tmax)
    {
        if (i%100==0)   // le pas doit être petit donc pour éviter d'avoir trop de valeur on prend tous les 100 x
        {

            // coordoonnées en bloc pour un tracé simplifié lors de l'animation
            coordonnee<<pend_1.GetT()<<" "<<"0"<<" "<<"0"<<endl; //point d'origine du pendule
            coordonnee<<pend_1.GetT()<<" "<<pend_1.GetX()<<" "<<pend_1.GetY()<<endl;
            coordonnee<<" "<<endl;
            coordonnee<<" "<<endl;
        }
        deplacement(pend_1, h);
        t+=h;
        i+=1;
    }

    ofstream animation("animationpendule.gnu"); // création du fichier qui permet d'animé le pendule
    animation<<"set key font \"Verdana,12\""<<endl;
    animation<<"set title \"Animation du pendule au cours du temps\""<<endl;
    animation<<"set terminal gif animate delay "<<h*10000<<endl;
    animation<<"set xrange ["<<-(longueur)<<":"<<(longueur)<<"]"<<endl;
    animation<<"set yrange ["<<-(longueur)<<":"<<(longueur)<<"]"<<endl;
    animation<<"set output \"penduleanime.gif\"" <<endl;
    animation<<"set xtics font \"Verdana,15\""<<endl;
    animation<<"set ytics font \"Verdana,15\""<<endl;
    animation<<"set style line 11 lc rgb '#808080' lt 1"<<endl;
    animation<<"set border 3 back ls 11"<<endl;
    animation<<"set tics nomirror"<<endl;
    animation<<"set pointintervalbox 3"<<endl;
    animation<<"do for [i=1:999] {plot \"coordonnee\" index i using 2:3 title 'pendule' w linespoints ls 1}"<<endl;
    system("gnuplot animationpendule.gnu"); // representation du pendule
    return 0;
}
