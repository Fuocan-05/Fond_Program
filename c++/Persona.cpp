/*Classe Persona*/
/*creare una classe che si chiami conto corrente. Nome, Cognome, Numero del conto, il saldo del conto.
  Metodo aggiorna che accetti un doblue. aggiungi +, ritiri -. Metodo verifica copertura con un boul. Metodo di stampa. */
#include <iostream>
#include <cstring>

using namespace std;

class Persona
{
    public:
    string nome;
    string cognome;

    Persona(string nome, string cognome)
    {
       this->nome=nome;
       this->cognome=cognome;
    }

    void stampa()
    {
       cout<<"nome = "<< nome <<endl;
       cout<<"cognome = "<<cognome<<endl;
    }

};

int main()
{
    Persona persona1("luca", "rossi");
    persona1.stampa();

    return 0;
}