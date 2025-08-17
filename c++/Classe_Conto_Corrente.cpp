 /*
  creare una classe che si chiami conto corrente. Nome, Cognome, Numero del conto, il saldo del conto.
  Metodo aggiorna che accetti un doblue. aggiungi +, ritiri -. Metodo verifica copertura con un boul. Metodo di stampa.
 */
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

class Conto: public Persona
{
    public: 
    int n_conto;
    float s_conto;
    float importo;

    Conto(string nome, string cognome, int n_conto, float s_conto, float importo) : Persona(nome, cognome)
    {
        this->n_conto=n_conto;
        this->s_conto=s_conto;
        this->importo=importo;
    }

    void stampa()
    {
        Persona::stampa();
        cout<<"numero del conto = "<<n_conto<<endl;
        cout<<"saldo del conto = euro"<<s_conto<<endl;
    }

    void operazione()
    {
        if(importo>0)
        {
            s_conto = s_conto + importo;
            cout<<"il tuo saldo nel conto ora e aumentato di  euro"<<s_conto<<endl;
        }
        if(importo<0)
        {
            if(importo*-1>s_conto)
            {
                cout<<"non e possibile ritirare euro"<<importo*-1<<endl;
                cout<<"operazione non disponibile"<<endl;
            }
            if(importo*-1<s_conto)
            {
                s_conto = s_conto + importo;
                cout<<"hai prelevato euro"<<importo*-1<<endl<<"il tuo saldo ora e di euro"<<s_conto<<endl;
            }
        }
        if(importo==0)
        {
            cout<<"il tuo saldo non e cambiato"<<endl;
        }
    }
};

int main()
{
    Conto persona1("luca", "rossi", 325, 35.50, -50);
    persona1.stampa();
    persona1.operazione();
    return 0;
}