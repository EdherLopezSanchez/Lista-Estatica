#include <iostream>
#include <string.h>
#define TAM 50

using namespace std;

class Mamifero
{
    private:
        int nacimiento;
        std::string lugar_nacimiento;

    public:
        Mamifero(int n, std::string ln): nacimiento(n), lugar_nacimiento(ln){}
        Mamifero():nacimiento(0), lugar_nacimiento(""){}

        void imprimir_nacimiento(){
            std::cout<<"\nAno de nacimiento: "<<nacimiento<<std::endl<<"\nLugar de nacimiento: "<<lugar_nacimiento<<std::endl;
        }

        friend Mamifero operator + (Mamifero a, Mamifero b){
            return Mamifero(a.nacimiento + b.nacimiento, a.lugar_nacimiento + b.lugar_nacimiento);
        }

        bool operator == ( Mamifero &a){
            if (nacimiento == a.nacimiento && lugar_nacimiento == a.lugar_nacimiento)
            {
                return true;
            }
            return false;
        }

        bool operator != ( Mamifero &a){
            if (nacimiento != a.nacimiento || lugar_nacimiento != a.lugar_nacimiento)
            {
                return true;
            }
            return false;
        }

        bool operator < ( Mamifero &a){
            if (nacimiento < a.nacimiento)
            {
                return true;
            }
            return false;
        }

        bool operator > ( Mamifero &a){
            if (nacimiento > a.nacimiento)
            {
                return true;
            }
            return false;
        }

        int getnacimiento(){
            return nacimiento;
        }

        void setnacimiento(int nacimiento){
            this->nacimiento = nacimiento;
        }

        std::string getlugardenacimiento(){
            return lugar_nacimiento;
        }

        void setlugardenacimiento(std::string lugar_nacimiento){
            this->lugar_nacimiento = lugar_nacimiento;
        }
};

class Felino : public Mamifero
{
    private:
        std::string dieta;
        std::string raza;
        std::string circo;

    public:
        Felino(int n, std::string ln, std::string d, std::string r, std::string c): Mamifero(n, ln), dieta(d), raza(r), circo(c){}
        Felino(): Mamifero(), dieta(""), raza(""), circo(""){}

        void imprimir_dieta(){
            std::cout<<"Su dieta es: "<<dieta<<std::endl;
        }

        void imprimir_raza(){
            std::cout<<"La raza es: "<<raza<<std::endl;
        }

        void cambiar_circo(std::string nuevo_circo){
            circo = nuevo_circo;
            std::cout<<"Nombre del circo cambiado!"<<std::endl;
        }

        friend Felino operator + (Felino a, Felino b){
            a.setnacimiento(a.getnacimiento() + b.getnacimiento());
            a.setlugardenacimiento(a.getlugardenacimiento() + b.getlugardenacimiento());
            a.dieta += b.dieta;
            a.raza += b.raza;
            a.circo += b.circo;
            return Felino(a);
        }

        bool operator == (Felino &a){
            if (getnacimiento() == a.getnacimiento() && getlugardenacimiento() == a.getlugardenacimiento() && dieta == a.dieta && raza == a.raza && circo == a.circo)
            {
                return true;
            }
            return false;
        }

        bool operator != ( Felino &a){
            if (getnacimiento() != a.getnacimiento() || getlugardenacimiento() != a.getlugardenacimiento() || dieta != a.dieta || raza != a.raza || circo != a.circo)
            {
                return true;
            }
            return false;
        }

        bool operator < ( Felino &a){
            if (getnacimiento() < a.getnacimiento() && getlugardenacimiento() < a.getlugardenacimiento() && dieta < a.dieta && raza < a.raza && circo < a.circo)
            {
                return true;
            }
            return false;
        }

        bool operator > ( Felino &a){
            if (getnacimiento() > a.getnacimiento() && getlugardenacimiento() > a.getlugardenacimiento() && dieta > a.dieta && raza > a.raza && circo > a.circo)
            {
                return true;
            }
            return false;
        }

        std::string getdieta(){
            return dieta;
        }

        void setdieta(std::string dieta){
            this->dieta = dieta;
        }

        std::string getraza(){
            return raza;
        }

        void setraza(std::string raza){
             this->raza = raza;
        }

        std::string getcirco(){
            return circo;
        }

        void setcirco(std::string circo){
             this->circo = circo;
        }
};

class GatoDomestico : public Felino
{
    private:
        std::string dueno;

    public:
        GatoDomestico(int n, std::string ln, std::string d, std::string r, std::string c, std::string due): Felino(n, ln, d, r, c), dueno(due){}
        GatoDomestico(): Felino(), dueno(""){}

        void cambiar_dueno(std::string nuevo_dueno){
            dueno = nuevo_dueno;
            std::cout<<"Dueno cambiado!"<<std::endl;
        }

        std::string getdueno(){
            return dueno;
        }

        void setdueno (std::string dueno){
            this->dueno = dueno;
        }

        friend GatoDomestico operator + (GatoDomestico a, GatoDomestico b){
            a.setdieta(a.getdieta() + b.getdieta());
            a.setlugardenacimiento(a.getlugardenacimiento() + b.getlugardenacimiento());
            a.setdieta(a.getdieta() + b.getdieta());
            a.setraza(a.getraza() + b.getraza());
            a.setcirco(a.getcirco() + b.getcirco());
            a.dueno += b.dueno;
            return GatoDomestico(a);
        }

        bool operator == ( GatoDomestico &a){
            if (getnacimiento() == a.getnacimiento() && getlugardenacimiento() == a.getlugardenacimiento() && getdieta() == a.getdieta() && getraza() == a.getraza() && getcirco() == a.getcirco() && dueno == a.dueno)
            {
                return true;
            }
            return false;
        }

        bool operator != ( GatoDomestico &a){
            if (getnacimiento() != a.getnacimiento() || getlugardenacimiento() != a.getlugardenacimiento() || getdieta() != a.getdieta() || getraza() != a.getraza() || getcirco() != a.getcirco() || dueno == a.dueno)
            {
                return true;
            }
            return false;
        }

        bool operator < ( GatoDomestico &a){
            if (getnacimiento() < a.getnacimiento() && getlugardenacimiento() < a.getlugardenacimiento() && getdieta() < a.getdieta() && getraza() < a.getraza() && getcirco() < a.getcirco() && dueno < a.dueno)
            {
                return true;
            }
            return false;
        }

        bool operator > ( GatoDomestico &a){
            if (getnacimiento() > a.getnacimiento() && getlugardenacimiento() > a.getlugardenacimiento() && getdieta() > a.getdieta() && getraza() > a.getraza() && getcirco() > a.getcirco() && dueno > a.dueno)
            {
                return true;
            }
            return false;
        }

        void mostrar(){
            std::cout<<std::endl<<std::endl<<"Anio de nacimiento: ";
            std::cout<<getnacimiento()<<std::endl;
            std::cout<<"Lugar de nacimiento: ";
            std::cout<<getlugardenacimiento()<<std::endl;
            std::cout<<"Dieta: ";
            std::cout<<getdieta()<<std::endl;
            std::cout<<"Raza: ";
            std::cout<<getraza()<<std::endl;
            std::cout<<"Circo: ";
            std::cout<<getcirco()<<std::endl;
            std::cout<<"Dueno: ";
            std::cout<<dueno<<std::endl;
        }

        friend ostream& operator <<(ostream& os, GatoDomestico gato){
            std::cout<<std::endl<<std::endl<<"Anio de nacimiento: ";
            os<<gato.getnacimiento()<<std::endl;
            std::cout<<"Lugar de nacimiento: ";
            os<<gato.getlugardenacimiento()<<std::endl;
            std::cout<<"Dieta: ";
            os<<gato.getdieta()<<std::endl;
            std::cout<<"Raza: ";
            os<<gato.getraza()<<std::endl;
            std::cout<<"Circo: ";
            os<<gato.getcirco()<<std::endl;
            std::cout<<"Dueno: ";
            os<<gato.dueno<<std::endl;
        }

        void obtener(){
            int aux;
            std::string aux2;
            std::cout<<std::endl<<std::endl<<"Ano de nacimiento: ";
            std::cin>>aux;
            setnacimiento(aux);
            std::cout<<"Lugar de nacimiento: ";
            fflush(stdin);
            getline(std::cin, aux2);
            setlugardenacimiento(aux2);
            std::cout<<"Dieta: ";
            fflush(stdin);
            getline(std::cin, aux2);
            setdieta(aux2);
            std::cout<<"Raza: ";
            fflush(stdin);
            getline(std::cin, aux2);
            setraza(aux2);
            std::cout<<"Circo: ";
            fflush(stdin);
            getline(std::cin, aux2);
            setcirco(aux2);
            std::cout<<"Nombre del dueno: ";
            fflush(stdin);
            getline(std::cin, aux2);
            setdueno(aux2);
        }

        friend istream& operator >>(istream& os, GatoDomestico gato){
            int aux;
            std::string aux2;
            std::cout<<std::endl<<std::endl<<"Ano de nacimiento: ";
            std::cin>>aux;
            gato.setnacimiento(aux);
            std::cout<<"Lugar de nacimiento: ";
            std::cin>>aux2;
            gato.setlugardenacimiento(aux2);
            std::cout<<"Dieta: ";
            std::cin>>aux2;
            gato.setdieta(aux2);
            std::cout<<"Raza: ";
            std::cin>>aux2;
            gato.setraza(aux2);
            std::cout<<"Circo: ";
            std::cin>>aux2;
            gato.setcirco(aux2);
            std::cout<<"Nombre del dueno";
            os>>gato.dueno;
        }
};

class Lista{
    private:
        GatoDomestico datos[TAM];
        int ult;

    public:
        Lista(){
            ult = -1;
        }

        bool vacia()const{
            return ult==-1;
        }

        bool llena()const{
            return ult==TAM-1;
        }

        void agrega(GatoDomestico elem){
            if (!llena()){
                datos[ult + 1] = elem;
                ult++;
            }
            else{
                std::cout<<"No se pudo agregar"<<std::endl;
            }
        }

        bool inserta(GatoDomestico elem, int pos){
            if(llena() || pos < 0 || pos > ult + 1){
                std::cout<<"\n No se pudo insertar";
                return false;
            }
            for (int i = ult + 1; i > pos; i--){
                datos[i] = datos[i - 1];
            }
            datos[pos] = elem;
            ult++;
            return true;
        }

        int buscar(GatoDomestico elem){
            int aux,i;
            for (int i = 0; i > ult; i++){
                if (elem == datos[i]){
                    return i;
                }
                aux=i;
            }
            return aux;
        }

        bool elimina(int pos){
            if(vacia() || pos < 0 || pos > ult - 1){
                std::cout<<"\n No se pudo eliminar";
                return false;
            }
            for (int i = pos; i < ult; i++){
                datos[i] = datos[i + 1];
            }
            ult--;
            return true;
        }

        void imprime(){
            if(!vacia()){
                for(int i = 0; i <= ult; i++){
                    datos[i].mostrar();
                }
            }
        }

        GatoDomestico recupera(int pos)const{
            if(vacia() || pos < 0 || pos > ult - 1){
                std::cout<<"\n Insuficiencia de datos";
            }
            else{
            return datos[pos];
            }
        }

        int primero()const{
            if(vacia()){
                return -1;
            }
            return 0;
        }

        int ultimo()const{
            if(vacia()){
                return -1;
            }
            return ult;
        }
};

int main(){
    Lista lis;
    GatoDomestico elem;

    int opc, pos;
    string aux;

    do{
        std::cout<<"\n\t\tMenu"<<std::endl;
        std::cout<<" 1.Agrega"<<std::endl;
        std::cout<<" 2.Buscar"<<std::endl;
        std::cout<<" 3.Eliminar"<<std::endl;
        std::cout<<" 4.Insertar"<<std::endl;
        std::cout<<" 5.Mostrar"<<std::endl;
        std::cout<<" 6.Salir"<<std::endl;
        std::cout<<"Elija una opcion: ";
        std::cin>>opc;

        switch (opc)
        {
            case 1:
                std::cout<<"Ingrese los datos del elemento gato domestico: ";
                elem.obtener();
                lis.agrega(elem);
            break;
            case 2:
                std::cout<<"Ingresa los datos del elemento gato domestico";
                std::cin>>elem;
                std::cout<<std::endl<<"Su dato esta en la posicion: "<<lis.buscar(elem);
            break;
            case 3:
                std::cout<<"Ingresa la posicion a eliminar";
                std::cin>>pos;
                lis.elimina(pos);
            break;
            case 4:
                std::cout<<"Ingresa los datos del elemento gato domestico";
                std::cin>>elem;
                std::cout<<"Ingresa la posicion";
                std::cin>>pos;
                lis.inserta(elem, pos);
            break;
            case 5:
                lis.imprime();
            break;
        }
    } while (opc != 6);


    return 0;
}
