int8 set_mod(int8 val_mod)
{
/* val_mod doit �tre de type int8
   Deux mode possible "lora" ou "fsk":
   pour le mode "lora" val_mod ='l', pour le mode "fsk" val_mod ='f'
   Par d�faut mode: "lora"
*/
if(val_mod=='l'){
delay_ms(200);
printf("radio set mod lora\r\n");
delay_ms(50);
}
else{
   if(val_mod=='f'){
   delay_ms(200);
   printf("radio set mod fsk\r\n");
   delay_ms(50);
   }
}
return val_mod;
}  

void set_freq(int16 val_freq)
{
/* Val freq doit �tre de type int16
   Soit "433,0" MHz soit la plage de fr�quence de "863,0 � "870,0" Hz
   Par d�faut freq: "868,1" MHz
*/
delay_ms(200);
printf("radio set freq 868000000\r\n");
delay_ms(50);
get_freq();
}  

void set_sf(int8 val_sf)
{
/* val_sf doit �tre de type int8 et doit �tre compris entre 7 et 12
   Le facteur de propagation (spread factor) peut prendre 6 valeurs:
   "sf7","sf8","sf9","sf10","sf11" et "sf12"
  
   Par d�faut sf: "sf12"
*/
delay_ms (200);
printf("radio set sf sf7\r\n");
delay_ms (50);
get_sf();
}

void set_bw(int8 val_bw)
{
/* val_bw doit �tre de type int8
   La bande d'�mission radio (bandwitch) s'exprime en kHz et peut prendre 3 valeurs "125","250" ou "500"
   Par d�faut bw: "125" kHz
*/

delay_ms(200);
printf("radio set bw %u\r\n",val_bw);
delay_ms(50);
get_bw();
}  

void set_pwr(int8 val_pwr)
{
/* val_pwr doit �tre de type int8
   La puissance s'exprime en dB et va de "-3" � "15" dB
   Par d�faut pwr: "1" dB
*/
delay_ms(200);
printf("radio set pwr %u\r\n",val_pwr);
delay_ms(50);
get_pwr();
}
void set_bitrate(int16 val_bitrate){
/* val_bitrate doit �tre de type int16 !
   Le d�bit binaire (bit rate) varie de "0" � "65535"
   et ne peut �tre r�gl� qu'en mode fsk
   Par d�faut bitrate: "5000"
*/
int8 val_mod;
val_mod = get_mod();
delay_ms(200);
printf("radio set bitrate 5000\r\n");
delay_ms(50);
get_bitrate();
}
 
void set_crc(int8 val_crc)
{
/* val_crc doit �tre de type int8
   L'en-t�te crc peut �tre dans deux �tat "on" ou "off";
   Pour le mode "on" val_crc ="1" et pour le mode "off" val_crc = "0" 
   Par d�faut crc: "on"
*/

if(val_crc==1){
delay_ms(200);
printf("radio set crc on\r\n");
delay_ms(50);
}
else{
   if(val_crc==0){
   delay_ms(200);
   printf("radio set crc off\r\n");
   delay_ms(50);
   }
}
get_crc();
}

void set_prlen(unsigned short val_prlen)
{
/* val_prlen doit �tre de type unsigned short
   La taille de l'en-t�te crc (crc header) varie de "0" � "65535"
   Par d�faut crc: "8"
*/
delay_ms(200);
printf("radio set prlen 8\r\n");
delay_ms(50);
get_prlen();
}
