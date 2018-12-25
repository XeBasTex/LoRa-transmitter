void set_default_param()
{
set_mod('l');           //communication en mode lora

set_freq(8681);    //fr�quence d'�mission 868.1 MHz

set_sf(12);             //facteur de propagation de 12

set_bw(125);            //bande passante 125 kHz

set_pwr(14);             //puissace du signal 1 dB

set_crc(1);             //en-t�te CRC active

set_prlen(8);           //en-t�te CRC de 8 bits

set_bitrate(5000);      //d�bit binaire 5000 bps
}
