//
//  How to access GPIO registers from C-code on the Raspberry-Pi
//  Example program
//  15-January-2012
//  Dom and Gert
//  Revised: 31-05-2017
 
 
// Access from ARM Running Linux

 
 
#include <stdio.h>
#include <stdlib.h>
#include "GPIO_erisim.h"

 
 void bekleme(int a){
	 for(int i=0; i<a;i++){
		 asm("nop");
	 }
 }
 
 /* bekletme süresi
  * 141 - 500Khz
  * 290 - 250Khz
  * 600 - 125Khz
  * 720 - 100Khz
  * 1450 - 50Khz
  */
 
 #define bek 1450
 
int main(int argc, char **argv)
{
 
  // Set up gpi pointer for direct register access
  setup_io();
	
	INP_GPIO(4);
	OUT_GPIO(4);
 
	while(1){
		GPIO_SET = 1<<4;
		bekleme(bek);
		GPIO_CLR = 1<<4;
		bekleme(bek);
	}

  return 0;
 
} // main
 
 


