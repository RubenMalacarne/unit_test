#include "calc.hpp"
#include <gtest/gtest.h>

// Test somma
TEST(CalcolatriceTest, SommaPositivi)
{
    Calcolatrice c;
    EXPECT_DOUBLE_EQ(c.somma(3.5, 2.5), 6.0);
}

TEST(CalcolatriceTest, SommaConZero)
{
    Calcolatrice c;
    EXPECT_DOUBLE_EQ(c.somma(3.5, 0.0), 3.5);
}

// Test divisione
TEST(CalcolatriceTestDDivisione, DivisioneNormale)
{
    Calcolatrice c;
    EXPECT_DOUBLE_EQ(c.divisione(10.0, 2.0), 5.0);
}

TEST(CalcolatriceTestDDivisione, DivisionePerZero)
{
    Calcolatrice c;
    EXPECT_THROW(c.divisione(10.0, 0.0), std::invalid_argument);
}

// per testare esegui: 
// cmake .. && make && ctest && ./test_calcolatrice