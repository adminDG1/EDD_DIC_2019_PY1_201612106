
class NodoArbol
{

private:
    PlayList *playlist;
    NodoArbol *izquierdo;
    NodoArbol *derecho;


public:

NodoArbol(PlayList playlist_)
{
    playlist = playlist_;
    izquierdo = 0;
    derecho = 0;

}

PlayList *getPlayList(){return playlist;};
void setPlayList(PlayList playlist_){playlist = playlist_};
NodoArbol *getIzquierdo(){return izquierdo;};
NodoArbol *getDerecho(){return derecho;};
void setIzquierdo(NodoArbol *nodo){izquierdo = nodo;};
void setDerecho(NodoArbol *nodo){derecho = nodo;};

NodoArbo *insertarNodo(int entrada,NodoArbo *raiz)
{
 if(entrada < raiz)
 {
     return insertarNodo(entrada, raiz->izquierda);

 } else
 {
     return insertarNodo(entrada, raiz->derecha);
 }

}

};

class ArbolB
{


};
