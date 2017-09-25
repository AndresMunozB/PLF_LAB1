#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{NUMERO_ENTERO,STRING,IDENTIFICADOR,NUMERO_REAL,PALABRA_RESERVADA,OPERADOR_PUNTUACION,NADA=10};
//NO SE RECONOCE LA Ñ  NI LA ñ;

/*
 * Funcion isSimbol
 * funcion que verifica si caracter es un simbolo
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea un simbolo el caracter y 0 en caso contrario.
*/
int isSimbol(char c){
    if(c>=32 && c<=47 && c!='\''){
        return 1;
    }
    if(c>=58 && c<=64){
        return 1;
    }
    if (c>=91 && c<=93){
        return 1;
    }
    if (c==95){
        return 1;
    }
    if (c>=123 && c<=125){
        return 1;
    }
    return 0;
}

/*
 * Funcion isLetterMin
 * funcion que verifica si un caracter es una letra minuscula
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea una letra minuscula el caracter y 0 en caso contrario.
*/
int isLetterMin(char c){
    if(c>=97 && c<=122){
        return 1;
    }
    /*if(c==164){
        return 1;
    }*/
    return 0;
}

/*
 * Funcion isLetterMay
 * funcion que verifica si un caracter es una letra mayuscula
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea una letra mayuscula el caracter y 0 en caso contrario.
*/
int isLetterMay(char c){
    if(c>=65 && c<=90){
        return 1;
    }
   /* if (c==165){
        return 1;
    }*/
    return 0;
}

/*
 * Funcion isLetter
 * funcion que verifica si un caracter es una letra (mayuscula o minuscula)
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea una letra el caracter y 0 en caso contrario.
*/
int isLetter(char c){
    if(isLetterMay(c)){
        return 1;
    }
    if (isLetterMin(c)){
        return 1;
    }
    return 0;
}

/*
 * Funcion isDigit
 * funcion que verifica si un caracter es un digito
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea un digito el caracter y 0 en caso contrario.
*/
int isDigit(char c){
    if(c>=48 && c<=57){
        return 1;
    }
    return 0;
}
/*
 * Funcion isCaracter
 * funcion que verifica si un caracter es un caracter (simbolo o letra o digito)
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea un caracter el caracter y 0 en caso contrario.
*/
int isCaracter(char c){
    if(isLetter(c)){
        return 1;
    }
    if(isSimbol(c)){
        return 1;
    }
    if(isDigit(c)){
        return 1;
    }
    return 0;
}

/*
 * Funcion isOperator
 * funcion que verifica si un caracter es operador (+,-,*,/)
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea un operador el caracter y 0 en caso contrario.
*/
int isOperator(char c){
    switch(c){
        case '>':
            return 1;
        case '<':
            return 1;
        case '=':
            return 1;
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 1;
        case '/':
            return 1;
        default:
            return 0;
    }
}

/*
 * Funcion isPunctuationSign
 * funcion que verifica si un caracter es signo de puntuacion (.,:,,,;,(,))
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que sea un signo de puntuacion el caracter y 0 en caso contrario.
*/
int isPunctuationSign(char c){
    switch(c){
        case '.':
            return 1;
        case ':':
            return 1;
        case ',':
            return 1;
        case ';':
            return 1;
        case '(':
            return 1;
        case ')':
            return 1;
        default:
            return 0;
    }
}

/*
 * Funcion isReservedWord
 * funcion que verifica si una cadena caracteres es  una palabra reservada
 * @param char c, caracter a verificar
 * @return entero 1 en caso de que la cadena de carateres sea una palabra reservada y 0 en caso contrario.
*/
int isReservedWord(char *word){
    if(!strcmp(word,"ABS")){
        return 1;
    }
    else if(!strcmp(word,"BAJAR")){
        return 1;
    }
    else if(!strcmp(word,"CARACTER")){
        return 1;
    }
    else if(!strcmp(word,"CONST")){
        return 1;
    }
    else if(!strcmp(word,"CUADR")){
        return 1;
    }
    else if(!strcmp(word,"CUANDO")){
        return 1;
    }
    else if(!strcmp(word,"DIV")){
        return 1;
    }
    else if(!strcmp(word,"ENTERO")){
        return 1;
    }
    else if(!strcmp(word,"ENTONCES")){
        return 1;
    }
    else if(!strcmp(word,"ESCRIB")){
        return 1;
    }
    else if(!strcmp(word,"ESCRIBL")){
        return 1;
    }
    else if(!strcmp(word,"FALSO")){
        return 1;
    }
    else if(!strcmp(word,"FIN")){
        return 1;
    }
    else if(!strcmp(word,"HACER")){
        return 1;
    }
    else if(!strcmp(word,"HASTA")){
        return 1;
    }
    else if(!strcmp(word,"IMPAR")){
        return 1;
    }
    else if(!strcmp(word,"INICIO")){
        return 1;
    }
    else if(!strcmp(word,"LEER")){
        return 1;
    }
    else if(!strcmp(word,"LOGICO")){
        return 1;
    }
    else if(!strcmp(word,"MIENTRAS")){
        return 1;
    }
    else if(!strcmp(word,"NO")){
        return 1;
    }
    else if(!strcmp(word,"O")){
        return 1;
    }
    else if(!strcmp(word,"PROGRAMA")){
        return 1;
    }
    else if(!strcmp(word,"REAL")){
        return 1;
    }
    else if(!strcmp(word,"REPITA")){
        return 1;
    }
    else if(!strcmp(word,"RESTO")){
        return 1;
    }
    else if(!strcmp(word,"SEA")){
        return 1;
    }
    else if(!strcmp(word,"SI")){
        return 1;
    }
    else if(!strcmp(word,"SINO")){
        return 1;
    }
    else if(!strcmp(word,"SUBIR")){
        return 1;
    }
    else if(!strcmp(word,"VAR")){
        return 1;
    }
    else if(!strcmp(word,"VERDAD")){
        return 1;
    }
    else if(!strcmp(word,"Y")){
        return 1;
    }
    return 0;
    
    
}

/*
 * Funcion automataNumeroEntero
 * funcion que realiza la funcion de un automata, para un numero entero.
 * @param int state,estando en el cual se encuentra actualmente. char c, caracter con el cual se hace una transicion 
 * @return entero, entrega el siguiente estado. Si es un estado final entrega -1, si entra un caracter invalido entrega -2.
*/
int automataNumeroEntero(int state,char c){
    switch(state){
        case 1:
            if(isDigit(c))
                return 2;
            else
                return -2;
        case 2:
            if(isDigit(c))
                return 2;
            else
                return -1;

    }
    return -2;
}

/*
 * Funcion automataString
 * funcion que realiza la funcion de un automata, para un string.
 * @param int state,estando en el cual se encuentra actualmente. char c, caracter con el cual se hace una transicion 
 * @return entero, entrega el siguiente estado. Si es un estado final entrega -1, si entra un caracter invalido entrega -2.
*/
int automataString(int state, char c){
    switch(state){
        case 1:
            if (c == '\'')
                return 2;
            else
                return -2;
        case 2:
            if (isCaracter(c))
                return 3;
            else
                return -2;
        case 3:
            if (isCaracter(c))
                return 3;
            else if (c == '\'')
                return 4;
            else
                return -2;
        case 4:
            return -1;
    }
    //solamente el estado final debe retornar -1
    return -2;
}

/*
 * Funcion automataIdentificador
 * funcion que realiza la funcion de un automata, para un identificador.
 * @param int state,estando en el cual se encuentra actualmente. char c, caracter con el cual se hace una transicion 
 * @return entero, entrega el siguiente estado. Si es un estado final entrega -1, si entra un caracter invalido entrega -2.
*/
int automataIdentificador(int state,char c){
    switch(state){
        case 1:
            if(isLetter(c))
                return 2;
            else
                return -2;
        case 2:
            if(isLetter(c) || isDigit(c))
                return 2;
            else
                return -1;
    }
    return -2;
}

/*
 * Funcion automataNumeroReal
 * funcion que realiza la funcion de un automata, para un numero real.
 * @param int state,estando en el cual se encuentra actualmente. char c, caracter con el cual se hace una transicion 
 * @return entero, entrega el siguiente estado. Si es un estado final entrega -1, si entra un caracter invalido entrega -2.
*/
int automataNumeroReal(int state,char c){
    switch(state){
        case 1:
            if(isDigit(c))
                return 2;
            else
                return -2;
        case 2:
            if(isDigit(c))
                return 2;
            else if(c == '.')
                return 3;
            else if (c == 'E')
                return 5;
            else
                return -2;

        case 3: //tengo digito(digito)*.
            if(isDigit(c))
                return 4;
            else
                return -2;
        case 4: // ESTADO FINAL : digito(digito)*.digito
            if (c == 'E')
                return 5;
            else
                return -1;
        case 5:
            
            if (c == '+')
                return 6;
            else if (c == '-')
                return 7;
            else if(isDigit(c))
                return 8;
            else 
                return -2;
        case 6:
            if(isDigit(c))
                return 8;
            else 
                return -2;
        case 7:
            if (isDigit(c))
                return 8;
            else
                return -2;
        case 8:
            if(isDigit(c))
                return 8;
            else
                return -1;

    }
    return -2;
}

/*
 * Funcion reconocerNumeroEntero
 * funcion que reconoce una expresion regular (numero entero)
 * @param char *string, cadena de caracteres en la cual se reconocera la expresion regular. int position, posicion desde la cual se comenzara a reconocer la expresion regular.
 * @return entero, posicion que corresponde a la siguiente despues de reconocer la expresion regular, entrega 0 si no reconoce ninguna expresion.
*/
int reconocerNumeroEntero(char *string,int position){
    int state = 1;
    int i=position;
    while( i<=strlen(string) ){
        state = automataNumeroEntero(state,string[i]);
        //printf("%d",state);
        if (state == -1){
            return i;
        }
        if (state == -2){
            return position;
        }
        i++;
    }
    return i;
}

/*
 * Funcion reconocerString
 * funcion que reconoce una expresion regular (string)
 * @param char *string, cadena de caracteres en la cual se reconocera la expresion regular. int position, posicion desde la cual se comenzara a reconocer la expresion regular.
 * @return entero, posicion que corresponde a la siguiente despues de reconocer la expresion regular, entrega 0 si no reconoce ninguna expresion.
*/
int reconocerString(char *string,int position){
    int state = 1;
    int i=position;
    while( i<=strlen(string) ){
        state = automataString(state,string[i]);
        if (state == -1){
            return i;
        }
        if(state == -2){
            return position;
        }
        i++;
    }
    return i;
}

/*
 * Funcion reconocerIdentificador
 * funcion que reconoce una expresion regular (identificador)
 * @param char *string, cadena de caracteres en la cual se reconocera la expresion regular. int position, posicion desde la cual se comenzara a reconocer la expresion regular.
 * @return entero, posicion que corresponde a la siguiente despues de reconocer la expresion regular, entrega 0 si no reconoce ninguna expresion.
*/
int reconocerIdentificador(char *string, int position){
    int state = 1;
    int i=position;
    while( i<=strlen(string) ){
        state = automataIdentificador(state,string[i]);
        if (state == -1){
            return i;
        }
        if(state == -2){
            return position;
        }
        i++;
    }
    return i;
}

/*
 * Funcion reconocerNumeroReal
 * funcion que reconoce una expresion regular (numero real)
 * @param char *string, cadena de caracteres en la cual se reconocera la expresion regular. int position, posicion desde la cual se comenzara a reconocer la expresion regular.
 * @return entero, posicion que corresponde a la siguiente despues de reconocer la expresion regular, entrega 0 si no reconoce ninguna expresion.
*/
int reconocerNumeroReal(char *string, int position){
    int state = 1;
    int i=position;
    while( i<=strlen(string) ){
        state = automataNumeroReal(state,string[i]);
        if (state == -1){
            return i;
        }
        if(state == -2){
            return position;
        }
        i++;
    }
    return i;
}

/*
 * Funcion findFinal
 * funcion que busca el final de una posible palabra reservada.
 * @param char *string, string en el que se busca el final. int position, posicion desde la cual se comeinza a buscar el final
 * @return entero, posicion del final de una posible palabra reservada.
*/
int findFinal(char *string,int position){
    int i = position;
    while(i<strlen(string)){
        if(!isCaracter(string[i]) || string[i] == ' ')
            return i;
        i++;
    }
    return -1;

}

/*
 * Funcion strsecpy
 * funcion que copia un string desde una posicion incial hasta una final.
 * @param char *dest, string destino. char *src, string origen. int start, posicion inicial.int end, posicion final.
*/
void strsecpy(char *dest,char *src,int start,int end){
    int i=0;
    while(i<end-start){
        dest[i] = src[start+i]; 
        i++;
    }
    dest[i] = '\0';
    return;
}

/*
 * Funcion reconocerPalabraReservada
 * funcion que reconoce si un string es una palabra reservada
 * @param char *string, cadena de caracteres en la cual se reconce la palabra reservada. int position, posicion desde la cual se comenzara a reconocer la expresion regular.
 * @return entero, posicion que corresponde a la siguiente despues de reconocer la palabra reservada, entrega 0 si no reconoce ninguna palabra reservada.
*/
int reconocerPalabraReservada(char *string, int position){
    int final = findFinal(string,position);
    char buffer[300];
    if(final != -1){
        memset(buffer,0,sizeof(buffer));
        strsecpy(buffer,string,position,final);
        //printf("\n\nbuffer:%s\n\n",buffer);
        if(isReservedWord(buffer)){
            return final;
        }
    }
    return position;
}

/*
 * Funcion fprintToken
 * funcion que escribe en un archivo el tipo de token entregado por parametro
 * @param int token,FILE *fileOut
*/
void fprintToken(int token,FILE *fileOut){
    switch(token){
        case NUMERO_ENTERO:
            //fprintf(fileOut,"PC: %d,NUMERO_ENTERO\n",pc);
            fprintf(fileOut,"NUMERO_ENTERO\n");
            break;
        case STRING:
            //fprintf(fileOut,"PC: %d,STRING\n",pc);
            fprintf(fileOut,"STRING\n");
            break;
        case IDENTIFICADOR:
            //fprintf(fileOut,"PC: %d,IDENTIFICADOR\n",pc);
            fprintf(fileOut,"IDENTIFICADOR\n");
            break;
        case NUMERO_REAL:
            //fprintf(fileOut,"PC: %d,NUMERO_REAL\n",pc);
            fprintf(fileOut,"NUMERO_REAL\n");
            break;
        /*case NADA:
            fprintf(fileOut,"PC: %d,NADA\n",pc);
            break;*/
        default:
            break;
    }
}

/*
 * Funcion changeToken
 * funcion encargada de reconocer el token mas largo
 * @param int *token,parametro por referencia para ir modificando el token cada vez que se reconoce una expresion regular. char *string, cadena de caracteres que se esta analizando. int pc, posicion desde donde se comienza a analizar las expresiones regulares.FILE *fileOut, archivo de salida en el cual se escribe el tipo de expresion regular reconocida.
 * @return entero, posicion que corresponde a la siguiente despues de reconocer alguna expresion, entrega 0 si no reconoce ninguna expresion.
*/
int changeToken(int *token, char *string, int pc,FILE *fileOut){
    int max = pc;
    int buffer;
    buffer = reconocerPalabraReservada(string,pc);
    if(max<buffer){
        *token = PALABRA_RESERVADA;
        char word[50];
        strsecpy(word,string,pc,buffer);
        //fprintf(fileOut,"PC: %d,%s\n",buffer,word);
        fprintf(fileOut,"%s\n",word);
        return buffer;
    }
    if(isPunctuationSign(string[pc]) || isOperator(string[pc])){
        *token = OPERADOR_PUNTUACION;
        //fprintf(fileOut,"PC: %d,%c\n",pc,string[pc]);
        fprintf(fileOut,"%c\n",string[pc]);
        return pc+1;
    }
    buffer = reconocerNumeroEntero(string,pc);
    if(max<buffer){
        *token = NUMERO_ENTERO;
        max = buffer;
    }
    buffer = reconocerString(string,pc);
    if(max<buffer){
        *token = STRING;
        max = buffer;
    }
    buffer = reconocerIdentificador(string,pc);
    if(max<buffer){
        *token = IDENTIFICADOR;
        max = buffer;
    }
    buffer = reconocerNumeroReal(string,pc);
    if(max<buffer){
        *token = NUMERO_REAL;
        max = buffer;
    }
    if(max == pc){
        *token = NADA;
    }
    fprintToken(*token,fileOut);
    return max;
}

/*
 * Funcion existFile
 * funcion que verifica si un archivo de texto plano existe
 * @param char* fileName, nombre del archivo
 * @return entero 1 en caso de que si exista y 0 en caso contrario
*/
int existsFile(char* fileName) 
{
	FILE* file = NULL;
	file = fopen(fileName,"r");
	if (file == NULL)
		return 0;
	else {
		fclose(file);
		return 1;
	}
	return 0;
}

/*
 * Funcion validarEntradas
 * funcion que verifica si los parametros de entrada del programa son validos
 * @param int argc,numero de argumentos. char** argv, arreglo de cadena de caracteres que contiene los parametros de entrada.
 * @return entero 1 en caso de que si los parametros sean validos y 0 en caso contrario
*/
int validarEntradas(int argc, char** argv){
    //Caso 1

    if (argc == 1){
        printf("Error: Faltan parámetros en la línea de comandos.\n");
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n\n");
        return 0;
    }
    //Caso 2
    if (argc == 2){
        printf("Error: Falta parámetro en la línea de comandos.\n");
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n\n");
        return 0;
    }
    //Caso 3 
    if( argc > 3 ){
        printf("Error: Demasiados parámetros en la línea de comandos.\n");
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n\n");
        return 0;
    }
    //Caso 4
    if (!existsFile(argv[1])){
        printf("Error: El archivo de entrada no existe\n\n");
        return 0;
    }
    //Caso 5
    if (existsFile(argv[2])){
        printf("Error: El archivo de salida ya existe.\n\n");
        return 0;
    }
    return 1;
}


int main(int argc, char** argv){
    
    //VALIDANDO ENTRADAS
    if(!validarEntradas(argc,argv)){
        return 0;
    }
    
    

    
    //PROCESADO LA INFORMACION
    FILE *fileIn = fopen(argv[1],"r");
    FILE *fileOut = fopen(argv[2],"w");
    char buffer[1000];
    int pc;
    int token;
    while(!feof(fileIn)){
        memset(buffer,0,sizeof(buffer));
        pc=0;
        token = NADA;
        fgets(buffer,1000,fileIn);
        while(pc<strlen(buffer)){
            pc = changeToken(&token,buffer,pc,fileOut);   
            if(token==NADA){
                pc++;
            }
        }
    }
    fclose(fileIn);
    fclose(fileOut);
    
    
    
    
    //FINAL
    printf("\n");
    return 1;
}