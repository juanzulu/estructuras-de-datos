#ifndef clases_h
#define clases_h
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
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

class Elemento {
private:
  string tipo_elemento;
  int tamano;
  string unidad_medida;
  int coordenada_x;
  int coordenada_y;

public:
  void fijarTipoElemento(string tipo_elemento);
  void fijarTamano(int tamano);
  void fijarUnidadMedida(string unidad_medida);
  void fijarCoordenada_x(int coordenada_x);
  void fijarCoordenada_y(int coordenada_y);
  bool operator==(const Elemento &elem) const;
  string toString();

  // Getters
  string obtenerTipoElemento();
  int obtenerTamano();
  string obtenerUnidadmedida();
  int obtenerCoordenada_x();
  int obtenerCoordenada_y();
};

class Movimiento {
private:
  string tipo_movimiento;
  float magnitud;
  string unidad_medida;

public:
  void fijarTipo_movimiento(string tipo_movimiento);
  void fijarMagnitud(float magnitud);
  void fijarUnidadMedida(string unidad_medida);

  // Getters
  string obtenerTipo_movimiento();
  float obtenerMagnitud();
  string obtenerUnidadMedida();
};

class Analisis {
private:
  // instruccion
  string tipo_analisis;
  string objeto;
  string comentario;

public:
  void fijarTipo_analisis(string tipo_analisis);
  void fijarObjeto(string objeto);
  void fijarComentario(string comentario);

  // Getters
  string obtenerTipo_analisis();
  string obtenerObjeto();
  string obtenerComentario();
};

class Curiosity {
private:
  list<Elemento> elementos;
  list<Movimiento> listaMovimientos;
  list<Analisis> listaAnalisis;

public:
  // Setters
  void fijarElementos(const list<Elemento> &newElementos);
  void fijarListaMovimientos(const list<Movimiento> &newListaMovimientos);
  void fijarListaAnalisis(const list<Analisis> &newListaAnalisis);

  // Getters
  list<Elemento> obtenerElementos();
  list<Movimiento> obtenerListaMovimientos();
  list<Analisis> obtenerListaAnalisis();
  list<Elemento>::iterator getElementoBegin();
  list<Elemento>::iterator getElementoEnd();
  list<Analisis>::iterator getAnalisisBegin();
  list<Analisis>::iterator getAnalisisEnd();
  list<Movimiento>::iterator getMovimientoBegin();
  list<Movimiento>::iterator getMovimientoEnd();
  //Métodos
  void agregarElemento(Elemento auxEle);
  void agregarMovimiento(Movimiento auxMov);
  void agregarAnalisis(Analisis auxAna);
};
//Clase Rectangulo, utilizada para representar cada elemento y cuadrante
class Rectangulo{
    private:
    int xmin, xmax, ymin, ymax;
    string tipo;
    public:
    Rectangulo(int x1, int x2, int y1, int y2, string t);//Constructor
    //Setters
    void fijarXmin(int x1);
    void fijarXmax(int x2);
    void fijarYmin(int y1);
    void fijarYmax(int y2);
    void fijarTipo(string t);
    //Getters
    int obtenerXmin();
    int obtenerXmax();
    int obtenerYmin();
    int obtenerYmax();
    string obtenerTipo();
    bool intersecta(const Rectangulo& o);//Función que determina si dos rectángulos se intersectan
    bool contiene(const Rectangulo& o);//Función que determina si un rectángulo contiene a otro
};

//Clase nodo, utilizada por el KDTree
class Nodo{
    private:
    Rectangulo *obstaculo;//Obstaculo que contiene el nodo(Roca, duna, etc)
    Nodo *izq, *der;
    public:
    Nodo(Rectangulo *o);//Constructor
    ~Nodo();//Destructor
    //Setters
    void fijarObstaculo(Rectangulo *o);
    void fijarIzq(Nodo *nodo);
    void fijarDer(Nodo *nodo);
    //Getters
    Rectangulo *obtenerObstaculo();
    Nodo *obtenerIzq();
    Nodo *obtenerDer();
    Nodo *&obtenerIzqRef();//Referencia al puntero izquierdo, utilizada para modificar el puntero en la función de insertar del KDTree
    Nodo *&obtenerDerRef();

};

//Clase KDTree
class KDTree{
    private:
    Nodo*raiz;
    bool insertar(Rectangulo *o, Nodo *&nodo, bool eje);//Función recursiva que inserta un rectángulo en el KDTree
    bool buscar(Nodo *nodo, Rectangulo *rect, bool &hayUno);//Función recursiva que busca un rectángulo dentro de otro rectangulo
    public:
    KDTree();//Constructor
    ~KDTree();//Destructor
    void fijarRaiz(Nodo *nodo);//Setter
    Nodo *obtenerRaiz();//Getter
    bool insertar(Rectangulo *o);//Función pública que llama a la función recursiva de insertar
    bool buscar(Rectangulo *rect);//Función pública que llama a la función recursiva de buscar
    bool vacio();//Función que determina si el KDTree está vacío
};

class Vertice {
  private:
    Elemento* elemento;
    bool marcado = false;

  public:
    Vertice();
    Vertice(Elemento* elem);
    Elemento* getElemento();
    void marcar();
    void desmarcar();
    bool estaMarcado();
};

class Grafo {
  using Arista = pair<float, int>; //* el priemro se refiere al coste y el segundo al vértice destino
    
  private:
      list<Vertice> vertices; //* la posición en la lista corresponde al número de vértice.
      list<set<Arista>> aristas;
      
  public:
      Grafo();

      //* Retorna la información de Tipo T almacenada en el vértice
      Elemento* InfoVertice(int v);
      
      //* Obtener el id de un vertice dado
      int idVertice(Elemento v);

      //* Agregar vértice v al final de la lista de vértices con Infovertice de tipo T.
      void InsVertice(Elemento* v);
      
      //* Ver si un elemento dado ya existe en  el grafo
      bool existeVertice(Elemento v);

      //* inserta un arco con costo c entre los vértices v1 y v2
      bool InsArco(int v1, int v2, float c);

      //* Elimina el arco entre los vértices v1 y v2
      void ElimArco(int v1, int v2);

      //* Marca el vértice v
      void MarcarVertice(int v);
      
      //* Desmarca el vértice v
      void DesmarcarVertice(int v);

      //* Desmarca todos los vértices del grafo
      void DesmarcarGrafo();
      
      //* Retorna true si el vértice v está marcado, false en caso contrario
      bool MarcadoVertice(int v);

      //* Retorna el número de vértices que tiene el grafo
      int OrdenGrafo() const;

      //* Retorna el costo del arco existente entre v1 y v2. Sino existe un arco entre los dos vértices retorna -1
      float CostoArco(int v1, int v2);
      
      //* Retorna una lista con los vértices del grafo. Cada ver de la lista tiene la información (tipo T) de cada vértice
      list<Elemento*> getVertices();

      //* Retorna la lista enteros con los sucesores del vértice v1
      list<int> sucesores(int v) ;

      //* Borra la información almacenada en el grafo
      void borrar();
};

#endif