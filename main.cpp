#include <iostream>
#include <string>
#include <vector>

class Angajati{
private:
    std::string nume;
    std::string prenume;
    int salariu;
    std::string functie;
public:
    explicit Angajati(const std::string &n="", const std::string &pre="", int sal=0, const std::string &func="")
    {this->nume = n;
        this->functie= func;
        this->prenume=pre;
        this->salariu=sal;}
    ~Angajati() {
        nume.clear();
        functie.clear();
        salariu=0;
        prenume.clear();
    }

    Angajati(const Angajati &aux){
        this->nume=aux.nume;
        this->functie=aux.functie;
        this->salariu=aux.salariu;
        this->prenume=aux.prenume;

    }

    bool operator==(const Angajati &angajat) const {
        return nume == angajat.nume &&
               prenume == angajat.prenume &&
               salariu == angajat.salariu &&
               functie == angajat.functie;
    }

    bool operator!=(const Angajati &angajat) const {
        return !(angajat == *this);
    }

    friend std::ostream &operator<<(std::ostream &out, const Angajati &angajat) {
        out<< "Nume: " << angajat.nume << ",Prenume: " << angajat.prenume << ",Salariu lunar: " << angajat.salariu
           << ",Functie: " << angajat.functie<<"\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &ci, Angajati &angajat){
        std::cout<<"Introduceti numele angajatului:";
        ci >> angajat.nume ;
        std::cout<<"Introduceti prenumele angajatului:";
        ci >> angajat.prenume;
        std::cout<<"Introduceti salariul lunar angajatului:";
        ci >>angajat.salariu;
        std::cout<<"Introduceti functia angajatului:";
        ci >>angajat.functie;
        return ci;
    }

    int getSalariu() const {
        return salariu;
    }
};

class Avioane{
private:
    std::string model;
    std::string destinatie;
    int capacitate;
    int locuri_ocupate;
    int pret_bilet;
    int medie_bilete;
    int nr_pers_echipaj;
    std::vector<Angajati> echipaj;
public:
    explicit Avioane(const std::string &mod="", const std::string &dest="", int cap=0,
                     int locuriOcupate=0,int pret=0,int med=0,int nr=0,const std::vector<Angajati> &ech= std:: vector<Angajati>()) {
        this->model=mod;
        this->destinatie=dest;
        this->capacitate=cap;
        this->locuri_ocupate=locuriOcupate;
        this->pret_bilet=pret;
        this->medie_bilete=med;
        this->nr_pers_echipaj=nr;
        this->echipaj=ech;}

    ~Avioane(){
        model.clear();
        destinatie.clear();
        capacitate=0;
        locuri_ocupate=0;
        pret_bilet=0;
        medie_bilete=0;
        nr_pers_echipaj=0;
        echipaj.clear();
    }

    friend std::ostream &operator<<(std::ostream &out, const Avioane &avion) {
        out << "Model avion: " << avion.model <<",Destinatie: "
            << avion.destinatie << ",Capacitate: " << avion.capacitate << ",Numarul de locuri ocupate: "
            << avion.locuri_ocupate<<",Pretul unui bilet: "<<avion.pret_bilet
            <<",Media de vanzare a biletelor per zbor: "<<avion.medie_bilete
            << ",Numarul de persoane din echipaj: " << avion.nr_pers_echipaj << "\n" << "Echipajul:" << "\n";
        for(int i=0;i<avion.nr_pers_echipaj;i++)
            out << avion.echipaj[i];
        return out;
    }

    friend std::istream &operator>>(std::istream &ci,Avioane &avion) {
        std::cout<<"Introduceti modelul avionului:";
        ci >> avion.model;
        std::cout<<"Introduceti destinatia:";
        ci >> avion.destinatie;
        std::cout<<"Introduceti capacitatea avionului:";
        ci >> avion.capacitate;
        std::cout<<"Introduceti numarul de locuri ocupate:";
        ci >> avion.locuri_ocupate;
        std::cout<<"Introduceti pretul unui bilet:";
        ci>>avion.pret_bilet;
        std::cout<<"Introduceti media de vanzare a biletelor per zbor:";
        ci>>avion.medie_bilete;
        std::cout<<"Introduceti numarul de persoane din echipaj:";
        ci >> avion.nr_pers_echipaj;
        avion.echipaj.clear();
        for (int i = 0; i < avion.nr_pers_echipaj; i++) {
            Angajati angajat;
            std::cout<<"Introduceti persoana "<<i+1<<" din echipaj :"<<"\n";
            ci >> angajat;
            avion.echipaj.push_back(angajat);
        }
        return ci;
    }

    bool operator==(const Avioane &av) const {
        return model == av.model &&
               destinatie == av.destinatie &&
               capacitate == av.capacitate &&
               locuri_ocupate == av.locuri_ocupate &&
               pret_bilet == av.pret_bilet &&
               medie_bilete == av.medie_bilete &&
               nr_pers_echipaj == av.nr_pers_echipaj &&
               echipaj == av.echipaj;
    }

    bool operator!=(const Avioane &rhs) const {
        return !(rhs == *this);
    }

    const std::string &getDestinatie() const {
        return destinatie;
    }

    int getPretBilet() const {
        return pret_bilet;
    }

    const std::vector<Angajati> &getEchipaj() const {
        return echipaj;
    }

    int getMedieBilete() const {
        return medie_bilete;
    }

};
class Aeroport{
private:
    std::string nume;
    std::string tara;
    std::string oras;
    int nrAvioane;
    std::vector<Avioane> avioane;
public:
    explicit Aeroport(const std::string &n="Henri Coanda", const std::string &t="Romania", const std::string &o="Bucuresti",int nr=0,const std::vector<Avioane>& av=std::vector<Avioane>())
    {this->nume=n;
        this->tara=t;
        this->oras=o;
        this->nrAvioane=nr;
        this->avioane=av;}

    ~Aeroport()
    {   nume.clear();
        tara.clear();
        oras.clear();
        nrAvioane=0;
        avioane.clear();
    }

    Aeroport(const Aeroport& other){
        this->nume = other.nume;
        this->tara = other.tara;
        this->oras = other.oras;
        this->nrAvioane = other.nrAvioane;
        this->avioane = other.avioane;
    }


    friend std::ostream &operator<<(std::ostream &out, const Aeroport &aeroport) {
        out << "Numele aeroportului: " << aeroport.nume << ",Tara: " << aeroport.tara
            << ",Oras: " << aeroport.oras <<"\n"<< "Numarul de avioane: " << aeroport.nrAvioane<<"\n";
        for(int i=0;i<aeroport.nrAvioane;i++)
            out <<"Avionul "<<i+1<<": "<<"\n"<<aeroport.avioane[i];
        return out;
    }
    friend std::istream &operator>>(std::istream &ci,Aeroport &aer) {
        std::cout<<"Introduceti numarul de avioane aflate pe aeroport:";
        ci>> aer.nrAvioane;
        aer.avioane.clear();
        for (int i = 0; i < aer.nrAvioane; i++) {
            Avioane av;
            std::cout<<"Introduceti avionul "<<i+1<<" :"<<"\n";
            ci >> av;
            aer.avioane.push_back(av);
        }
        return ci;
    }

    bool operator==(const Aeroport &aer) const {
        return nume == aer.nume &&
               tara == aer.tara &&
               oras == aer.oras &&
               nrAvioane == aer.nrAvioane &&
               avioane == aer.avioane;
    }

    bool operator!=(const Aeroport &obj) const {
        return !(obj == *this);
    }
    friend Aeroport& operator+(const Aeroport &a1,const Aeroport &a2){
        Aeroport *a3;
        a3 = new Aeroport(a1.nume, a1.tara, a1.oras, a1.nrAvioane + a2.nrAvioane,a1.avioane);
        for(int j=0;j<a2.nrAvioane;j++)
            a3->avioane.push_back(a2.avioane[j]);
        return *a3;
    }

    friend bool operator>(const Aeroport& a1, const Aeroport& a2);

    void AvionAterizat(const Avioane& avion) {
        nrAvioane++;
        avioane.push_back(avion);
    }
    void DecolareAvion(const std::string& destinatieAvion){
        for(int i=0;i!=nrAvioane;i++)
            if (avioane[i].getDestinatie() == destinatieAvion) {
                avioane.erase(avioane.begin() + i);
                nrAvioane--;
                break;
            }
    }

    void Destinatii(){
        std::cout<<"Avioane de pe aeroport au destinatiile:"<<"\n";
        for(int i=0;i!=nrAvioane;i++)
            std::cout<<avioane[i].getDestinatie()<<"\n";
    }

    void ProfitAeroport(){
        int cheltuieli=0,incasari=0,profit;
        for(int i=0;i!=nrAvioane;i++)
            incasari+=avioane[i].getMedieBilete()*avioane[i].getPretBilet()*30;
        for(int i=0;i!=nrAvioane;i++){
            std::vector<Angajati>ech=avioane[i].getEchipaj();
            unsigned long long nr=ech.size();
            for(unsigned long long j = 0; j < nr; j++)
                cheltuieli += ech[j].getSalariu();
        }
        profit=incasari-cheltuieli;
        if(profit>0)
            std::cout<<"Aeroportul are un profit lunar de "<<profit<<"\n";
        else {
            if (profit < 0)
                std::cout << "Aeroportul are pierderi lunare de " << profit << "\n";
            else
                std::cout << "Aeroportul nu are nici profit,nici pierderi" << "\n";
        }
    }
};
bool operator>(const Aeroport& a1, const Aeroport& a2) {
    return a1.nrAvioane > a2.nrAvioane;
}
void meniu(){
    std::cout<<"1.Vezi informatiile aeroportului"<<"\n";
    std::cout<<"2.Adauga un avion care a aterizat pe aeroport"<<"\n";
    std::cout<<"3.Elimina un avion care a decolat de pe avion"<<"\n";
    std::cout<<"4.Vezi profitul lunar al aeroportului"<<"\n";
    std::cout<<"5.Iesi din meniu"<<"\n"<<"\n";
    std::cout<<"Alege:"<<"\n";
}
int main() {
    Aeroport a;
    std::cin>>a;
    int alg;
    bool m= true;
    while(m){
        meniu();
        std::cin>>alg;
        switch (alg) {
            case 1:{std::cout<<a;
                break;}
            case 2:{
                Avioane av;
                std::cin>>av;
                a.AvionAterizat(av);
                break;
            }
            case 3:{std::string dest;
                std::cout<<"Ce destinatie are avionul decolat?"<<"\n";
                a.Destinatii();
                std::cin>>dest;
                a.DecolareAvion(dest);
                break;
            }
            case 4:{a.ProfitAeroport();
                break;}
            default:{std::cout<<"Aceasta optiune nu exista"<<"\n";
                break;}

            case 5: {m= false;
                break;}}
    }
    return 0;
}

