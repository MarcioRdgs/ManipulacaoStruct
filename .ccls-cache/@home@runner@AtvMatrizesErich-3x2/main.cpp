/* 
Titulo: Manipulação de Struct
Autor: Prof. Berssa
Data: 11/10/2024
*/

// Espaço reservado para declaração de bibliotecas
#include <iostream>
#include <limits>  
#include <iomanip>

using namespace std;

//Espaço reservado para construção de Structs
struct Pessoa{
  int codigo;
  string nome;
  float altura;
};

//Espaço reservado para prototipação de funções
int menu();
int lerCodigoValido(const string &mensagem);
void limparBuffer();
void exibirMsgErro(const string &mensagem);
void mostrarArray(Pessoa array[], int tamanho);
void esperarEnter();
void ZerarArray(Pessoa array[], int tamanho);


//Função principal
int main() {
  const int TAMANH0 = 5; //Define o tamanho do array de pessoas
  Pessoa array[TAMANHO]; //Declara o array para armazenar TAMANHO registros de pessoas
  int opcao;

  do {
    opcao = menu();
    switch(opcao){
      case 1: mosrtarArray(array, TAMANHO); break;
      case 2: zerarArray(array, TAMANHO); break;
      case 3: cout<<"Preenche Array"; break;
      case 4: cout<<"Editar Array"; break;
      case 5: cout<<"Verificar"; break;
      case 6: cout<<"Ordenar"; break;
      case 0: cout<<"Encerrando o programa..."<<endl; break;
      default: exibirMsgErro("Opção inválida! Escolha uma Opção válida!");
    }
    
  }while(opcao != 0);
  return 0;
};

//Função para exibir mensagem de Erro
void exibirMSgErro(const string &mensagem){
  cout<<mensagem<<endl;
}

//Função para mostrar o array de Pessoas
void mostrarArray(Pessoa array[], int tamanho){
  cout<<left<<setw(10)<<"Código"<<"\t"
      <<left<<setw(20)<<"Nome"<<"\t"
      <<left<<setw(10)<<"Altura"<<endl;
  cout<<string(50, '-')<<endl;
  for(int i = 0; i < tamanho; i++){
    cout<<left<<setw(10)<<array[i].codigo<<"\t"
        <<left<<setw(20)<<array[i].nome<<"\t"
        <<left<<setw(10)<<array[i].altura<<endl;
  }
  esperarEnter();
}

//Função para esperar o usuário pressionar Enter
void esperarEnter(){
  cout<<"\nPressione Enter para continuar..."<<endl;
  cin.get();
}

//Função para zerar o array de pessoas
void zerarArray(Pessoa array[], int tamanho){
  for(int i=0; i<tamanho; i++){
    array[i].codigo = 0;
    array[i].nome = "";
    array[i].altura = 0.0;
  }
  cout<<"Array de pessoas zerado!";
  esperarEnter();
}

//Função para preencher array de pessoas
void preencherArray(Pessoa array[], int tamanho){
  for(int i=0; i<tamanho; i++){
    array[i].codigo = lerCodigoValido("Digite o código da pessoa: ["+to_string(i)+"]: ");
    array[i].nome = lerStringValida("Digite o nome da pessoa: ["+to_string(i)+"]: ");
    array[i].altura = lerAlturaValida("Digite a altura da pessoa: ["+to_string(i)+"]: ");
    cout<<"Array de pessoas preenchido com sucesso!"<<endl; 
  }
  esperarEnter();
}

//Função para ler uma string válida
string lerStringValida(const string &mensagem){
  string entrada;
  cout<<mensagem;
  getline(cin, entrada);
  return entrada;
}

//Função para ler altura válida
float lerAlturaValida(const string &mensagem){
  float altura;
  while(true){
    cout<<mensagem;
    cin>>altura;
    if(cin.fail() || altura <= 0){
      limparBuffer();
      exibirMsgErro("Entrada inválida! Digite uma altura válida.");
    }else{
      limparBuffer();
      return altura;
    }
  }
}