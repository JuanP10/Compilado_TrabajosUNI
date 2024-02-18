#include <iostream>
#include <chrono>

using namespace std;

struct Nodo{
    string dato;
    Nodo *sig{};
};

class ListaSimple{
    Nodo *ptr=nullptr;
public:
    void insFinal(string x);
    void insInicio(string x);

    void elimFinal();

    void mostrar();
    bool listaVacia();
};
void ListaSimple::elimFinal(){
    if(!listaVacia()){
        Nodo *p=ptr;
        if(ptr->sig==nullptr){
            ptr=nullptr;
        }else{
            Nodo *q=p;
            while(p->sig!=nullptr){
                q=p;
                p=p->sig;
            }
            q->sig=nullptr;
        }
        delete p;
    }
}
void ListaSimple::insInicio(string x){
    Nodo *nuevo=new Nodo;
    nuevo->dato=std::move(x);
    nuevo->sig=nullptr;

    if(listaVacia()){
        ptr=nuevo;
    }
    else{
        nuevo->sig=ptr;
        ptr=nuevo;
    }
}

void ListaSimple::mostrar(){
    if(!listaVacia()){
        Nodo *p=ptr;
        while(p!=nullptr){
            cout<<" "<<p->dato;
            p=p->sig;
        }
    }
}

bool ListaSimple::listaVacia(){
    return (ptr==nullptr);
}

void ListaSimple::insFinal(string x){
    Nodo *nuevo=new Nodo;
    nuevo->dato=std::move(x);
    nuevo->sig=nullptr;

    if(listaVacia()){
        ptr=nuevo;
    }else{
        Nodo *p=ptr;
        while(p->sig!=nullptr){
            p=p->sig;
        }
        p->sig=nuevo;
    }
}

int main(){
    auto begin = std::chrono::high_resolution_clock::now();
    string dato;
    dato = "test";
    ListaSimple lista;
    for(int i=0; i<100; i++){
        lista.insFinal(dato);
        lista.insInicio(dato);
        lista.mostrar();
        lista.listaVacia();
        lista.elimFinal();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("\nTiempo de ejecucion: %.6f seconds.\n", elapsed.count()*1e-9);

    return 1;
}