// -*- coding:utf-8 -*-
// Time-stamp: <Feb 02 2012>
// rename all arguments as a file list

// this program will do
// - add extension to all files

// usage:
// put a shortcut icon of 'renamex' to C:\Users\<YOUR USERNAME>\AppData\Roaming\Microsoft\Windows\SendTo (Windows7) 

// how to compile (with gnupack-devel 7.02):
//    gcc -O2 -mwindows -o confexec.exe confexec.c ; strip confexec.exe

#define DEFAULT_EXTENSION ".xx"

#include <sys/types.h> // stat()
#include <sys/stat.h> // stat()
#include <unistd.h> // stat()
#include <stdio.h> // printf(), rename()
#include <stdlib.h> // exit(), system()
#include <string.h> // memset(), strncpy(), strncat()
#include "getopt.h" //getopt()

int main(int argc, char **argv){
    // variables for getopt
    //
    int opt;
    extern char *optarg;
    extern int optind, opterr;

    // variables
    //
    struct stat sb;
    int i;
    char extname[256];
    memset(extname, 0x00, 256);

    // command line option
    //
    while((opt = getopt(argc, argv, "e:")) != -1){
        switch(opt){
        case 'e':
            //printf("dir = %s\n", optarg);
            strncpy(extname, optarg, 255);
            break;
        default:
            break;
        }
    }
    argc -= optind;
    argv += optind;

    // confirm existance of argv[0]
    //
    if(argc < 1) exit(EXIT_FAILURE);
    //printf("error arg (%d) = %s\n", argc, argv[0]); exit(-1);

    // confirm specifying extname
    //
    if (*extname == '\0'){
        strncpy(extname, DEFAULT_EXTENSION, 255);
    }

    for (i=0; i<argc; i++){
        if (stat(argv[i], &sb)){
            printf("%s is not found\n", argv[i]);
        }else{
            char newname[1024];
            memset(newname, 0x00, 1024);
            strncpy(newname, argv[i], 1023);
            strncat(newname, extname, 1023);
            if (rename(argv[i], newname)){
                printf("err: rename %s to %s in fail\n", argv[i], newname);
                exit(EXIT_FAILURE);
            }
        }
    }

    exit(EXIT_SUCCESS);
}
