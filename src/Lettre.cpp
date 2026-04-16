#include "Lettre.h"
#include <iostream>
using namespace std;

Lettre::Lettre()
    : Objet_postal(), urgent(false)
{}

Lettre::Lettre(string orig, string dest, int code_p, float p, float v,
               int t_rec, bool urgent)
    : Objet_postal(orig, dest, code_p, p, v, t_rec), urgent(urgent)
{}

Lettre::~Lettre() {}

float Lettre::tarif_affranchissement()
{
    float tarif = 0.5f; // tarif de base

    int taux = getTauxRecommandation();
    if (taux == 1)      tarif += 0.5f;
    else if (taux == 2) tarif += 1.5f;

    if (urgent) tarif += 0.30f;

    return tarif;
}

float Lettre::tarif_remboursement()
{
    int taux = getTauxRecommandation();
    if (taux == 1) return 1.5f;
    if (taux == 2) return 15.0f;
    return 0.0f;
}

void Lettre::afficher()
{
    cout << "Lettre ";
    Objet_postal::afficher();
    if(urgent==true){
        cout << "/ urgente" << endl;
    }
    else{
        cout << "/ non urgente" << endl;
    }

}
