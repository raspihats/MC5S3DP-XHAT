/*
 * serial_port.h
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#ifndef SERIAL_PORT_H_
#define SERIAL_PORT_H_

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_dma.h"

namespace hal {

class SerialPort {
public:
  SerialPort(
      USART_TypeDef* usart,
      DMA_TypeDef* rx_dma, uint32_t rx_dma_stream,
      DMA_TypeDef* tx_dma, uint32_t tx_dma_stream);
  void Open(
      const uint32_t baudrate = 115200,
      const uint32_t data_bits = LL_USART_DATAWIDTH_8B,
      const uint32_t parity = LL_USART_PARITY_NONE,
      const uint32_t stop_bits = LL_USART_STOPBITS_1);
  bool Read(uint8_t& byte);
  bool Write(uint8_t byte);
  void ISR();
private:
  USART_TypeDef* usart_;
  DMA_TypeDef* rx_dma_;
  uint32_t rx_dma_stream_;
  DMA_TypeDef* tx_dma_;
  uint32_t tx_dma_stream_;


  const static uint32_t kRxBufferSize = 256;
  uint8_t rx_buffer_[kRxBufferSize];
  uint8_t* rx_tail_pointer_;

  const static uint32_t kTxBufferSize = 256;
  uint8_t tx_buffer_[kTxBufferSize];
  uint8_t* tx_head_pointer_;
  volatile uint8_t* tx_tail_pointer_;
  volatile uint32_t tx_cnt_;

  void StartTxDMA();

};

} /* namespace hal */

#endif /* SERIAL_PORT_H_ */
