#ifndef OBJET_POSTAL_H
#define OBJET_POSTAL_H

#include <string>
using namespace std;

class Objet_postal
{
    public:
        Objet_postal();
        Objet_postal(string orig, string dest, int code_p, float p, float v, int t_rec);
        virtual ~Objet_postal();

        virtual float tarif_affranchissement() = 0;
        virtual float tarif_remboursement() = 0;
        virtual void afficher();

        string getOrigine() const        { return origine; }
        string getDestination() const    { return destination; }
        int    getCodePostal() const     { return code_postal; }
        float  getPoids() const          { return poids; }
        float  getVolume() const         { return volume; }
        int    getTauxRecommandation() const { return taux_recommendation; }

        void setOrigine(string orig)     { origine = orig; }
        void setDestination(string dest) { destination = dest; }
        void setCodePostal(int code)     { code_postal = code; }
        void setPoids(float p)           { poids = p; }
        void setVolume(float v)          { volume = v; }
        void setTauxRecommandation(int t);

    private:
        string origine;
        string destination;
        int    code_postal;
        float  poids;
        float  volume;
        int    taux_recommendation;
};

#endif // OBJET_POSTAL_H
