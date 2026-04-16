#include "Colis.h"
#include <iostream>
using namespace std;

Colis::Colis()
    : Objet_postal(), declaration_contenu(""), valeur_declaree(0)
{}

Colis::Colis(string orig, string dest, int code_p, float p, float v,
             int t_rec, string declaration, float valeur)
    : Objet_postal(orig, dest, code_p, p, v, t_rec),
      declaration_contenu(declaration), valeur_declaree(valeur)
{}

Colis::~Colis() {}

float Colis::tarif_affranchissement()
{
    float tarif = 2.0f;

    int taux = getTauxRecommandation();
    if (taux == 1)      tarif += 0.5f;
    else if (taux == 2) tarif += 1.5f;

    if (getVolume() > 1.0f / 8.0f) tarif += 3.0f;

    return tarif;
}

float Colis::tarif_remboursement()
{
    int taux = getTauxRecommandation();
    if (taux == 1) return 0.10f * valeur_declaree;
    if (taux == 2) return 0.50f * valeur_declaree;
    return 0.0f;
}

void Colis::afficher()
{
    cout << "Colis ";
    Objet_postal::afficher();
    cout << "/" << getVolume() << "/" << valeur_declaree << endl;
}
