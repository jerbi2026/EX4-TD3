#ifndef LETTRE_H
#define LETTRE_H

#include "Objet_postal.h"
#include <string>
using namespace std;

class Lettre : public Objet_postal
{
    public:
        Lettre();
        Lettre(string orig, string dest, int code_p, float p, float v,
               int t_rec, bool urgent = false);
        virtual ~Lettre();

        float tarif_affranchissement();
        float tarif_remboursement();
        void  afficher();

        bool isUrgent() const        { return urgent; }
        void setUrgent(bool u)       { urgent = u; }

    private:
        bool urgent;
};

#endif // LETTRE_H
