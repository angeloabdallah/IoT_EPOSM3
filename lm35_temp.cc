#include <adc.h>
#include <machine.h>
#include <system/config.h>
#include <alarm.h>

using namespace EPOS;

OStream cout;

ADC a;

int main()
{
	unsigned int temp;
	unsigned int temp_final, t_final;
	int cem, dez;


	//COnfiguração da porta PA5 como entrada
	GPIO b('A', 5, GPIO::IN);

	cout << "porta configurada" << endl; 

	//Cofiguração adc na porta PA5, com referencia no epos e resolução de 12 bits
	ADC a(ADC::SINGLE_ENDED_ADC5, ADC::SYSTEM_REF, ADC::BITS_12);

	cout << "adc configurado" << endl; 

while(1)
{
	Alarm::delay(5000000);

	//Valor digital retornado pelo conversor
	temp = a.read();
	cout << temp << endl; 
	//Valor digital convertido para o valor de tensão que corresponde a temperatura correta
	temp_final = a.convert(temp, 3300);

	t_final = temp_final;

	cem = t_final/10;
	dez = t_final%10; 
;
	cout << " Temperatura : " << cem <<"."<< dez << " C " <<endl;
}
	return 0;
}