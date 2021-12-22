#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc and friends
#define SIZE_NOTE 100
//Reads a one-line note pass pointer of pointer to note
void enter_note(int* lines, char*** notebook_pointer) {
    (*lines) ++; 
    *notebook_pointer = realloc(*notebook_pointer, (*lines) * sizeof(char*));
    (*notebook_pointer)[(*lines) -1] = malloc(SIZE_NOTE * sizeof(char)); 
    printf("Enter a new note:");
    fgets((*notebook_pointer)[(*lines)-1], SIZE_NOTE, stdin);
}

//display all written notes, req: lines + p_notebook(derefrenced) = notebok itself
void show_notes(int lines, char **notebook ){
    printf("\nNotes stored so far:");
    for(int line=0; line < lines; line++){
            printf("Note #%d : %s", line+1, notebook[line]);
    }
}
int main(){    
    //declaration & initialisation
    int lines = 0;                                  //notes of notebook
    char** notebook = malloc(sizeof(char*));        //initalise notebook    
    for(int i = 0; i < 10; i++){
        enter_note(&lines, &notebook);             //ERROR: third line raises segmentation fault
    }
    show_notes(lines, notebook);    
}


/*
p_notebook, char*** --> notebook, char** --> char*  --> char char char ...
                                         --> char*  --> char char char char char ...
                                         --> char*  --> char char ...
                         ...
*/














/*
#IGONORE:
void menu(char user_input, int len, char *notebook[len] ){
    switch (user_input)
    {
    case 1:
        enter_note(); 
        break;
    case 2:
        show_notes(len, notebook[len]);
        break;
    case 3:
        printf("Programm stoped"); 
        //TODO: goto 
        break;
    default:
        menu(user_input, len, notebook);  //recursive call -- ( inefficient )
    }
}
*/