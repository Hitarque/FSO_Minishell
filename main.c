//FSO project 

#include <stdbool.h>
#include <stdlib.h>

void main(int argc, char* argv) {
        bool loop = true;
        int cmdc, cmdt;
        char* cmdv;

        displayStart();

        while(loop) {
                // input -> cmdv
                // nb de param de cmdv -> cmdc (delimiter " ")

                if (cmdt = (verifCmd(cmdc, cmdv)) != 0) {
                        switch (smdt) :
                                case 1:
                                        exec_ls(cmdc, cmdv);
                                        break;
                                case 2:
                                        exec_cat(cmdc, cmdv);
                                        break;
                                case 3:
                                        loop = false;
                                        break;
                                default :
                                        break;
                } 
                // Print warning si cmdc > 2
        }

        displayEnd();

        return 0;
}

// J
void exec_ls(cmdc, cmdv) {
        // Création du fork
        // Vérification (child/parent)
                // Si enfant exec()
                        // display result
                // Sinon await -> a voir
}

// H
void exec_cat(cmdc, cmdv) {
        // Création du fork
        // Vérification (child/parent)
                // Si enfant exec()
                        // display result
                // Sinon await -> a voir
}

// H
// Verif si input correspont a cmd "ls", "cat", "exit"
//         none -> 0
//         ls -> 1
//         cat -> 2
//         exit -> 3
int verifCmd(cmdc, cmdv) {

}

// H
void displayStart() {

}

// J
void displayEnd() {

}

// J
void warning(cmdc, cmdv) {
        
}

