#include "defs.h"
#include <stdio.h>
#include <stdlib.h>

#define C1 1
#define C2 2
#define C3 3

int main(){
   unsigned char code_now= NOKEY, code_ante;
   unsigned char kbhit=0,kbcode, loop_cnt=0;

	int lumi=50;  //luminozitatea
   char buf_lumi[4];

   unsigned char stare = C1;
   char buf_pit[4];
   unsigned long int a,b,c;

   sysinit();
   
   while(1){
      if(loop_cnt==200){
         code_ante=code_now;
         code_now = kbscan();
         if(code_now! = NOKEY && code_ante== NOKEY ){
            kbhit=1;
            kbcode=code_now;
         }
         loop_cnt=0;
      }

/*      //PWM start
      if(kbhit  && (kbcode == 'C' || kbcode == 'D')){
         if(kbcode == 'C'){
            //lumi=//...creste luminozitatea
            //...
         }
         if(kbcode == 'D'){
            //lumi=//...scade luminozitatea
            //...
         }
         gotoLC(2,1);
         putsLCD("L=");
         itoa(lumi, buf_lumi, 10);
         putsLCD(buf_lumi);
         putsLCD("%  " );
      }
*/      //PWM end

      if(kbhit){
         gotoLC(1,1);
         kbhit=0;
         putchLCD(kbcode);
      }

/*	  //c pitagoreic start
      if( kbhit && kbcode>='0' && kbcode<='9'){
         kbhit=0;

         switch(stare){
         	case C1:   //cifra 0
               gotoLC(1, 1);
               putsLCD("                ");
               gotoLC(1, 1);
               buf_pit[0]=kbcode;
               scrie prima cifra
               stare=C2;
               break;

            case C2:
               buf_pit[1]=kbcode;
               scrie a doua cifra
               stare=C3;
               break;
         
            case C3:
               buf_pit[2]=kbcode;
               buf_pit[3]='\0';
               scrie a treia cifra
               scrie "Busy... ," pe linia 1, din coloana 8
               calculeaza c

               for(a = 1;...){
                  for(b = 1...){
                     verifica daca a^2 + b^2 = c^2
                  }
               }
               
               gotoLC(1,8);
      		   if(...){
      		      putsLCD("PYTH    ");
      		   }
      		   else{
      		      putsLCD("nonPYTH ");
      		   }
               stare=C1;
               break;
         }//end switch     
      }
*/       // end c pitagoreic      

      kbhit=0;
      loop_cnt++;
   }//end while
}//end main

