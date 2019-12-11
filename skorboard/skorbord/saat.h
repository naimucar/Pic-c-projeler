//////////////////////////////////////////////////////////////      
// ds1307 ye veri yollamak i�in s_yaz komutunu kullan�n     // 
// s_yaz(veri adresi,ilgili veri hex olarak )               // 
// ds1307 den veri almak i�in s_oku yu kullan�n             // 
// veri=s_oku(veri adresi) burada d�n�� de�eri hex tiplidir // 
// adresler:                                                // 
// saniye   ==>0                                            //
// dakika   ==>1                                            // 
// saat     ==>2                                            // 
// g�n      ==>4                                            // 
// ay       ==>5                                            // 
// y�l      ==>6                                            // 
//////////////////////////////////////////////////////////////  


// SC ve SD pinlerinini isterseniz tan�mlayabilirsiniz
#ifndef SD
#define SD PIN_E1 
#endif
#ifndef SC       
#define SC PIN_E0
#endif
#use I2C(master, sda=SD, scl=SC)

void s_init() {
   output_float(SC);
   output_float(SD);
}

BOOLEAN ext_eeprom_ready() {
   int1 ack;
   i2c_start();            
   ack = i2c_write(0xd0);  
   i2c_stop();
   return !ack;
}

void s_yaz(unsigned int8 addres, unsigned int8 data) {
   while(!ext_eeprom_ready());
   i2c_start();
   i2c_write(0xd0);
   i2c_write(addres);
   i2c_write(data);
   i2c_stop();
}


unsigned int8 s_oku(unsigned int8 addres) 
{
   unsigned int8 data;

   while(!ext_eeprom_ready());
   i2c_start();
   i2c_write(0xd0);
   i2c_write(addres);
   i2c_start();
   i2c_write(0xd1);
   data=i2c_read(0);
   i2c_stop();
   return(data);
}
