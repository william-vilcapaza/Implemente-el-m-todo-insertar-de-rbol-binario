#include <iostream>

using namespace std;

class Nodo{
    int dato;
    Nodo* hijoDerecho;
    Nodo* hijoIzquierdo;
public:
    Nodo(int dato)
    {
        this->dato = dato;
        hijoDerecho = NULL;
        hijoIzquierdo = NULL;
    }
    int getDato()
    {
        return dato;
    }
    void setDato(int dato)
    {
        this->dato = dato;
    }
    Nodo* getHijoIzquierdo()
    {
        return this->hijoIzquierdo;
    }
    void setHijoIzquierdo(Nodo* enlace)
    {
        this->hijoIzquierdo = enlace;
    }
    Nodo* getHijoDerecho()
    {
        return this->hijoDerecho;
    }
    void setHijoDerecho(Nodo* enlace)
    {
        this->hijoDerecho = enlace;
    }
    void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Dato: " << dato << endl;
        cout << "|-------------------" << endl;
        cout << "|Izquierdo: " << hijoIzquierdo << "\tDerecho: " << hijoDerecho << endl;
        cout << "\\------------------/" << endl;
    }
};
class ArbolBinario{
    Nodo* raiz;
public:
    ArbolBinario(){
        raiz = NULL;
    }
    Nodo* getRaiz()
    {
        return raiz;
    }

    bool EstaVacia()
    {
        if (raiz == NULL)
            return true;
        else
            return false;
    }
    void Insertar(Nodo* inicial, int dato){//Funcion insertar implementada
        Nodo* temp = new Nodo(dato);
        if(EstaVacia())
        {
            raiz = temp;
        }
        else
        {
            if(dato < inicial->getDato())
            {
                //insertar izquierda
                if(inicial->getHijoIzquierdo()==NULL)
                    inicial->setHijoIzquierdo(temp);
                else
                    Insertar(inicial->getHijoIzquierdo(), dato);
            }
            else
            {
                //insertar derecha
                if(inicial->getHijoDerecho()==NULL)
                    inicial->setHijoDerecho(temp);
                else
                    Insertar(inicial->getHijoDerecho(), dato);
            }
        }
    }
    void Insertar(int dato){
        Insertar(raiz, dato);
    }
    //preorder, inorder, postorder
    void PreOrden(Nodo* inicial){
        //condición de finalización
        if(inicial==NULL){
            return;
        }
        else{
            cout<<inicial->getDato()<<endl;
            PreOrden(inicial->getHijoIzquierdo());
            PreOrden(inicial->getHijoDerecho());
        }
    }
    void InOrden(Nodo* inicial){
        if(inicial==NULL){
            return;
        }
        else{
            InOrden(inicial->getHijoIzquierdo());
            cout<<inicial->getDato()<<endl;//raiz
            InOrden(inicial->getHijoDerecho());
        }
    }

    void PostOrden(Nodo* inicial){
        if(inicial==NULL){
            return;
        }
        else{
            PostOrden(inicial->getHijoIzquierdo());
            PostOrden(inicial->getHijoDerecho());
            cout<<inicial->getDato()<<endl;//raiz
        }
    }
    void PreOrden(){
        PreOrden(raiz);
    }
    void InOrden(){
        InOrden(raiz);
    }
    void PostOrden(){
        PostOrden(raiz);
    }

};

int main()
{
    ArbolBinario arbol = ArbolBinario();
    arbol.Insertar(7);
    arbol.Insertar(9);
    arbol.Insertar(1);
    arbol.Insertar(15);
    arbol.Insertar(10);
    arbol.Insertar(6);
    arbol.Insertar(5);
    arbol.Insertar(0);
    arbol.Insertar(7);


    arbol.PreOrden();
    arbol.InOrden();
    arbol.PostOrden();


    return 0;
}
