#ifndef Header_h // identifier
#define Header_h

class pendule{
private:
    //définition du temps
    double t;
    //numerotation du pendule
    int num ;
    //définition de la position, vitesse et accélération
    double x,dx,ddx;
    double y,dy,ddy;
    //définition des angles associé (position, vitesse et accélération angulaire)
    double theta,omega,domega;
    //définition des parametres du système (masse et longueur)
    double longueur;
    double masse;

public:
    //Constructeur et Destructeur
    pendule(){};
    pendule(int,double,double,double,double,double,double);
    ~pendule(){};
    //Initialisation
    void init(int,double,double,double,double,double,double);
    //Coordon√©e
    void coordonnee();

    // Accesseur — GET, on met const pour pas avoir de valeur dynamique dans nos élément associé aux GET,
    // Les accesseurs permettent d'obtenir les données de notre classe
    // Déclaration de variable
    int GetNum() const{return num;}
    double GetT() const{return t;}
    double GetX() const{return x;}
    double GetY() const{return y;}
    double GetDx()const{return dx;}
    double GetDdx()const{return ddx;}
    double GetDy()const{return dy;}
    double GetDdy() const{return ddy ;}
    double GetTheta()const{return theta ;}
    double GetOmega()const{return omega ;}
    double GetDomega()const{return domega ;}
    double GetLongueur() const{return longueur;}
    double GetMasse() const{return masse ;}

    //Mutateur — SET,
    //Attribution de valeurs
    void SetNum(int a){num=a;}
    void SetT(double a){t=a;}
    void SetX(double a){x=a;}
    void SetY(double a){y=a;}
    void SetDx(double a){dx=a;}
    void SetDy(double a){dy=a;}
    void SetDdx(double a){ddx=a;}
    void SetDdy(double a){ddy=a;}
    void SetTheta(double a){theta=a;}
    void SetOmega(double a){omega=a;}
    void SetDomega(double a){domega=a;}
    void SetLongueur(double a){longueur=a;}
    void SetMasse(double a){masse=a;}

    //incrément +=
    void AdX(double a){x+=a;}
    void AdY(double a){y+=a;}
    void AdDx(double a){dx+=a;}
    void AdDy(double a){dy+=a;}
    void AdDdx(double a){ddx+=a;}
    void AdDdy(double a){ddy+=a;}
};

#endif
