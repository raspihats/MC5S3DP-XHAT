/*
 * serial_port.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#include "serial_port.h"
#include "utils.h"

namespace hal {


SerialPort::SerialPort(
    USART_TypeDef* usart,
    DMA_TypeDef* rx_dma, uint32_t rx_dma_stream,
    DMA_TypeDef* tx_dma, uint32_t tx_dma_stream) :
        usart_(usart),
        rx_dma_(rx_dma), rx_dma_stream_(rx_dma_stream),
        tx_dma_(tx_dma), tx_dma_stream_(tx_dma_stream),
        rx_tail_pointer_(rx_buffer_),
        tx_head_pointer_(tx_buffer_),
        tx_tail_pointer_(tx_buffer_),
        tx_cnt_(0) {

}


void SerialPort::Open(
    const uint32_t baudrate,
    const uint32_t data_bits,
    const uint32_t parity,
    const uint32_t stop_bits) {

  LL_USART_InitTypeDef USART_InitStruct;

  LL_USART_Disable(usart_);

  USART_InitStruct.BaudRate = baudrate;
  USART_InitStruct.DataWidth = data_bits;
  USART_InitStruct.StopBits = stop_bits;
  USART_InitStruct.Parity = parity;
  USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  LL_USART_Init(usart_, &USART_InitStruct);

  LL_USART_ConfigAsyncMode(usart_);

  LL_USART_Enable(usart_);


  LL_DMA_SetPeriphAddress(rx_dma_, rx_dma_stream_, LL_USART_DMA_GetRegAddr(usart_));
  LL_DMA_SetMemoryAddress(rx_dma_, rx_dma_stream_, (uint32_t)rx_buffer_);
  LL_DMA_SetDataLength(rx_dma_, rx_dma_stream_, kRxBufferSize);
  LL_DMA_EnableStream(rx_dma_, rx_dma_stream_);
  LL_USART_EnableDMAReq_RX(usart_);


  LL_DMA_SetPeriphAddress(tx_dma_, tx_dma_stream_, LL_USART_DMA_GetRegAddr(usart_));
  LL_USART_EnableDMAReq_TX(usart_);
//  LL_DMA_EnableIT_TC(tx_dma_, tx_dma_stream_);

}


bool SerialPort::Read(uint8_t& byte) {
  uint8_t* rx_head_pointer;

  rx_head_pointer = rx_buffer_ + (kRxBufferSize - LL_DMA_GetDataLength(rx_dma_, rx_dma_stream_));

  // check if rx circular buffer is empty
  if(rx_tail_pointer_ == rx_head_pointer) {
    return false;
  }
  else {
    byte = *rx_tail_pointer_;
    rx_tail_pointer_++;
    if(rx_tail_pointer_ == (rx_buffer_ + kRxBufferSize)) {
      rx_tail_pointer_ = rx_buffer_; // roll-over
    }
    return true;
  }

}


void SerialPort::StartTxDMA() {
  LL_DMA_SetMemoryAddress(tx_dma_, tx_dma_stream_, (uint32_t)tx_tail_pointer_);
  if(tx_head_pointer_ > tx_tail_pointer_) {
    tx_cnt_ = (uint32_t)tx_head_pointer_ - (uint32_t)tx_tail_pointer_;
  }
  else {
    tx_cnt_ = (uint32_t)(tx_buffer_ + kTxBufferSize) - (uint32_t)tx_tail_pointer_;
  }


  LL_DMA_SetDataLength(tx_dma_, tx_dma_stream_, tx_cnt_);
  LL_DMA_EnableIT_TC(tx_dma_, tx_dma_stream_);
  LL_DMA_EnableStream(tx_dma_, tx_dma_stream_);
}


void SerialPort::ISR() {
  if(LL_DMA_IsActiveFlag_TC(tx_dma_, tx_dma_stream_)) {

      LL_DMA_DisableIT_TC(tx_dma_, tx_dma_stream_);
      LL_DMA_DisableStream(tx_dma_, tx_dma_stream_);
      LL_DMA_ClearFlag_TC(tx_dma_, tx_dma_stream_);

      tx_tail_pointer_+= tx_cnt_;
      tx_cnt_ = 0;
      if(tx_tail_pointer_ == (tx_buffer_ + kTxBufferSize)) {
        tx_tail_pointer_ = tx_buffer_; // roll-over
      }

      // check if tx circular is not buffer is empty
      if(tx_tail_pointer_ != tx_head_pointer_) {
        StartTxDMA();
      }
  }
}


bool SerialPort::Write(uint8_t byte) {
  uint8_t* tx_head_pointer;

  tx_head_pointer = tx_head_pointer_;
  tx_head_pointer++; // increment tx head pointer clone
  if(tx_head_pointer == (tx_buffer_ + kTxBufferSize)) {
    tx_head_pointer = tx_buffer_; // roll-over
  }

  // use tx head pointer clone to check if tx circular buffer is full
  if(tx_head_pointer == tx_tail_pointer_) {
    return false;
  }
  else {
    *tx_head_pointer_ = byte;
    tx_head_pointer_ = tx_head_pointer; //increment
    if(tx_cnt_ == 0) {
      StartTxDMA();
    }
    return true;
  }
}


} /* namespace hal */
