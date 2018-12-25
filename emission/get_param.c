void get_ver(){
delay_ms(200);
printf("sys get ver\r\n");
   if(uart_line_received==true)  //if new line received{
   uart_line_received=false;  
  // }
}  

int8 get_mod(){
delay_ms(200);
printf("radio get mod\r\n");
   if(uart_line_received==true)  //if new line received{
   uart_line_received=false;
      if((in_data[0]==108)&&(in_data[1]==111)&&(in_data[2]==114)&&(in_data[3]==97)){
// if answer= lora
      return 1;}
      return 0;//}
}  

int8 get_freq(){
delay_ms(200);
printf("radio get freq\r\n");
   if(uart_line_received==true)  //if new line received{
   uart_line_received=false;
      if((in_data[0]==56)&&(in_data[1]==54)&&(in_data[2]==56)) // if answer= 868
      {
      return 1;}
      return 0;
}
 
int8 get_sf(){
delay_ms(200);
printf("radio get sf\r\n");
   if(uart_line_received==true)  //if new line received
   {
   uart_line_received=false;
      if((in_data[0]==115)&&(in_data[1]==102)&&(in_data[2]==49)&&(in_data[3]==50)){
// if answer= sf12 
return 1;}
 return 0;}
}
 
int8 get_bw(){
delay_ms(200);
printf("radio get bw\r\n");
   if(uart_line_received==true)  //if new line received{
   uart_line_received=false;
      if((in_data[0]==49)&&(in_data[1]==50)&&(in_data[2]==53)) // if answer= 125 
      {
      return 1;}
      return 0;
}  

int8 get_cr()
{
delay_ms(200);
printf("radio get cr\r\n");
   if(uart_line_received==true)  //if new line received{
   uart_line_received=false;
      if((in_data[0]==52)&&(in_data[1]==47)&&(in_data[2]==53)) // if answer= 4/5 
      {
      return 1;}
      return 0;
}  

int8 get_prlen() {
delay_ms(200);
printf("radio get prlen\r\n");
   if(uart_line_received==true)  //if new line received
   {
   uart_line_received=false;
      if(in_data[0]==56) // if answer= 8
      {
      return 1;}
      return 0;}
}  

int8 get_pwr(){
delay_ms(200);
printf("radio get pwr\r\n");
   if(uart_line_received==true)  //if new line received{
   uart_line_received=false;
      if(in_data[0]==52) // if answer= 1
      {
      return 1;}
      return 0;
}  


int8 get_bitrate(){
delay_ms(200);
printf("radio get bitrate\r\n");
   if(uart_line_received==true)  //if new line received
   {
   uart_line_received=false;
      if((in_data[0]==53)&&(in_data[1]==48)&&(in_data[2]==48)&&(in_data[3]==48)){
// if answer= 5000
      return 1;}
      return 0;}
}  

int8 get_crc(){
delay_ms(200);
printf("radio get crc\r\n");
   if(uart_line_received==true)  //if new line received
  {
   uart_line_received=false;      
      if((in_data[0]==111)&&(in_data[1]==110)) // if answer= on
    {
      return 1;}
      return 0;}
}  
