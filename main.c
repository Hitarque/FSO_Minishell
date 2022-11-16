// FSO project
#include <stdbool.h>
#include <stdlib.h>

void main(int argc, char *argv)
{
        bool loop = true, scan;
        int cmdc, cmdt = 1;
        char *cmdv;

        displayStart();
        printf("Running main");

        //for(int i=0; i<4; i++) {
        //        scanf("%s", &cmdv[i]);
        //}
        char test[128];
        scanf("%c",test);
        cmdv = strtok(test," ");
        printf("Command :%s %s\n", &cmdv[0],&cmdv[1]);
        // while (loop)
        // {
        // input -> cmdv        
        // scan = true;
        // int parameters_number = 0;
        // while (scan)
        // {
        //         scanf("minishell -->%s", cmdv[parameters_number]);
        //         parameters_number++;
        //         if (cmdv[parameters_number] = " ")
        //         {
        //                 scan = false;
        //         }
        // }
        // // printf("Sortie de la boucle de parametres");
        // nb de param de cmdv -> cmdc (delimiter " ")

        // if (cmdt = (verifCmd(cmdc, cmdv)) != 0)
        // {
        switch (cmdt)
        {
        case 1:
                exec_ls(cmdc, cmdv);
                break;
        case 2:
                exec_cat(cmdc, cmdv);
                break;
        case 3:
                loop = false;
                break;
        default:
                break;
        }
        // }
        scan = true;

        // Print warning si cmdc > 2
        // }

        displayEnd();

        return 0;
}

// J
void exec_ls(int cmdc, char *cmdv)
{
        printf("exec_ls\n");
        // Création du fork
        pid_t parent = getpid();
        pid_t child = fork();
        int status = 0;

        // Vérification (child/parent)

        // Si enfant exec()
        if (child == 0)
        {
                // char *cmd = malloc(strlen(cmdv[1]) + strlen(cmdv[2]) + 2);
                // strcat(cmd, cmdv[1]);
                // strcat(cmd, " ");
                // strcat(cmd, cmdv[2]);
                printf(execl(cmdv[0], cmdv[1], NULL));
                // Execute ls commande
        }
        // Sinon await -> a voir
        while ((parent = wait(&status)) > 0)
                ;
}

// H
void exec_cat(int cmdc, char *cmdv)
{
        // Création du fork
        pid_t parent = getpid();
        pid_t child = fork();
        int status = 0;

        // Vérification (child/parent)
        if (child == 0)
        {
                // Si enfant exec()
                // display result
                char *cmd;
                cmd = malloc(strlen(cmdv[1]) + strlen(cmdv[2]) + 1);
                strcat(cmd, cmdv[1]);
                strcat(cmd, " ");
                strcat(cmd, cmdv[2]);
                char *args[] = {cmd, NULL};
                printf(execv(args[0], args));
                free(cmd);
        }
        // Sinon await -> a voir
        while ((parent = wait(&status)) > 0)
                ;
}

// H
// Verif si input correspont a cmd "ls", "cat", "exit"
//         none -> 0
//         ls -> 1
//         cat -> 2
//         exit -> 3
int verifCmd(int cmdc, char *cmdv)
{
        if (cmdv[0] == "ls")
        {
                return 1;
        }
        if (cmdv[0] == "cat")
        {
                return 2;
        }
        if (cmdv[0] == "exit")
        {
                return 3;
        }
        return 0;
}

// H
void displayStart()
{
        printf(" ██████   ██████  ███              ███          █████               ████  ████ \n░░██████ ██████  ░░░              ░░░          ░░███               ░░███ ░░███ \n ░███░█████░███  ████  ████████   ████   █████  ░███████    ██████  ░███  ░███ \n ░███░░███ ░███ ░░███ ░░███░░███ ░░███  ███░░   ░███░░███  ███░░███ ░███  ░███ \n ░███ ░░░  ░███  ░███  ░███ ░███  ░███ ░░█████  ░███ ░███ ░███████  ░███  ░███ \n ░███      ░███  ░███  ░███ ░███  ░███  ░░░░███ ░███ ░███ ░███░░░   ░███  ░███ \n █████     █████ █████ ████ █████ █████ ██████  ████ █████░░██████  █████ █████\n░░░░░     ░░░░░ ░░░░░ ░░░░ ░░░░░ ░░░░░ ░░░░░░  ░░░░ ░░░░░  ░░░░░░  ░░░░░ ░░░░░ \n                                                                               \n                                                                               \n");
        printf("V 1.0 Minshell by Hugo FABRE & Julien MOINARD - FSO project\n");
        printf("Contact: hfabre.ing2022@esaip.org & julienm.ir2023@esaip.org\n\n");

        printf("This project work only with 2 command: cat and ls\n");
        printf("Only 1 parameters is allowed for each command, all other parameters will not be used\n");

        return 0;
}

// J
void displayEnd()
{
        printf("Thanks for using our miniShell solution.\nWe hope see you as soon as possible.\n");
}

// J
void warning(int cmdc, char *cmdv)
{
        // Print warning message if there are too much parameter in comande line
        if (cmdc > 2)
        {
                printf("Warning: There is too much parameters. We'll only take the first command parameters!\n");
                printf("The command executed will be : %c %c", cmdv[0], cmdv[1]);
        }
}
