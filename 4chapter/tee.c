#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>

/*
tee file1 file2 ....
supported options 
-a --> append to the files
-h --> show help to the command
*/

#define INPUT_SIZE 1024
#define EXIT_SUCCESS 0
#define EXIT_FAILUER 1
const char *USAGE_MSG =  "Usage: tee <file1> <file2>...";
const char *OPT_STRING =  ":ah";
bool isappend = false;

void print_usage(){
    printf("%s\n", USAGE_MSG);
}

int main(int argc, char ** argv){

    // if(argc < 2 ){
    //     print_usage();
    //     return EXIT_FAILUER;
    //
    // }

    int opt , argcc = argc - 1;
    while((opt = getopt(argc, argv, OPT_STRING)) != -1){
        switch(opt){
            /* Append at each file*/
            case 'a':{
                isappend = true;
                --argcc;
                break;
            }

            case 'h':{
                print_usage();
                return EXIT_SUCCESS;
                break;
            }

            /*missing argument*/
            // case ':':{
            //     print_usage();
            //     printf("Missing argument for \"-%c\"\n", optopt);
            //     break;
            // }

            /*unrecognized option*/
            case '?':{
                print_usage();
                printf("Unrecognzied option \"-%c\"\n", optopt);
                return EXIT_SUCCESS;
                break;
            }

            default:
                printf("ERROR");

        }
    }

    int fd_arr[argcc] = {};
    char input [INPUT_SIZE] =  {0};
    if(read(STDIN_FILENO, input, INPUT_SIZE) == -1)
        perror("ERROR: ");

    // input[strcspn(input, "\n")] = '\0';

    if(write(STDOUT_FILENO, input, strlen(input)) == -1){
        perror("Error writing to stdout");
    }

    int openFlags;
    mode_t filePerms;
    bool iswritable = true;

    /* Loop through Operands(files)*/
    for(size_t i = 0 ; optind < argc; optind++, i++){
        openFlags = O_CREAT | O_WRONLY ;
        if(isappend) openFlags |= O_APPEND;
        else openFlags |= O_TRUNC;

        /*rw-rw-rw-*/
        filePerms = S_IRUSR | S_IWUSR | 
                    S_IRGRP | S_IWGRP |
                    S_IROTH | S_IWOTH;

        fd_arr[i] = open(argv[optind], openFlags , filePerms);

        if(fd_arr[i] == -1) {
            iswritable = false;
            printf("Error opening file %s: %s", argv[optind], strerror(errno));
         }   

        /*Write to files*/
        if(iswritable){
            if(write(fd_arr[i], input, strlen(input)) == -1){
                printf("ERROR: %s | opening %s", strerror(errno), argv[optind]);
            }
        }
        close(fd_arr[i]);
    }

    return EXIT_SUCCESS;
}
