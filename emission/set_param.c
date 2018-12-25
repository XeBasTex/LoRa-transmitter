int8 set_mod(int8 val_mod)
{
/* val_mod doit être de type int8
   Deux mode possible "lora" ou "fsk":
   pour le mode "lora" val_mod ='l', pour le mode "fsk" val_mod ='f'
   Par défaut mode: "lora"
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
/* Val freq doit être de type int16
   Soit "433,0" MHz soit la plage de fréquence de "863,0 à "870,0" Hz
   Par défaut freq: "868,1" MHz
*/
delay_ms(200);
printf("radio set freq 868000000\r\n");
delay_ms(50);
get_freq();
}  

void set_sf(int8 val_sf)
{
/* val_sf doit être de type int8 et doit être compris entre 7 et 12
   Le facteur de propagation (spread factor) peut prendre 6 valeurs:
   "sf7","sf8","sf9","sf10","sf11" et "sf12"
  
   Par défaut sf: "sf12"
*/
delay_ms (200);
printf("radio set sf sf7\r\n");
delay_ms (50);
get_sf();
}

void set_bw(int8 val_bw)
{
/* val_bw doit être de type int8
   La bande d'émission radio (bandwitch) s'exprime en kHz et peut prendre 3 valeurs "125","250" ou "500"
   Par défaut bw: "125" kHz
*/

delay_ms(200);
printf("radio set bw %u\r\n",val_bw);
delay_ms(50);
get_bw();
}  

void set_pwr(int8 val_pwr)
{
/* val_pwr doit être de type int8
   La puissance s'exprime en dB et va de "-3" à "15" dB
   Par défaut pwr: "1" dB
*/
delay_ms(200);
printf("radio set pwr %u\r\n",val_pwr);
delay_ms(50);
get_pwr();
}
void set_bitrate(int16 val_bitrate){
/* val_bitrate doit être de type int16 !
   Le débit binaire (bit rate) varie de "0" à "65535"
   et ne peut être réglé qu'en mode fsk
   Par défaut bitrate: "5000"
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
/* val_crc doit être de type int8
   L'en-tête crc peut être dans deux état "on" ou "off";
   Pour le mode "on" val_crc ="1" et pour le mode "off" val_crc = "0" 
   Par défaut crc: "on"
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
/* val_prlen doit être de type unsigned short
   La taille de l'en-tête crc (crc header) varie de "0" à "65535"
   Par défaut crc: "8"
*/
delay_ms(200);
printf("radio set prlen 8\r\n");
delay_ms(50);
get_prlen();
}
