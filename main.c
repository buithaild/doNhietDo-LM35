#include <main.h>

void main()
{
   float Tam,GiaTriADC;
   float NhietDo;
   
   lcd_init();//khoi tao lcd
   lcd_putc('\f');//xoa man hinh lcd
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"DO NHIET DO LM35");
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0_AN1_VSS_VREF);
   set_adc_channel(0);
   
   
   while(TRUE)
   {
      //TODO: User Code
      GiaTriADC = read_adc();
      Tam = (GiaTriADC*5)/1023.0f;// hay con goi la gia tri dien ap
      /*
         Ta co 10mV --> 1 do C
         -->   xV  ---> ? do C
         =====> ? = xV*1/10mv(0.01V)
      */
      NhietDo = Tam *100.0f;// nhan 100 = chia 0.01V
      lcd_gotoxy(1,2);
      printf(lcd_putc,"NHIETDO:%02.2f",NhietDo);
      lcd_putc(223);
      lcd_putc("C");
      
   }

}

