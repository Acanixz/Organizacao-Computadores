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
	cout << "RESULTADO: " << resultado << endl;
	float porcentagem1 = (resultado - 1) * 100;

	float porcentagem2 = 100 - porcentagem1;
	float porcentagem3 = 100 + porcentagem1;
	if (resultado > 1) {
		cout << "Arquitetura X possui " << porcentagem1 << "% a mais de desempenho do que Arquitetura B" << endl;
		cout << "Enquanto a arquitetura B possui apenas " << porcentagem2 << "% do desempenho da arquitetura A" << endl;
		return;
	}
	if (resultado < 1) {
		cout << "Arquitetura X possui apenas " << porcentagem3 << "% do desempenho da Arquitetura B" << endl;
		cout << "Enquanto a arquitetura B possui " << -porcentagem1 << "% a mais de desempenho do que arquitetura A" << endl;
		return;
	}

	cout << "Arquitetura X e Y possuem o mesmo desempenho para este programa!" << endl;
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

/* Taxa de execução das instruções
* ainda não utilizado, então vamos deixar aqui pra caso a M2 precise
* É MUITA FORMULA AAAAA
float taxaExecInstrucoes() {

}
*/

// Ciclos-Por-Instrução
// Formula = CiclosCPU / quantInstrucoes
// EXPERIMENTAL, TALVEZ NÃO ESTEJA CERTO
// (variação da formula de ciclosCPU)
float gerarCPI(float ciclosCPU, int quantInstrucoes) {
	return ciclosCPU / quantInstrucoes;
}

/*
* também ainda não utilizado
float TMedioExecucao(){

}
*/

#endif // CALCULOS_H