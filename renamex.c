// -*- coding:utf-8 -*-
// Time-stamp: <Feb 08 2012>
// rename all arguments as a file list

// this program will do
// - add extension to files
// - delete extension to files that already have the extension

// usage:
// put a shortcut icon of 'renamex' to
//   C:\Users\<YOUR USERNAME>\AppData\Roaming\Microsoft\Windows\SendTo (Windows7)
//   C:\Documents and Settings\<YOUR USERNAME>\SendTo (WindowsXP)

// how to compile (with gnupack-devel 7.02):
//    gcc -O2 -mwindows -o renamex.exe renamex.c ; strip renamex.exe

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
    char ext_str[256];
    memset(ext_str, 0x00, 256);

    // command line option
    //
    while((opt = getopt(argc, argv, "e:")) != -1){
        switch(opt){
        case 'e':
            //printf("dir = %s\n", optarg);
            strncpy(ext_str, optarg, 255);
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

    // confirm specifying ext_str
    //
    if (*ext_str == '\0'){
        strncpy(ext_str, DEFAULT_EXTENSION, 255);
    }

    for (i=0; i<argc; i++){
        if (stat(argv[i], &sb)){
            printf("%s is not found\n", argv[i]);
        }else{
            char newname[1024];
            char *p;
            memset(newname, 0x00, 1024);
            strncpy(newname, argv[i], 1023);

            //if newname = "aa.xx", strlen(newname)== 5, strlen(ext_str)==3
            p = newname + strlen(newname) - strlen(ext_str);
            if (strncmp(ext_str, p, 1023) == 0){
                //delete extension
                 *p = '\0';
            }else{
                //add extension
                strncat(newname, ext_str, 1023);
            }

            if (rename(argv[i], newname)){
                printf("err: rename %s to %s in fail\n", argv[i], newname);
                exit(EXIT_FAILURE);
            }
        }
    }

    exit(EXIT_SUCCESS);
}
