///////////Definicion de imagen de entradas y salidas///////////////////////////////////////////////
int1 I0_IMG = 0;
int1 I1_IMG = 0;
int1 I2_IMG = 0;
int1 I3_IMG = 0;
int1 I4_IMG = 0;
int1 I5_IMG = 0;
int1 I6_IMG = 0;
int1 I7_IMG = 0;

int1 Q0_IMG = 0;
int1 Q1_IMG = 0;
int1 Q2_IMG = 0;
int1 Q3_IMG = 0;

///////////Definicion  de ENTRADAS///////////////////////////////////
#define I0 PIN_B0
#define I1 PIN_B1
#define I2 PIN_B2
#define I3 PIN_B3
#define I4 PIN_B4
#define I5 PIN_B5
#define I6 PIN_B6
#define I7 PIN_B7

///////////Estado de ENTRADAS////////////////////
#define I0_STATE  input(I0)
#define I1_STATE  input(I1)
#define I2_STATE  input(I2)
#define I3_STATE  input(I3)
#define I4_STATE  input(I4)
#define I5_STATE  input(I5)
#define I6_STATE  input(I6)
#define I7_STATE  input(I7)

///////////Definicion de SALIDAS////////////////////////////////////////////////////
#define Q0 PIN_D0
#define Q1 PIN_D1
#define Q2 PIN_D2
#define Q3 PIN_D3

//////////Definicion de indicadores de estado////////////////////////////////
#define ERR_STATE PIN_D5
#define RUN_STATE PIN_D6
#define STP_STATE PIN_D7

/////////Definicion de variables de estado////////////////////////////////////
int1 RUN_FLAG,ERR_FLAG,STP_FLAG;

////////Definicion de entradas de control/////////////////////////////////////
#define SRC_SENSE PIN_A0
#define RUN_MODE PIN_A1

////////LCD/////////////////////////////////////////////////////////////////////////////
#define LCD_ENABLE_PIN  PIN_C0                                    
#define LCD_RS_PIN      PIN_C1                                   
#define LCD_RW_PIN     PIN_C2                                    
#define LCD_DATA4       PIN_C4                                    
#define LCD_DATA5       PIN_C5                                    
#define LCD_DATA6       PIN_C6                                    
#define LCD_DATA7       PIN_C7 

