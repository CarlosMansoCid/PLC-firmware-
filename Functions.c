//Programa que contiene la definicion de todas las funciones utilizadas en el programa principal


#include<LCD420.C>

/*Funcion de actualizar imagen de ENTRADAS*/
void REFRESH_IMG_IN(){
   int1 I0_IMG = I0_STATE;
   int1 I1_IMG = I1_STATE;
   int1 I2_IMG = I2_STATE;
   int1 I3_IMG = I3_STATE;
   int1 I4_IMG = I4_STATE;
   int1 I5_IMG = I5_STATE;
   int1 I6_IMG = I6_STATE;
   int1 I7_IMG = I7_STATE;
}

/*Funcion de actualizar imagen de SALIDAS*/
void REFRESH_OUT_IMG(){
   output_bit(Q0, !Q0_IMG);
   output_bit(Q1, !Q1_IMG);
   output_bit(Q2, !Q2_IMG);
   output_bit(Q3, !Q3_IMG);  
}

/*Rutina de chequeo de errores de hardware*/
void PLC_CHECK_HDW_STATUS(){ 
   
  /*Error No.1: Falla de alimentacion*/
   if (input(SRC_SENSE) == 0){
      ERR_FLAG = 1;
       
   
   }
   else{
      ERR_FLAG = 0;
       
   }   
}



/*Rutina de chequeo de modo de ejecucion*/
void PLC_CHECK_MODE(){
   
   if (input(RUN_MODE)==1){
      RUN_FLAG = 1;
   }
   else{
      RUN_FLAG = 0;
   }   
}



/*Rutina de ejecucion del programa de usuario*/
void PLC_RUN(){
   
   if (input(PIN_A2) == 1){
 
    //el programa de usuario aqui  
      Q0_IMG = 1;
      }else{
	Q0_IMG = 0; 
      }
}

/*Rutina de parada*/
void PLC_STOP(){
 
   output_high(Q0);
   output_high(Q1);
   output_high(Q2);
   output_high(Q3);
     
}



/*Rutina de programacion del PLC*/
void PLC_PROG(){
   
   PLC_STOP();
   
     
}

/*Actualizar salidas en display*/
void REFRESH_OUT_LCD(){
 
   if (Q0_IMG == 0){
	    lcd_gotoxy(1,3); 
	    lcd_putc("OUT1");
	    lcd_gotoxy(1,4); 
	    lcd_putc("=OFF");	 
	    } else{	       
	    lcd_gotoxy(1,3); 
	    lcd_putc("OUT1");
	    lcd_gotoxy(1,4); 
	    lcd_putc("=ON");
	    }
	    
	    if (Q1_IMG == 0){
	    lcd_gotoxy(6,3); 
	    lcd_putc("OUT2");
	    lcd_gotoxy(6,4); 
	    lcd_putc("=OFF");	 
	    } else{	       
	    lcd_gotoxy(6,3); 
	    lcd_putc("OUT2");
	    lcd_gotoxy(6,4); 
	    lcd_putc("=ON");
	    }
	    
	    if (Q2_IMG == 0){
	    lcd_gotoxy(11,3); 
	    lcd_putc("OUT3");
	    lcd_gotoxy(11,4); 
	    lcd_putc("=OFF");	 
	    } else{	       
	    lcd_gotoxy(11,3); 
	    lcd_putc("OUT3");
	    lcd_gotoxy(11,4); 
	    lcd_putc("=ON");
	    }
	    
	    if (Q3_IMG == 0){
	    lcd_gotoxy(16,3); 
	    lcd_putc("OUT4");
	    lcd_gotoxy(16,4); 
	    lcd_putc("=OFF");	 
	    } else{	       
	    lcd_gotoxy(16,3); 
	    lcd_putc("OUT4");
	    lcd_gotoxy(16,4); 
	    lcd_putc("=ON");
	    }
	 }


/*Muestra el estado del PLC en indicadores y perifericos*/
void SHOW_PLC_STATE(){
   lcd_putc("\f");    
   if ( ERR_FLAG == 1){
      output_high(ERR_STATE);
      output_low(RUN_STATE);
      output_low(STP_STATE);
      lcd_gotoxy(4,1); 
      lcd_putc("ERROR CODE:");
      }
      else
      if(ERR_FLAG == 0 && RUN_FLAG == 0){
	 output_low(ERR_STATE);
	 output_low(RUN_STATE);
	 output_high(STP_STATE);
	 lcd_gotoxy(4,1); 
	 lcd_putc("Stop");
	 
      }
      else if (ERR_FLAG == 0 && RUN_FLAG == 1){
	 output_low(ERR_STATE);
	 output_high(RUN_STATE);
	 output_low(STP_STATE);
	 lcd_gotoxy(1,1); 
	 lcd_putc("Running...\n");
	  lcd_putc("____________________");
	 REFRESH_OUT_LCD();
	 
	 
	
	 
      }
      else{
	 output_high(ERR_STATE);
	 output_low(RUN_STATE);
	 output_low(STP_STATE); 
      }	 

}
















