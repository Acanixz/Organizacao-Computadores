#ifndef CALCULOS_H
#define CALCULOS_H

#include <iostream>
#include <fstream>

using namespace std;


//Para melhorar o desempenho da CPU
//Reduzir o numero de ciclos para a execu??o do programa ou
//Reduzir o tempo do ciclo de clock(período do clock), ou 
//seja, aumentar a frequ?ncia do clock

// Calcula o tempo/frequencia do clock
float clock(float tempo){
	float clock = 1 / tempo;
	return clock;
}

// Calcula as instrucoes
// Nao terminei
int instrucoes(){
	int instrucoes;
	return instrucoes;
}

// Calcula a quantidade de ciclos por instrucao
// Nao terminei
float ciclosPorInstrucao() {
	float ciclosPorInstrucao;
	return ciclosPorInstrucao;
}

// Calcula os ciclos da CPU a partir das qtde de instrucoes e da CPI
// CCPU = I * CPI
float ciclosDaCPU(int instrucoes, float ciclosPorInstrucao) {
	float ciclosDaCPU = instrucoes * ciclosPorInstrucao;
	return ciclosDaCPU;
}


//** DESEMPENHO **//
//**			**// 
// Calcula o Desempenho individual
// Desempenho = 1 / TCPU
float desempenho(float tempoDeExecucaoCPU) {
	float desempenho = 1 / tempoDeExecucaoCPU;
	return desempenho;
}

// Calcula o Desempenho por comparacao de duas organizacoes
float desempenhoComparativo(float tempoDeExecucaoCPUX, float tempoDeExecucaoCPUY) {
	float desempenhoComparativo = tempoDeExecucaoCPUY / tempoDeExecucaoCPUX;
	return desempenhoComparativo;
}


//**  TEMPO DE EXECUCAO DA CPU  **//
//**							**// 
// Calcula o tempo de execu??o da CPU a partir de instrucoes, ciclos e clock
// TCPU = I * CPI * Tclock
float tempoDeExecucaoCPU(float instrucoes, float ciclosCPU, float tempoClock) {
	float tempoDeExecucaoCPU = instrucoes * ciclosCPU * tempoClock;
	return tempoDeExecucaoCPU;
}

// Calcula o tempo de execu??o da CPU por tempo de clock
float tempoDeExecucaoCPUTempoClock(float ciclosCPU, float tempoClock){
	float tempoDeExecucaoCPU = ciclosCPU * tempoClock;
	return tempoDeExecucaoCPU;
}

// Calcula o tempo de execu??o da CPU por frequencia de clock
float tempoDeExecucaoCPUFrequenciaClock(float ciclosCPU, float frequenciaClock) {
	float tempoDeExecucaoCPU = ciclosCPU / frequenciaClock;
	return tempoDeExecucaoCPU;
}



//** TAXA DE EXECUCAO DE INSTRUCOES **//
//**								**// 
// Calcula a taxa de execu??o de instrucoes
float taxaDeExecInstrucoes(int instrucoes, float tempoDeExecucaoCPU) {
	float taxaDeExecInstrucoes = instrucoes / tempoDeExecucaoCPU;
	return taxaDeExecInstrucoes;
}
// Calcula a taxa de execu??o de instrucoes pelo CPI
// 1 / (CPI * Tclock)
float taxaDeExecInstrucoesCPI(float tempoClock, float ciclosPorInstrucao) {
	float taxaDeExecInstrucoes = 1 / (tempoClock * ciclosPorInstrucao);
	return taxaDeExecInstrucoes;
}
// Calcula a taxa de execu??o de instrucoes pela frequencia de clock
// Fclock / CPI
float taxaDeExecInstrucoesFrequencia(float frequenciaClock, float ciclosPorInstrucao) {
	float taxaDeExecInstrucoes = frequenciaClock / ciclosPorInstrucao;
	return taxaDeExecInstrucoes;
}

//**   TEMPO MEDIO DE EXECUCAO  **//
//**							**// 
// Calcula a taxa de execu??o de instrucoes pela frequencia de clock
// Nao terminei
float tempoMedioExecucao(float tempoDeExecucao) {
	float tempoMedioExecucao;
	return tempoMedioExecucao;
}


//** ACELERACAO **//
//**			**// 
// Calcula a aceleracao de desempenho
float aceleracao(float tempoDeExecucaoOld, float tempoDeExecucaoNew) {
	float aceleracao = tempoDeExecucaoOld / tempoDeExecucaoNew;
	return aceleracao;
}

#endif // CALCULOS_H