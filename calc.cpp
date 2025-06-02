#include "calc.hpp"
#include <stdexcept>

Calcolatrice::Calcolatrice() {}

double Calcolatrice::somma(double a, double b)
{
    return a + b;
}

double Calcolatrice::divisione(double dividendo, double divisore)
{
    if (divisore == 0.0)
    {
        throw std::invalid_argument("Errore: Divisione per zero non consentita.");
    }
    return dividendo / divisore;
}
