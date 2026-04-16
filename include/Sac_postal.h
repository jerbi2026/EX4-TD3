#ifndef SAC_POSTAL_H
#define SAC_POSTAL_H

#include "Vecteur.h"
#include "Objet_postal.h"

class Sac_postal
{
    public:
        Sac_postal();
        Sac_postal(float capacite_max);
        ~Sac_postal();

        bool   ajouter(Objet_postal* objet);
        bool   supprimer(Objet_postal* objet);
        int    rechercher(Objet_postal* objet) const;
        float  volumeOccupe() const;
        bool   estVide() const;
        void   afficher() const;

    private:
        Vecteur<Objet_postal*> contenu;
        float capacite_maximale;

        static const float CAPACITE_DEFAUT;
};

#endif // SAC_POSTAL_H
