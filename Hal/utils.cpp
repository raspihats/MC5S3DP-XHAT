/*
 * utils.cpp
 *
 *  Created on: 17 Sep 2018
 *      Author: fcos
 */

#include "utils.h"

namespace hal {

uint32_t LL_DMA_IsActiveFlag_TC(DMA_TypeDef *DMAx, uint32_t Stream) {
  uint32_t flag = 0;
  switch(Stream) {
  case LL_DMA_STREAM_0:
    flag = LL_DMA_IsActiveFlag_TC0(DMAx);
    break;
  case LL_DMA_STREAM_1:
    flag = LL_DMA_IsActiveFlag_TC1(DMAx);
    break;
  case LL_DMA_STREAM_2:
    flag = LL_DMA_IsActiveFlag_TC2(DMAx);
    break;
  case LL_DMA_STREAM_3:
    flag = LL_DMA_IsActiveFlag_TC3(DMAx);
    break;
  case LL_DMA_STREAM_4:
    flag = LL_DMA_IsActiveFlag_TC4(DMAx);
    break;
  case LL_DMA_STREAM_5:
    flag = LL_DMA_IsActiveFlag_TC5(DMAx);
    break;
  case LL_DMA_STREAM_6:
    flag = LL_DMA_IsActiveFlag_TC6(DMAx);
    break;
  case LL_DMA_STREAM_7:
    flag = LL_DMA_IsActiveFlag_TC7(DMAx);
    break;
  }
  return flag;
}


void LL_DMA_ClearFlag_TC(DMA_TypeDef *DMAx, uint32_t Stream) {
  switch(Stream) {
  case LL_DMA_STREAM_0:
    LL_DMA_ClearFlag_TC0(DMAx);
    break;
  case LL_DMA_STREAM_1:
    LL_DMA_ClearFlag_TC1(DMAx);
    break;
  case LL_DMA_STREAM_2:
    LL_DMA_ClearFlag_TC2(DMAx);
    break;
  case LL_DMA_STREAM_3:
    LL_DMA_ClearFlag_TC3(DMAx);
    break;
  case LL_DMA_STREAM_4:
    LL_DMA_ClearFlag_TC4(DMAx);
    break;
  case LL_DMA_STREAM_5:
    LL_DMA_ClearFlag_TC5(DMAx);
    break;
  case LL_DMA_STREAM_6:
    LL_DMA_ClearFlag_TC6(DMAx);
    break;
  case LL_DMA_STREAM_7:
    LL_DMA_ClearFlag_TC7(DMAx);
    break;
  }

}

} /* namespace hal */
