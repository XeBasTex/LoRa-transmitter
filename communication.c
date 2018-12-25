
void process_int_uart(){
in_data[uart_cptr]=getc();

if (in_data[uart_cptr]==10) //if LF (EOL)
{
uart_cptr=255;
uart_line_cptr++;
uart_line_received=true;
}
uart_cptr++;
}

void reset_RN2483(){
output_low(RN2483_RST);
delay_ms(1);
output_high(RN2483_RST);
delay_ms(1);
}

void zero_in_data(){
int8 i;
for (i=0;i<100;i++){
in_data[i]=0;
}
}

void mac_pause(){
delay_ms(200);
printf("mac pause\r\n");
}

