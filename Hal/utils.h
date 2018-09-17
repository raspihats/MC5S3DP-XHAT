/*
 * utils.h
 *
 *  Created on: 17 Sep 2018
 *      Author: fcos
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "stm32f4xx_ll_dma.h"

namespace hal {

uint32_t LL_DMA_IsActiveFlag_TC(DMA_TypeDef *DMAx, uint32_t Stream);
void LL_DMA_ClearFlag_TC(DMA_TypeDef *DMAx, uint32_t Stream);

} /* namespace hal */

#endif /* UTILS_H_ */
