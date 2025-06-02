class Calcolatrice:

    def __init__(self):

        # print("Oggetto Calcolatrice creato!") # Opzionale
        pass

    def moltiplicazione(self, a, b):
        return a * b

    def divisione(self, dividendo, divisore):
        if divisore == 0:
            raise ValueError("Errore: Divisione per zero non consentita.")
        return dividendo / divisore

# --- Blocco Main per testare la classe ---
if __name__ == "__main__":
    # Creiamo un'istanza (oggetto) della classe Calcolatrice
    mia_calcolatrice = Calcolatrice()

    num1 = 10.0
    num2 = 5.0
    num3 = 0.0  # Per testare la divisione per zero
    num4 = 3.0

    # Test della funzione moltiplicazione
    risultato_moltiplicazione = mia_calcolatrice.moltiplicazione(num1, num2)
    print(f"{num1} * {num2} = {risultato_moltiplicazione}")  # Output: 10.0 * 5.0 = 50.0

    risultato_moltiplicazione_2 = mia_calcolatrice.moltiplicazione(num2, num4)
    print(f"{num2} * {num4} = {risultato_moltiplicazione_2}") # Output: 5.0 * 3.0 = 15.0

    # Test della funzione divisione (caso valido)
    try:
        risultato_divisione1 = mia_calcolatrice.divisione(num1, num2)
        print(f"{num1} / {num2} = {risultato_divisione1}")  # Output: 10.0 / 5.0 = 2.0
    except ValueError as e:
        print(f"Errore catturato: {e}")

    # Test della funzione divisione (divisione per zero)
    print(f"\nTentativo di dividere {num1} per {num3}:")
    try:
        risultato_divisione2 = mia_calcolatrice.divisione(num1, num3)
        # Questa riga non verrà eseguita se viene sollevata l'eccezione
        print(f"{num1} / {num3} = {risultato_divisione2}")
    except ValueError as e:
        # Cattura l'eccezione specifica ValueError
        print(f"Errore catturato: {e}")  # Output: Errore: Divisione per zero non consentita.
    except ZeroDivisionError as e_zero: # Python solleva ZeroDivisionError di default
        print(f"Errore Python nativo catturato: {e_zero}")


    # Altri esempi
    print(f"\nAltri esempi:")
    print(f"7.5 * 2.0 = {mia_calcolatrice.moltiplicazione(7.5, 2.0)}")
    try:
        print(f"15.0 / 4.0 = {mia_calcolatrice.divisione(15.0, 4.0)}")
    except ValueError as e:
        print(f"Errore catturato: {e}")