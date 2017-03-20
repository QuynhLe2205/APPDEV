/* This program is just for testing */
#include "wave.h"	// double quotion marks are used for user defined header
#include <stdio.h>
#include <math.h>
#include <signal.h>
#include <sys/wait.h>
#include "screen.h"
#include <stdlib.h>	// eliminate the warning when -c99 standard is used

int main(int argc, char *argv[]){
	FILE *fp;
	WAVHDR myhdr;
	short int sa[SAMPLE_RATE];
	int answer, ret;
/*	if (argc !=2){
		printf("Usage: %s wave_file\n", argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r");	// try to open the wav file
	if (fp==NULL){
		printf("Cannot find file %s\n", argv[1]);
		return -1;
	}*/
	for(;;){
		ret = system("arecord -r16000 -c1 -d1 -f S16_LE -q data.wav");	// return SIGNALING
		clearScreen();	// a fresh screen to display
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT||WTERMSIG(ret)==SIGQUIT))break;
		fp = fopen("data.wav", "r");	// open the wav file to read data
		fread(&myhdr, sizeof(myhdr), 1, fp);	// read wav header
		displayWAVHDR(myhdr);		// display wav header
		fread(&sa, sizeof(short int), SAMPLE_RATE, fp);	// read wav samples
		displayWAVdata(sa);		// calculate RMS values and display them
		fclose(fp);			// close the opened file
	}
	printf("Do you want to generate a test tone? (1: yes, 0: no)\n");
	scanf("%d", &answer);
	if(answer == 1) testTone(440, 5);
}

