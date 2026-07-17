#include <LPC21xx.h>
#include "delay.h"
#include "can.h"

CANF rxF;

int main(){
	unsigned char n;
	Init_CAN1();
	IODIR0|=0xFF;
	IOSET0=	0xFF;
	while(1){
	 	if(C1GSR&0X01){
			CAN1_Rx(&rxF);
			C1CMR=(0x04);
			if(rxF.ID==1){
				if(rxF.Data1==1){
					while(1){
		 				n=0x01;
						while(n){
						 	IOCLR0=n;
							delay_ms(200);
							n=n<<1;
							if(C1GSR&1){
							 	CAN1_Rx(&rxF);
								if(rxF.ID==1)
									if(rxF.Data1!=1)
										break;
							}
						}
						IOSET0=0xFF;
						delay_ms(200);
						if(rxF.ID==1)
							if(rxF.Data1!=1)
								break;
					}
				}else if(rxF.Data1==2){
					while(1){
			 			n=0x80;
						while(n){
						 	IOCLR0=n;
							delay_ms(200);
							n=n>>1;
							if(C1GSR&1){
								CAN1_Rx(&rxF);
								if(rxF.ID==1)
								       if(rxF.Data1!=2)
										break;
							}
						}
						IOSET0=0xFF;
						delay_ms(200);
						if(rxF.ID==1)
						       if(rxF.Data1!=2)
								break;
					}
				}else{
				 	IOSET0=0xFF;	 
				}
			}
		}
	}
}
