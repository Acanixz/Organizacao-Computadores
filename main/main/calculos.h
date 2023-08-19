#ifndef CALCULOS_H
#define CALCULOS_H

#include <iostream>
#include <fstream>

using namespace std;


//Para melhorar o desempenho da CPU
//Reduzir o numero de ciclos para a execu??o do programa ou
//Reduzir o tempo do ciclo de clock(periodo do clock), ou 
//seja, aumentar a frequ?ncia do clock

// Calcula o frequencia do clock
float freqClock(float tempoClock) {
	float clock = 1 / tempoClock;
	return clock;
}

// ------ REVISAR ------
// Calcula as instrucoes
// I = CPI * CCPU
float instrucoes(float ciclosPorInstrucao, float ciclosDaCPU) {
	float instrucoes = ciclosPorInstrucao * ciclosDaCPU;
	return instrucoes;
}

// ------ REVISAR ------
// Calcula a quantidade de ciclos por instrucao
// CPI = CCPU / I
float ciclosPorInstrucao(float quantInstrucoes, float ciclosDaCPU) {
	float ciclosPorInstrucao = ciclosDaCPU / quantInstrucoes;
	return ciclosPorInstrucao;
}

// Calcula os ciclos da CPU a partir das qtde de instrucoes e da CPI
// CCPU = I * CPI
float ciclosDaCPU(float quantInstrucoes, float ciclosPorInstrucao) {
	float ciclosDaCPU = quantInstrucoes * ciclosPorInstrucao;
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
float tempoDeExecucaoCPU(float quantInstrucoes, float ciclosCPU, float tempoClock) {
	float tempoDeExecucaoCPU = quantInstrucoes * ciclosCPU * tempoClock;
	return tempoDeExecucaoCPU;
}

// Calcula o tempo de execu??o da CPU por tempo de clock
float tempoDeExecucaoCPUTempoClock(float ciclosCPU, float tempoClock) {
	float tempoDeExecucaoCPU = ciclosCPU * tempoClock;
	return tempoDeExecucaoCPU;
}

// Calcula o tempo de execu??o da CPU por frequencia de clock
float tempoDeExecucaoCPUFrequenciaClock(float ciclosCPU, float frequenciaClock) {
	float tempoDeExecucaoCPU = ciclosCPU / frequenciaClock;
	return tempoDeExecucaoCPU;
}

// Calcula o novo tempo de execucao a partir do tempo de execucao antigo, parcelas e aceleracao
// TexecN = TexecV * ( Pnu + ( Pu / Au ) )
float tempoDeExecucaoNovo(float tempoDeExecucaoVelho, float parcelaUsada, float parcelaNaoUsada, float aceleracaoUsada) {
	float parcelaUsadaNumero = parcelaUsada / 100;
	float parcelaNaoUsadaNumero = parcelaNaoUsada / 100;
	// dividir parcelas por 100 pra tirar da porcentagem
	float tempoDeExecucaoNovo = tempoDeExecucaoVelho * (parcelaNaoUsadaNumero * (parcelaUsadaNumero / aceleracaoUsada));
	//float tempoDeExecucaoNovo = tempoDeExecucaoVelho * (parcelaNaoUsada * (parcelaUsada / aceleracaoUsada));
	return tempoDeExecucaoNovo;
}



//** TAXA DE EXECUCAO DE INSTRUCOES **//
//**								**// 
// Calcula a taxa de execu??o de instrucoes
float taxaDeExecInstrucoes(float instrucoes, float tempoDeExecucaoCPU) {
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
//float tempoMedioExecucao(float tempoDeExecucao) {
	///*programa*/ int i = 1;
	///*frequencia*/ int n = 1;
	//float tempoMedioExecucao = 1 / n * tempoDeExecucao;
	//return tempoMedioExecucao;
//}

//float tempoDeExecucao() {
//}

//** ACELERACAO **//
//**			**// 
// Calcula a aceleracao de desempenho
float aceleracao(float tempoDeExecucaoVelho, float tempoDeExecucaoNovo) {
	float aceleracao = tempoDeExecucaoVelho / tempoDeExecucaoNovo;
	return aceleracao;
}

// ------ REVISAR ------
// Calcula a aceleracao de desempenho a partir da parcela
// Nao terminei
float aceleracaoParcela(float tempoDeExecucaoVelho, float tempoDeExecucaoNovo, float parcelaUsada, float parcelaNaoUsada, float aceleracaoUsada) {
	float aceleracao = tempoDeExecucaoVelho / tempoDeExecucaoNovo;
	return aceleracao;
}

#endif // CALCULOS_H