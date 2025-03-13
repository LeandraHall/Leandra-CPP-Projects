#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> //Include sys/types.h for waitpid function

using namespace std;

int main() {
    while (true) {
        
        //Comfy handle for terminal
        cout << "Comfy> ";

        //Handles user input
        char input[1024];
        if (!cin.getline(input, sizeof(input)) || strcmp(input, "Exit") == 0 || strcmp(input, "exit") == 0) {
            break; //Exit loop on EOF or error
        }

        //Tokenize the input
        char* cmd_args[256]; //Maximum of 256 tokens
        char* token = strtok(input, " \n");
        int i = 0;

        //Adds each token to the cmd_args array
        while (token != nullptr && i < 256) {
            cmd_args[i] = token;
            token = strtok(nullptr, " \n");
            i++;
        }
        cmd_args[i] = nullptr; //Sets the last element to NULL

        //Forks a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error: Fork failed");
            exit(1);
        } 
        
        //Child process
        else if (pid == 0) {
            if (execvp(cmd_args[0], cmd_args) == -1) {
                perror("Error: execvp failed");
                exit(1);
            }
            
            //This code prints tokens in child process from cmd_args
            /*cout << "Tokens in child process:\n";
            for (int j = 0; j < i; j++) {
                cout << "cmd_args[" << j << "] = " << cmd_args[j] << endl;
            }*/
            
            exit(1); //Terminates child process
        } 
        
        //Parent process
        else {

            //Prints if child processes ended as it should
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                cout << "Child process terminated normally" << endl;
            }
        }
    }

    return 0;
}
