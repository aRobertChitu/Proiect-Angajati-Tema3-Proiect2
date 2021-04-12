#include <iostream>
using namespace std;

class Data{
private:
    int zi;
    int luna;
    int an;
public:
    void setZi(int zi){
        this->zi=zi;
    }
    void setLuna(int luna){
        this->luna=luna;
    }
    void setAn(int an){
        this->an=an;
    }
    int getZi(){
        return zi;
    }
    int getLuna(){
        return luna;
    }
    int getAn(){
        return an;
    }


};
class Angajat{
protected:
    string nume;
    string prenume;
    float salariu;
    Data data_angajare;
public:
    Angajat(){}
    Angajat(string nume, string prenume, float salariu,int zi, int luna, int an){
        this->nume=nume;
        this->prenume=prenume;
        this->salariu=salariu;
        data_angajare.setZi(zi);
        data_angajare.setLuna(luna);
        data_angajare.setAn(an);
    }
void setNume(string nume){
    this->nume=nume;
}
void setPrenume(string prenume){
    this->prenume=prenume;
}
void setSalariu(float salariu){
    this->salariu=salariu;
}
void setZi(int zi){
    data_angajare.setZi(zi);
}
void setLuna(int luna){
    data_angajare.setLuna(luna);
}
void setAn(int an){
    data_angajare.setAn(an);
}
string getNume(){
    return this->nume;
}
string getPrenume(){
    return this->prenume;
}
float getSalariu(){
    return this->salariu;
}
int getZi(){
    return data_angajare.getZi();
}
int getLuna(){
    return data_angajare.getLuna();
}
int getAn(){
    return data_angajare.getAn();
}
float calculPrima(){
    return salariu*2;
}

~Angajat(){}
};



class Permanent: public Angajat {
private:
    int nr_minori;
public:
    Permanent(){}
    Permanent(string nume, string prenume, float salariu,int zi, int luna, int an, int minori): Angajat(nume, prenume, salariu, zi, luna, an){
    this->nr_minori=minori;
    data_angajare.setAn(an);
    data_angajare.setZi(zi);
    data_angajare.setLuna(luna);
    }
    void setMinori(int minori){
        nr_minori=minori;
    }
    int getMinori(){
    return nr_minori;
    }
    float calculSpor(){
    return ((2020-data_angajare.getAn())*nr_minori*calculPrima())/100;
    }
~Permanent(){}
friend ostream &operator << (ostream &out, Permanent &p );
friend istream &operator >> (istream &in, Permanent &q);
};


class PartTime: public Angajat {
private:
    int nrOre;
    Data final_contract;
public:
    PartTime(){}
    PartTime(string nume, string prenume, float salariu,int zi, int luna, int an, int zi1, int luna1, int an1):Angajat(nume, prenume, salariu, zi, luna, an){
        final_contract.setZi(zi1);
        final_contract.setLuna(luna1);
        final_contract.setAn(an1);

    }
void setFinalZi(int zi){
    final_contract.setZi(zi);
}
void setFinalLuna(int luna){
    final_contract.setLuna(luna);
}
void setFinalAn(int an){
    final_contract.setAn(an);
}
int getFinalZi(){
    return final_contract.getZi();
}
int getFinalLuna(){
    return final_contract.getLuna();
}
int getFinalAn(){
    return final_contract.getAn();
}
float calcul(){
    if(final_contract.getAn()==2020)
        return calculPrima() * 0.75;
    else if (final_contract.getAn()<2020){
        return 0;
    }
    else
        return calculPrima();
}
~PartTime(){}
friend ostream &operator << (ostream &out, PartTime &t);
friend istream &operator >> (istream &in, PartTime &r);
};
istream &operator >> (istream &in, PartTime &r){

            cout<<"Nume: ";in>>r.nume;cout<<'\n';
            cout<<"Prenume : ";in>>r.prenume;cout<<'\n';
            cout<<"Salariu : ";in>>r.salariu;;cout<<'\n';int numar;
            cout<<"Zi Angajare : ";in>>numar;r.setZi(numar);cout<<'\n';
            cout<<"Luna Angajare : ";in>>numar;r.setLuna(numar);cout<<'\n';
            cout<<"An Angajare : ";in>>numar;r.setAn(numar);cout<<'\n';
            cout<<"Zi Finala : ";in>>numar;r.setFinalZi(numar);cout<<'\n';
            cout<<"Luna Finala : ";in>>numar;r.setFinalLuna(numar);cout<<'\n';
            cout<<"An Final : ";in>>numar;r.setFinalAn(numar);cout<<'\n';
            cout<<'\n';
            cout<<"Angajatul a fost adaugat."<<'\n'<<'\n';

    return in;
}

istream &operator >> (istream &in, Permanent &q){

            cout<<"Nume: ";in>>q.nume;cout<<'\n';
            cout<<"Prenume : ";in>>q.prenume;cout<<'\n';
            cout<<"Salariu : ";in>>q.salariu;;cout<<'\n';int numar;
            cout<<"Zi Angajare : ";in>>numar;q.setZi(numar);cout<<'\n';
            cout<<"Luna Angajare : ";in>>numar;q.setLuna(numar);cout<<'\n';
            cout<<"An Angajare : ";in>>numar;q.setAn(numar);cout<<'\n';
            cout<<"Nr Copii: ";in>>q.nr_minori;cout<<'\n';
            cout<<'\n';
            cout<<"Angajatul a fost adaugat."<<'\n'<<'\n';


  return in;
}



ostream &operator << (ostream &out, PartTime &t){
out<<"TEMP. Nume: "<<t.nume<<"  Prenume: "<<t.prenume<<"  Salariu: "<<t.salariu<<" Angajare: "<<t.getZi()<<"."<<t.getLuna()<<"."<<t.getAn();
out<<" Final: "<<t.getFinalZi()<<"."<<t.getFinalLuna()<<"."<<t.getFinalAn()<<" Prima primita: "<<t.calcul()<<'\n';
return out;
}

ostream &operator << (ostream &out, Permanent &p){
out<<"PERM. Nume: "<<p.nume<<"  Prenume: "<<p.prenume<<"  Salariu: "<<p.salariu<<" Angajare: "<<p.getZi()<<"."<<p.getLuna()<<"."<<p.getAn()<<" Copii: "<<p.getMinori();
out<<" Prima primita: "<<p.calculPrima()+p.calculSpor()<<'\n';
return out;
}

int main()
{

    string raspuns;
    string tip;
    string cuvant;
    string n1, n2;
    static Permanent Perm[100];
    static PartTime Part[100];
    int i=2;
    int j=1;
    int newsal;
    cout<<"MENIU INTERACTIV"<<'\n'<<'\n';
    cout<<"DEPARTAMENTUL DE SALARIZARE"<<'\n'<<'\n';
    cout<<"In momentul de fata au fost deja introdusi urmatorii angajati:"<<'\n'<<'\n';
    Permanent A1("Cosmin", "Mihai", 10000,1,7,2012,3);
    Permanent A2("Ionescu", "Dan", 30000,1,7,2015,1);
    Permanent A3("Popescu", "George", 40000,1,7,1999,0);
    PartTime  A4("Cristache", "Andra", 8000,17,2,2019,17,2,2021);
    PartTime  A5("Dumitru", "Ion", 7000,22,11,2018,22,11,2020);
    Perm[0]=A1;Perm[1]=A2;Perm[2]=A3;Part[0]=A4;Part[1]=A5;
   // delete &A1;delete &A2;delete &A3;delete &A4;delete &A5;
    cout<<A1;cout<<A2;cout<<A3;cout<<A4<<A5;
    cout<<'\n'<<'\n';

    while(1==1){
    cout<<'\n'<<'\n';
    cout<<"Ce doresti sa faci acum? "<<'\n';
    cout<<"[1] Adaugare Angajat"<<'\n';
    cout<<"[2] Eliminare Angajat"<<'\n';
    cout<<"[3] Afisare toti anagajatii"<<'\n';
    cout<<"[4] Schimbare salariu Angajat"<<'\n';
    cout<<"[5] Cautare Angajat"<<'\n';
    cout<<"[6] Iesire"<<'\n'<<'\n';
    cin>>raspuns;
    cout<<'\n'<<'\n';

    if(raspuns=="1"){
        cout<<"Angajatul este permanent sau Part-Time?   ( perm / temp)"<<'\n';
        cin>>tip;
        if(tip=="perm"){
            i++;
            cin>>Perm[i];
            cout<<Perm[i];

        }
        else if(tip=="temp"){
            j++;
            cin>>Part[j];
            cout<<Part[j];
        }
        else{

            cout<<"Introducere gresita"<<'\n';
        }

    }
    else if(raspuns=="3")
    {
        for (int k=0;k<=i;k++){
                if(Perm[k].getSalariu()>0)
            cout<<Perm[k];
        }
        for (int m=0;m<=j;m++){
                if(Part[m].getSalariu()>0)
            cout<<Part[m];
        }

    }
    else if (raspuns=="6"){
        break;
    }
    else if (raspuns=="2"){
        cout<<"Ce angajat doresti sa elimini? "<<'\n';
        cout<<"Nume: ";cin>>n1;cout<<"Prenume: ";cin>>n2;cout<<'\n';
        for (int k=0;k<=i;k++){
            if(Perm[k].getNume()==n1 && Perm[k].getPrenume()==n2){
                cout<<"Urmatorul Angajat a fost elimiant: "<<'\n'<<Perm[k];Perm[k].setSalariu(-5);}
        }
        for (int m=0;m<=j;m++){
            if(Part[m].getNume()==n1 && Part[m].getPrenume()==n2){
                cout<<"Urmatorul Angajat a fost elimiant: "<<'\n'<<Part[m]<<'\n';Part[m].setSalariu(-5);}
        }
    }
    else if (raspuns=="4"){
        cout<<"Cui doresti sa ii mofici salariul? "<<'\n';
        cout<<"Nume: ";cin>>n1;cout<<"Prenume: ";cin>>n2;cout<<'\n';cout<<"Salariu nou: ";cin>>newsal;cout<<'\n';
        for (int k=0;k<=i;k++){
            if(Perm[k].getNume()==n1 && Perm[k].getPrenume()==n2){
                Perm[k].setSalariu(newsal);cout<<"Salariul a fost modificat"<<'\n'<<Perm[k];}
        }
        for (int m=0;m<=j;m++){
            if(Part[m].getNume()==n1 && Part[m].getPrenume()==n2){
                Part[m].setSalariu(newsal);cout<<"Salariul a fost modificat"<<'\n'<<Part[m];}
        }

    }
        else if (raspuns=="5"){
        cout<<"Pe cine vrei sa cauti? "<<'\n';
        cout<<"Nume: ";cin>>n1;cout<<"Prenume: ";cin>>n2;
        for (int k=0;k<=i;k++)if(Perm[k].getNume()==n1 || Perm[k].getPrenume()==n2)cout<<Perm[k];
        for (int m=0;m<=j;m++)if(Part[m].getNume()==n1 || Part[m].getPrenume()==n2)cout<<Part[m];

    }
}
    return 0;
}
