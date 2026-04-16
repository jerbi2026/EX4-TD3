#include <iostream>
#include "Lettre.h"
#include "Colis.h"
#include "Sac_postal.h"
using namespace std;

int main()
{
    Sac_postal pSac;

    Lettre* pl1 = new Lettre("Paris","famille Kirik, igloo 5 banquise nord",7742, 50, 0.001f, 1, true);

    Lettre* pl2 = new Lettre("Lyon","famille Dupont, 12 rue des lilas",3301, 30, 0.002f, 0, false);

    Colis* pc1 = new Colis("Marseille","famille Kaya, igloo 10 terres ouest",7854, 2000, 0.02f, 2, "Livres", 200.0f);

    Colis* pc2 = new Colis("Bordeaux","entreprise Soleil, zone industrielle nord",5510, 5000, 0.05f, 1, "Materiel informatique", 800.0f);

    pSac.ajouter(pl1);
    pSac.ajouter(pl2);
    pSac.ajouter(pc1);
    pSac.ajouter(pc2);
    pSac.afficher();
    delete pl1;
    delete pl2;
    delete pc1;
    delete pc2;

    return 0;
}
