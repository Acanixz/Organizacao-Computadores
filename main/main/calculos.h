/*
* Disciplina: Organização de Computadores
* Atividade : Avaliação 02
*
* Grupo:
* - Cassiano de Sena Crispim
* - Hérick Vitor Vieira Bittencourt
* - Eduardo Miguel Fuchs Perez
*
* OBSERVAÇÃO:
* - Devido o uso de for loops com lógica [key, value], o padrão ISO para
* este projeto deve ser o C++ 17, caso contrário a build irá falhar
* (vá na aba projeto->propriedades de main no visual studio 2019)
*/

#ifndef CALCULOS_H
#define CALCULOS_H

#include <iostream>
#include <fstream>

using namespace std;

// Calculos feitos a partir da tabela de formulas disponivel no AVA

float gerarDesempenho(float tempoExecucao) {
	return 1.0 / tempoExecucao;
}

// Cout dos dois métodos de comparação de desempenho
void responderDesempenho(float resultado) {
	cout << "----------------------" << endl;
	cout << "RESULTADO DA COMPARACAO: " << resultado << endl;
	float porcentagem1 = (resultado - 1) * 100;
	float porcentagem2 = resultado * 100;
	if (resultado > 1) {
		cout << "Arquitetura A possui " << (resultado-1) <<  "X (" << porcentagem1 << "%) a mais de desempenho do que Arquitetura B" << endl;
		cout << "Enquanto a arquitetura B eh " << (resultado - 1) << "X (" << porcentagem1 << "%) mais lenta" << endl;
		return;
	}
	if (resultado < 1) {
		cout << "Arquitetura A possui apenas " << resultado << "X (" << porcentagem2 << "%) do desempenho da Arquitetura B" << endl;
		cout << "Enquanto a arquitetura B possui " << (1-resultado) << "X (" << -porcentagem1 << "%) a mais de desempenho do que arquitetura A" << endl;
		return;
	}

	cout << "Arquitetura A e B possuem o mesmo desempenho para este programa!" << endl;
	cout << "----------------------" << endl << endl;
	return;
}

// Comparação de desempenho por desempenho
// Formula = desempenhoX / desempenhoY
float compararDesempenhoPorDesempenho(float desempenhoX, float desempenhoY) {
	float resultado = desempenhoX / desempenhoY;
	responderDesempenho(resultado);
	return resultado;
}

// Comparação de desempenho por tempo de execução
// Formula = tempoExecY / tempoExecX
float compararDesempenhoPorTempoExec(float tempoExecucaoX, float tempoExecucaoY) {
	float resultado = tempoExecucaoY / tempoExecucaoX;
	responderDesempenho(resultado);
	return resultado;
}

// Retorna os ciclos da CPU
// Formula = quantInstrucoes * CPI
float gerarCiclosCPU(int quantInstrucoes, float CPI) {
	return quantInstrucoes * CPI;
}

// Tempo de execução da CPU por tempo de clock
// Formula = QuantInstrucoes * CPI * TempoClock
// OBS: CiclosCPU = QuantInstrucoes * CPI
float TExecCPUPorTempoClock(int quantInstrucoes, float CPI, float tempoClock) {
	return quantInstrucoes * CPI * tempoClock;
}

// Tempo de execução da CPU por frequencia de clock
// Formula = (quantInstrucoes * CPI) / FreqClock
// OBS: CiclosCPU = QuantInstrucoes * CPI
float TExecCPUPorFreqClock(int quantInstrucoes, float CPI, float freqClock) {
	return (quantInstrucoes * CPI) / freqClock;
}

// Taxa de execução das instruções
// Formula = I / TExecCPU
float taxaExecInstrucoes(int quantInstrucoes, float TExecCPU) {
	return quantInstrucoes / TExecCPU;
}

// Ciclos-Por-Instrução
// Formula = CiclosCPU / quantInstrucoes
// EXPERIMENTAL, TALVEZ NÃO ESTEJA CERTO
// (variação da formula de ciclosCPU)
float gerarCPI(float ciclosCPU, int quantInstrucoes) {
	return ciclosCPU / quantInstrucoes;
}

/*
* Náo há porque gerar o tempo médio ainda
* pois há apenas um programa, só pegar o TExecCPU
float gerarTMedioExecucao(){

}
*/

#endif // CALCULOS_H