#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "windows.h"
#include "math.h"

void maxHeapfy(int *v, int i, int tamH){
	int l = 2*i;
	int r = 2*i+1;
	int maior;
	int aux;
	if (l<=tamH &&v[l]>v[i]){
		maior=l;
	}else{
		maior=i;
	}
	if(r<=tamH&&v[r]>v[maior]){
		maior=r;
	}
	if(maior!=i){
		aux=v[i];
		v[i]=v[maior];
		v[maior]=aux;
		maxHeapfy(v,maior,tamH);
	}
}

void buildMaxHeap(int *v, int tam){
	int tamH = tam;
	int i;
	for(i=tam/2;i>=1;i--){
		maxHeapfy(v,i,tamH);
	}
}

void heapsort(int *v, int tam){
	buildMaxHeap(v,tam);
	int i,aux,tamH;
	tamH=tam;
	for(i=tam;i>=2;i--){
		aux=v[0];
		v[0]=v[i];
		v[i]=aux;
		tamH=tamH-1;
		maxHeapfy(v,i,tamH);
	}
}

void merge(int v[], int n) {
  int mid;
  int i, j, k;
  int* tmp;
 
  tmp = (int*) malloc(n * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = n / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < n) {
    if (v[i] <= v[j]) {
      tmp[k] = v[i++];
    }
    else {
      tmp[k] = v[j++];
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < n) {
      tmp[k++] = v[j++];
    }
  }
  else {
    while (i < mid) {
      tmp[k++] = v[i++];
 
    }
  }
 
  for (i = 0; i < n; ++i) {
    v[i] = tmp[i];
  }
 
  free(tmp);
}
 
void mergeSort(int v[], int n) {
  int mid;
 
  if (n > 1) {
    mid = n / 2;
    mergeSort(v, mid);
    mergeSort(v + mid, n - mid);
    merge(v, n);
  }
}

void quicksort (int n, int *v)
{
	if(n > 1)
	{
		int x = v[0];
		int a = 1;
		int b = n - 1;
		while(1)
		{
			while(a < n && v[a] <= x) a++;
			while(v[b] > x) b--;
			if(a < b)
			{
				int temp = v[a];
				v[a] = v[b];
				v[b] = temp;
				a++;
				b--;
			}
			else
				break;
		}
		v[0] = v[b];
		v[b] = x;
		quicksort(b, v);
		quicksort(n - a, &v[a]);
	}
}

int main (){

	//Declaração das variáveis
	int opcao, num, cont;
	 int n;
	


	//Declaração de contadores
	double time1, time2, time3, time4, time5;
	LARGE_INTEGER tempoInicial, tempoFinal, freq;

	//Verificador
	int verifica, opc;
	opc = 0;

	//Usuario insere o tamanho do vetor
	

	printf("Digite um valor N: ");
	scanf("%d", & n);

printf("foi até aqui");

	//Declaração de vetores
	//int vet[n], vetB[n], vetI[n], vetQ[n], vetH[n], vetM[n];
	int *vet= (int*) malloc(n * sizeof(int));
	int *vetB= (int*) malloc(n * sizeof(int));
	int *vetI= (int*) malloc(n * sizeof(int));
	int *vetQ= (int*) malloc(n * sizeof(int));
	int *vetH= (int*) malloc(n * sizeof(int));
	int *vetM= (int*) malloc(n * sizeof(int));
	
printf("foi até aqui");
	//Loop principal
	do
	{
		do
		{
			//Menu
			system("cls");
			printf("	SEMPRE GERE OS DADOS ANTES DE REALIZAR AS ORDENAÇOES:");
			printf("\n	Menu:");
			printf("\n\n    1. Gerar dados");
			printf("\n    2. Bubble sort");
			printf("\n    3. Quick sort");
			printf("\n    4. Insertion sort");
			printf("\n    5. Merge sort");
			printf("\n    6. Heap sort");
			printf("\n    7. SAIR");
			printf("\n\nOpcao: ");
			scanf("%d", & opcao);

		}
		while(opcao < 0 || opcao > 8);    //Obriga o usuario a escolher uma das opções
		if(opcao != 7)
		{
			//Apenas questão de estilo, se o usuario entrar no menu, limpa a tela
			system("cls");
		}
		
	

		switch(opcao)
		{
		case 1: //Gerar dados
			
			
			

			opc = 1;//Vetor desodernado gerado
			verifica = 0;
			srand(time(NULL));
			int a;
			
			for( cont = 0; cont < n; cont++)
			{
				do
				{
					//Gera valores aleatorios para inserir no vetor, entre 1 e N
					vet[cont] = rand() % n + 1;
					/*for(a = 0; a < cont; a++)
					{
						//Verifica se o valor gerado já está no vetor
						if(vet[a] == vet[cont])
						{
							verifica = 1;
							//Quebra o laço para gerar um novo numero
							break;
						}
						else
						{
							verifica = 0;
						}
					}*/
				}
				while(verifica == 1);   //Se o valor gerado já estiver no vetor vai repetir o processo
			}
			//Mostra o vetor desordenado
			verifica = 0;
			num = 0;
			verifica = 0;
			
			break;
		
		case 2: //Bubble sort

			
			if(opc)   //Verifica se o vetor desordenado foi gerado
			{
				verifica = 0;
				for(cont = 0; cont < n; cont++)
				{
					/*Para manter o vetor desordenado salvo,
					copia os valores para outro vetor que será ordenado*/
					vetB[cont] = vet[cont];
				}
				//Começa a contagem
				QueryPerformanceCounter( & tempoInicial);
				//Ordenação
				int i, j, temp, troca;
				for(i = n - 1; i > 0; i--)
				{
					troca = 0;
					for(j = 0; j < i; j++)
						if(vetB[j] > vetB[j + 1])
						{
							temp = vetB[j]; // Troca
							vetB[j] = vetB[j + 1];
							vetB[j + 1] = temp;
							troca = 1;
						}
					if(troca == 0)
					{
						break;
					}
					
				}

				QueryPerformanceCounter( & tempoFinal);
				QueryPerformanceFrequency( & freq);
				//Faz a conversão para segundos
				time1 = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart) / freq.QuadPart;

				printf("\n");
				//Multiplica por mil para mostrar o tempo em milissegundos
				printf("Tempo em milissegundos para terminar a ordenacao: %f ms ", time1 * 1000);
				system("pause");
			}
			
			break;
		case 3:
			if(opc)   //Verifica se o vetor desordenado foi gerado
			{
				verifica = 0;
				for(cont = 0; cont < n; cont++)
				{
					/*Para manter o vetor desordenado salvo,
					copia os valores para outro vetor que será ordenado*/
					vetQ[cont] = vet[cont];
				}
				//Começa a contagem
				QueryPerformanceCounter( & tempoInicial);
				//Ordenação
				quicksort(n, vetQ);
				QueryPerformanceCounter( & tempoFinal);
				QueryPerformanceFrequency( & freq);
				//Faz a conversão para segundos
				time2 = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart) / freq.QuadPart;

				printf("\n");
				//Multiplica por mil para mostrar o tempo em milissegundos
				printf("Tempo em milissegundos para terminar a ordenacao: %f ms para n elementos ", time2 * 1000);
				system("pause");
			}
				break;
			case 4: //Insertion sort
		
				//Verifica se foi gerado o vetor desordenado
				if(opc)
				{
					//Começa a contar o tempo
					QueryPerformanceCounter( & tempoInicial);
					//Ordena os dois primeiros valores
					if(vet[0] < vet[1])
					{
						vetI[0] = vet[0];
						vetI[1] = vet[1];
					}
					else
					{
						vetI[0] = vet[1];
						vetI[1] = vet[0];
					}
					//Ordenar os outros valores
					//vet = vetor desordenado
					//vetI = vetor ordenado
					int cont;
					int cont2 ;
					int cont3;
					for( cont = 2; cont < n; cont++)
					{
						//Introduzindo o elemento vet[cont] no vetI
						verifica = 1; //Considera vetI não ordenado

						// Verificando se algum dos elementos de vetI é maior que vet[cont]
						
						for(cont2= 0; cont2 < cont; cont2++)
						{
							if(vetI[cont2] > vet[cont])
							{
								//Jogando os elementos de vetI para frente
								for( cont3= cont; cont3 > cont2; cont3--)
									vetI[cont3] = vetI[cont3 - 1];
								//Inserindo vet[cont] em sua posição ordenada
								vetI[cont2] = vet[cont];
								verifica = 0; //Considerando vetI ordenado
								break;
							}
						}

						//Se nenhum elemento de vetI é maior que vet[cont]
						if(verifica == 1)
							vetI[cont] = vet[cont];
					}
					//Para de contar o tempo
					QueryPerformanceCounter( & tempoFinal);
					QueryPerformanceFrequency( & freq);
					//Faz a conversão para segundos
					time3 = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart) / freq.QuadPart;

					printf("\n");
					//Multiplica por mil para mostrar o tempo em milissegundos
					printf("Tempo em milissegundos para terminar a ordenacao: %f ms ", time3 * 1000);
					system("pause");
					break;
			case 5: //Merge sort
				if(opc)   //Verifica se o vetor desordenado foi gerado
			{
				verifica = 0;
				for(cont = 0; cont < n; cont++)
				{
					/*Para manter o vetor desordenado salvo,
					copia os valores para outro vetor que será ordenado*/
					vetM[cont] = vet[cont];
				}
				//Começa a contagem
				QueryPerformanceCounter( & tempoInicial);
				//Ordenação
				mergeSort(vetM, n);
				QueryPerformanceCounter( & tempoFinal);
				QueryPerformanceFrequency( & freq);
				//Faz a conversão para segundos
				time4 = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart) / freq.QuadPart;

				printf("\n");
				//Multiplica por mil para mostrar o tempo em milissegundos
				printf("Tempo em milissegundos para terminar a ordenacao: %f ms ", time4 * 1000);
				system("pause");
			}
				break;
			case 6: //heap sort
				
				if(opc)   //Verifica se o vetor desordenado foi gerado
			{
				verifica = 0;
				for(cont = 0; cont < n; cont++)
				{
					/*Para manter o vetor desordenado salvo,
					copia os valores para outro vetor que será ordenado*/
					vetH[cont] = vet[cont];
				}
				//Começa a contagem
				QueryPerformanceCounter( & tempoInicial);
				//Ordenação
				heapsort(vetM, n);
				QueryPerformanceCounter( & tempoFinal);
				QueryPerformanceFrequency( & freq);
				//Faz a conversão para segundos
				time5 = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart) / freq.QuadPart;

				printf("\n");
				//Multiplica por mil para mostrar o tempo em milissegundos
				printf("Tempo em milissegundos para terminar a ordenacao: %f ms ", time5 * 1000);
				system("pause");
			}
				break;
				

				}
			}
		
			system("pause");
			
		
	}while(opcao != 7);
return(0);
}


