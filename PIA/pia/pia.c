#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

typedef struct calificacionParcial{
	unsigned int alumnos_reprobados;
	int *califparcialA;
	double promedio;
} calificacionParcial;

typedef struct alumno {
	char matricula[8];
	int calif[7];
	unsigned int parciales_reprobados;
	double promedio;
} alumno;


typedef struct grupo {
	unsigned int alumnos_reprobados;
	int *califAlumnos;
	double promedio;
} grupo;

unsigned int contador_lineas(const char* calificaciones_pia_pe) {
	FILE* stream = fopen("calificaciones_pia_pe.csv","r");
	if(!stream) {
		printf("\n","calificaciones_pia_pe.csv");
		exit(EXIT_FAILURE);
	}
	unsigned int numero_lineas = 0;
	char texto[ESPACE];
	while(fgets(texto,ESPACE,stream) != NULL) {
		numero_lineas++;
	}

	fclose(stream);

	return numero_lineas;
}

char** split_str(char* str, const char a_delim) {
	char **_str = NULL;
	size_t contador;
	char *str_tmp = str;
	char *last_delim = NULL;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = '\0';

	while(*str_tmp) {
		if(*str_tmp == a_delim) {
			contador++;
			last_delim = str_tmp;
		}
		str_tmp++;
	}
	contador += last_delim < (str + strlen(str) - 1);
	contador++;

	_str = malloc(sizeof(char*)*(size_t)contador);
	if(_str) {
		size_t idx = 0;
		char* token = strtok(str,delim);
		while(token) {
			assert(idx < contador);
			*(_str + idx++) = strdup(token);
			token = strtok(NULL,delim);
		}

		assert(idx == (contador - 1));
		*(_str + idx) = '\0';
	} else {
		printf("Error. No se pudo reservar espacio en memoria.\n");
		exit(EXIT_FAILURE);
	}

	return _str;
}

alumno register_student(char** tokens) {
	size_t i = 0,k = 0;
	alumno a;

	for(i = 0; *(tokens + i); ++i) {
		if(i > 0) {
			a.calif[k] = (int)strtol(tokens[i],NULL,10);
			k++;
		} else {
			strncpy(a.matricula,tokens[i],strlen(tokens[i]));
		}
	}

	return a;
}

void load_data(const char* calificaciones_pia_pe, alumno* alumnos) {
	FILE* stream = fopen("calificaciones_pia_pe.csv","r");
	if(!stream) {
		printf("Error. Hubo un problema al abrir el archivo %s en modo lectura.\n","calificaciones_pia_pe.csv");
		exit(EXIT_FAILURE);
	}
	size_t idx = 0;
	size_t i = 0;
	char texto[ESPACE];
	unsigned int numero_lineas = 0;
	char** tokens = NULL;
	while(fgets(texto,ESPACE,stream) != NULL) {
		numero_lineas++;
		texto[strcspn(texto,"\n")] = '\0';
		if(numero_lineas > 1) {
			tokens = split_str(texto,',');
			if(tokens) {
				alumnos[idx] = register_student(tokens);
				//liberamos espacio de memoria
				for(i = 0; *(tokens + i); ++i) {
					free(*(tokens+i));
				}
				free(tokens);
				tokens = NULL;
			}
			idx++;
		}
	}

	fclose(stream);
}

void saveData_at_file(const char* documento, alumno* alumnos, calificacionParcial* calificaciones, grupo g, const size_t tamA, const size_t tamC) {
	FILE* stream = fopen(documento,"w");
	if(!stream) {
		printf("Error. No se pudo abrir el archivo.\n",documento);
		exit(EXIT_FAILURE);
	}
	size_t i = 0, j = 0;
	size_t len = 0;
	fprintf(stream,"Matricula,Parcial 1,Parcial 2,Parcial 3,Parcial 4,Parcial 5,Parcial 6,Parcial 7,Promedio Calificaciones Parciales,No. de parciales no aprobados\n");
	for(i = 0; i < tamA; ++i) {
		len = strlen(alumnos[i].matricula);
		for(j = len - 4; j < len; ++j) {
			fputc(alumnos[i].matricula[j],stream);
		}
		fprintf(stream,",%d,%d,%d,%d,%d,%d,%d,%d,%u\n",alumnos[i].calif[0],alumnos[i].calif[1],alumnos[i].calif[2],alumnos[i].calif[3],alumnos[i].calif[4],alumnos[i].calif[5],alumnos[i].calif[6],(int)alumnos[i].promedio,alumnos[i].parciales_reprobados);
	}
	fprintf(stream,"Promedio,");
	for(i = 0; i < tamC; ++i) {
		fprintf(stream,"%d,",(int)calificaciones[i].promedio);
	}
	fprintf(stream,"%d\n",(int)g.promedio);
	fprintf(stream,"No aprobados,");
	for(i = 0; i < tamC; ++i) {
		fprintf(stream,"%u,",calificaciones[i].alumnos_reprobados);
	}
	fprintf(stream,"%u",g.alumnos_reprobados);
	fclose(stream);
}

double calcular_promedioFinal(int* calif, const size_t tam) {
	double prom = 0.0;
	size_t i = 0;
	for(i = 0; i < tam; ++i) {
		prom += calif[i];
}
	prom /= tam;
	return prom;
}

unsigned int numero_parciales_reprobados(int* calif,const size_t tam) {
	size_t i = 0;
	unsigned int reprobados = 0;
	for(i = 0; i < tam; ++i) {
				if(calif[i] < 7)
						reprobados++;
}
	return reprobados;
}

void ini_CalifParcial(unsigned* n_alumR, double* prom, int** califAlumP, const size_t tam, alumno* alumnos, const unsigned idx_P) {
	*n_alumR = 0;
	*prom = 0.0;
	*califAlumP = (int*) malloc(sizeof(int)*(size_t)tam);
	if(!(*califAlumP)) {
						printf("Error. No se pudo reservar espacio en memoria.\n");
									exit(EXIT_FAILURE);
	}
	size_t k = 0;
		for(k; k < tam; ++k){
				(*califAlumP)[k] = alumnos[k].calif[idx_P];
	}
}

double calcular_promedioParcial(int* califAlumnosP, const size_t tam) {
	double prom = 0.0;
	size_t i = 0;
	for(i; i < tam; ++i) {
		prom += califAlumnosP[i];
}
	prom /= tam;
	return prom;
}

unsigned int NalumnosReprobados_P(int* califAlumnosP, const size_t tam) {
unsigned int reprobados = 0;
size_t i = 0;
			for(i; i < tam; ++i) {
				if(califAlumnosP[i] < 7)
						reprobados++;
}
	return reprobados;
}

void ini_califGrupo(grupo* g, alumno* alumnos, const size_t tam) {
	g->califAlumnos = (int*) malloc(sizeof(int)*(size_t)tam);
	if(!g->califAlumnos) {
		printf("Error. No se pudo reservar espacion en memoria\n");
		exit(EXIT_FAILURE);
	}
	size_t i = 0;
	for(i; i < tam; ++i) {
		g->califAlumnos[i] = (int)alumnos[i].promedio;
	}
}

double calcular_promGrupo(int* califAlumnos, const size_t tam) {
	size_t i = 0;
	double prom = 0.0;
	for(i; i < tam; ++i) {
		prom += califAlumnos[i];
	}
	prom /= tam;

	return prom;
}

unsigned int NAlumnosReprobados_G(int* califAlumnos, const size_t tam) {
	unsigned int reprobados = 0;
	size_t i = 0;
	for(i; i < tam; ++i) {
		if(califAlumnos[i] < 7)
			reprobados++;
	}

	return reprobados;
}

void print_arrayAlumnos(alumno* alumnos,const size_t tam) {
	size_t i = 0, j = 0;
	for(i = 0; i < tam; ++i) {
		printf("Alumno %d\nMatricula: %s\nCalif: ",i+1,alumnos[i].matricula);
		for(j = 0; j < 7; ++j) {
			printf("%d ",alumnos[i].calif[j]);
		}
		printf("\n# de parciales reprobados: %u\npromedio final: %.2lf",alumnos[i].parciales_reprobados,alumnos[i].promedio);
		if(i < tam - 1)
			printf("\n-\n");
	}
	printf("\n");
}

void print_arrayCalifP(calificacionParcial* calificaciones, const size_t tam) {
	size_t i = 0;
	for(i = 0; i < tam; ++i) {
		printf("Parcial %d\n# de alumnos reprobados: %u\nPromedio general del parcial: %.2lf",i+1,calificaciones[i].alumnos_reprobados,calificaciones[i].promedio);
		if(i < tam - 1)
			printf("\n-\n");
	}
	printf("\n");
}

int main() {
	const size_t SIZE = contador_lineas("csv.csv") - 1;
	alumno alumnos[SIZE];
	calificacionParcial calificacionesP[7];
	grupo g = {0,NULL,0.0};
	size_t i = 0, j = 0;

	load_data("csv.csv",alumnos);

	for(i = 0; i < SIZE; ++i) {
		alumnos[i].promedio = round(calcular_promedioFinal(alumnos[i].calif,7));
		alumnos[i].parciales_reprobados = numero_parciales_reprobados(alumnos[i].calif,7);
	}
	for(i = 0; i < 7; ++i) {
		ini_CalifParcial(&calificacionesP[i].alumnos_reprobados,&calificacionesP[i].promedio,&calificacionesP[i].califparcialA,SIZE,alumnos,i);
		calificacionesP[i].promedio = round(calcular_promedioParcial(calificacionesP[i].califparcialA,SIZE));
		calificacionesP[i].alumnos_reprobados = numero_parciales_reprobados(calificacionesP[i].califparcialA,SIZE);
	}

	ini_califGrupo(&g,alumnos,SIZE);
	g.promedio = round(calcular_promGrupo(g.califAlumnos,SIZE));
	g.alumnos_reprobados = NAlumnosReprobados_G(g.califAlumnos,SIZE);

	saveData_at_file("final.csv",alumnos,calificacionesP,g,SIZE,7);

	print_arrayAlumnos(alumnos,SIZE);
	printf("\n");
	print_arrayCalifP(calificacionesP,7);
	printf("\nEl promedio del grupo es: %.2lf\nEl total de alumnos reprobados del grupo es d %u\n",g.promedio,g.alumnos_reprobados);

	for(i = 0; i < 7; ++i) {
		free(calificacionesP[i].califparcialA);
	}
	free(g.califAlumnos);

	return 0;
}
