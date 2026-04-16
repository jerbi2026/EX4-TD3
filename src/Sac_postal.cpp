#include "Sac_postal.h"
#include <iostream>
using namespace std;

const float Sac_postal::CAPACITE_DEFAUT = 0.5f;

Sac_postal::Sac_postal()
    : capacite_maximale(CAPACITE_DEFAUT)
{}

Sac_postal::Sac_postal(float capacite_max)
    : capacite_maximale(capacite_max > 0 ? capacite_max : CAPACITE_DEFAUT)
{}

Sac_postal::~Sac_postal()
{

}

float Sac_postal::volumeOccupe() const
{
    float total = 0.0f;
    for (int i = 0; i < contenu.taille(); i++)
        total += contenu.get(i)->getVolume();
    return total;
}

bool Sac_postal::ajouter(Objet_postal* objet)
{
    if (objet == nullptr) {
        cout << "Objet invalide (null)." << endl;
        return false;
    }
    if (volumeOccupe() + objet->getVolume() > capacite_maximale) {
        cout << "Impossible d'ajouter : volume insuffisant dans le sac." << endl;
        return false;
    }
    contenu.ajouter(objet);
    cout << "Objet ajoute avec succes." << endl;
    return true;
}

int Sac_postal::rechercher(Objet_postal* objet) const
{
    for (int i = 0; i < contenu.taille(); i++)
        if (contenu.get(i) == objet)
            return i;
    return -1;
}

bool Sac_postal::supprimer(Objet_postal* objet)
{
    int index = rechercher(objet);
    if (index == -1) {
        cout << "Objet introuvable dans le sac." << endl;
        return false;
    }
    contenu.supprimer(index);
    cout << "Objet supprime avec succes." << endl;
    return true;
}

bool Sac_postal::estVide() const
{
    return contenu.estVide();
}

void Sac_postal::afficher() const
{
    cout << "capacite maximale : " << capacite_maximale << " m3" << endl;
    cout << "volume occupe     : " << volumeOccupe()    << " m3" << endl;
    cout << "nombre d'objets   : " << contenu.taille()  << endl;
    cout << "------------------" << endl;

    if (contenu.estVide()) {
        cout << "  (sac vide)" << endl;
    } else {
        for (int i = 0; i < contenu.taille(); i++) {
            cout << "  [" << i << "] ";
            contenu.get(i)->afficher();
        }
    }
}
