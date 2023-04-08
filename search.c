#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    if(argv[1] == NULL){
        printf("Kein Wort angegeben.");
        return 0;
    }
    if(argv[2] == NULL){
        printf("Keine Datei angegeben.");
        return 0;
    }
    
    FILE *fptr;

    fptr = fopen(argv[2], "r");

    if(fptr == NULL){
        printf("Datei nicht vorhanden");
        return 0;
    }

    char line[500];

    int lin = 0;

    while(fgets(line, 500, fptr)){
        printf("Line %i:\n", lin);
        searchLine(argv[1], &line);
        lin++;
    }
    

    return 0;
}


void searchLine(char const wort[], char const *text){
    int loc = 0;

    int w_len = strlen(wort);
    int t_len = strlen(text);

    for(int i = 0; i < t_len; i++){
        if(text[i] == wort[loc]){
            loc++;
            if(loc == w_len){
                printf("Found word at %i\n", i+1-w_len);
                if(text[i] == wort[0]){
                    loc = 1;
                }else{
                    loc = 0;
                }
            }
        }else{
            if(text[i] == wort[0]){
                loc = 1;
            }else{
                loc = 0;
            }
        }
    }
}