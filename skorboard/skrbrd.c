#include<16f877.h>
#use delay(clock=4000000)
#fuses xt,noprotect,nowdt
#include<ekran.h>





void main()
{
int y=0,a=0;
output_b(0x00);
lcd_init();
printf(lcd_putc,"\fADI-SOYADI");
DELAY_ms(3000);
printf(lcd_putc,"\fBASLATMAK iCiN   ");
lcd_gotoxy(2,1);
printf(lcd_putc," BUTONA BASINIZ  ");
while(1)
{if(input(pin_a0)==1)
{delay_ms(300);
goto ana;}}
ana:
 {
  printf(lcd_putc,"\fiYi EGLENCELER  ");
   delay_ms(1000);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"\fHOME  ");
   delay_ms(1000);
   lcd_gotoxy(1,8);
   printf(lcd_putc,"OPPOSiTE  ");
   delay_ms(1000);
   lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d" ,y);
   delay_ms(500);
   lcd_gotoxy(2,11);
   printf(lcd_putc,"%02d",a);
if(input(pin_a1)==1)
{
delay_ms(300);
goto HA;
}
if(input(pin_a2)==1)
{goto HE;}
if(input(pin_a3)==1)
{goto OA;}
if(input(pin_a4)==1)
{goto OE;}
//if(input(pin_a1)==1)
//{goto rst;}
}
HA:
y++;
   lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d",y);
   delay_ms(500);
  
HE:
{delay_ms(300);
y--;
   lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d" ,y);
   delay_ms(500);
if(y=-1)
{y=0;
lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d" ,y);
   delay_ms(500);
}
}
OA:
{
delay_ms(300);
a++;
   lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d" ,a);
   delay_ms(500);
}
OE:
{
delay_ms(300);
a--;
   lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d" ,a);
   delay_ms(500);
if(y=-1)
{y=0;
lcd_gotoxy(2,1);
   printf(lcd_putc,"%02d" ,a);
   delay_ms(500);
}
}



}
