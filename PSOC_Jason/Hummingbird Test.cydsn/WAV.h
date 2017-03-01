/*
A simple sound library for CSE 20211 by Douglas Thain
For course assignments, you should not change this file.
For complete documentation, see:
http://www.nd.edu/~dthain/courses/cse20211/fall2013/wavfile
*/

#ifndef WAV_H
#define WAV_H

#include <stdio.h>
#include <inttypes.h>

#define WAVFILE_SAMPLES_PER_SECOND 1024
    
FILE * wavfile_open( const char *filename );
void wavfile_write( FILE *file, short data[], int length );
void wavfile_close( FILE * file );



#endif