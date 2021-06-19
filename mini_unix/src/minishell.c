#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int miniShell_cd(char **args);
int miniShell_help(char **args);
int miniShell_exit(char **args);

/*
 * List of all the commands followed by their corresponding function
 */
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &miniShell_cd,
    &miniShell_help,
    &miniShell_exit
};

int miniShell_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

/*
 * Builtin functions implem
 */
int miniShell_cd(char **args)
{
    if (args[1] == NULL){
        fprintf(stderr, "miniShell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("miniShell");
        }
    }
    return 1;
}

int miniShell_help(char **args)
{
    int i;
    printf("Cedric Brisson's miniShell (yeah, it's sucky)\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");
    
    for(int i; i < miniShell_num_builtins(); i++){
        printf("    %\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int miniShell_exit(char **args)
{
    return 0;
}

#define MINISHELL_TOK_BUFSIZE 64
#define MINISHELL_TOK_DELIM " \t\r\n\a"
char **miniShell_split_line(char *line)
{
    int bufsize = MINISHELL_TOK_BUFSIZE;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    int position = 0;
    if(!tokens){
        fprintf(stderr, "miniShell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, MINISHELL_TOK_DELIM);
    while(token != NULL){
        tokens[position] = token;
        position++;

        if(position >= bufsize){
            bufsize += MINISHELL_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if(!tokens){
                fprintf(stderr, "miniShell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, MINISHELL_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int miniShell_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0){
        // Child process
        if(execvp(args[0], args) == -1){
            perror("miniShell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0){
        perror("miniShell");
    } else{
        // Parent process
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int miniShell_execute(char **args)
{
    int i;

    if (args[0] == NULL){
        // Empty command
        return 1;
    }

    for(i = 0; i < miniShell_num_builtins(); i++){
        if (strcmp(args[0], builtin_str[i]) == 0){
            return (*builtin_func[i])(args);
        }
    }
    return miniShell_launch(args);
}

#define MINISHELL_RL_BUFSIZE 1024
char *miniShell_read_line(void)
{
    int bufsize = MINISHELL_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char)* bufsize);
    int c;

    if(!buffer){
        fprintf(stderr, "miniShell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        // Read the current char
        c = getchar();
        
        // If we hit EOF, replace with null char(\0) and newline (\n)
        if(c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If we need more buffer space, realloc
        if(position >= bufsize){
            bufsize += MINISHELL_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer){
                fprintf(stderr, "miniShell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

    }
}


void miniShell_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = miniShell_read_line();
        args = miniShell_split_line(line);
        status = miniShell_execute(args);

        free(line);
        free(args);
    }while(status);
}

int main(int argc, char * argv[])
{
    // Start loop
    miniShell_loop();
    
    // Cleanup on exit
    return EXIT_SUCCESS;
}

