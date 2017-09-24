#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{NUMERO_ENTERO,STRING,IDENTIFICADOR,NUMERO_REAL,NADA=10};
//NO SE RECONOCE LA Ñ  NI LA ñ;
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
int isLetterMin(char c){
    if(c>=97 && c<=122){
        return 1;
    }
    /*if(c==164){
        return 1;
    }*/
    return 0;
}
int isLetterMay(char c){
    if(c>=65 && c<=90){
        return 1;
    }
   /* if (c==165){
        return 1;
    }*/
    return 0;
}
int isLetter(char c){
    if(isLetterMay(c)){
        return 1;
    }
    if (isLetterMin(c)){
        return 1;
    }
    return 0;
}
int isDigit(char c){
    if(c>=48 && c<=57){
        return 1;
    }
    return 0;
}
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
}
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

int findSpace(char *string,int position){
    int i = position;
    while(i<strlen(string)){
        if(!isCaracter(string[i]) || string[i] == ' ')
            return i;
        i++;
    }
    return -1;

}
void strsecpy(char *dest,char *src,int start,int end){
    int i=0;
    while(i<end-start){
        dest[i] = src[start+i]; 
        i++;
    }
    dest[i] = '\0';
    return;
}
int reconocerPalabraReservada(char *string, int position){
    int space = findSpace(string,position);
    char buffer[300];
    if(space != -1){
        memset(buffer,0,sizeof(buffer));
        strsecpy(buffer,string,position,space);
        //printf("\n\nbuffer:%s\n\n",buffer);
        if(isReservedWord(buffer)){
            return space;
        }
    }
    return position;
}

void printToken(int token,int pc){
    switch(token){
        case NUMERO_ENTERO:
            printf("PC: %d,NUMERO_ENTERO\n",pc);
            break;
        case STRING:
            printf("PC: %d,STRING\n",pc);
            break;
        case IDENTIFICADOR:
            printf("PC: %d,IDENTIFICADOR\n",pc);
            break;
        case NUMERO_REAL:
            printf("PC: %d,NUMERO_REAL\n",pc);
            break;
        case NADA:
            printf("PC: %d,NADA\n",pc);
            break;
        default:
            break;
    }
}
void fprintToken(int token,int pc,FILE *fileOut){
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
int changeToken(int *token, char *string, int pc,FILE *fileOut){
    int max = pc;
    int buffer;
    buffer = reconocerPalabraReservada(string,pc);
    if(max<buffer){
        char word[50];
        strsecpy(word,string,pc,buffer);
        fprintf(fileOut,"PC: %d,%s\n",buffer,word);
        return buffer;
    }
    if(isPunctuationSign(string[pc]) || isOperator(string[pc])){
        fprintf(fileOut,"PC: %d,%c\n",pc,string[pc]);
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
    fprintToken(*token,pc,fileOut);
    return max;
}


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
void saveFile(char* stringFile,int* lenght,char* fileName){
    FILE* file = fopen(fileName,"r");
    while(!feof(file)){
        stringFile[*lenght] = fgetc(file);
        *lenght = *lenght +1;
    }
    fclose(file);
}


int main(int argc, char** argv){
    
    //VALIDANDO ENTRADAS
    if(!validarEntradas(argc,argv)){
        return 0;
    }
    
    
    /*char stringFile[8300000];
    int lenght = 0;
    
    saveFile(stringFile,&lenght,"entrada.txt");
    int pc = 0;
    int token = NADA;
    while(pc<strlen(stringFile)){
        printf("pc: %d ",pc);
        pc = changeToken(&token,stringFile,pc);
        //printf("token:%d pc:%d\n",token,pc);
        

        if(token==NADA){
            pc++;
        }
    }*/

    
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
            //printf("pc: %d ",pc);
            pc = changeToken(&token,buffer,pc,fileOut);
            //printf("token:%d pc:%d\n",token,pc);
            
    
            if(token==NADA){
                pc++;
            }
        }
        //printf("%s",buffer);
    }
    fclose(fileIn);
    fclose(fileOut);
    
    
    
    
    //FINAL
    printf("\n");
    return 1;
}