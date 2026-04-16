#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
using namespace std;

template <typename T>
class Vecteur
{
    public:
        Vecteur();
        Vecteur(int capacite_initiale);
        Vecteur(const Vecteur<T>& other);
        ~Vecteur();

        bool        ajouter(T element);
        bool        supprimer(int index);
        bool        contient(T element) const;
        bool        estVide() const;
        int         taille() const;
        T           get(int index) const;
        Vecteur<T>& operator=(const Vecteur<T>& other);

    private:
        T*  tableau;
        int nb_elements;
        int capacite;

        void agrandir();
};


template <typename T>
Vecteur<T>::Vecteur()
    : nb_elements(0), capacite(4)
{
    tableau = new T[capacite];
}

template <typename T>
Vecteur<T>::Vecteur(int capacite_initiale)
    : nb_elements(0), capacite(capacite_initiale)
{
    if (capacite < 1) capacite = 4;
    tableau = new T[capacite];
}

template <typename T>
Vecteur<T>::Vecteur(const Vecteur<T>& other)
    : nb_elements(other.nb_elements), capacite(other.capacite)
{
    tableau = new T[capacite];
    for (int i = 0; i < nb_elements; i++)
        tableau[i] = other.tableau[i];
}

template <typename T>
Vecteur<T>::~Vecteur()
{
    delete[] tableau;
}

template <typename T>
Vecteur<T>& Vecteur<T>::operator=(const Vecteur<T>& other)
{
    if (this != &other) {
        delete[] tableau;
        capacite    = other.capacite;
        nb_elements = other.nb_elements;
        tableau     = new T[capacite];
        for (int i = 0; i < nb_elements; i++)
            tableau[i] = other.tableau[i];
    }
    return *this;
}

template <typename T>
void Vecteur<T>::agrandir()
{
    capacite *= 2;
    T* nouveau = new T[capacite];
    for (int i = 0; i < nb_elements; i++)
        nouveau[i] = tableau[i];
    delete[] tableau;
    tableau = nouveau;
}

template <typename T>
bool Vecteur<T>::ajouter(T element)
{
    if (nb_elements == capacite)
        agrandir();
    tableau[nb_elements++] = element;
    return true;
}

template <typename T>
bool Vecteur<T>::supprimer(int index)
{
    if (index < 0 || index >= nb_elements) {
        cout << "Index invalide." << endl;
        return false;
    }
    for (int i = index; i < nb_elements - 1; i++)
        tableau[i] = tableau[i + 1];
    nb_elements--;
    return true;
}

template <typename T>
bool Vecteur<T>::contient(T element) const
{
    for (int i = 0; i < nb_elements; i++)
        if (tableau[i] == element)
            return true;
    return false;
}

template <typename T>
bool Vecteur<T>::estVide() const
{
    return nb_elements == 0;
}

template <typename T>
int Vecteur<T>::taille() const
{
    return nb_elements;
}

template <typename T>
T Vecteur<T>::get(int index) const
{
    if (index < 0 || index >= nb_elements) {
        cout << "Index invalide." << endl;
        return tableau[0];
    }
    return tableau[index];
}

#endif // VECTEUR_H
