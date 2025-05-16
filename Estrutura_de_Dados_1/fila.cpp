/**/

#include <iostream>
#include <stdio.h>
#define tam 10
using namespace std;

class Fila{
    string n1;
    string v[tam];
    int qtd;
    
    public:
    
    Fila(){
        for(int i=0; i<10; i++){
            v[i] = "";
        }
        this->qtd = 0;
    }
    
    Fila(string nome){
        
        for(int i=0; i<10; i++){
            v[i] = "";
        }
        
        this->add(nome);
        this->qtd = 1;
    }
    
    void add(string nome){
        if(qtd == sizeof(v)/sizeof(v[0])){
            cout << "Fila cheia\n" << nome << " não adicionado\n" << endl;
        }
        else{
        v[qtd] = nome;
        qtd++;
        }
    }
    
    void olhar(){
        int i=0;
        while(i!=qtd){
               cout << v[i] << endl;
               i++;
            }
    }
    
    string andar(){
        
        if(qtd!=0){
        int i=1;
        string sai = v[0];
        
            cout << "\n\nFila após o andamento: \n" << endl;
            while(v[i] != "" && i==qtd-1){
                v[i-1] = v[i];
                i++;
            }
            v[qtd - 1] = "";
            qtd--;
            return sai;
        }
        else{
            cout << "Pilha vazia" << endl;
            return "";
        }
    }
};

int main(){
    
    Fila fila;
    fila.add("jorge");
    fila.add("thiaguinho");
    fila.add("caio");
    fila.add("felipe");
    fila.add("raissa");
    fila.add("a");
    fila.add("b");
    fila.add("c");
    fila.add("d");
    fila.add("e");
    fila.add("f");
    
    fila.olhar();
    string pessoa = fila.andar();
    fila.olhar();
    cout << "\n\nPessoa que saiu: " << pessoa << endl;
    return 0;
}
