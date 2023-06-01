#include "clases.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

// DECLARACIÓN DE CLASES
// --------------------------------------------------------------------------------------

// Los enteros pueden cambiarse por float
// elementos = obstaculos

//-----------------------Elemento----------------------------------------------
  void Elemento::fijarTipoElemento(string tipo_elemento) {
    this->tipo_elemento = tipo_elemento;
  }
  void Elemento::fijarTamano(int tamano) { this->tamano = tamano; }
  void Elemento::fijarUnidadMedida(string unidad_medida) {
    this->unidad_medida = unidad_medida;
  }
  void Elemento::fijarCoordenada_x(int coordenada_x) {
    this->coordenada_x = coordenada_x;
  }
  void Elemento::fijarCoordenada_y(int coordenada_y) {
    this->coordenada_y = coordenada_y;
  }
  string Elemento::toString() {
    return tipo_elemento + ' ' + to_string(tamano) + ' ' + unidad_medida
      + ' ' + to_string(coordenada_x) + ' ' + to_string(coordenada_y);
  }
  bool Elemento::operator==(const Elemento &elem) const {
    return (this->tipo_elemento == elem.tipo_elemento &&
            this->tamano == elem.tamano &&
            this->unidad_medida == elem.unidad_medida &&
            this->coordenada_x == elem.coordenada_x &&
            this->coordenada_y == elem.coordenada_y
      );
  }
  
  // Getters
  string Elemento::obtenerTipoElemento() { return tipo_elemento; }
  int Elemento::obtenerTamano() { return tamano; }
  string Elemento::obtenerUnidadmedida() { return unidad_medida; }
  int Elemento::obtenerCoordenada_x() { return coordenada_x; }
  int Elemento::obtenerCoordenada_y() { return coordenada_y; }


//-----------------------Movimiento----------------------------------------------
  void Movimiento::fijarTipo_movimiento(string tipo_movimiento) {
    this->tipo_movimiento = tipo_movimiento;
  }
  void Movimiento::fijarMagnitud(float magnitud) { this->magnitud = magnitud; }
  void Movimiento::fijarUnidadMedida(string unidad_medida) {
    this->unidad_medida = unidad_medida;
  }

  // Getters
  string Movimiento::obtenerTipo_movimiento() { return tipo_movimiento; }
  float Movimiento::obtenerMagnitud() { return magnitud; }
  string Movimiento::obtenerUnidadMedida() { return unidad_medida; }


//-----------------------Analisis----------------------------------------------
  void Analisis::fijarTipo_analisis(string tipo_analisis) {
    this->tipo_analisis = tipo_analisis;
  }
  void Analisis::fijarObjeto(string objeto) { this->objeto = objeto; }
  void Analisis::fijarComentario(string comentario) { this->comentario = comentario; }

  // Getters
  string Analisis::obtenerTipo_analisis() { return tipo_analisis; }
  string Analisis::obtenerObjeto() { return objeto; }
  string Analisis::obtenerComentario() { return comentario; }


//-----------------------Curiosity----------------------------------------------
  // Setters
  void Curiosity::fijarElementos(const list<Elemento> &newElementos) {
    elementos = newElementos;
  }
  void Curiosity::fijarListaMovimientos(const list<Movimiento> &newListaMovimientos) {
    listaMovimientos = newListaMovimientos;
  }
  void Curiosity::fijarListaAnalisis(const list<Analisis> &newListaAnalisis) {
    listaAnalisis = newListaAnalisis;
  }

  // Getters
  list<Elemento> Curiosity::obtenerElementos() { return elementos; }
  list<Movimiento> Curiosity::obtenerListaMovimientos() { return listaMovimientos; }
  list<Analisis> Curiosity::obtenerListaAnalisis() { return listaAnalisis; }
    list<Elemento>::iterator Curiosity::getElementoBegin() {
    return elementos.begin();
  }
  list<Elemento>::iterator Curiosity::getElementoEnd() {
    return elementos.end();
  }

  list<Analisis>::iterator Curiosity::getAnalisisBegin() {
    return listaAnalisis.begin();
  }
  list<Analisis>::iterator Curiosity::getAnalisisEnd() {
    return listaAnalisis.end();
  }

  list<Movimiento>::iterator Curiosity::getMovimientoBegin() {
    return listaMovimientos.begin();
  }
  list<Movimiento>::iterator Curiosity::getMovimientoEnd() {
    return listaMovimientos.end();
  }
  //Métodos
  void Curiosity::agregarElemento(Elemento auxEle){
    elementos.push_back(auxEle);
  }
void Curiosity::agregarMovimiento(Movimiento auxMov){
    listaMovimientos.push_back(auxMov);
  }
void Curiosity::agregarAnalisis(Analisis auxAna){
    listaAnalisis.push_back(auxAna);
  }

//-----------------------Rectangulo----------------------------------------------

  Rectangulo::Rectangulo(int x1, int x2, int y1, int y2, string t){
      xmin = x1;
      xmax = x2;
      ymin = y1;
      ymax = y2;
      tipo = t;
 }
  void Rectangulo::fijarXmin(int x1){
    xmin = x1;
  }
  void Rectangulo::fijarXmax(int x2){
    xmax = x2;
  }
  void Rectangulo::fijarYmin(int y1){
    ymin = y1;
  }
  void Rectangulo::fijarYmax(int y2){
    ymax = y2;
  }
  void Rectangulo::fijarTipo(string t){
    tipo = t;
  }
  int Rectangulo::obtenerXmin(){
    return xmin;
  }
  int Rectangulo::obtenerXmax(){
    return xmax;
  }
  int Rectangulo::obtenerYmin(){
    return ymin;
  }
  int Rectangulo::obtenerYmax(){
    return ymax;
  }
  string Rectangulo::obtenerTipo(){
    return tipo;
  }
//Función de intersección
  bool Rectangulo::intersecta(const Rectangulo& o) {
        if (xmax < o.xmin || o.xmax < xmin) {//Si no se intersectan en x
            return false;
        }
        if (ymax < o.ymin || o.ymax < ymin) {//Si no se intersectan en y
            return false;
        }
        return true;
    }
  //Función de contención  
    bool Rectangulo::contiene(const Rectangulo& o){
        if(o.xmin >= xmin && o.xmax <= xmax && o.ymin >= ymin && o.ymax <= ymax){//Si el rectángulo o está dentro de this
            return true;
        }

        return false;
  }

   //-----------------------Nodo---------------------------------------------- 


    Nodo::Nodo(Rectangulo *o){
        obstaculo = o;
        izq = NULL;
        der = NULL;
    }

    Nodo::~Nodo(){
        delete obstaculo;
        delete izq;
        delete der;
    }
    //Setters
    void Nodo::fijarObstaculo(Rectangulo *o){
        obstaculo = o;
    }
    void Nodo::fijarIzq(Nodo *n){
        izq = n;
    }
    void Nodo::fijarDer(Nodo *n){
        der = n;
    }
    Rectangulo* Nodo::obtenerObstaculo(){
        return obstaculo;
    }
    //Getters
    Nodo* Nodo::obtenerIzq(){
        return izq;
    }
    Nodo* Nodo::obtenerDer(){
        return der;
    }
    Nodo* &Nodo::obtenerIzqRef(){
        return izq;
    }
    Nodo* &Nodo::obtenerDerRef(){
        return der;
    }
    //-----------------------KDTree---------------------------------------------- 


    KDTree::KDTree(){
        raiz = NULL;
    }
    KDTree::~KDTree(){
        delete raiz;
    }
    //Getter
    void KDTree::fijarRaiz(Nodo *n){
        raiz = n;
    }
    //Setter
    Nodo* KDTree::obtenerRaiz(){
        return raiz;
    }
    //Función pública de inserción
    bool KDTree::insertar(Rectangulo *o){
        if(insertar(o, raiz, true)){
            return true;
        }else
            return false;    
    }
    //Función pública de búsqueda
    bool KDTree::buscar(Rectangulo *rect){
      bool hayUno=false;
      return buscar(raiz, rect, hayUno);
    }
    //Función privada de inserción
    bool KDTree::insertar(Rectangulo *o, Nodo *&nodo, bool eje){
        if(nodo == NULL){
          nodo = new Nodo(o);
          return true;
        }else{
          if(nodo->obtenerObstaculo()->intersecta(*o)){//Si el obstaculo a insertar intersecta con el nodo actual(Ya hay un obstaculo en esas coordenadas)
            return false;
          }
          if(eje){//Si el eje es x
            if(o->obtenerXmin() < nodo->obtenerObstaculo()->obtenerXmin()){//Si el obstaculo a insertar tiene xmin menor que el nodo actual
              return insertar(o, nodo->obtenerIzqRef(), !eje);//Se inserta en el subarbol izquierdo y se cambia el eje
            }else{
              return insertar(o, nodo->obtenerDerRef(), !eje);//Se inserta en el subarbol derecho y se cambia el eje
            }
          }else{//Si el eje es y
            if(o->obtenerYmin() < nodo->obtenerObstaculo()->obtenerYmin()){//Si el obstaculo a insertar tiene ymin menor que el nodo actual
              return insertar(o, nodo->obtenerIzqRef(), !eje);//Se inserta en el subarbol izquierdo y se cambia el eje
            }else{
              return insertar(o, nodo->obtenerDerRef(), !eje);//Se inserta en el subarbol derecho y se cambia el eje
            }
          }
        }
    }
    //Función privada de búsqueda, recorre el árbol inorden y compara si el obstaculo del nodo está en el rectángulo(Cuadrante)
    bool KDTree::buscar(Nodo *nodo, Rectangulo *rect, bool &hayUno){
        if(nodo == NULL){
          return false;
        }
             buscar(nodo->obtenerIzq(), rect,hayUno);//Se busca en el subarbol izquierdo
            if(rect->intersecta(*nodo->obtenerObstaculo())){//Si el cuadrante contiene al obstaculo
              cout<<"Elemento:"<<nodo->obtenerObstaculo()->obtenerTipo()
              <<" \nCoordenadas: ("<<nodo->obtenerObstaculo()->obtenerXmin()<<","<<nodo->obtenerObstaculo()->obtenerYmin()<<"),("
              <<nodo->obtenerObstaculo()->obtenerXmax()<<","<<nodo->obtenerObstaculo()->obtenerYmax()<<")\n";
              hayUno=true;
              }
             buscar(nodo->obtenerDer(), rect,hayUno);//Se busca en el subarbol derecho
            return hayUno;
        }

    //Función pública de vacío
   bool KDTree::vacio(){
        if(raiz == NULL){
            return true;
        }else{
            return false;;
        }
    }


//-----------------------Grafo---------------------------------------------- 

Grafo::Grafo() {}

int Grafo::idVertice(Elemento el) {
    int k = 0;
    for (Vertice v: this->vertices) {
        if (*(v.getElemento()) == el) {
            return k;
        }
        k++;
    }

    return -1;
}

Elemento* Grafo::InfoVertice(int v) {
    if (v >= this->aristas.size())
        throw runtime_error("El vertice no existe en el grafo.");

    list<Vertice>::iterator it = this->vertices.begin();
    advance(it, v);

    return it->getElemento();
}

void Grafo::InsVertice(Elemento* v) {
    vertices.push_back(Vertice(v));
    aristas.push_back(set<Arista>());
}

bool Grafo::existeVertice(Elemento el) {
    for (Vertice v: this->vertices) {
        if (*(v.getElemento()) == el) {
            return true;
        }
    }
    return false;
}

bool Grafo::InsArco(int v1, int v2, float c) {
    if (v1 >= this->vertices.size() || v2 >= this->vertices.size())
        return false;
        
    list<set<Arista>>::iterator it = this->aristas.begin();
    advance(it, v1);

    it->insert({c, v2});
    return true;
}

void Grafo::ElimArco(int v1, int v2) {
    if (v1 >= this->vertices.size() || v2 >= this->vertices.size())
        return;
    
    list<set<Arista>>::iterator it1 = this->aristas.begin();
    advance(it1, v1);

    for (Arista a: *it1) {
        if (a.second == v2) {
            it1->erase(a);
            return;
        }
    }

}

int Grafo::OrdenGrafo() const {
    return vertices.size();
}

float Grafo::CostoArco(int v1, int v2) {
    if (v1 == v2){
        return 0;
    }
    
    list<set<Arista>>::iterator it1 = this->aristas.begin();
    advance(it1, v1);

    for (Arista a: *it1) {
        if (a.second == v2) {
            return a.first;
        }
    }

    return -1;
}

bool Grafo::MarcadoVertice(int v) {
    if (v >= this->aristas.size())
        return false;

    list<Vertice>::iterator it = this->vertices.begin();
    advance(it, v);

    return it->estaMarcado();
}

void Grafo::DesmarcarGrafo() {
    for (Vertice vertice: this->vertices) {
        vertice.desmarcar();
    }
}

void Grafo::DesmarcarVertice(int v) {
    if (v >= this->aristas.size())
        return;

    list<Vertice>::iterator it = this->vertices.begin();
    advance(it, v);

    it->desmarcar();
}

void Grafo::MarcarVertice(int v) {
    if (v >= this->aristas.size())
        return;

    list<Vertice>::iterator it = this->vertices.begin();
    advance(it, v);

    return it->marcar();
}

list<Elemento*> Grafo::getVertices() {
    list<Elemento*> elemVertices;
    for (Vertice v: this->vertices) {
        elemVertices.push_back(v.getElemento());
    }
    return elemVertices;
}

list<int> Grafo::sucesores(int v) {
    if (v >= this->aristas.size())
        return list<int>();

    list<set<Arista>>::iterator it1 = this->aristas.begin();
    advance(it1, v);

    list<int> l_res;

    for (Arista a: *it1) {
        l_res.push_back(a.second);
    }

    return l_res;
}

void Grafo::borrar() {
    this->aristas.clear();
    this->vertices.clear();
}

//-----------------------Vertice----------------------------------------------

Vertice::Vertice() {}

Vertice::Vertice(Elemento* elem) {
    this->elemento = elem;
}

Elemento* Vertice::getElemento() {
    return elemento;
}

void Vertice::marcar() {
    this->marcado = true;
}

void Vertice::desmarcar() {
    this->marcado = false;
}

bool Vertice::estaMarcado() {
    return this->marcado;
}