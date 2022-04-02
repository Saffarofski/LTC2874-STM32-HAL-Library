#include "LTC2874_STM32_HAL_Library.h"

/*!
OR'd together with the register address to form the command byte
| LTC2874 Command String   | Value |
| :------------------------| :---: |
| LTC2874_READ             | 0x00  |
| LTC2874_WRITE_NO_UPDATE  | 0x20  |
| LTC2874_UPDATE_ALL       | 0x40  |
| LTC2874_WRITE_UPDATE_ALL | 0x60  |
| LTC2874_RESET            | 0xE0  |
*/
/*! @name Command Codes
@{ */

// Command Codes
#define   LTC2874_READ               0x00  //! READ REGISTER
#define   LTC2874_WRITE_NO_UPDATE    0x20  //! WRITE REGISTER (NO UPDATE)
#define   LTC2874_UPDATE_ALL         0x40  //! UPDATE ALL REGISTERS
#define   LTC2874_WRITE_UPDATE_ALL   0x60  //! WRITE ONE REGISTER AND UPDATE
#define   LTC2874_RESET              0xE0  //! RESET
//! @}


/*!
| Register             | Address |
| :--------------------| :-----: |
| LTC2874_IRQREG_REG0  | 0x00    |
| LTC2874_IRQMASK_REG1 | 0x01    |
| LTC2874_EVENT1_REG2  | 0x02    |
| LTC2874_EVENT2_REG3  | 0x03    |
| LTC2874_EVENT3_REG4  | 0x04    |
| LTC2874_EVENT4_REG5  | 0x05    |
| LTC2874_STATUS1_REG6 | 0x06    |
| LTC2874_STATUS2_REG7 | 0x07    |
| LTC2874_MODE1_REG8   | 0x08    |
| LTC2874_MODE2_REG9   | 0x09    |
| LTC2874_NSF_REGA     | 0x0A    |
| LTC2874_ILLM_REGB    | 0x0B    |
| LTC2874_TMRCTRL_REGC | 0x0C    |
| LTC2874_CTRL1_REGD   | 0x0D    |
| LTC2874_CTRL2_REGE   | 0x0E    |
*/
/*! @name Register Addresses
@{ */

// Register Addresses
#define   LTC2874_IRQREG_REG0    0x00
#define   LTC2874_IRQMASK_REG1   0x01
#define   LTC2874_EVENT1_REG2    0x02
#define   LTC2874_EVENT2_REG3    0x03
#define   LTC2874_EVENT3_REG4    0x04
#define   LTC2874_EVENT4_REG5    0x05
#define   LTC2874_STATUS1_REG6   0x06
#define   LTC2874_STATUS2_REG7   0x07
#define   LTC2874_MODE1_REG8     0x08
#define   LTC2874_MODE2_REG9     0x09
#define   LTC2874_NSF_REGA       0x0A
#define   LTC2874_ILLM_REGB      0x0B
#define   LTC2874_TMRCTRL_REGC   0x0C
#define   LTC2874_CTRL1_REGD     0x0D
#define   LTC2874_CTRL2_REGE     0x0E
//! @}

/*! @name Register Bit and Mask Definitions
@{ */

// register bit definitions / masks
#define    LTC2874_OT             (0x1<<7)      // REGISTER IRQREG
#define    LTC2874_SUPPLY         (0x1<<6)      // REGISTER IRQREG
#define    LTC2874_WU             (0x1<<5)      // REGISTER IRQREG
#define    LTC2874_TOC_LP         (0x1<<4)      // REGISTER IRQREG
#define    LTC2874_PWRCHNG        (0x1<<3)      // REGISTER IRQREG
#define    LTC2874_TOC_CQ         (0x1<<2)      // REGISTER IRQREG
#define    LTC2874_CSENSE         (0x1<<1)      // REGISTER IRQREG

#define    LTC2874_OT_MASK        (0x1<<7)      // REGISTER IRQMASK
#define    LTC2874_SUPPLY_MASK    (0x1<<6)      // REGISTER IRQMASK
#define    LTC2874_WU_MASK        (0x1<<5)      // REGISTER IRQMASK
#define    LTC2874_TOC_LP_MASK    (0x1<<4)      // REGISTER IRQMASK
#define    LTC2874_PWRCHNG_MASK   (0x1<<3)      // REGISTER IRQMASK
#define    LTC2874_TOC_CQ_MASK    (0x1<<2)      // REGISTER IRQMASK
#define    LTC2874_CSENSE_MASK    (0x1<<1)      // REGISTER IRQMASK

#define    LTC2874_OT_SD          (0x1<<7)      // REGISTER EVENT1
#define    LTC2874_OT_WARN        (0x1<<6)      // REGISTER EVENT1
#define    LTC2874_UVLO_VL        (0x1<<4)      // REGISTER EVENT1
#define    LTC2874_UVLO_VDD       (0x1<<3)      // REGISTER EVENT1
#define    LTC2874_UV_VDD         (0x1<<2)      // REGISTER EVENT1
#define    LTC2874_OV_VDD         (0x1<<1)      // REGISTER EVENT1

#define    LTC2874_WU4            (0x1<<7)      // REGISTER EVENT2
#define    LTC2874_WU3            (0x1<<6)      // REGISTER EVENT2
#define    LTC2874_WU2            (0x1<<5)      // REGISTER EVENT2
#define    LTC2874_WU1            (0x1<<4)      // REGISTER EVENT2
#define    LTC2874_TOC_LP4        (0x1<<3)      // REGISTER EVENT2
#define    LTC2874_TOC_LP3        (0x1<<2)      // REGISTER EVENT2
#define    LTC2874_TOC_LP2        (0x1<<1)      // REGISTER EVENT2
#define    LTC2874_TOC_LP1         0x1          // REGISTER EVENT2

#define    LTC2874_PWRCHNG4       (0x1<<7)      // REGISTER EVENT3
#define    LTC2874_PWRCHNG3       (0x1<<6)      // REGISTER EVENT3
#define    LTC2874_PWRCHNG2       (0x1<<5)      // REGISTER EVENT3
#define    LTC2874_PWRCHNG1       (0x1<<4)      // REGISTER EVENT3
#define    LTC2874_TOC_CQ4        (0x1<<3)      // REGISTER EVENT3
#define    LTC2874_TOC_CQ3        (0x1<<2)      // REGISTER EVENT3
#define    LTC2874_TOC_CQ2        (0x1<<1)      // REGISTER EVENT3
#define    LTC2874_TOC_CQ1         0x1          // REGISTER EVENT3

#define    LTC2874_CQ_SNS4        (0x1<<7)      // REGISTER EVENT4
#define    LTC2874_CQ_SNS3        (0x1<<6)      // REGISTER EVENT4
#define    LTC2874_CQ_SNS2        (0x1<<5)      // REGISTER EVENT4
#define    LTC2874_CQ_SNS1        (0x1<<4)      // REGISTER EVENT4
#define    LTC2874_CSENSE4        (0x1<<3)      // REGISTER EVENT4
#define    LTC2874_CSENSE3        (0x1<<2)      // REGISTER EVENT4
#define    LTC2874_CSENSE2        (0x1<<1)      // REGISTER EVENT4
#define    LTC2874_CSENSE1         0x1          // REGISTER EVENT4

#define    LTC2874_OT_STAT        (0x1<<7)      // REGISTER STATUS1
#define    LTC2874_WU_COOL_STAT   (0x1<<6)      // REGISTER STATUS1
#define    LTC2874_UVLO_VDD_STAT  (0x1<<5)      // REGISTER STATUS1
#define    LTC2874_OV_VDD_STAT    (0x1<<4)      // REGISTER STATUS1
#define    LTC2874_OC_LP4_STAT    (0x1<<3)      // REGISTER STATUS1
#define    LTC2874_OC_LP3_STAT    (0x1<<2)      // REGISTER STATUS1
#define    LTC2874_OC_LP2_STAT    (0x1<<1)      // REGISTER STATUS1
#define    LTC2874_OC_LP1_STAT     0x1          // REGISTER STATUS1

#define    LTC2874_PWRGD4         (0x1<<7)      // REGISTER STATUS2
#define    LTC2874_PWRGD3         (0x1<<6)      // REGISTER STATUS2
#define    LTC2874_PWRGD2         (0x1<<5)      // REGISTER STATUS2
#define    LTC2874_PWRGD1         (0x1<<4)      // REGISTER STATUS2
#define    LTC2874_OC_CQ4         (0x1<<3)      // REGISTER STATUS2
#define    LTC2874_OC_CQ3         (0x1<<2)      // REGISTER STATUS2
#define    LTC2874_OC_CQ2         (0x1<<1)      // REGISTER STATUS2
#define    LTC2874_OC_OQ1          0x1          // REGISTER STATUS2

#define    LTC2874_24VMODE        (0x1<<7)      // REGISTER MODE1
#define    LTC2874_CSENSE_MODE    (0x1<<6)      // REGISTER MODE1
// multibit definition
#define    LTC2874_2XPTC_pos         4          // REGISTER MODE1
#define    LTC2874_2XPTC_msk      (0x3<<4)      // REGISTER MODE1
#define    LTC2874_2XPTC(value)   (LTC2874_2XPTC_msk & ((value) << LTC2874_2XPTC_pos))

#define    LTC2874_FLDBK_MODE     (0x1<<3)      // REGISTER MODE1
#define    LTC2874_RETRY_OV       (0x1<<2)      // REGISTER MODE1
#define    LTC2874_RETRY_LP       (0x1<<1)      // REGISTER MODE1
#define    LTC2874_RETRY_CQ        0x1          // REGISTER MODE1

#define    LTC2874_SLEW4          (0x1<<7)      // REGISTER MODE2
#define    LTC2874_SLEW3          (0x1<<6)      // REGISTER MODE2
#define    LTC2874_SLEW2          (0x1<<5)      // REGISTER MODE2
#define    LTC2874_SLEW1          (0x1<<4)      // REGISTER MODE2
// multibit definition
#define    LTC2874_OV_TH_pos         2          // REGISTER MODE2
#define    LTC2874_OV_TH_msk      (0x3<<2)      // REGISTER MODE2
#define    LTC2874_OV_TH(value)   (LTC2874_OV_TH_msk & ((value) << LTC2874_OV_TH_pos))

#define    LTC2874_OV_ALLOW       (0x1<<1)      // REGISTER MODE2
#define    LTC2874_CQ_SNS_MODE     0x1          // REGISTER MODE2

// multibit definitions
#define    LTC2874_NSF4_pos          6          // REGISTER NSF
#define    LTC2874_NSF4_msk       (0x3<<6)      // REGISTER NSF
#define    LTC2874_NSF4(value)    (LTC2874_NSF4_msk & ((value) << LTC2874_NSF4_pos))
#define    LTC2874_NSF3_pos          4          // REGISTER NSF
#define    LTC2874_NSF3_msk       (0x3<<4)      // REGISTER NSF
#define    LTC2874_NSF3(value)     LTC2874_NSF3_msk & ((value) << LTC2874_NSF3_pos))
#define    LTC2874_NSF2_pos          2          // REGISTER NSF
#define    LTC2874_NSF2_msk       (0x3<<2)      // REGISTER NSF
#define    LTC2874_NSF2(value)    (LTC2874_NSF2_msk & ((value) << LTC2874_NSF2_pos))
#define    LTC2874_NSF1_pos          0          // REGISTER NSF
#define    LTC2874_NSF1_msk         0x3         // REGISTER NSF
#define    LTC2874_NSF1(value)     (LTC2874_NSF1_msk & ((value) << LTC2874_NSF1_pos))

#define    LTC2874_ILLM4_pos         6          // REGISTER ILLM
#define    LTC2874_ILLM4_msk       (0x3<<6)     // REGISTER ILLM
#define    LTC2874_ILLM4(value)    (LTC2874_ILLM4_msk & ((value) << LTC2874_ILLM4_pos))
#define    LTC2874_ILLM3_pos        4           // REGISTER ILLM
#define    LTC2874_ILLM3_msk       (0x3<<4)     // REGISTER ILLM
#define    LTC2874_ILLM3(value)    (LTC2874_ILLM3_msk & ((value) << LTC2874_ILLM3_pos))
#define    LTC2874_ILLM2_pos        2           // REGISTER ILLM
#define    LTC2874_ILLM2_msk       (0x3<<2)     // REGISTER ILLM
#define    LTC2874_ILLM2(value)    (LTC2874_ILLM2_msk & ((value) << LTC2874_ILLM2_pos))
#define    LTC2874_ILLM1_pos        0           // REGISTER ILLM
#define    LTC2874_ILLM1_msk        0x3         // REGISTER ILLM
#define    LTC2874_ILLM1(value)    (LTC2874_ILLM1_msk & ((value) << LTC2874_ILLM1_pos))

#define    LTC2874_LPTC_pos         4           // REGISTER TMRCTRL
#define    LTC2874_LPTC_msk        (0xF<<4)     // REGISTER TMRCTRL
#define    LTC2874_LPTC(value)     (LTC2874_LPTC_msk & ((value) << LTC2874_LPTC_pos))

#define    LTC2874_RETRYTC_pos     0            // REGISTER TMRCTRL
#define    LTC2874_RETRYTC_msk     0x07         // REGISTER TMRCTRL
#define    LTC2874_RETRYTC(value) (LTC2874_RETRYTC_msk & (value))

#define    LTC2874_WKUP4          (0x1<<7)      // REGISTER CTRL1
#define    LTC2874_WKUP3          (0x1<<6)      // REGISTER CTRL1
#define    LTC2874_WKUP2          (0x1<<5)      // REGISTER CTRL1
#define    LTC2874_WKUP1          (0x1<<4)      // REGISTER CTRL1
#define    LTC2874_DRVEN4         (0x1<<3)      // REGISTER CTRL1
#define    LTC2874_DRVEN3         (0x1<<2)      // REGISTER CTRL1
#define    LTC2874_DRVEN2         (0x1<<1)      // REGISTER CTRL1
#define    LTC2874_DRVEN1          0x1          // REGISTER CTRL1

#define    LTC2874_ENLP4          (0x1<<7)      // REGISTER CTRL2
#define    LTC2874_ENLP3          (0x1<<6)      // REGISTER CTRL2
#define    LTC2874_ENLP2          (0x1<<5)      // REGISTER CTRL2
#define    LTC2874_ENLP1          (0x1<<4)      // REGISTER CTRL2
#define    LTC2874_SIO_MODE4      (0x1<<3)      // REGISTER CTRL2
#define    LTC2874_SIO_MODE3      (0x1<<2)      // REGISTER CTRL2
#define    LTC2874_SIO_MODE2      (0x1<<1)      // REGISTER CTRL2
#define    LTC2874_SIO_MODE1       0x1          // REGISTER CTRL2

#define    LTC2874_CQ1     0x01
#define    LTC2874_CQ2     0x02
#define    LTC2874_CQ3     0x04
#define    LTC2874_CQ4     0x08
#define    LTC2874_CQ_ALL  0x0F

#define    LTC2874_LP1     0x10
#define    LTC2874_LP2     0x20
#define    LTC2874_LP3     0x40
#define    LTC2874_LP4     0x80
#define    LTC2874_LP_ALL  0xF0

//! @}



/* these are the functions which i added myself: */
void LTC2874_Init(LTC2874_InitTypeDef *LTC2874_handle)
{
	CS_GPIO_PORT = LTC2874_handle->CS_GPIO_PORT;
	CS_GPIO_Pin  = LTC2874_handle->CS_GPIO_Pin;
	SPI_Handler  = LTC2874_handle->SPI_Handler;
}

void GPIO_ResetBits(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIOx , GPIO_Pin , GPIO_PIN_RESET);
}

void GPIO_SetBits(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIOx , GPIO_Pin , GPIO_PIN_SET);
}

void spi_write (uint8_t Data)
{
	HAL_SPI_Transmit(SPI_Handler, &Data, 1, 10);
}

uint8_t spi_read(uint8_t Data)
{
	uint8_t data_byte;
//	HAL_SPI_Transmit(&hspi1, &Data, 1, 10);
//	HAL_SPI_Receive(&hspi1, &data_byte, 1, 10);
	HAL_SPI_TransmitReceive(SPI_Handler, &Data , &data_byte, 1, 10);
//	HAL_SPI_TransmitReceive(hspi, pTxData, pRxData, Size, Timeout)
	return data_byte;
}

void SET_LTC2874_CS(void)
{
	 HAL_GPIO_WritePin(CS_GPIO_PORT , CS_GPIO_Pin , GPIO_PIN_SET);
}

void RESET_LTC2874_CS(void)
{
	 HAL_GPIO_WritePin(CS_GPIO_PORT , CS_GPIO_Pin , GPIO_PIN_RESET);
}


void LTC2874_cq_output(uint8_t port, uint8_t value)
{
  uint8_t data_byte, command_byte;

  command_byte = LTC2874_READ | (LTC2874_CTRL1_REGD << 1);

  HAL_GPIO_WritePin(CS_GPIO_PORT , CS_GPIO_Pin , GPIO_PIN_RESET);     //! 1) Pull CS low
  HAL_SPI_Transmit(SPI_Handler, &command_byte, 1, 10);                                //! 2) Write first byte and send command | address
  HAL_SPI_TransmitReceive(SPI_Handler, 0X00, &data_byte, 1, 10);                      //! 3) Read last byte (while sending null data)
  HAL_GPIO_WritePin(CS_GPIO_PORT , CS_GPIO_Pin , GPIO_PIN_SET);

  if (port == 5)
  {
    port = 0xF;
  }
  else
  {
    port = 0x01 << (port - 1);      // make mask
  }

  if (value)
  {
    data_byte |= port;                // bitwise OR
  }
  else
  {
    data_byte &= ~port;
  }

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_CTRL1_REGD << 1);

  HAL_GPIO_WritePin(CS_GPIO_PORT , CS_GPIO_Pin , GPIO_PIN_RESET);    //! 1) Pull CS low to start transaction
  spi_write(command_byte);                                                      //! 2) Write the command and address
  spi_write(data_byte);                                                         //! 3) Write the data
  HAL_GPIO_WritePin(CS_GPIO_PORT , CS_GPIO_Pin , GPIO_PIN_SET);      //! 4) Pull CS high to finish transaction
}



//************************************************************************************
//  Enables or Disables L+ output for specified port, then Updates.
//  parameters: port (1-4, or 5=ALL), value (0=Disable, 1=Enable)
//  returns: nothing
//************************************************************************************
void LTC2874_lplus_output(uint8_t port, uint8_t value)
{
  uint8_t data_byte, command_byte;

  command_byte = LTC2874_READ | (LTC2874_CTRL2_REGE << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low
  spi_write(command_byte);           //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);        //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();

  if (port == 5)
  {
    port = 0xF0;
  }
  else
  {
    port = 0x01 << (port + 3);         //make mask
  }

  if (value)
  {
    data_byte |= port;                   //bitwise OR
  }
  else
  {
    data_byte &= ~port;
  }

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_CTRL2_REGE << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low to start transaction
  spi_write(command_byte);               //! 2) Write the command and address
  spi_write(data_byte);                  //! 3) Write the data
  SET_LTC2874_CS();               //! 4) Pull CS high to finish transaction
}



//************************************************************************************
//  Sets SIO_MODE bit (and also Clears SLEW bit) for specified port, then Updates.
//  parameter: port (1-4, or 5=ALL)
//  returns: nothing
//************************************************************************************
void LTC2874_sio_mode(uint8_t port)
{
  uint8_t data_byte_9, data_byte_E, command_byte_9, command_byte_E, position_9, position_E;

  if (port == 5)                       // If 5 set to 0x0F
  {
    position_E = 0x0f;
  }
  else
  {
    position_E = (0x01 << (port - 1));  // convert port number to position
  }

  position_9 = position_E << 4;          // move position for slew bits

  command_byte_9 = LTC2874_READ | (LTC2874_MODE2_REG9 << 1);
  command_byte_E = LTC2874_READ | (LTC2874_CTRL2_REGE << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low
  spi_write(command_byte_9);             //! 2) Write first byte and send command1 | address
  data_byte_9 = spi_read(0x00);          //! 3) Read last byte (while sending null data)
  spi_write(command_byte_E);             //! 4) Write first byte and send command2 | address
  data_byte_E = spi_read(0x00);          //! 5) Read last byte (while sending null data)
  SET_LTC2874_CS();               //! 6) Pull CS high to finish transaction

  data_byte_9 &= ~position_9;            // SLEW=0
  data_byte_E |= position_E;             // SIO_MODE=1

  command_byte_9 = LTC2874_WRITE_NO_UPDATE | (LTC2874_MODE2_REG9 << 1);
  command_byte_E = LTC2874_WRITE_UPDATE_ALL | (LTC2874_CTRL2_REGE << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low to start transaction
  spi_write(command_byte_9);             //! 2) Write the command and address
  spi_write(data_byte_9);                //! 3) Write the data
  spi_write(command_byte_E);             //! 4) Write the command and address
  spi_write(data_byte_E);                //! 5) Write the data
  SET_LTC2874_CS();               //! 6) Pull CS high to finish transaction
}

//************************************************************************************
//  Changes value of the 24VMODE bit, then Updates.
//  parameter: value (0=Disable, 1=Enable)
//  returns: nothing
//************************************************************************************
void LTC2874_24v_mode(uint8_t value)
{
  uint8_t command_byte, data_byte;
  command_byte = LTC2874_READ | (LTC2874_MODE1_REG8 << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low
  spi_write(command_byte);               //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);            //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();               //! 4) Pull CS high to finish transaction

  if (value)
  {
    data_byte |= LTC2874_24VMODE;        // set bit
  }
  else
  {
    data_byte &= ~LTC2874_24VMODE;     // clr bit
  }

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_MODE1_REG8 << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low to start transaction
  spi_write(command_byte);               //! 2) Write the command and address
  spi_write(data_byte);                  //! 3) Write the data
  SET_LTC2874_CS();               //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Changes NSF (Noise Suppression Filter) setting for specified port.
//  parameters: port#, value
//    port#: [1,2,3, or 4]
//    value: 0x0=disabled, 0x1=20.3us, 0x2=2.8us, 0x3=0.6us (default)
//  Higher bits are ignored. No update. Returns: nothing.
//************************************************************************************
void LTC2874_write_NSF_value(uint8_t port, uint8_t value)
{
  uint8_t command_byte , data_byte, position;
  command_byte = LTC2874_READ | (LTC2874_NSF_REGA << 1);    // Create command and address byte

  RESET_LTC2874_CS();               //! 1) Pull CS low
  spi_write(command_byte);              //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);           //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();              //! 4) Pull CS high to finish transaction

  position = ((port - 1) << 1);         // convert port number to position,Equivalent to multiply by 2
  data_byte &= ~(0x3<<position);        // clear NSF bits with inverse mask
  data_byte |= ((value) << position);   // bitwise OR value into NSF port position

  command_byte = LTC2874_WRITE_NO_UPDATE | (LTC2874_NSF_REGA << 1);

  RESET_LTC2874_CS();               //! 1) Pull CS low to start transaction
  spi_write(command_byte);              //! 2) Write the command and address
  spi_write(data_byte);                 //! 3) Write the data
  SET_LTC2874_CS();              //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Changes ILLM (Sinking current) setting for specified port.
//  parameters: port#, value
//    port#: (1-4, or 5=ALL)
//    value: 0x0=500kohm, 0x1=2.5mA, 0x2=3.7mA, 0x3=6.2mA (default)
//  Higher bits are ignored. No update. Returns: nothing.
//************************************************************************************
void LTC2874_write_ILLM_value(uint8_t port, uint8_t value)
{
  uint8_t command_byte , data_byte, position;
  // Create command and address byte
  command_byte = LTC2874_READ | (LTC2874_ILLM_REGB << 1);

  RESET_LTC2874_CS();                    //! 1) Pull CS low
  spi_write(command_byte);                   //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);                //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                   //! 4) Pull CS high to finish transaction

  if (port == 5)                           // If 5 load each port same value
  {
    data_byte = value + (value << 2) + (value << 4) + (value << 6);
  }
  else
  {
    position = ((port - 1) << 1);          // convert port number to position
    data_byte &= ~(0x3<<position);         // clear ILLM bits with inverse mask
    data_byte |= ((value) << position);    // bitwise OR value into ILLM port position
  }

  command_byte = LTC2874_WRITE_NO_UPDATE | (LTC2874_ILLM_REGB << 1);

  RESET_LTC2874_CS();                    //! 1) Pull CS low to start transaction
  spi_write(command_byte);                   //! 2) Write the command and address
  spi_write(data_byte);                      //! 3) Write the data
  SET_LTC2874_CS();                   //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Change L+ Overcurrent Timer Control (LPTC) setting.
//  parameter: value (4 bits, 0x0-0xF)
//    0x0=17us, 0x1=30us, 0x2=60us, 0x3=120us, 0x4=0.25ms, 0x5=0.5ms, 0x6=1ms, 0x7=2ms
//    0x8=3.9ms, 0x9=7.8ms, 0xA=16ms, 0xB=30ms, 0xC=0.60ms, 0xD=0.13s, 0xE/0xF=0.25s
//  Higher bits are ignored. No update. Returns: nothing.
//************************************************************************************
void LTC2874_write_LPTC_value(uint8_t value)
{
  uint8_t command_byte , data_byte;
  // Create command and address byte
  command_byte = LTC2874_READ | (LTC2874_TMRCTRL_REGC << 1);

  RESET_LTC2874_CS();                  //! 1) Pull CS low
  spi_write(command_byte);                 //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);              //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                 //! 4) Pull CS high to finish transaction

  data_byte &= ~(LTC2874_LPTC_msk);        // clear LPTC bits with inverse mask
  data_byte |= (LTC2874_LPTC(value));      // bitwise OR value into LPTC bits

  command_byte = LTC2874_WRITE_NO_UPDATE | (LTC2874_TMRCTRL_REGC << 1);

  RESET_LTC2874_CS();                  //! 1) Pull CS low to start transaction
  spi_write(command_byte);                 //! 2) Write the command and address
  spi_write(data_byte);                    //! 3) Write the data
  SET_LTC2874_CS();                 //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Changes Auto-Retry Timer Control (RETRYTC) setting.
//  parameter: value (0x0=0.12s, 0x1=0.24s, 0x2=0.49s, 0x3=0.98s, 0x4=2.0s, 0x5=3.9s, 0x6=7.9s, 0x7=15.7s)
//  Higher bits are ignored. No update. Returns: nothing.
//************************************************************************************
void LTC2874_write_RETRYTC_value(uint8_t value)
{
  uint8_t command_byte , data_byte;
  // Create command and address byte
  command_byte = LTC2874_READ | (LTC2874_TMRCTRL_REGC << 1);

  RESET_LTC2874_CS();                   //! 1) Pull CS low
  spi_write(command_byte);                  //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);               //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                  //! 4) Pull CS high to finish transaction

  data_byte &= ~(LTC2874_RETRYTC_msk);      // clear RETRYTC bits with inverse mask
  data_byte |= (LTC2874_RETRYTC(value));    // bitwise OR value into RETRYTC bits

  command_byte = LTC2874_WRITE_NO_UPDATE | (LTC2874_TMRCTRL_REGC << 1);

  RESET_LTC2874_CS();                   //! 1) Pull CS low to start transaction
  spi_write(command_byte);                  //! 2) Write the command and address
  spi_write(data_byte);                     //! 3) Write the data
  SET_LTC2874_CS();                  //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Changes 2X Current Pulse Timer Control (2XPTC) setting.
//  parameter: value (0x0=60ms (default), 0x1=disabled, 0x2=30ms, 0x3=120ms)
//  Higher bits are ignored. No update. Returns: nothing.
//************************************************************************************
void LTC2874_write_2XPTC_value(uint8_t value)
{
  uint8_t command_byte , data_byte;
  // Create command and address byte
  command_byte = LTC2874_READ | (LTC2874_MODE1_REG8 << 1);

  RESET_LTC2874_CS();                   //! 1) Pull CS low
  spi_write(command_byte);                  //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);               //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                  //! 4) Pull CS high to finish transaction

  data_byte &= ~(LTC2874_2XPTC_msk);        // clear 2XPTC bits with inverse mask
  data_byte |= (LTC2874_2XPTC(value));      // bitwise OR value into 2XPTC bits

  command_byte = LTC2874_WRITE_NO_UPDATE | (LTC2874_MODE1_REG8 << 1);

  RESET_LTC2874_CS();                   //! 1) Pull CS low to start transaction
  spi_write(command_byte);                  //! 2) Write the command and address
  spi_write(data_byte);                     //! 3) Write the data
  SET_LTC2874_CS();                  //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Changes VDD Overvoltage Threshold (OV_TH) setting.
//  parameter: value (0x0=18V, 0x1=32V (default), 0x2=34V, 0x3=36V)
//  Higher bits are ignored. No update. Returns: nothing.
//************************************************************************************
void LTC2874_write_OV_TH_value(uint8_t value)
{
  uint8_t command_byte , data_byte;
  // Create command and address byte
  command_byte = LTC2874_READ | (LTC2874_MODE2_REG9 << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low
  spi_write(command_byte);                //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);             //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction

  data_byte &= ~(LTC2874_OV_TH_msk);      // clear OV_TH bits with inverse mask
  data_byte |= (LTC2874_OV_TH(value));    // bitwise OR value into OV_TH bits

  command_byte = LTC2874_WRITE_NO_UPDATE | (LTC2874_MODE2_REG9 << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low to start transaction
  spi_write(command_byte);                //! 2) Write the command and address
  spi_write(data_byte);                   //! 3) Write the data
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction
}


//************************************************************************************
// Sends WURQ (Wake-up Request) on specified port.
// parameter: port# [1,2,3, or 4; only one at a time]
// returns: nothing.
//************************************************************************************
void LTC2874_wakeup_request(uint8_t port)
{
  uint8_t data_byte, command_byte;
  port = 0x01 << (port + 3);         //move to MS of byte, make mask

  command_byte = LTC2874_READ | (LTC2874_CTRL1_REGD << 1);

  RESET_LTC2874_CS();            //! 1) Pull CS low
  spi_write(command_byte);           //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);        //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();

  data_byte |= port;                 // bitwise OR

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_CTRL1_REGD << 1);

  RESET_LTC2874_CS();              //! 1) Pull CS low to start transaction
  spi_write(command_byte);             //! 2) Write the command and address
  spi_write(data_byte);                //! 3) Write the data
  SET_LTC2874_CS();             //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Updates all registers.
//  parameters: none
//  returns: nothing
//************************************************************************************
void LTC2874_update_all(void)
{
  uint8_t command_byte;
  command_byte = LTC2874_UPDATE_ALL;

  RESET_LTC2874_CS();                 //! 1) Pull CS low to start transaction
  spi_write(command_byte);                //! 2) Write the command and address
  spi_write(0x00);                        //! 3) Write null data
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Writes byte of data to a register, then Updates.
//  parameters: register, data
//  returns: nothing
//************************************************************************************
void LTC2874_write_register_update_all(uint8_t LTC2874_register, uint8_t LTC2874_data)
{
  uint8_t command_byte;
  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_register << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low to start transaction
  spi_write(command_byte);                //! 2) Write the command and address
  spi_write(LTC2874_data);                //! 3) Write the data
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction
}

//************************************************************************************
//  Changes value of a register bit, then Updates.
//    NOTE: multi-bit handled by specific functions such as LTC2874_2XPTC_value()
//  parameters: register, bit, value
//    port#: [1,2,3, or 4]
//    value: 0 or 1
//  returns: nothing
//************************************************************************************
void LTC2874_write_bit_value_update_all(uint8_t LTC2874_register, uint8_t LTC2874_bit, uint8_t value)
{
  uint8_t command_byte , data_byte;
  command_byte = LTC2874_READ | (LTC2874_register << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low
  spi_write(command_byte);                //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);             //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction

  if (value)
  {
    data_byte |= LTC2874_bit;            //bitwise or
  }
  else
  {
    data_byte &= ~LTC2874_bit;
  }

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_register << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low to start transaction
  spi_write(command_byte);                //! 2) Write the command and address
  spi_write(data_byte);                   //! 3) Write the data
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction

}

//************************************************************************************
//  Sets a register bit, then Updates.
//  parameters: register, bit
//  returns: nothing
//************************************************************************************
void LTC2874_write_bit_set_update_all(uint8_t LTC2874_register, uint8_t LTC2874_bit)
{
  uint8_t command_byte, data_byte;
  command_byte = LTC2874_READ | (LTC2874_register << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low
  spi_write(command_byte);                //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);             //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction

  data_byte |= LTC2874_bit;               // compound bitwise OR

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_register << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low to start transaction
  spi_write(command_byte);                //! 2) Write the command and address
  spi_write(data_byte);                   //! 3) Write the data
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Clears a register bit, then Updates.
//  parameters: register, bit
//  returns: nothing
//************************************************************************************
void LTC2874_write_bit_clr_update_all(uint8_t LTC2874_register, uint8_t LTC2874_bit)
{
  uint8_t command_byte , mask, data_byte;
  command_byte = LTC2874_READ | (LTC2874_register << 1);

  RESET_LTC2874_CS();            //! 1) Pull CS low
  spi_write(command_byte);           //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);        //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();           //! 4) Pull CS high to finish transaction

  mask = ~LTC2874_bit;               // bitwise NOT
  data_byte &= mask;                 // clears the bit, leaves the rest unchanged

  command_byte = LTC2874_WRITE_UPDATE_ALL | (LTC2874_register << 1);

  RESET_LTC2874_CS();            //! 1) Pull CS low to start transaction
  spi_write(command_byte);           //! 2) Write the command and address
  spi_write(data_byte);              //! 3) Write the data
  SET_LTC2874_CS();           //! 4) Pull CS high to finish transaction
}

//************************************************************************************
//  Resets LTC2874, returning default values to registers.
//  parameter: none
//  returns: nothing
//************************************************************************************
void LTC2874_reset(void)
{
  uint8_t command_byte;
  command_byte = LTC2874_RESET;

  RESET_LTC2874_CS();             //! 1) Pull CS low to start transaction
  spi_write(command_byte);            //! 2) Write the command and address
  spi_write(0x00);                    //! 3) Write null data
  SET_LTC2874_CS();            //! 4) Pull CS high to finish transaction
}

//************************************************************************************
//  Reads data byte from specified register.
//  parameter: register address
//  returns: data byte
//************************************************************************************
uint8_t LTC2874_read_reg(uint8_t LTC2874_register)
{
  uint8_t command_byte, data_byte;
  //!  Build the reg command byte
  command_byte = LTC2874_READ |  (LTC2874_register << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low
  spi_write(command_byte);               //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);            //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();               //! 4) Pull CS high to finish transaction

  return data_byte;
}


//************************************************************************************
//  Reads a data BIT from specified register.
//  parameters: register address, bit mask
//  returns: bit value.
//************************************************************************************
uint8_t LTC2874_read_bit(uint8_t LTC2874_register, uint8_t LTC2874_bit)
{
  uint8_t command_byte, data_byte;

  command_byte = LTC2874_READ |  (LTC2874_register << 1);

  RESET_LTC2874_CS();                 //! 1) Pull CS low
  spi_write(command_byte);                //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);             //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                //! 4) Pull CS high to finish transaction

  data_byte &= LTC2874_bit;
  data_byte = data_byte != 0;             //! 5) If the bit is not zero set data_byte to 1

  return data_byte;
}


//************************************************************************************
//  Writes byte of data to a register without Updating.
//  parameters: register, data
//  returns: nothing
//************************************************************************************
void LTC2874_write_register(uint8_t LTC2874_register, uint8_t LTC2874_data)
{
  uint8_t command_byte;
  command_byte = LTC2874_WRITE_NO_UPDATE |  (LTC2874_register << 1);

  RESET_LTC2874_CS();               //! 1) Pull CS low to start transaction
  spi_write(command_byte);              //! 2) Write the command and address
  spi_write(LTC2874_data);              //! 3) Write the data
  SET_LTC2874_CS();              //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Sets a register bit without Updating.
//  parameters: register, bit
//  returns: nothing
//************************************************************************************
void LTC2874_write_bit_set(uint8_t LTC2874_register, uint8_t LTC2874_bit)
{
  uint8_t command_byte , data_byte;
  command_byte = LTC2874_READ | (LTC2874_register << 1);

  RESET_LTC2874_CS();               //! 1) Pull CS low
  spi_write(command_byte);            //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);           //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();              //! 4) Pull CS high to finish transaction

  data_byte |= LTC2874_bit;             // compound bitwise OR

  command_byte = LTC2874_WRITE_NO_UPDATE |  (LTC2874_register << 1);

  RESET_LTC2874_CS();                //! 1) Pull CS low to start transaction
  spi_write(command_byte);               //! 2) Write the command and address
  spi_write(data_byte);                  //! 3) Write the data
  SET_LTC2874_CS();               //! 4) Pull CS high to finish transaction
}

//************************************************************************************
//  Clears a register bit without Updating.
//  parameters: register, bit
//  returns: nothing.
//************************************************************************************
void LTC2874_write_bit_clr(uint8_t LTC2874_register, uint8_t LTC2874_bit)
{
  uint8_t command_byte , mask, data_byte;
  command_byte = LTC2874_READ |  (LTC2874_register << 1);

  spi_write(command_byte);              //! 2) Write first byte and send command | address
  SET_LTC2874_CS();              //! 4) Pull CS high to finish transaction

  mask = ~LTC2874_bit;                  // bitwise NOT
  data_byte &= mask;                    // clears the bit, leaves the rest unchanged

  command_byte = LTC2874_WRITE_NO_UPDATE |  (LTC2874_register << 1);

  RESET_LTC2874_CS();               //! 1) Pull CS low to start transaction
  spi_write(command_byte);              //! 2) Write the command and address
  spi_write(data_byte);                 //! 3) Write the data
  SET_LTC2874_CS();              //! 4) Pull CS high to finish transaction
}


//************************************************************************************
//  Changes value of a register bit without Updating.
//    NOTE: multi-bit handled by specific functions such as LTC2874_NSF_value()
//  parameters: register, bit, value
//    port#: [1,2,3, or 4]
//    value: 0 or 1
//  returns: nothing
//************************************************************************************
void LTC2874_write_bit_value(uint8_t LTC2874_register, uint8_t LTC2874_bit, uint8_t value)
{
  uint8_t command_byte , data_byte;
  command_byte = LTC2874_READ |  (LTC2874_register << 1);

  RESET_LTC2874_CS();                   //! 1) Pull CS low
  spi_write(command_byte);                  //! 2) Write first byte and send command | address
  data_byte = spi_read(0x00);               //! 3) Read last byte (while sending null data)
  SET_LTC2874_CS();                  //! 4) Pull CS high to finish transaction

  if (value)
  {
    data_byte |= LTC2874_bit;
  }
  else
  {
    data_byte &= ~LTC2874_bit;
  }

  command_byte = LTC2874_WRITE_NO_UPDATE |  (LTC2874_register << 1);

  RESET_LTC2874_CS();                     //! 1) Pull CS low to start transaction
  spi_write(command_byte);                    //! 2) Write the command and address
  spi_write(data_byte);                       //! 3) Write the data
  SET_LTC2874_CS();                    //! 4) Pull CS high to finish transaction
}
