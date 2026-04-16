#include "Objet_postal.h"
#include <iostream>
using namespace std;

Objet_postal::Objet_postal()
    : origine(""), destination(""), code_postal(0),
      poids(0), volume(0), taux_recommendation(0)
{}

Objet_postal::Objet_postal(string orig, string dest, int code_p, float p, float v, int t_rec)
    : origine(orig), destination(dest), code_postal(code_p), poids(p), volume(v)
{
    if (t_rec == 0 || t_rec == 1 || t_rec == 2)
        taux_recommendation = t_rec;
    else {
        cout << "Taux de recommandation invalide : mis a 0" << endl;
        taux_recommendation = 0;
    }
}

Objet_postal::~Objet_postal() {}

void Objet_postal::setTauxRecommandation(int t)
{
    if (t == 0 || t == 1 || t == 2)
        taux_recommendation = t;
    else
        cout << "Taux de recommandation invalide : inchange" << endl;
}

void Objet_postal::afficher()
{
    cout << code_postal << "/" << destination << "/" << taux_recommendation<<endl;
}
