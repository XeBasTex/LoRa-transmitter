#include <18F2685.h>
#DEVICE ICD=true
#use delay(clock=20M)
#fuses HS,NOPROTECT,NOLVP,NOWDT
#use rs232(baud=57600, xmit=PIN_C6, rcv=PIN_C7, PARITY=N, TIMEOUT=250)

#define LED1 PIN_C0
#define RN2483_RST PIN_B4

#include "can-18xxx8.c"
#include "global_vars.h"
#include "communication.c"
#include "get_param.c"
#include "set_param.c"
#include "default_param.c"
#define lora 300
#define imu 100

#int_rda
void rcv_uart(){
process_int_uart();
}

void main()
{
struct rx_stat ma_stat;
//int8 in_data[2]={2,2};
//int8 rx_len = 2,i;
//int8 lecture = 0;
int8 i = 0;

//setup_spi(SPI_MASTER|SPI_L_TO_H|SPI_XMIT_L_TO_H|SPI_CLK_DIV_4); //On utilise le microproc
//setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2);
//can_init(); // initialisation du CANBUS
//can_set_baud(); //La fusée est alimenté, on buzz 2 fois court

disable_interrupts(INT_AD);
enable_interrupts(INT_RDA);
enable_interrupts(global);

reset_RN2483();
zero_in_data();


//get_ver();
//get_mod();


set_default_param();
delay_ms(200);


mac_pause();

//printf("radio set pwr 14\r\n");
delay_ms(200);

   
while(TRUE) {

//mac_pause();



output_high(LED1);
printf("radio tx %u\r\n",i);

delay_ms(50);

output_low(LED1);

i++;
   }
}
