import pytest
from calculator import Calcolatrice  # Assicurati che il file con la classe si chiami calcolatrice.py

@pytest.fixture
def calc():
    return Calcolatrice()

def test_moltiplicazione(calc):
    assert calc.moltiplicazione(10, 5) == 50
    assert calc.moltiplicazione(2, 3) == 6
    assert calc.moltiplicazione(7.5, 2.0) == 15.0

def test_divisione_valida(calc):
    assert calc.divisione(10, 5) == 2
    assert calc.divisione(15.0, 4.0) == 3.75

def test_divisione_per_zero(calc):
    with pytest.raises(ValueError, match="Divisione per zero"):
        calc.divisione(10, 0)

#per il test: 