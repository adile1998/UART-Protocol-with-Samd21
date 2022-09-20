//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "sam.h"
#include "definitions.h"
#include "delay.h"
#include "app.h"
#include "SERCOMforUSART.h"

//////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////
void ClocksInit(void);	// Configure Clock, Wait States and synch, bus clocks for 48MHz operation
uint8_t GelenData[100];
int i = 0;
/*******************************************************************************
 * Function:        void main(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This is our main function
 *
 * Note:
 *
 ******************************************************************************/
int main(void){
	AppInit(); // clock has been started and port which is needed is configed.
	uartInit(115200);
	
	// Super loop
	while(1)
	{
		
	}
	
} // main()

void SERCOM3_Handler(){
	
		GelenData[i] = SERCOM3->USART.DATA.bit.DATA; // This flag is cleared by reading the Data register (DATA) or by disabling the receiver.

		if (GelenData[i] == '*')
		{	
			uartWrite(GelenData + i, 1);
			i = 0;
			uint8_t sonKontrol[] = "son deger geldi\r";
			uartWrite(sonKontrol, 16);
		}
		else{	
			uartWrite(GelenData + i, 1);
			i += 1;
		}
			
}


