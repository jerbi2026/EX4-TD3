#ifndef COLIS_H
#define COLIS_H

#include "Objet_postal.h"
#include <string>
using namespace std;

class Colis : public Objet_postal
{
    public:
        Colis();
        Colis(string orig, string dest, int code_p, float p, float v,
              int t_rec, string declaration, float valeur);
        virtual ~Colis();

        float tarif_affranchissement();
        float tarif_remboursement();
        void  afficher();

        string getDeclaration() const      { return declaration_contenu; }
        float  getValeurDeclaree() const   { return valeur_declaree; }
        void   setDeclaration(string d)    { declaration_contenu = d; }
        void   setValeurDeclaree(float v)  { valeur_declaree = v; }

    private:
        string declaration_contenu;
        float  valeur_declaree;
};

#endif // COLIS_H
