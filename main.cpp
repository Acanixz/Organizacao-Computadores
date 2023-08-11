#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// Armazena informações geradas pelo binary dump
struct LinhaASM{
    string instrucao;
    string opcode;
    string rd;
    string funct3;
    string rs1;
    string rs2;
    string funct7;
};

// Uma organização, utilizado para gerar estatisticas com um vetor de LinhaASM
struct Organizacao{
    int clock;
    map<string, int> quantCiclos; // Quantos ciclos leva cada instrução?

    Organizacao() {
        quantCiclos["U"] = 10;
        quantCiclos["J"] = 10;
        quantCiclos["B"] = 10;
        quantCiclos["I_ar"] = 10; // Quant. Ciclos p/ instrução Imm. Aritmetico
        quantCiclos["I_lo"] = 10; // Quant. Ciclos p/ instrução Imm. Load
        quantCiclos["R"] = 10;
        quantCiclos["S"] = 10;
    }
};

// Resultados de desempenho da organização com um binary dump
struct Resultados{
    int CPI; // Ciclos por instrução
    int Texec; // Tempo de execução (Quant. instrucoes * CPI * Clock)
};

// Abre o arquivo, redundante, mas quem sabe
// ganha um proposito melhor depois
bool abrirArquivo(ifstream &saida, string caminho){
    saida.open(caminho);
    if (saida.is_open()){
        return true;
    }
    cout << "Nao foi possivel abrir o arquivo: " << caminho << endl;
    return false;
}

// Recebe um ifstream para ler e gera um vetor
// cada indice do vetor representa uma instrução de 32 bits
vector<LinhaASM> lerArquivo(ifstream &arquivo){
    vector<LinhaASM> instrucoes;

    if (!arquivo.is_open()){
        throw std::runtime_error("Abra o arquivo antes de tentar ler!");
    }
    
    int i = 0;
    while (arquivo.good()){
        i++;
        LinhaASM linhaAtual;
        arquivo >> linhaAtual.instrucao;

        if (linhaAtual.instrucao.size() != 32){
            if (arquivo.good()){
                // alguma linha não está certa
                throw std::runtime_error("Nao foi possivel ler a linha " + to_string(i) + ", verifique o arquivo.");
            } else {
                // newline final, só ignorar
                continue;
            }
        }
        
        // obs: a ordem dos numeros é o inverso do site
        // https://jemu.oscc.cc/ADD
        // (site vai da direita pra esquerda, aqui é esq. pra dir.)
        linhaAtual.opcode = linhaAtual.instrucao.substr(25, 7);
        linhaAtual.rd = linhaAtual.instrucao.substr(20, 5);
        linhaAtual.funct3 = linhaAtual.instrucao.substr(17, 3);
        linhaAtual.rs1 = linhaAtual.instrucao.substr(12, 5);
        linhaAtual.rs2 = linhaAtual.instrucao.substr(7, 5);
        linhaAtual.funct7 = linhaAtual.instrucao.substr(0, 7);
        // se tudo deu certo, pode colocar no array
        instrucoes.push_back(linhaAtual);
    }
    

    return instrucoes;
}

int main(){
    Organizacao orgA;
    cout << orgA.quantCiclos["S"] << endl;

    ifstream progA;
    abrirArquivo(progA, "binary_dump");
    vector<LinhaASM> instrucoes = lerArquivo(progA);

    for (int i = 0; i < instrucoes.size(); i++){
        cout << "INSTRUCAO " << i+1 << " completa: " << instrucoes[i].instrucao << endl;
        cout << "INSTRUCAO " << i+1 << " separada: " 
        << instrucoes[i].funct7 << " "
        << instrucoes[i].rs2  << " "
        << instrucoes[i].rs1  << " "
        << instrucoes[i].funct3  << " "
        << instrucoes[i].rd  << " "
        << instrucoes[i].opcode
        << endl;
    }

    return 0;
}