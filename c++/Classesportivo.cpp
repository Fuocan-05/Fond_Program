#include <iostream>
#include <cstring>

using namespace std;

class Persona
{
    string cognome;
    string nome;
    
    public:

    Persona(string p_nome, string p_cognome)
    {
        nome = p_nome;
        cognome = p_cognome;
    }

    void set_nome(string p_nome)
    {
        nome = p_nome;
    }

    void set_cognome(string p_cognome)
    {
        cognome = p_cognome;
    }

    string get_nome()
    {
        return nome;
    }

    string get_cognome()
    {
        return cognome;
    }

    void stampa()
    {
        cout<<"nome = "<<" "<<nome<<endl;
        cout<<"cognome = "<<" "<<cognome<<endl;
    };

};

class Sportivo : public Persona
{
    string sport;

    public:

    Sportivo(string p_nome, string p_cognome, string p_sport):Persona(p_nome, p_cognome)
    {
        sport = p_sport;
    }
    void stampa()
    {
        Persona::stampa();
        cout<<"sport = "<<sport<<endl;
    }
};

int main()
{
    Persona p("rosario" , "mancino");
    p.stampa();
    Sportivo s("francesco" , "minà" , "boxe");
    s.stampa();
    
    return 0;
}