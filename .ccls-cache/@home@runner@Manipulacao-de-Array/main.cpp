/* 
Titulo: Manipulação de Struct
Autor: Prof. Berssa
Data: 11/10/2024
*/

// Espaço reservado para declaração de bibliotecas
#include <iostream>
#include <limits>  
#include <iomanip>
#include <string>


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
void zerarArray(Pessoa array[], int tamanho);
void preencherArray(Pessoa array[], int tamanho);
string lerStringValida(const string &mensagem);
float lerAlturaValida(const string &mensagem);


//Função principal
int main() {
  const int TAMANH0 = 2; //Define o tamanho do array de pessoas
  Pessoa array[TAMANHO]; //Declara o array para armazenar TAMANHO registros de pessoas
  int opcao;

  do {
    opcao = menu();
    switch(opcao){
      case 1: mosrtarArray(array, TAMANHO); break;
      case 2: zerarArray(array, TAMANHO); break;
      case 3: preencherArray(array, int TAMANHO); break;
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
  }
  cout<<"\nArray de pessoas preenchido com sucesso!"<<endl; 
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

//Função para editar pessoa especifica no array
void editarArray(Pessoa array[], int tamanho){
  int posicao = lerCodigoValido("Digite a posição que deseja editar (0 a "+to_string(tamanho-1)+"): ");
  while(posicao < 0 || posicao >= tamanho){
    exibirMsgErro("Posição inválida! Tente novamente.");
    posicao = lerCodigoValido("Digite uma posição válida: ");
  }
  array[posicao].codigo = lerCodigoValido("Digite o novo código para a posição ["+to_string(posicao)+"]: ");
  limparBuffer();
  array[posicao].nome = lerStringValida("Digite o novo nome da pessoa ["+to_string(posicao)+"]: ");
  array[posicao].altura = lerAlturaValida("Digite a nova altura da pessoa ["+to_string(posicao)+"]: ");
  cout<<"Pessoa Editada com Sucesso!";
  esperarEnter;
}

//Função para verificar pessoa no array
void verificarArray(Pessoa array[], int tamanho){
  int codigo = lerCodigoValido("Digite o código da pessoa que deseja verificar: ");
  bool encontrado = false;
  for(int i=0; i<tamanho; i++){
    if(array[i].codigo == codigo){
      cout<<"Pessoa com o código "<<codigo<<" encontrada na posição"<<endl;
      cout<<"Nome: "<<array[i].nome<<endl;
      cout<<"Altura: "<<array[i].altura<<endl;
      encontrado = true;
      break;
    }
  }
  if(!encontrado){
    cout<<"Pessoa com o código "<<codigo<<" não encontrada no array."<<endl;
  }
  esperarEnter();
}

//Função para ordenar array de pessoas por código
void ordenarArray(Pessoa array[], int tamanho){
  sort(array, array+tamanho, [](Pessoa a, Pessoa b){
    return a.codigo < b.codigo;
  });
cout<<"Array de pessoas ordenado por código!"<<endl;
  esperarEnter();
}