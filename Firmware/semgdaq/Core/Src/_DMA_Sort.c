/*
 * _DMA_Sort.c
 *
 *  Created on: Sep 14, 2024
 *  Author: Mwangi Alex. W
 *
 *  Defines all the functions that implement the sorting algorithm for all ADCs
 */
//INCLUDES
#include "_DMA_Sort.h"

//VARIABLES
uint8_t ADC1_Current_buffer = 1;
uint8_t ADC2_Current_buffer = 1;
uint8_t ADC3_Current_buffer = 1;

//FUNCTION DEFINITIONS
void ADC1_DMA_sort_uhb (void)
{
  if(ADC1_Current_buffer == 1)
  {
	for(uint32_t m=0; m<ADC_DMA_HALFBUFFERSIZE-1; m++)  //Scans the upper half of the DMA buffer
	{
		if(m==0 || (m%2==0)) // Checks that the buffer register location is even and loads the data
		{
			for(uint32_t n=0; n<ADC_DMA_QUATERBUFFERSIZE-1; n++)  // Stores data on the upper half of IN1 channel data buffer
			{
				ADC1_DMA_sort_ptr->ADC1_IN1_bfr[n] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
		else  // Checks that the buffer register location is odd and loads the data
		{
			for(uint32_t p=0; p<ADC_DMA_QUATERBUFFERSIZE-1; p++)  // Stores data on the upper half of IN2 channel data buffer
			{
				ADC1_DMA_sort_ptr->ADC1_IN2_bfr[p] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
     }
  }
  else
  {
	  for(uint32_t m=0; m<ADC_DMA_HALFBUFFERSIZE-1; m++)  //Scans the upper half of the DMA buffer
	  	{
	  		if(m==0 || (m%2==0)) // Checks that the buffer register location is even and loads the data
	  		{
	  			for(uint32_t n=0; n<ADC_DMA_QUATERBUFFERSIZE-1; n++)  // Stores data on the upper half of IN1 channel data buffer
	  			{
	  				ADC1_DMA_sort_ptr->ADC1_IN1_bfr_alt[n] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
	            }
	        }
	  		else  // Checks that the buffer register location is odd and loads the data
	  		{
	  			for(uint32_t p=0; p<ADC_DMA_QUATERBUFFERSIZE-1; p++)  // Stores data on the upper half of IN2 channel data buffer
	  			{
	  				ADC1_DMA_sort_ptr->ADC1_IN2_bfr_alt[p] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
	  			}
	  		}
	     }

  }
};


void ADC1_DMA_sort_lhb (void)
{
  if (ADC1_Current_buffer == 1)
  {
	for(uint32_t m=ADC_DMA_HALFBUFFERSIZE; m<ADC_DMA_BUFFERSIZE-1; m++) // Scans the lower half of the DMA buffer
	{
		if(m==0||(m%2==0)) // Checks that the buffer register location is even and loads the data
		{
			for(uint32_t n=ADC_DMA_QUATERBUFFERSIZE; n<ADC_DMA_HALFBUFFERSIZE-1; n++)  // Stores data on the lower half of IN1 channel data buffer
			{
				ADC1_DMA_sort_ptr->ADC1_IN1_bfr[n] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
		else  // Checks that the buffer register location is odd and loads the data
		{
			for(uint32_t p=ADC_DMA_QUATERBUFFERSIZE; p<ADC_DMA_HALFBUFFERSIZE-1; p++)  // Stores data on the lower half of IN2 channel data buffer
			{
				ADC1_DMA_sort_ptr->ADC1_IN2_bfr[p] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
     }

	ADC1_Current_buffer = 2;
  }

  else
  {
	for(uint32_t m=ADC_DMA_HALFBUFFERSIZE; m<ADC_DMA_BUFFERSIZE-1; m++) // Scans the lower half of the DMA buffer
	{
		if(m==0||(m%2==0)) // Checks that the buffer register location is even and loads the data
		{
			for(uint32_t n=ADC_DMA_QUATERBUFFERSIZE; n<ADC_DMA_HALFBUFFERSIZE-1; n++)  // Stores data on the lower half of IN1 channel data buffer
			{
				ADC1_DMA_sort_ptr->ADC1_IN1_bfr_alt[n] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
		else  // Checks that the buffer register location is odd and loads the data
		{
			for(uint32_t p=ADC_DMA_QUATERBUFFERSIZE; p<ADC_DMA_HALFBUFFERSIZE-1; p++)  // Stores data on the lower half of IN2 channel data buffer
			{
				ADC1_DMA_sort_ptr->ADC1_IN2_bfr_alt[p] = ADC1_DMA_sort_ptr->ADC1_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
	 }

	ADC1_Current_buffer = 1;
   }

};


void ADC2_DMA_sort_uhb (void)
{
  if(ADC2_Current_buffer == 1)
  {
	for(uint32_t m=0; m<ADC_DMA_HALFBUFFERSIZE-1; m++)
	{
		if(m==0 || (m%2==0))
		{
			for(uint32_t n=0; n<ADC_DMA_QUATERBUFFERSIZE-1; n++)
			{
				ADC2_DMA_sort_ptr->ADC2_IN3_bfr[n] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
		else
		{
			for(uint32_t p=0; p<ADC_DMA_QUATERBUFFERSIZE-1; p++)
			{
				ADC2_DMA_sort_ptr->ADC2_IN4_bfr[p] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
     }
   }

  else
  {
  	for(uint32_t m=0; m<ADC_DMA_HALFBUFFERSIZE-1; m++)
  	{
  		if(m==0 || (m%2==0))
  		{
  			for(uint32_t n=0; n<ADC_DMA_QUATERBUFFERSIZE-1; n++)
  			{
  				ADC2_DMA_sort_ptr->ADC2_IN3_bfr_alt[n] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
  		else
  		{
  			for(uint32_t p=0; p<ADC_DMA_QUATERBUFFERSIZE-1; p++)
  			{
  				ADC2_DMA_sort_ptr->ADC2_IN4_bfr_alt[p] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
  			}
  		}
     }
   }

};


void ADC2_DMA_sort_lhb (void)
{
  if(ADC2_Current_buffer == 1)
  {
	for(uint32_t m=ADC_DMA_HALFBUFFERSIZE; m<ADC_DMA_BUFFERSIZE-1; m++)
	{
		if(m==0||(m%2==0))
		{
			for(uint32_t n=ADC_DMA_QUATERBUFFERSIZE; n<ADC_DMA_HALFBUFFERSIZE-1; n++)
			{
				ADC2_DMA_sort_ptr->ADC2_IN3_bfr[n] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
		else
		{
			for(uint32_t p=ADC_DMA_QUATERBUFFERSIZE; p<ADC_DMA_HALFBUFFERSIZE-1; p++)
			{
				ADC2_DMA_sort_ptr->ADC2_IN4_bfr[p] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
	}

	ADC2_Current_buffer = 2;
  }
  else
  {
  	for(uint32_t m=ADC_DMA_HALFBUFFERSIZE; m<ADC_DMA_BUFFERSIZE-1; m++)
  	{
  		if(m==0||(m%2==0))
  		{
  			for(uint32_t n=ADC_DMA_QUATERBUFFERSIZE; n<ADC_DMA_HALFBUFFERSIZE-1; n++)
  			{
  				ADC2_DMA_sort_ptr->ADC2_IN3_bfr_alt[n] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
  		else
  		{
  			for(uint32_t p=ADC_DMA_QUATERBUFFERSIZE; p<ADC_DMA_HALFBUFFERSIZE-1; p++)
  			{
  				ADC2_DMA_sort_ptr->ADC2_IN4_bfr_alt[p] = ADC2_DMA_sort_ptr->ADC2_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
  			}
  		}
  	 }

  	ADC2_Current_buffer = 1;
   }

};


void ADC3_DMA_sort_uhb (void)
{
  if(ADC3_Current_buffer == 1)
  {
	for(uint32_t m=0; m<ADC_DMA_HALFBUFFERSIZE-1; m++)
	{
		if(m==0 || (m%2==0))
		{
			for(uint32_t n=0; n<ADC_DMA_QUATERBUFFERSIZE-1; n++)
			{
				ADC3_DMA_sort_ptr->ADC3_IN1_bfr[n] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
		else
		{
			for(uint32_t p=0; p<ADC_DMA_QUATERBUFFERSIZE-1; p++)
			{
				ADC3_DMA_sort_ptr->ADC3_IN2_bfr[p] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
     }
  }
  else
  {
  	for(uint32_t m=0; m<ADC_DMA_HALFBUFFERSIZE-1; m++)
  	{
  		if(m==0 || (m%2==0))
  		{
  			for(uint32_t n=0; n<ADC_DMA_QUATERBUFFERSIZE-1; n++)
  			{
  				ADC3_DMA_sort_ptr->ADC3_IN1_bfr_alt[n] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
  		else
  		{
  			for(uint32_t p=0; p<ADC_DMA_QUATERBUFFERSIZE-1; p++)
  			{
  				ADC3_DMA_sort_ptr->ADC3_IN2_bfr_alt[p] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
  			}
  		}
     }
   }

};


void ADC3_DMA_sort_lhb (void)
{
  if(ADC3_Current_buffer == 1)
  {
	for(uint32_t m=ADC_DMA_HALFBUFFERSIZE; m<ADC_DMA_BUFFERSIZE-1; m++)
	{
		if(m==0||(m%2==0))
		{
			for(uint32_t n=ADC_DMA_QUATERBUFFERSIZE; n<ADC_DMA_HALFBUFFERSIZE-1; n++)
			{
				ADC3_DMA_sort_ptr->ADC3_IN1_bfr[n] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
		else
		{
			for(uint32_t p=ADC_DMA_QUATERBUFFERSIZE; p<ADC_DMA_HALFBUFFERSIZE-1; p++)
			{
				ADC3_DMA_sort_ptr->ADC3_IN2_bfr[p] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
			}
		}
     }

	ADC3_Current_buffer = 2;
  }
  else
  {
  	for(uint32_t m=ADC_DMA_HALFBUFFERSIZE; m<ADC_DMA_BUFFERSIZE-1; m++)
  	{
  		if(m==0||(m%2==0))
  		{
  			for(uint32_t n=ADC_DMA_QUATERBUFFERSIZE; n<ADC_DMA_HALFBUFFERSIZE-1; n++)
  			{
  				ADC3_DMA_sort_ptr->ADC3_IN1_bfr_alt[n] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
            }
        }
  		else
  		{
  			for(uint32_t p=ADC_DMA_QUATERBUFFERSIZE; p<ADC_DMA_HALFBUFFERSIZE-1; p++)
  			{
  				ADC3_DMA_sort_ptr->ADC3_IN2_bfr_alt[p] = ADC3_DMA_sort_ptr->ADC3_DMA_bfr[m] * LEVEL_VALUE_SCALAR;
  			}
  		}
     }

  	ADC3_Current_buffer = 1;
  }


};
