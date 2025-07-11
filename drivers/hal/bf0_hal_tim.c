/*
 * SPDX-FileCopyrightText: 2016 STMicroelectronics
 * SPDX-FileCopyrightText: 2019-2025 SiFli Technologies(Nanjing) Co., Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause AND Apache-2.0
 */

#include "bf0_hal.h"
#include "bf0_hal_tim.h"
/*
#ifdef __HAL_GPT_MOE_ENABLE
    #undef __HAL_GPT_MOE_ENABLE
    #define __HAL_GPT_MOE_ENABLE(hdl)
#endif

#ifdef __HAL_GPT_MOE_DISABLE
    #undef __HAL_GPT_MOE_DISABLE
    #define __HAL_GPT_MOE_DISABLE(hdl)
#endif
*/
/** @addtogroup BF0_HAL_Driver
  * @{
  */

/** @defgroup TIM Hardware Timer
  * @brief TIM HAL module driver
  * @{
  */
#if defined(HAL_GPT_MODULE_ENABLED)||defined(_SIFLI_DOXYGEN_)

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @addtogroup GPT_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void GPT_OC1_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config);
static void GPT_OC3_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config);
static void GPT_OC4_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config);

static void GPT_TI1_ConfigInputStage(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICFilter);
static void GPT_TI2_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                              uint32_t GPT_ICFilter);
static void GPT_TI2_ConfigInputStage(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICFilter);
static void GPT_TI3_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                              uint32_t GPT_ICFilter);
static void GPT_TI4_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                              uint32_t GPT_ICFilter);

static void GPT_ETR_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ExtTRGPrescaler,
                              uint32_t GPT_ExtTRGPolarity, uint32_t ExtTRGFilter);

static void GPT_ITRx_SetConfig(GPT_TypeDef *TIMx, uint16_t GPT_ITRx);
static void GPT_DMAPeriodElapsedCplt(DMA_HandleTypeDef *hdma);
static void GPT_DMATriggerCplt(DMA_HandleTypeDef *hdma);
static void GPT_SlaveTimer_SetConfig(GPT_HandleTypeDef *htim,
                                     GPT_SlaveConfigTypeDef *sSlaveConfig);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPT_Exported_Functions TIM Exported Functions
  * @{
  */

/** @defgroup GPT_Exported_Functions_Group1 Time Base functions
 *  @brief    Time Base functions
 *
@verbatim
  ==============================================================================
              ##### Time Base functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM base.
    (+) De-initialize the TIM base.
    (+) Start the Time Base.
    (+) Stop the Time Base.
    (+) Start the Time Base and enable interrupt.
    (+) Stop the Time Base and disable interrupt.
    (+) Start the Time Base and enable DMA transfer.
    (+) Stop the Time Base and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM Time base Unit according to the specified
  *         parameters in the GPT_HandleTypeDef and create the associated handle.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Init(GPT_HandleTypeDef *htim)
{
    /* Check the TIM handle allocation */
    if (htim == NULL)
    {
        return HAL_ERROR;
    }

#ifdef hwp_gptim1
    if (htim->Instance == hwp_gptim1)
        HAL_RCC_EnableModule(RCC_MOD_GPTIM1);
#endif /* hwp_gptim1 */
#ifdef hwp_gptim2
    if (htim->Instance == hwp_gptim2)
        HAL_RCC_EnableModule(RCC_MOD_GPTIM2);
#endif /* hwp_gptim2 */
#ifdef hwp_gptim3
    if (htim->Instance == hwp_gptim3)
        HAL_RCC_EnableModule(RCC_MOD_GPTIM3);
#endif /* hwp_gptim3 */
#ifdef hwp_gptim4
    if (htim->Instance == hwp_gptim4)
        HAL_RCC_EnableModule(RCC_MOD_GPTIM4);
#endif /* hwp_gptim4 */
#ifdef hwp_gptim5
    if (htim->Instance == hwp_gptim5)
        HAL_RCC_EnableModule(RCC_MOD_GPTIM5);
#endif /* hwp_gptim5 */
#ifdef hwp_atim1
    if (htim->Instance == (GPT_TypeDef *)hwp_atim1)
        HAL_RCC_EnableModule(RCC_MOD_ATIM1);
#endif /* hwp_atim1 */
#ifdef hwp_atim2
    if (htim->Instance == (GPT_TypeDef *)hwp_atim2)
        HAL_RCC_EnableModule(RCC_MOD_ATIM2);
#endif /* hwp_atim2 */
#ifdef hwp_btim1
    if (htim->Instance == (GPT_TypeDef *)hwp_btim1)
        HAL_RCC_EnableModule(RCC_MOD_BTIM1);
#endif /* hwp_btim1 */
#ifdef hwp_btim2
    if (htim->Instance == (GPT_TypeDef *)hwp_btim2)
        HAL_RCC_EnableModule(RCC_MOD_BTIM2);
#endif /* hwp_btim2 */
#ifdef hwp_btim3
    if (htim->Instance == (GPT_TypeDef *)hwp_btim3)
        HAL_RCC_EnableModule(RCC_MOD_BTIM3);
#endif /* hwp_btim3 */
#ifdef hwp_btim4
    if (htim->Instance == (GPT_TypeDef *)hwp_btim4)
        HAL_RCC_EnableModule(RCC_MOD_BTIM4);
#endif /* hwp_btim4 */

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_COUNTER_MODE(htim->Init.CounterMode));

    if (htim->State == HAL_GPT_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        htim->Lock = HAL_UNLOCKED;
        /* Init the low level hardware : GPIO, CLOCK, NVIC */
        HAL_GPT_Base_MspInit(htim);
    }

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Set the Time Base configuration */
    GPT_Base_SetConfig(htim->Instance, &htim->Init);

    __HAL_GPT_CLEAR_FLAG(htim, GPT_FLAG_UPDATE);     /* clear update flag */
    __HAL_GPT_URS_ENABLE(htim);                      /* enable update request source */
    /* Initialize the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM Base peripheral
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_DeInit(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the TIM Peripheral Clock */
    __HAL_GPT_DISABLE(htim);

    /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
    HAL_GPT_Base_MspDeInit(htim);

    /* Change TIM state */
    htim->State = HAL_GPT_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM Base MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_Base_MspInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_Base_MspInit could be implemented in the user file
     */
}

/**
  * @brief  DeInitializes TIM Base MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_Base_MspDeInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_Base_MspDeInit could be implemented in the user file
     */
}

/**
  * @brief  Starts the TIM Base generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Start(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Change the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Base generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Stop(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Base generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Start_IT(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    /* Enable the TIM Update interrupt */
    __HAL_GPT_ENABLE_IT(htim, GPT_IT_UPDATE);

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Base generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Stop_IT(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    /* Disable the TIM Update interrupt */
    __HAL_GPT_DISABLE_IT(htim, GPT_IT_UPDATE);

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Base generation in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  pData The source Buffer address.
  * @param  Length The length of data to be transferred from memory to peripheral.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Start_DMA(GPT_HandleTypeDef *htim, uint32_t *pData, uint16_t Length)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMA_INSTANCE(htim->Instance));

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if ((pData == 0U) && (Length > 0))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }
    /* Set the DMA Period elapsed callback */
    htim->hdma[GPT_DMA_ID_UPDATE]->XferCpltCallback = GPT_DMAPeriodElapsedCplt;

    /* Set the DMA error callback */
    htim->hdma[GPT_DMA_ID_UPDATE]->XferErrorCallback = GPT_DMAError ;

    /* Enable the DMA Stream */
    HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_UPDATE], (uint32_t)pData, (uint32_t)&htim->Instance->ARR, Length);

    /* Enable the TIM Update DMA request */
    __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_UPDATE);

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Base generation in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Base_Stop_DMA(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMA_INSTANCE(htim->Instance));

    /* Disable the TIM Update DMA request */
    __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_UPDATE);

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group2 Time Output Compare functions
 *  @brief    Time Output Compare functions
 *
@verbatim
  ==============================================================================
                  ##### Time Output Compare functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM Output Compare.
    (+) De-initialize the TIM Output Compare.
    (+) Start the Time Output Compare.
    (+) Stop the Time Output Compare.
    (+) Start the Time Output Compare and enable interrupt.
    (+) Stop the Time Output Compare and disable interrupt.
    (+) Start the Time Output Compare and enable DMA transfer.
    (+) Stop the Time Output Compare and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM Output Compare according to the specified
  *         parameters in the GPT_HandleTypeDef and create the associated handle.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Init(GPT_HandleTypeDef *htim)
{
    /* Check the TIM handle allocation */
    if (htim == NULL)
    {
        return HAL_ERROR;
    }

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_COUNTER_MODE(htim->Init.CounterMode));

    if (htim->State == HAL_GPT_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        htim->Lock = HAL_UNLOCKED;
        /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
        HAL_GPT_OC_MspInit(htim);
    }

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Init the base time for the Output Compare */
    GPT_Base_SetConfig(htim->Instance,  &htim->Init);

    /* Initialize the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM peripheral
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_DeInit(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the TIM Peripheral Clock */
    __HAL_GPT_DISABLE(htim);

    /* DeInit the low level hardware: GPIO, CLOCK, NVIC and DMA */
    HAL_GPT_OC_MspDeInit(htim);

    /* Change TIM state */
    htim->State = HAL_GPT_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM Output Compare MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_OC_MspInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_OC_MspInit could be implemented in the user file
     */
}

/**
  * @brief  DeInitializes TIM Output Compare MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_OC_MspDeInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_OC_MspDeInit could be implemented in the user file
     */
}

/**
  * @brief  Starts the TIM Output Compare signal generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Start(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    /* Enable the Output compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Output Compare signal generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Stop(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    /* Disable the Output compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Output Compare signal generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Start_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Enable the TIM Capture/Compare 1 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Enable the TIM Capture/Compare 2 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Enable the TIM Capture/Compare 3 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Enable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC4);
    }
    break;

    default:
        break;
    }

    /* Enable the Output compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Output Compare signal generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Stop_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Disable the TIM Capture/Compare 1 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Disable the TIM Capture/Compare 2 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Disable the TIM Capture/Compare 3 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Disable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC4);
    }
    break;

    default:
        break;
    }

    /* Disable the Output compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Output Compare signal generation in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @param  pData The source Buffer address.
  * @param  Length The length of data to be transferred from memory to TIM peripheral
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Start_DMA(GPT_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if (((uint32_t)pData == 0U) && (Length > 0))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }
    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)pData, (uint32_t)&htim->Instance->CCR1, Length);

        /* Enable the TIM Capture/Compare 1 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)pData, (uint32_t)&htim->Instance->CCR2, Length);

        /* Enable the TIM Capture/Compare 2 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC3], (uint32_t)pData, (uint32_t)&htim->Instance->CCR3, Length);

        /* Enable the TIM Capture/Compare 3 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC4], (uint32_t)pData, (uint32_t)&htim->Instance->CCR4, Length);

        /* Enable the TIM Capture/Compare 4 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC4);
    }
    break;

    default:
        break;
    }

    /* Enable the Output compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Output Compare signal generation in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_Stop_DMA(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Disable the TIM Capture/Compare 1 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Disable the TIM Capture/Compare 2 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Disable the TIM Capture/Compare 3 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Disable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC4);
    }
    break;

    default:
        break;
    }

    /* Disable the Output compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group3 Time PWM functions
 *  @brief    Time PWM functions
 *
@verbatim
  ==============================================================================
                          ##### Time PWM functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM OPWM.
    (+) De-initialize the TIM PWM.
    (+) Start the Time PWM.
    (+) Stop the Time PWM.
    (+) Start the Time PWM and enable interrupt.
    (+) Stop the Time PWM and disable interrupt.
    (+) Start the Time PWM and enable DMA transfer.
    (+) Stop the Time PWM and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM PWM Time Base according to the specified
  *         parameters in the GPT_HandleTypeDef and create the associated handle.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Init(GPT_HandleTypeDef *htim)
{
    /* Check the TIM handle allocation */
    if (htim == NULL)
    {
        return HAL_ERROR;
    }

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_COUNTER_MODE(htim->Init.CounterMode));

    if (htim->State == HAL_GPT_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        htim->Lock = HAL_UNLOCKED;
        /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
        HAL_GPT_PWM_MspInit(htim);
    }

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Init the base time for the PWM */
    GPT_Base_SetConfig(htim->Instance, &htim->Init);

    /* Initialize the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM peripheral
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_DeInit(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the TIM Peripheral Clock */
    __HAL_GPT_DISABLE(htim);

    /* DeInit the low level hardware: GPIO, CLOCK, NVIC and DMA */
    HAL_GPT_PWM_MspDeInit(htim);

    /* Change TIM state */
    htim->State = HAL_GPT_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM PWM MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_PWM_MspInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_PWM_MspInit could be implemented in the user file
     */
}

/**
  * @brief  DeInitializes TIM PWM MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_PWM_MspDeInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_PWM_MspDeInit could be implemented in the user file
     */
}

/**
  * @brief  Starts the PWM signal generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Start(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    /* Enable the Capture compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the PWM signal generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Stop(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    /* Disable the Capture compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the PWM signal generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channel to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Start_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Enable the TIM Capture/Compare 1 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Enable the TIM Capture/Compare 2 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Enable the TIM Capture/Compare 3 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Enable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC4);
    }
    break;

    default:
        break;
    }

    /* Enable the Capture compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the PWM signal generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Stop_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Disable the TIM Capture/Compare 1 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Disable the TIM Capture/Compare 2 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Disable the TIM Capture/Compare 3 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Disable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC4);
    }
    break;

    default:
        break;
    }

    /* Disable the Capture compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM PWM signal generation in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @param  pData The source Buffer address.
  * @param  Length The length of data to be transferred from memory to TIM peripheral
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Start_DMA(GPT_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if (((uint32_t)pData == 0U) && (Length > 0))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }
    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)pData, (uint32_t)&htim->Instance->CCR1, Length);

        /* Enable the TIM Capture/Compare 1 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)pData, (uint32_t)&htim->Instance->CCR2, Length);

        /* Enable the TIM Capture/Compare 2 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC3], (uint32_t)pData, (uint32_t)&htim->Instance->CCR3, Length);

        /* Enable the TIM Output Capture/Compare 3 request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC4], (uint32_t)pData, (uint32_t)&htim->Instance->CCR4, Length);

        /* Enable the TIM Capture/Compare 4 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC4);
    }
    break;

    default:
        break;
    }

    /* Enable the Capture compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM PWM signal generation in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_Stop_DMA(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Disable the TIM Capture/Compare 1 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Disable the TIM Capture/Compare 2 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Disable the TIM Capture/Compare 3 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Disable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC4);
    }
    break;

    default:
        break;
    }

    /* Disable the Capture compare channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group4 Time Input Capture functions
 *  @brief    Time Input Capture functions
 *
@verbatim
  ==============================================================================
              ##### Time Input Capture functions #####
  ==============================================================================
 [..]
   This section provides functions allowing to:
   (+) Initialize and configure the TIM Input Capture.
   (+) De-initialize the TIM Input Capture.
   (+) Start the Time Input Capture.
   (+) Stop the Time Input Capture.
   (+) Start the Time Input Capture and enable interrupt.
   (+) Stop the Time Input Capture and disable interrupt.
   (+) Start the Time Input Capture and enable DMA transfer.
   (+) Stop the Time Input Capture and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM Input Capture Time base according to the specified
  *         parameters in the GPT_HandleTypeDef and create the associated handle.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Init(GPT_HandleTypeDef *htim)
{
    /* Check the TIM handle allocation */
    if (htim == NULL)
    {
        return HAL_ERROR;
    }

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_COUNTER_MODE(htim->Init.CounterMode));

    if (htim->State == HAL_GPT_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        htim->Lock = HAL_UNLOCKED;
        /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
        HAL_GPT_IC_MspInit(htim);
    }

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Init the base time for the input capture */
    GPT_Base_SetConfig(htim->Instance, &htim->Init);

    /* Initialize the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM peripheral
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_DeInit(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the TIM Peripheral Clock */
    __HAL_GPT_DISABLE(htim);

    /* DeInit the low level hardware: GPIO, CLOCK, NVIC and DMA */
    HAL_GPT_IC_MspDeInit(htim);

    /* Change TIM state */
    htim->State = HAL_GPT_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM INput Capture MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_IC_MspInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_IC_MspInit could be implemented in the user file
     */
}

/**
  * @brief  DeInitializes TIM Input Capture MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_IC_MspDeInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_IC_MspDeInit could be implemented in the user file
     */
}

/**
  * @brief  Starts the TIM Input Capture measurement.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Start(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    /* Enable the Input Capture channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Input Capture measurement.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Stop(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    /* Disable the Input Capture channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Input Capture measurement in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Start_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Enable the TIM Capture/Compare 1 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Enable the TIM Capture/Compare 2 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Enable the TIM Capture/Compare 3 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Enable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC4);
    }
    break;

    default:
        break;
    }
    /* Enable the Input Capture channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Input Capture measurement in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Stop_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Disable the TIM Capture/Compare 1 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Disable the TIM Capture/Compare 2 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Disable the TIM Capture/Compare 3 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Disable the TIM Capture/Compare 4 interrupt */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC4);
    }
    break;

    default:
        break;
    }

    /* Disable the Input Capture channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Input Capture measurement on in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @param  pData The destination Buffer address.
  * @param  Length The length of data to be transferred from TIM peripheral to memory.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Start_DMA(GPT_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));
    HAL_ASSERT(IS_GPT_DMA_CC_INSTANCE(htim->Instance));

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if ((pData == 0U) && (Length > 0))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)&htim->Instance->CCR1, (uint32_t)pData, Length);

        /* Enable the TIM Capture/Compare 1 DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)&htim->Instance->CCR2, (uint32_t)pData, Length);

        /* Enable the TIM Capture/Compare 2  DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC3], (uint32_t)&htim->Instance->CCR3, (uint32_t)pData, Length);

        /* Enable the TIM Capture/Compare 3  DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC4], (uint32_t)&htim->Instance->CCR4, (uint32_t)pData, Length);

        /* Enable the TIM Capture/Compare 4  DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC4);
    }
    break;

    default:
        break;
    }

    /* Enable the Input Capture channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_ENABLE);

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Input Capture measurement on in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_Stop_DMA(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CCX_INSTANCE(htim->Instance, Channel));
    HAL_ASSERT(IS_GPT_DMA_CC_INSTANCE(htim->Instance));

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Disable the TIM Capture/Compare 1 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC1);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Disable the TIM Capture/Compare 2 DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    case GPT_CHANNEL_3:
    {
        /* Disable the TIM Capture/Compare 3  DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC3);
    }
    break;

    case GPT_CHANNEL_4:
    {
        /* Disable the TIM Capture/Compare 4  DMA request */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC4);
    }
    break;

    default:
        break;
    }

    /* Disable the Input Capture channel */
    GPT_CCxChannelCmd(htim->Instance, Channel, GPT_CCx_DISABLE);

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group5 Time One Pulse functions
 *  @brief    Time One Pulse functions
 *
@verbatim
  ==============================================================================
                        ##### Time One Pulse functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM One Pulse.
    (+) De-initialize the TIM One Pulse.
    (+) Start the Time One Pulse.
    (+) Stop the Time One Pulse.
    (+) Start the Time One Pulse and enable interrupt.
    (+) Stop the Time One Pulse and disable interrupt.
    (+) Start the Time One Pulse and enable DMA transfer.
    (+) Stop the Time One Pulse and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM One Pulse Time Base according to the specified
  *         parameters in the GPT_HandleTypeDef and create the associated handle.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  OnePulseMode Select the One pulse mode.
  *         This parameter can be one of the following values:
  *            @arg GPT_OPMODE_SINGLE: Only one pulse will be generated.
  *            @arg GPT_OPMODE_REPETITIVE: Repetitive pulses will be generated.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_Init(GPT_HandleTypeDef *htim, uint32_t OnePulseMode)
{
    /* Check the TIM handle allocation */
    if (htim == NULL)
    {
        return HAL_ERROR;
    }

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_COUNTER_MODE(htim->Init.CounterMode));
    HAL_ASSERT(IS_GPT_OPM_MODE(OnePulseMode));

    if (htim->State == HAL_GPT_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        htim->Lock = HAL_UNLOCKED;
        /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
        HAL_GPT_OnePulse_MspInit(htim);
    }

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Configure the Time base in the One Pulse Mode */
    GPT_Base_SetConfig(htim->Instance, &htim->Init);

    /* Reset the OPM Bit */
    htim->Instance->CR1 &= ~GPT_CR1_OPM;

    /* Configure the OPM Mode */
    htim->Instance->CR1 |= OnePulseMode;

    /* Initialize the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM One Pulse
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_DeInit(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the TIM Peripheral Clock */
    __HAL_GPT_DISABLE(htim);

    /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
    HAL_GPT_OnePulse_MspDeInit(htim);

    /* Change TIM state */
    htim->State = HAL_GPT_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM One Pulse MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_OnePulse_MspInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_OnePulse_MspInit could be implemented in the user file
     */
}

/**
  * @brief  DeInitializes TIM One Pulse MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_OnePulse_MspDeInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_OnePulse_MspDeInit could be implemented in the user file
     */
}

/**
  * @brief  Starts the TIM One Pulse signal generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  OutputChannel  TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_Start(GPT_HandleTypeDef *htim, uint32_t OutputChannel)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(OutputChannel);

    /* Enable the Capture compare and the Input Capture channels
      (in the OPM Mode the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2)
      if GPT_CHANNEL_1 is used as output, the GPT_CHANNEL_2 will be used as input and
      if GPT_CHANNEL_1 is used as input, the GPT_CHANNEL_2 will be used as output
      in all combinations, the GPT_CHANNEL_1 and GPT_CHANNEL_2 should be enabled together

      No need to enable the counter, it's enabled automatically by hardware
      (the counter starts in response to a stimulus and generate a pulse */

    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM One Pulse signal generation.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  OutputChannel  TIM Channels to be disable.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_Stop(GPT_HandleTypeDef *htim, uint32_t OutputChannel)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(OutputChannel);

    /* Disable the Capture compare and the Input Capture channels
    (in the OPM Mode the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2)
    if GPT_CHANNEL_1 is used as output, the GPT_CHANNEL_2 will be used as input and
    if GPT_CHANNEL_1 is used as input, the GPT_CHANNEL_2 will be used as output
    in all combinations, the GPT_CHANNEL_1 and GPT_CHANNEL_2 should be disabled together */

    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);
    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM One Pulse signal generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  OutputChannel  TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_Start_IT(GPT_HandleTypeDef *htim, uint32_t OutputChannel)
{
    /* Enable the Capture compare and the Input Capture channels
      (in the OPM Mode the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2)
      if GPT_CHANNEL_1 is used as output, the GPT_CHANNEL_2 will be used as input and
      if GPT_CHANNEL_1 is used as input, the GPT_CHANNEL_2 will be used as output
      in all combinations, the GPT_CHANNEL_1 and GPT_CHANNEL_2 should be enabled together

      No need to enable the counter, it's enabled automatically by hardware
      (the counter starts in response to a stimulus and generate a pulse */

    /* Prevent unused argument(s) compilation warning */
    UNUSED(OutputChannel);

    /* Enable the TIM Capture/Compare 1 interrupt */
    __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC1);

    /* Enable the TIM Capture/Compare 2 interrupt */
    __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC2);

    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Enable the main output */
        __HAL_GPT_MOE_ENABLE(htim);
    }

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM One Pulse signal generation in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  OutputChannel  TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_Stop_IT(GPT_HandleTypeDef *htim, uint32_t OutputChannel)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(OutputChannel);

    /* Disable the TIM Capture/Compare 1 interrupt */
    __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC1);

    /* Disable the TIM Capture/Compare 2 interrupt */
    __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC2);

    /* Disable the Capture compare and the Input Capture channels
    (in the OPM Mode the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2)
    if GPT_CHANNEL_1 is used as output, the GPT_CHANNEL_2 will be used as input and
    if GPT_CHANNEL_1 is used as input, the GPT_CHANNEL_2 will be used as output
    in all combinations, the GPT_CHANNEL_1 and GPT_CHANNEL_2 should be disabled together */
    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);
    GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);

    if (IS_GPT_ADVANCED_INSTANCE(htim->Instance) != RESET)
    {
        /* Disable the Main Output */
        __HAL_GPT_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group6 Time Encoder functions
 *  @brief    Time Encoder functions
 *
@verbatim
  ==============================================================================
                          ##### Time Encoder functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM Encoder.
    (+) De-initialize the TIM Encoder.
    (+) Start the Time Encoder.
    (+) Stop the Time Encoder.
    (+) Start the Time Encoder and enable interrupt.
    (+) Stop the Time Encoder and disable interrupt.
    (+) Start the Time Encoder and enable DMA transfer.
    (+) Stop the Time Encoder and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM Encoder Interface and create the associated handle.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sConfig TIM Encoder Interface configuration structure
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Init(GPT_HandleTypeDef *htim,  GPT_Encoder_InitTypeDef *sConfig)
{
    uint32_t tmpsmcr = 0U;
    uint32_t tmpccmr1 = 0U;
    uint32_t tmpccer = 0U;

    /* Check the TIM handle allocation */
    if (htim == NULL)
    {
        return HAL_ERROR;
    }

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
    //TODO: wrong defintion of GPT_ENCODERMODE_TI1
    //HAL_ASSERT(IS_GPT_ENCODER_MODE(sConfig->EncoderMode));
    HAL_ASSERT(IS_GPT_IC_SELECTION(sConfig->IC1Selection));
    HAL_ASSERT(IS_GPT_IC_SELECTION(sConfig->IC2Selection));
    HAL_ASSERT(IS_GPT_IC_POLARITY(sConfig->IC1Polarity));
    HAL_ASSERT(IS_GPT_IC_POLARITY(sConfig->IC2Polarity));
    HAL_ASSERT(IS_GPT_IC_PRESCALER(sConfig->IC1Prescaler));
    HAL_ASSERT(IS_GPT_IC_PRESCALER(sConfig->IC2Prescaler));
    HAL_ASSERT(IS_GPT_IC_FILTER(sConfig->IC1Filter));
    HAL_ASSERT(IS_GPT_IC_FILTER(sConfig->IC2Filter));

    if (htim->State == HAL_GPT_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        htim->Lock = HAL_UNLOCKED;
        /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
        HAL_GPT_Encoder_MspInit(htim);
    }

    /* Set the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Reset the SMS bits */
    htim->Instance->SMCR &= ~GPT_SMCR_SMS;

    /* Configure the Time base in the Encoder Mode */
    GPT_Base_SetConfig(htim->Instance, &htim->Init);

    /* Get the TIMx SMCR register value */
    tmpsmcr = htim->Instance->SMCR;

    /* Get the TIMx CCMR1 register value */
    tmpccmr1 = htim->Instance->CCMR1;

    /* Get the TIMx CCER register value */
    tmpccer = htim->Instance->CCER;

    /* Set the encoder Mode */
    tmpsmcr |= sConfig->EncoderMode;

    /* Select the Capture Compare 1 and the Capture Compare 2 as input */
    tmpccmr1 &= ~(GPT_CCMR1_CC1S | GPT_CCMR1_CC2S);
    tmpccmr1 |= (sConfig->IC1Selection | (sConfig->IC2Selection << 8U));

    /* Set the Capture Compare 1 and the Capture Compare 2 prescalers and filters */
    tmpccmr1 &= ~(GPT_CCMR1_IC1PSC | GPT_CCMR1_IC2PSC);
    tmpccmr1 &= ~(GPT_CCMR1_IC1F | GPT_CCMR1_IC2F);
    tmpccmr1 |= sConfig->IC1Prescaler | (sConfig->IC2Prescaler << 8U);
    tmpccmr1 |= (sConfig->IC1Filter << 4U) | (sConfig->IC2Filter << 12U);

    /* Set the TI1 and the TI2 Polarities */
    tmpccer &= ~(GPT_CCER_CC1P | GPT_CCER_CC2P);
    tmpccer &= ~(GPT_CCER_CC1NP | GPT_CCER_CC2NP);
    tmpccer |= sConfig->IC1Polarity | (sConfig->IC2Polarity << 4U);

    /* Write to TIMx SMCR */
    htim->Instance->SMCR = tmpsmcr;

    /* Write to TIMx CCMR1 */
    htim->Instance->CCMR1 = tmpccmr1;

    /* Write to TIMx CCER */
    htim->Instance->CCER = tmpccer;

    /* Initialize the TIM state*/
    htim->State = HAL_GPT_STATE_READY;

    return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM Encoder interface
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_DeInit(GPT_HandleTypeDef *htim)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

    htim->State = HAL_GPT_STATE_BUSY;

    /* Disable the TIM Peripheral Clock */
    __HAL_GPT_DISABLE(htim);

    /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
    HAL_GPT_Encoder_MspDeInit(htim);

    /* Change TIM state */
    htim->State = HAL_GPT_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM Encoder Interface MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_Encoder_MspInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_Encoder_MspInit could be implemented in the user file
     */
}

/**
  * @brief  DeInitializes TIM Encoder Interface MSP.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_Encoder_MspDeInit(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_Encoder_MspDeInit could be implemented in the user file
     */
}

/**
  * @brief  Starts the TIM Encoder Interface.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_ALL: TIM Channel 1 and TIM Channel 2 are selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Start(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

    /* Enable the encoder interface channels */
    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
        break;
    }
    case GPT_CHANNEL_2:
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);
        break;
    }
    default :
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);
        break;
    }
    }
    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Encoder Interface.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_ALL: TIM Channel 1 and TIM Channel 2 are selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Stop(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

    /* Disable the Input Capture channels 1 and 2
     (in the EncoderInterface the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2) */
    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);
        break;
    }
    case GPT_CHANNEL_2:
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);
        break;
    }
    default :
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);
        break;
    }
    }
    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Encoder Interface in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_ALL: TIM Channel 1 and TIM Channel 2 are selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Start_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

    /* Enable the encoder interface channels */
    /* Enable the capture compare Interrupts 1 and/or 2 */
    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC1);
        break;
    }
    case GPT_CHANNEL_2:
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC2);
        break;
    }
    default :
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC1);
        __HAL_GPT_ENABLE_IT(htim, GPT_IT_CC2);
        break;
    }
    }

    /* Enable the Peripheral */
    __HAL_GPT_ENABLE(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Encoder Interface in interrupt mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be disabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_ALL: TIM Channel 1 and TIM Channel 2 are selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Stop_IT(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

    /* Disable the Input Capture channels 1 and 2
      (in the EncoderInterface the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2) */
    if (Channel == GPT_CHANNEL_1)
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);

        /* Disable the capture compare Interrupts 1 */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC1);
    }
    else if (Channel == GPT_CHANNEL_2)
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);

        /* Disable the capture compare Interrupts 2 */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC2);
    }
    else
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);

        /* Disable the capture compare Interrupts 1 and 2 */
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC1);
        __HAL_GPT_DISABLE_IT(htim, GPT_IT_CC2);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Starts the TIM Encoder Interface in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_ALL: TIM Channel 1 and TIM Channel 2 are selected
  * @param  pData1 The destination Buffer address for IC1.
  * @param  pData2 The destination Buffer address for IC2.
  * @param  Length The length of data to be transferred from TIM peripheral to memory.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Start_DMA(GPT_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1, uint32_t *pData2, uint16_t Length)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMA_CC_INSTANCE(htim->Instance));

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if ((((pData1 == 0U) || (pData2 == 0U))) && (Length > 0))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)&htim->Instance->CCR1, (uint32_t)pData1, Length);

        /* Enable the TIM Input Capture DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC1);

        /* Enable the Peripheral */
        __HAL_GPT_ENABLE(htim);

        /* Enable the Capture compare channel */
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
    }
    break;

    case GPT_CHANNEL_2:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError;
        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)&htim->Instance->CCR2, (uint32_t)pData2, Length);

        /* Enable the TIM Input Capture  DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC2);

        /* Enable the Peripheral */
        __HAL_GPT_ENABLE(htim);

        /* Enable the Capture compare channel */
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);
    }
    break;

    case GPT_CHANNEL_ALL:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)&htim->Instance->CCR1, (uint32_t)pData1, Length);

        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)&htim->Instance->CCR2, (uint32_t)pData2, Length);

        /* Enable the Peripheral */
        __HAL_GPT_ENABLE(htim);

        /* Enable the Capture compare channel */
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_ENABLE);
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_ENABLE);

        /* Enable the TIM Input Capture  DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC1);
        /* Enable the TIM Input Capture  DMA request */
        __HAL_GPT_ENABLE_DMA(htim, GPT_DMA_CC2);
    }
    break;

    default:
        break;
    }
    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM Encoder Interface in DMA mode.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_ALL: TIM Channel 1 and TIM Channel 2 are selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_Encoder_Stop_DMA(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMA_CC_INSTANCE(htim->Instance));

    /* Disable the Input Capture channels 1 and 2
      (in the EncoderInterface the two possible channels that can be used are GPT_CHANNEL_1 and GPT_CHANNEL_2) */
    if (Channel == GPT_CHANNEL_1)
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);

        /* Disable the capture compare DMA Request 1 */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC1);
    }
    else if (Channel == GPT_CHANNEL_2)
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);

        /* Disable the capture compare DMA Request 2 */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC2);
    }
    else
    {
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_1, GPT_CCx_DISABLE);
        GPT_CCxChannelCmd(htim->Instance, GPT_CHANNEL_2, GPT_CCx_DISABLE);

        /* Disable the capture compare DMA Request 1 and 2 */
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC1);
        __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_CC2);
    }

    /* Disable the Peripheral */
    __HAL_GPT_DISABLE(htim);

    /* Change the htim state */
    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group7 TIM IRQ handler management
 *  @brief    IRQ handler management
 *
@verbatim
  ==============================================================================
                        ##### IRQ handler management #####
  ==============================================================================
  [..]
    This section provides Timer IRQ handler function.

@endverbatim
  * @{
  */
/**
  * @brief  This function handles TIM interrupts requests.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__HAL_ROM_USED void HAL_GPT_IRQHandler(GPT_HandleTypeDef *htim)
{
    /* Capture compare 1 event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_CC1) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_CC1) != RESET)
        {
            {
                __HAL_GPT_CLEAR_IT(htim, GPT_IT_CC1);
                htim->Channel = HAL_GPT_ACTIVE_CHANNEL_1;

                /* Input capture event */
                if ((htim->Instance->CCMR1 & GPT_CCMR1_CC1S) != 0x00U)
                {
                    HAL_GPT_IC_CaptureCallback(htim);
                }
                /* Output compare event */
                else
                {
                    HAL_GPT_OC_DelayElapsedCallback(htim);
                    HAL_GPT_PWM_PulseFinishedCallback(htim);
                }
                htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
            }
        }
    }
    /* Capture compare 2 event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_CC2) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_CC2) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_IT_CC2);
            htim->Channel = HAL_GPT_ACTIVE_CHANNEL_2;
            /* Input capture event */
            if ((htim->Instance->CCMR1 & GPT_CCMR1_CC2S) != 0x00U)
            {
                HAL_GPT_IC_CaptureCallback(htim);
            }
            /* Output compare event */
            else
            {
                HAL_GPT_OC_DelayElapsedCallback(htim);
                HAL_GPT_PWM_PulseFinishedCallback(htim);
            }
            htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
        }
    }
    /* Capture compare 3 event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_CC3) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_CC3) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_IT_CC3);
            htim->Channel = HAL_GPT_ACTIVE_CHANNEL_3;
            /* Input capture event */
            if ((htim->Instance->CCMR2 & GPT_CCMR2_CC3S) != 0x00U)
            {
                HAL_GPT_IC_CaptureCallback(htim);
            }
            /* Output compare event */
            else
            {
                HAL_GPT_OC_DelayElapsedCallback(htim);
                HAL_GPT_PWM_PulseFinishedCallback(htim);
            }
            htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
        }
    }
    /* Capture compare 4 event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_CC4) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_CC4) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_IT_CC4);
            htim->Channel = HAL_GPT_ACTIVE_CHANNEL_4;
            /* Input capture event */
            if ((htim->Instance->CCMR2 & GPT_CCMR2_CC4S) != 0x00U)
            {
                HAL_GPT_IC_CaptureCallback(htim);
            }
            /* Output compare event */
            else
            {
                HAL_GPT_OC_DelayElapsedCallback(htim);
                HAL_GPT_PWM_PulseFinishedCallback(htim);
            }
            htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
        }
    }
    /* TIM Update event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_UPDATE) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_UPDATE) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_IT_UPDATE);
            HAL_GPT_PeriodElapsedCallback(htim);
        }
    }
    /* TIM Break input event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_BREAK) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_BREAK) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_IT_BREAK);
            HAL_TIMEx_BreakCallback(htim);
        }
    }
    /* TIM Trigger detection event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_TRIGGER) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_TRIGGER) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_IT_TRIGGER);
            HAL_GPT_TriggerCallback(htim);
        }
    }
    /* TIM commutation event */
    if (__HAL_GPT_GET_FLAG(htim, GPT_FLAG_COM) != RESET)
    {
        if (__HAL_GPT_GET_IT_SOURCE(htim, GPT_IT_COM) != RESET)
        {
            __HAL_GPT_CLEAR_IT(htim, GPT_FLAG_COM);
            HAL_TIMEx_CommutationCallback(htim);
        }
    }
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group8 Peripheral Control functions
 *  @brief      Peripheral Control functions
 *
@verbatim
  ==============================================================================
                   ##### Peripheral Control functions #####
  ==============================================================================
 [..]
   This section provides functions allowing to:
   (+) Configure The Input Output channels for OC, PWM, IC or One Pulse mode.
   (+) Configure External Clock source.
   (+) Configure Complementary channels, break features and dead time.
   (+) Configure Master and the Slave synchronization.
   (+) Configure the DMA Burst Mode.

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the TIM Output Compare Channels according to the specified
  *         parameters in the GPT_OC_InitTypeDef.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sConfig TIM Output Compare configuration structure
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OC_ConfigChannel(GPT_HandleTypeDef *htim, GPT_OC_InitTypeDef *sConfig, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CHANNELS(Channel));
    HAL_ASSERT(IS_GPT_OC_MODE(sConfig->OCMode));
    HAL_ASSERT(IS_GPT_OC_POLARITY(sConfig->OCPolarity));

    /* Check input state */
    __HAL_LOCK(htim);

    htim->State = HAL_GPT_STATE_BUSY;

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));
        /* Configure the TIM Channel 1 in Output Compare */
        GPT_OC1_SetConfig(htim->Instance, sConfig);
    }
    break;

    case GPT_CHANNEL_2:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        /* Configure the TIM Channel 2 in Output Compare */
        GPT_OC2_SetConfig(htim->Instance, sConfig);
    }
    break;

    case GPT_CHANNEL_3:
    {
        HAL_ASSERT(IS_GPT_CC3_INSTANCE(htim->Instance));
        /* Configure the TIM Channel 3 in Output Compare */
        GPT_OC3_SetConfig(htim->Instance, sConfig);
    }
    break;

    case GPT_CHANNEL_4:
    {
        HAL_ASSERT(IS_GPT_CC4_INSTANCE(htim->Instance));
        /* Configure the TIM Channel 4 in Output Compare */
        GPT_OC4_SetConfig(htim->Instance, sConfig);
    }
    break;

    default:
        break;
    }
    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM Input Capture Channels according to the specified
  *         parameters in the GPT_IC_InitTypeDef.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sConfig TIM Input Capture configuration structure
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_IC_ConfigChannel(GPT_HandleTypeDef *htim, GPT_IC_InitTypeDef *sConfig, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_IC_POLARITY(sConfig->ICPolarity));
    HAL_ASSERT(IS_GPT_IC_SELECTION(sConfig->ICSelection));
    HAL_ASSERT(IS_GPT_IC_PRESCALER(sConfig->ICPrescaler));
    HAL_ASSERT(IS_GPT_IC_FILTER(sConfig->ICFilter));

    __HAL_LOCK(htim);

    htim->State = HAL_GPT_STATE_BUSY;

    if (Channel == GPT_CHANNEL_1)
    {
        /* TI1 Configuration */
        GPT_TI1_SetConfig(htim->Instance,
                          sConfig->ICPolarity,
                          sConfig->ICSelection,
                          sConfig->ICFilter);

        /* Reset the IC1PSC Bits */
        htim->Instance->CCMR1 &= ~GPT_CCMR1_IC1PSC;

        /* Set the IC1PSC value */
        htim->Instance->CCMR1 |= sConfig->ICPrescaler;
    }
    else if (Channel == GPT_CHANNEL_2)
    {
        /* TI2 Configuration */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

        GPT_TI2_SetConfig(htim->Instance,
                          sConfig->ICPolarity,
                          sConfig->ICSelection,
                          sConfig->ICFilter);

        /* Reset the IC2PSC Bits */
        htim->Instance->CCMR1 &= ~GPT_CCMR1_IC2PSC;

        /* Set the IC2PSC value */
        htim->Instance->CCMR1 |= (sConfig->ICPrescaler << 8U);
    }
    else if (Channel == GPT_CHANNEL_3)
    {
        /* TI3 Configuration */
        HAL_ASSERT(IS_GPT_CC3_INSTANCE(htim->Instance));

        GPT_TI3_SetConfig(htim->Instance,
                          sConfig->ICPolarity,
                          sConfig->ICSelection,
                          sConfig->ICFilter);

        /* Reset the IC3PSC Bits */
        htim->Instance->CCMR2 &= ~GPT_CCMR2_IC3PSC;

        /* Set the IC3PSC value */
        htim->Instance->CCMR2 |= sConfig->ICPrescaler;
    }
    else
    {
        /* TI4 Configuration */
        HAL_ASSERT(IS_GPT_CC4_INSTANCE(htim->Instance));

        GPT_TI4_SetConfig(htim->Instance,
                          sConfig->ICPolarity,
                          sConfig->ICSelection,
                          sConfig->ICFilter);

        /* Reset the IC4PSC Bits */
        htim->Instance->CCMR2 &= ~GPT_CCMR2_IC4PSC;

        /* Set the IC4PSC value */
        htim->Instance->CCMR2 |= (sConfig->ICPrescaler << 8U);
    }

    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM PWM  channels according to the specified
  *         parameters in the GPT_OC_InitTypeDef.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sConfig TIM PWM configuration structure
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_PWM_ConfigChannel(GPT_HandleTypeDef *htim, GPT_OC_InitTypeDef *sConfig, uint32_t Channel)
{
    __HAL_LOCK(htim);

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CHANNELS(Channel));
    HAL_ASSERT(IS_GPT_PWM_MODE(sConfig->OCMode));
    HAL_ASSERT(IS_GPT_OC_POLARITY(sConfig->OCPolarity));
    //HAL_ASSERT(IS_GPT_FAST_STATE(sConfig->OCFastMode));

    htim->State = HAL_GPT_STATE_BUSY;

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));
        /* Configure the Channel 1 in PWM mode */
        GPT_OC1_SetConfig(htim->Instance, sConfig);

        /* Set the Preload enable bit for channel1 */
        htim->Instance->CCMR1 |= GPT_CCMR1_OC1PE;
    }
    break;

    case GPT_CHANNEL_2:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        /* Configure the Channel 2 in PWM mode */
        GPT_OC2_SetConfig(htim->Instance, sConfig);

        /* Set the Preload enable bit for channel2 */
        htim->Instance->CCMR1 |= GPT_CCMR1_OC2PE;
    }
    break;

    case GPT_CHANNEL_3:
    {
        HAL_ASSERT(IS_GPT_CC3_INSTANCE(htim->Instance));
        /* Configure the Channel 3 in PWM mode */
        GPT_OC3_SetConfig(htim->Instance, sConfig);

        /* Set the Preload enable bit for channel3 */
        htim->Instance->CCMR2 |= GPT_CCMR2_OC3PE;

    }
    break;

    case GPT_CHANNEL_4:
    {
        HAL_ASSERT(IS_GPT_CC4_INSTANCE(htim->Instance));
        /* Configure the Channel 4 in PWM mode */
        GPT_OC4_SetConfig(htim->Instance, sConfig);

        /* Set the Preload enable bit for channel4 */
        htim->Instance->CCMR2 |= GPT_CCMR2_OC4PE;
    }
    break;

    default:
        break;
    }

    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Initializes the TIM One Pulse Channels according to the specified
  *         parameters in the GPT_OnePulse_InitTypeDef.
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sConfig TIM One Pulse configuration structure
  * @param  OutputChannel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  * @param  InputChannel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_OnePulse_ConfigChannel(GPT_HandleTypeDef *htim,  GPT_OnePulse_InitTypeDef *sConfig, uint32_t OutputChannel,  uint32_t InputChannel)
{
    GPT_OC_InitTypeDef temp1;

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_OPM_CHANNELS(OutputChannel));
    HAL_ASSERT(IS_GPT_OPM_CHANNELS(InputChannel));

    if (OutputChannel != InputChannel)
    {
        __HAL_LOCK(htim);

        htim->State = HAL_GPT_STATE_BUSY;

        /* Extract the Output compare configuration from sConfig structure */
        temp1.OCMode = sConfig->OCMode;
        temp1.Pulse = sConfig->Pulse;
        temp1.OCPolarity = sConfig->OCPolarity;
        temp1.OCNPolarity = sConfig->OCNPolarity;
        temp1.OCIdleState = sConfig->OCIdleState;
        temp1.OCNIdleState = sConfig->OCNIdleState;

        switch (OutputChannel)
        {
        case GPT_CHANNEL_1:
        {
            HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));

            GPT_OC1_SetConfig(htim->Instance, &temp1);
        }
        break;
        case GPT_CHANNEL_2:
        {
            HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

            GPT_OC2_SetConfig(htim->Instance, &temp1);
        }
        break;
        default:
            break;
        }
        switch (InputChannel)
        {
        case GPT_CHANNEL_1:
        {
            HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));

            GPT_TI1_SetConfig(htim->Instance, sConfig->ICPolarity,
                              sConfig->ICSelection, sConfig->ICFilter);

            /* Reset the IC1PSC Bits */
            htim->Instance->CCMR1 &= ~GPT_CCMR1_IC1PSC;

            /* Select the Trigger source */
            htim->Instance->SMCR &= ~GPT_SMCR_TS;
            htim->Instance->SMCR |= GPT_TS_TI1FP1;

            /* Select the Slave Mode */
            htim->Instance->SMCR &= ~GPT_SMCR_SMS;
            htim->Instance->SMCR |= GPT_SLAVEMODE_TRIGGER;
        }
        break;
        case GPT_CHANNEL_2:
        {
            HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

            GPT_TI2_SetConfig(htim->Instance, sConfig->ICPolarity,
                              sConfig->ICSelection, sConfig->ICFilter);

            /* Reset the IC2PSC Bits */
            htim->Instance->CCMR1 &= ~GPT_CCMR1_IC2PSC;

            /* Select the Trigger source */
            htim->Instance->SMCR &= ~GPT_SMCR_TS;
            htim->Instance->SMCR |= GPT_TS_TI2FP2;

            /* Select the Slave Mode */
            htim->Instance->SMCR &= ~GPT_SMCR_SMS;
            htim->Instance->SMCR |= GPT_SLAVEMODE_TRIGGER;
        }
        break;

        default:
            break;
        }

        htim->State = HAL_GPT_STATE_READY;

        __HAL_UNLOCK(htim);

        return HAL_OK;
    }
    else
    {
        return HAL_ERROR;
    }
}

/**
  * @brief  Configure the DMA Burst to transfer Data from the memory to the TIM peripheral
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  BurstBaseAddress TIM Base address from when the DMA will starts the Data write.
  *         This parameters can be on of the following values:
  *            @arg GPT_DMABASE_CR1
  *            @arg GPT_DMABASE_CR2
  *            @arg GPT_DMABASE_SMCR
  *            @arg GPT_DMABASE_DIER
  *            @arg GPT_DMABASE_SR
  *            @arg GPT_DMABASE_EGR
  *            @arg GPT_DMABASE_CCMR1
  *            @arg GPT_DMABASE_CCMR2
  *            @arg GPT_DMABASE_CCER
  *            @arg GPT_DMABASE_CNT
  *            @arg GPT_DMABASE_PSC
  *            @arg GPT_DMABASE_ARR
  *            @arg GPT_DMABASE_RCR
  *            @arg GPT_DMABASE_CCR1
  *            @arg GPT_DMABASE_CCR2
  *            @arg GPT_DMABASE_CCR3
  *            @arg GPT_DMABASE_CCR4
  *            @arg GPT_DMABASE_BDTR
  *            @arg GPT_DMABASE_DCR
  * @param  BurstRequestSrc TIM DMA Request sources.
  *         This parameters can be on of the following values:
  *            @arg GPT_DMA_UPDATE: TIM update Interrupt source
  *            @arg GPT_DMA_CC1: TIM Capture Compare 1 DMA source
  *            @arg GPT_DMA_CC2: TIM Capture Compare 2 DMA source
  *            @arg GPT_DMA_CC3: TIM Capture Compare 3 DMA source
  *            @arg GPT_DMA_CC4: TIM Capture Compare 4 DMA source
  *            @arg GPT_DMA_COM: TIM Commutation DMA source
  *            @arg GPT_DMA_TRIGGER: TIM Trigger DMA source
  * @param  BurstBuffer The Buffer address.
  * @param  BurstLength DMA Burst length. This parameter can be one value
  *         between GPT_DMABURSTLENGTH_1TRANSFER and GPT_DMABURSTLENGTH_18TRANSFERS.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_DMABurst_WriteStart(GPT_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc,
        uint32_t *BurstBuffer, uint32_t  BurstLength)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMABURST_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_DMA_BASE(BurstBaseAddress));
    HAL_ASSERT(IS_GPT_DMA_SOURCE(BurstRequestSrc));
    HAL_ASSERT(IS_GPT_DMA_LENGTH(BurstLength));

    /* TODO: not support */
    return HAL_ERROR;

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if ((BurstBuffer == 0U) && (BurstLength > 0U))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }
    switch (BurstRequestSrc)
    {
    case GPT_DMA_UPDATE:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_UPDATE]->XferCpltCallback = GPT_DMAPeriodElapsedCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_UPDATE]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_UPDATE], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC1:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC2:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC3:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC3], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC4:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferCpltCallback = GPT_DMADelayPulseCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC4], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_COM:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_COMMUTATION]->XferCpltCallback = TIMEx_DMACommutationCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_COMMUTATION]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_COMMUTATION], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_TRIGGER:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_TRIGGER]->XferCpltCallback = GPT_DMATriggerCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_TRIGGER]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_TRIGGER], (uint32_t)BurstBuffer, (uint32_t)&htim->Instance->DMAR, ((BurstLength) >> 8U) + 1U);
    }
    break;
    default:
        break;
    }
    /* configure the DMA Burst Mode */
//    htim->Instance->DCR = BurstBaseAddress | BurstLength;

    /* Enable the TIM DMA Request */
    __HAL_GPT_ENABLE_DMA(htim, BurstRequestSrc);

    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stops the TIM DMA Burst mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  BurstRequestSrc TIM DMA Request sources to disable
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_DMABurst_WriteStop(GPT_HandleTypeDef *htim, uint32_t BurstRequestSrc)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMA_SOURCE(BurstRequestSrc));

    /* Abort the DMA transfer (at least disable the DMA channel) */
    switch (BurstRequestSrc)
    {
    case GPT_DMA_UPDATE:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_UPDATE]);
    }
    break;
    case GPT_DMA_CC1:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC1]);
    }
    break;
    case GPT_DMA_CC2:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC2]);
    }
    break;
    case GPT_DMA_CC3:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC3]);
    }
    break;
    case GPT_DMA_CC4:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC4]);
    }
    break;
    case GPT_DMA_COM:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_COMMUTATION]);
    }
    break;
    case GPT_DMA_TRIGGER:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_TRIGGER]);
    }
    break;
    default:
        break;
    }

    /* Disable the TIM Update DMA request */
    __HAL_GPT_DISABLE_DMA(htim, BurstRequestSrc);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Configure the DMA Burst to transfer Data from the TIM peripheral to the memory
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  BurstBaseAddress TIM Base address from when the DMA will starts the Data read.
  *         This parameters can be on of the following values:
  *            @arg GPT_DMABASE_CR1
  *            @arg GPT_DMABASE_CR2
  *            @arg GPT_DMABASE_SMCR
  *            @arg GPT_DMABASE_DIER
  *            @arg GPT_DMABASE_SR
  *            @arg GPT_DMABASE_EGR
  *            @arg GPT_DMABASE_CCMR1
  *            @arg GPT_DMABASE_CCMR2
  *            @arg GPT_DMABASE_CCER
  *            @arg GPT_DMABASE_CNT
  *            @arg GPT_DMABASE_PSC
  *            @arg GPT_DMABASE_ARR
  *            @arg GPT_DMABASE_RCR
  *            @arg GPT_DMABASE_CCR1
  *            @arg GPT_DMABASE_CCR2
  *            @arg GPT_DMABASE_CCR3
  *            @arg GPT_DMABASE_CCR4
  *            @arg GPT_DMABASE_BDTR
  *            @arg GPT_DMABASE_DCR
  * @param  BurstRequestSrc TIM DMA Request sources.
  *         This parameters can be on of the following values:
  *            @arg GPT_DMA_UPDATE: TIM update Interrupt source
  *            @arg GPT_DMA_CC1: TIM Capture Compare 1 DMA source
  *            @arg GPT_DMA_CC2: TIM Capture Compare 2 DMA source
  *            @arg GPT_DMA_CC3: TIM Capture Compare 3 DMA source
  *            @arg GPT_DMA_CC4: TIM Capture Compare 4 DMA source
  *            @arg GPT_DMA_COM: TIM Commutation DMA source
  *            @arg GPT_DMA_TRIGGER: TIM Trigger DMA source
  * @param  BurstBuffer The Buffer address.
  * @param  BurstLength DMA Burst length. This parameter can be one value
  *         between GPT_DMABURSTLENGTH_1TRANSFER and GPT_DMABURSTLENGTH_18TRANSFERS.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_DMABurst_ReadStart(GPT_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc,
        uint32_t  *BurstBuffer, uint32_t  BurstLength)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMABURST_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_DMA_BASE(BurstBaseAddress));
    HAL_ASSERT(IS_GPT_DMA_SOURCE(BurstRequestSrc));
    HAL_ASSERT(IS_GPT_DMA_LENGTH(BurstLength));

    /* TODO: not support */
    return HAL_ERROR;

    if (htim->State == HAL_GPT_STATE_BUSY)
    {
        return HAL_BUSY;
    }
    else if (htim->State == HAL_GPT_STATE_READY)
    {
        if ((BurstBuffer == 0U) && (BurstLength > 0U))
        {
            return HAL_ERROR;
        }
        else
        {
            htim->State = HAL_GPT_STATE_BUSY;
        }
    }
    switch (BurstRequestSrc)
    {
    case GPT_DMA_UPDATE:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_UPDATE]->XferCpltCallback = GPT_DMAPeriodElapsedCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_UPDATE]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_UPDATE], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC1:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC1]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC1], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC2:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC2]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC2], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC3:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC3]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC3], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_CC4:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferCpltCallback = GPT_DMACaptureCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_CC4]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_CC4], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_COM:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_COMMUTATION]->XferCpltCallback = TIMEx_DMACommutationCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_COMMUTATION]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_COMMUTATION], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1U);
    }
    break;
    case GPT_DMA_TRIGGER:
    {
        /* Set the DMA Period elapsed callback */
        htim->hdma[GPT_DMA_ID_TRIGGER]->XferCpltCallback = GPT_DMATriggerCplt;

        /* Set the DMA error callback */
        htim->hdma[GPT_DMA_ID_TRIGGER]->XferErrorCallback = GPT_DMAError ;

        /* Enable the DMA Stream */
//        HAL_DMA_Start_IT(htim->hdma[GPT_DMA_ID_TRIGGER], (uint32_t)&htim->Instance->DMAR, (uint32_t)BurstBuffer, ((BurstLength) >> 8U) + 1);
    }
    break;
    default:
        break;
    }

    /* configure the DMA Burst Mode */
//    htim->Instance->DCR = BurstBaseAddress | BurstLength;

    /* Enable the TIM DMA Request */
    __HAL_GPT_ENABLE_DMA(htim, BurstRequestSrc);

    htim->State = HAL_GPT_STATE_READY;

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Stop the DMA burst reading
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  BurstRequestSrc TIM DMA Request sources to disable.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_DMABurst_ReadStop(GPT_HandleTypeDef *htim, uint32_t BurstRequestSrc)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_DMA_SOURCE(BurstRequestSrc));

    /* Abort the DMA transfer (at least disable the DMA channel) */
    switch (BurstRequestSrc)
    {
    case GPT_DMA_UPDATE:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_UPDATE]);
    }
    break;
    case GPT_DMA_CC1:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC1]);
    }
    break;
    case GPT_DMA_CC2:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC2]);
    }
    break;
    case GPT_DMA_CC3:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC3]);
    }
    break;
    case GPT_DMA_CC4:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_CC4]);
    }
    break;
    case GPT_DMA_COM:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_COMMUTATION]);
    }
    break;
    case GPT_DMA_TRIGGER:
    {
        HAL_DMA_Abort(htim->hdma[GPT_DMA_ID_TRIGGER]);
    }
    break;
    default:
        break;
    }

    /* Disable the TIM Update DMA request */
    __HAL_GPT_DISABLE_DMA(htim, BurstRequestSrc);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Generate a software event
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  EventSource specifies the event source.
  *          This parameter can be one of the following values:
  *            @arg GPT_EVENTSOURCE_UPDATE: Timer update Event source
  *            @arg GPT_EVENTSOURCE_CC1: Timer Capture Compare 1 Event source
  *            @arg GPT_EVENTSOURCE_CC2: Timer Capture Compare 2 Event source
  *            @arg GPT_EVENTSOURCE_CC3: Timer Capture Compare 3 Event source
  *            @arg GPT_EVENTSOURCE_CC4: Timer Capture Compare 4 Event source
  *            @arg GPT_EVENTSOURCE_COM: Timer COM event source
  *            @arg GPT_EVENTSOURCE_TRIGGER: Timer Trigger Event source
  *            @arg GPT_EVENTSOURCE_BREAK: Timer Break event source
  * @note   TIM6 and TIM7 can only generate an update event.
  * @note   GPT_EVENTSOURCE_COM and GPT_EVENTSOURCE_BREAK are used only with TIM1 and TIM8.
  * @retval HAL status
  */

__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_GenerateEvent(GPT_HandleTypeDef *htim, uint32_t EventSource)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_EVENT_SOURCE(EventSource));

    /* Process Locked */
    __HAL_LOCK(htim);

    /* Change the TIM state */
    htim->State = HAL_GPT_STATE_BUSY;

    /* Set the event sources */
    htim->Instance->EGR = EventSource;

    /* Change the TIM state */
    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    /* Return function status */
    return HAL_OK;
}

/**
  * @brief  Configures the OCRef clear feature
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sClearInputConfig pointer to a GPT_ClearInputConfigTypeDef structure that
  *         contains the OCREF clear feature and parameters for the TIM peripheral.
  * @param  Channel specifies the TIM Channel.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_ConfigOCrefClear(GPT_HandleTypeDef *htim, GPT_ClearInputConfigTypeDef *sClearInputConfig, uint32_t Channel)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_CHANNELS(Channel));
    HAL_ASSERT(IS_GPT_CLEARINPUT_SOURCE(sClearInputConfig->ClearInputSource));
    HAL_ASSERT(IS_GPT_CLEARINPUT_POLARITY(sClearInputConfig->ClearInputPolarity));
    HAL_ASSERT(IS_GPT_CLEARINPUT_PRESCALER(sClearInputConfig->ClearInputPrescaler));
    HAL_ASSERT(IS_GPT_CLEARINPUT_FILTER(sClearInputConfig->ClearInputFilter));

    /* Process Locked */
    __HAL_LOCK(htim);

    htim->State = HAL_GPT_STATE_BUSY;

    if (sClearInputConfig->ClearInputSource == GPT_CLEARINPUTSOURCE_ETR)
    {
        GPT_ETR_SetConfig(htim->Instance,
                          sClearInputConfig->ClearInputPrescaler,
                          sClearInputConfig->ClearInputPolarity,
                          sClearInputConfig->ClearInputFilter);
    }

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        if (sClearInputConfig->ClearInputState != RESET)
        {
            /* Enable the Ocref clear feature for Channel 1 */
            htim->Instance->CCMR1 |= GPT_CCMR1_OC1CE;
        }
        else
        {
            /* Disable the Ocref clear feature for Channel 1 */
            htim->Instance->CCMR1 &= ~GPT_CCMR1_OC1CE;
        }
    }
    break;
    case GPT_CHANNEL_2:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        if (sClearInputConfig->ClearInputState != RESET)
        {
            /* Enable the Ocref clear feature for Channel 2 */
            htim->Instance->CCMR1 |= GPT_CCMR1_OC2CE;
        }
        else
        {
            /* Disable the Ocref clear feature for Channel 2 */
            htim->Instance->CCMR1 &= ~GPT_CCMR1_OC2CE;
        }
    }
    break;
    case GPT_CHANNEL_3:
    {
        HAL_ASSERT(IS_GPT_CC3_INSTANCE(htim->Instance));
        if (sClearInputConfig->ClearInputState != RESET)
        {
            /* Enable the Ocref clear feature for Channel 3 */
            htim->Instance->CCMR2 |= GPT_CCMR2_OC3CE;
        }
        else
        {
            /* Disable the Ocref clear feature for Channel 3 */
            htim->Instance->CCMR2 &= ~GPT_CCMR2_OC3CE;
        }
    }
    break;
    case GPT_CHANNEL_4:
    {
        HAL_ASSERT(IS_GPT_CC4_INSTANCE(htim->Instance));
        if (sClearInputConfig->ClearInputState != RESET)
        {
            /* Enable the Ocref clear feature for Channel 4 */
            htim->Instance->CCMR2 |= GPT_CCMR2_OC4CE;
        }
        else
        {
            /* Disable the Ocref clear feature for Channel 4 */
            htim->Instance->CCMR2 &= ~GPT_CCMR2_OC4CE;
        }
    }
    break;
    default:
        break;
    }

    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief   Configures the clock source to be used
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sClockSourceConfig pointer to a GPT_ClockConfigTypeDef structure that
  *         contains the clock source information for the TIM peripheral.
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_ConfigClockSource(GPT_HandleTypeDef *htim, GPT_ClockConfigTypeDef *sClockSourceConfig)
{
    uint32_t tmpsmcr = 0U;

    /* Process Locked */
    __HAL_LOCK(htim);

    htim->State = HAL_GPT_STATE_BUSY;

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CLOCKSOURCE(sClockSourceConfig->ClockSource));

    /* Reset the SMS, TS, ECE, ETPS and ETRF bits */
    tmpsmcr = htim->Instance->SMCR;
    tmpsmcr &= ~(GPT_SMCR_SMS | GPT_SMCR_TS);
    tmpsmcr &= ~(GPT_SMCR_ETF | GPT_SMCR_ETPS | GPT_SMCR_ECE | GPT_SMCR_ETP);
    htim->Instance->SMCR = tmpsmcr;

    switch (sClockSourceConfig->ClockSource)
    {
    case GPT_CLOCKSOURCE_INTERNAL:
    {
        HAL_ASSERT(IS_GPT_INSTANCE(htim->Instance));

        /* Disable slave mode to clock the prescaler directly with the internal clock */
        htim->Instance->SMCR &= ~GPT_SMCR_SMS;
    }
    break;

    case GPT_CLOCKSOURCE_ETRMODE1:
    {
        HAL_ASSERT(IS_GPT_ETR_INSTANCE(htim->Instance));

        HAL_ASSERT(IS_GPT_CLOCKPOLARITY(sClockSourceConfig->ClockPolarity));
        HAL_ASSERT(IS_GPT_CLOCKPRESCALER(sClockSourceConfig->ClockPrescaler));
        HAL_ASSERT(IS_GPT_CLOCKFILTER(sClockSourceConfig->ClockFilter));

        /* Configure the ETR Clock source */
        GPT_ETR_SetConfig(htim->Instance,
                          sClockSourceConfig->ClockPrescaler,
                          sClockSourceConfig->ClockPolarity,
                          sClockSourceConfig->ClockFilter);
        /* Get the TIMx SMCR register value */
        tmpsmcr = htim->Instance->SMCR;
        /* Reset the SMS and TS Bits */
        tmpsmcr &= ~(GPT_SMCR_SMS | GPT_SMCR_TS);
        /* Select the External clock mode1 and the ETRF trigger */
        tmpsmcr |= (GPT_SLAVEMODE_EXTERNAL1 | GPT_CLOCKSOURCE_ETRMODE1);
        /* Write to TIMx SMCR */
        htim->Instance->SMCR = tmpsmcr;
    }
    break;

    case GPT_CLOCKSOURCE_ETRMODE2:
    {
        HAL_ASSERT(IS_GPT_ETR_INSTANCE(htim->Instance));

        HAL_ASSERT(IS_GPT_CLOCKPOLARITY(sClockSourceConfig->ClockPolarity));
        HAL_ASSERT(IS_GPT_CLOCKPRESCALER(sClockSourceConfig->ClockPrescaler));
        HAL_ASSERT(IS_GPT_CLOCKFILTER(sClockSourceConfig->ClockFilter));

        /* Configure the ETR Clock source */
        GPT_ETR_SetConfig(htim->Instance,
                          sClockSourceConfig->ClockPrescaler,
                          sClockSourceConfig->ClockPolarity,
                          sClockSourceConfig->ClockFilter);
        /* Enable the External clock mode2 */
        htim->Instance->SMCR |= GPT_SMCR_ECE;
    }
    break;

    case GPT_CLOCKSOURCE_TI1:
    {
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));

        /* Check TI1 input conditioning related parameters */
        HAL_ASSERT(IS_GPT_CLOCKPOLARITY(sClockSourceConfig->ClockPolarity));
        HAL_ASSERT(IS_GPT_CLOCKFILTER(sClockSourceConfig->ClockFilter));

        GPT_TI1_ConfigInputStage(htim->Instance,
                                 sClockSourceConfig->ClockPolarity,
                                 sClockSourceConfig->ClockFilter);
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_TI1);
    }
    break;
    case GPT_CLOCKSOURCE_TI2:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

        /* Check TI1 input conditioning related parameters */
        HAL_ASSERT(IS_GPT_CLOCKPOLARITY(sClockSourceConfig->ClockPolarity));
        HAL_ASSERT(IS_GPT_CLOCKFILTER(sClockSourceConfig->ClockFilter));

        GPT_TI2_ConfigInputStage(htim->Instance,
                                 sClockSourceConfig->ClockPolarity,
                                 sClockSourceConfig->ClockFilter);
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_TI2);
    }
    break;
    case GPT_CLOCKSOURCE_TI1ED:
    {
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));

        /* Check TI1 input conditioning related parameters */
        HAL_ASSERT(IS_GPT_CLOCKPOLARITY(sClockSourceConfig->ClockPolarity));
        HAL_ASSERT(IS_GPT_CLOCKFILTER(sClockSourceConfig->ClockFilter));

        GPT_TI1_ConfigInputStage(htim->Instance,
                                 sClockSourceConfig->ClockPolarity,
                                 sClockSourceConfig->ClockFilter);
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_TI1ED);
    }
    break;
    case GPT_CLOCKSOURCE_ITR0:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_ITR0);
    }
    break;
    case GPT_CLOCKSOURCE_ITR1:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_ITR1);
    }
    break;
    case GPT_CLOCKSOURCE_ITR2:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_ITR2);
    }
    break;
    case GPT_CLOCKSOURCE_ITR3:
    {
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        GPT_ITRx_SetConfig(htim->Instance, GPT_CLOCKSOURCE_ITR3);
    }
    break;

    default:
        break;
    }
    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Selects the signal connected to the TI1 input: direct from CH1_input
  *         or a XOR combination between CH1_input, CH2_input & CH3_input
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  TI1_Selection Indicate whether or not channel 1 is connected to the
  *         output of a XOR gate.
  *         This parameter can be one of the following values:
  *            @arg GPT_TI1SELECTION_CH1: The TIMx_CH1 pin is connected to TI1 input
  *            @arg GPT_TI1SELECTION_XORCOMBINATION: The TIMx_CH1, CH2 and CH3
  *            pins are connected to the TI1 input (XOR combination)
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_ConfigTI1Input(GPT_HandleTypeDef *htim, uint32_t TI1_Selection)
{
    uint32_t tmpcr2 = 0U;

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_XOR_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_TI1SELECTION(TI1_Selection));

    /* Get the TIMx CR2 register value */
    tmpcr2 = htim->Instance->CR2;

    /* Reset the TI1 selection */
    tmpcr2 &= ~GPT_CR2_TI1S;

    /* Set the TI1 selection */
    tmpcr2 |= TI1_Selection;

    /* Write to TIMxCR2 */
    htim->Instance->CR2 = tmpcr2;

    return HAL_OK;
}

/**
  * @brief  Configures the TIM in Slave mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sSlaveConfig pointer to a GPT_SlaveConfigTypeDef structure that
  *         contains the selected trigger (internal trigger input, filtered
  *         timer input or external trigger input) and the ) and the Slave
  *         mode (Disable, Reset, Gated, Trigger, External clock mode 1).
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_SlaveConfigSynchronization(GPT_HandleTypeDef *htim, GPT_SlaveConfigTypeDef *sSlaveConfig)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_SLAVE_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_SLAVE_MODE(sSlaveConfig->SlaveMode));
    HAL_ASSERT(IS_GPT_TRIGGER_SELECTION(sSlaveConfig->InputTrigger));

    __HAL_LOCK(htim);

    htim->State = HAL_GPT_STATE_BUSY;

    GPT_SlaveTimer_SetConfig(htim, sSlaveConfig);

    /* Disable Trigger Interrupt */
    __HAL_GPT_DISABLE_IT(htim, GPT_IT_TRIGGER);

    /* Disable Trigger DMA request */
    __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_TRIGGER);

    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Configures the TIM in Slave mode in interrupt mode
  * @param  htim TIM handle.
  * @param  sSlaveConfig pointer to a GPT_SlaveConfigTypeDef structure that
  *         contains the selected trigger (internal trigger input, filtered
  *         timer input or external trigger input) and the ) and the Slave
  *         mode (Disable, Reset, Gated, Trigger, External clock mode 1).
  * @retval HAL status
  */
__HAL_ROM_USED HAL_StatusTypeDef HAL_GPT_SlaveConfigSynchronization_IT(GPT_HandleTypeDef *htim,
        GPT_SlaveConfigTypeDef *sSlaveConfig)
{
    /* Check the parameters */
    HAL_ASSERT(IS_GPT_SLAVE_INSTANCE(htim->Instance));
    HAL_ASSERT(IS_GPT_SLAVE_MODE(sSlaveConfig->SlaveMode));
    HAL_ASSERT(IS_GPT_TRIGGER_SELECTION(sSlaveConfig->InputTrigger));

    __HAL_LOCK(htim);

    htim->State = HAL_GPT_STATE_BUSY;

    GPT_SlaveTimer_SetConfig(htim, sSlaveConfig);

    /* Enable Trigger Interrupt */
    __HAL_GPT_ENABLE_IT(htim, GPT_IT_TRIGGER);

    /* Disable Trigger DMA request */
    __HAL_GPT_DISABLE_DMA(htim, GPT_DMA_TRIGGER);

    htim->State = HAL_GPT_STATE_READY;

    __HAL_UNLOCK(htim);

    return HAL_OK;
}

/**
  * @brief  Read the captured value from Capture Compare unit
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  Channel TIM Channels to be enabled.
  *          This parameter can be one of the following values:
  *            @arg GPT_CHANNEL_1: TIM Channel 1 selected
  *            @arg GPT_CHANNEL_2: TIM Channel 2 selected
  *            @arg GPT_CHANNEL_3: TIM Channel 3 selected
  *            @arg GPT_CHANNEL_4: TIM Channel 4 selected
  * @retval Captured value
  */
__HAL_ROM_USED uint32_t HAL_GPT_ReadCapturedValue(GPT_HandleTypeDef *htim, uint32_t Channel)
{
    uint32_t tmpreg = 0U;

    __HAL_LOCK(htim);

    switch (Channel)
    {
    case GPT_CHANNEL_1:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));

        /* Return the capture 1 value */
        tmpreg = htim->Instance->CCR1;

        break;
    }
    case GPT_CHANNEL_2:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));

        /* Return the capture 2 value */
        tmpreg = htim->Instance->CCR2;

        break;
    }

    case GPT_CHANNEL_3:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC3_INSTANCE(htim->Instance));

        /* Return the capture 3 value */
        tmpreg = htim->Instance->CCR3;

        break;
    }

    case GPT_CHANNEL_4:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC4_INSTANCE(htim->Instance));

        /* Return the capture 4 value */
        tmpreg = htim->Instance->CCR4;

        break;
    }

    default:
        break;
    }

    __HAL_UNLOCK(htim);
    return tmpreg;
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group9 TIM Callbacks functions
 *  @brief    TIM Callbacks functions
 *
@verbatim
  ==============================================================================
                        ##### TIM Callbacks functions #####
  ==============================================================================
 [..]
   This section provides TIM callback functions:
   (+) Timer Period elapsed callback
   (+) Timer Output Compare callback
   (+) Timer Input capture callback
   (+) Timer Trigger callback
   (+) Timer Error callback

@endverbatim
  * @{
  */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_PeriodElapsedCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the __HAL_GPT_PeriodElapsedCallback could be implemented in the user file
     */
}

/**
  * @brief  Output Compare callback in non blocking mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_OC_DelayElapsedCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the __HAL_GPT_OC_DelayElapsedCallback could be implemented in the user file
     */
}

/**
  * @brief  Input Capture callback in non blocking mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_IC_CaptureCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the __HAL_GPT_IC_CaptureCallback could be implemented in the user file
     */
}

/**
  * @brief  Input Capture half complete callback in non-blocking mode
  * @param  htim TIM IC handle
  * @retval None
  */
__weak void HAL_GPT_IC_CaptureHalfCpltCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HAL_TIM_IC_CaptureHalfCpltCallback could be implemented in the user file
     */
}

/**
  * @brief  PWM Pulse finished callback in non blocking mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_PWM_PulseFinishedCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the __HAL_GPT_PWM_PulseFinishedCallback could be implemented in the user file
     */
}

/**
  * @brief  PWM Pulse finished half complete callback in non-blocking mode
  * @param  htim TIM handle
  * @retval None
  */
__weak void HAL_GPT_PWM_PulseFinishedHalfCpltCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HAL_TIM_PWM_PulseFinishedHalfCpltCallback could be implemented in the user file
     */
}


/**
  * @brief  Hall Trigger detection callback in non blocking mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_TriggerCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_TriggerCallback could be implemented in the user file
     */
}

/**
  * @brief  Timer error callback in non blocking mode
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_GPT_ErrorCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_GPT_ErrorCallback could be implemented in the user file
     */
}
/**
  * @}
  */

/** @defgroup GPT_Exported_Functions_Group10 Peripheral State functions
 *  @brief   Peripheral State functions
 *
@verbatim
  ==============================================================================
                        ##### Peripheral State functions #####
  ==============================================================================
  [..]
    This subsection permits to get in run-time the status of the peripheral
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Return the TIM Base state
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL state
  */
__HAL_ROM_USED HAL_GPT_StateTypeDef HAL_GPT_Base_GetState(GPT_HandleTypeDef *htim)
{
    return htim->State;
}

/**
  * @brief  Return the TIM OC state
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL state
  */
__HAL_ROM_USED HAL_GPT_StateTypeDef HAL_GPT_OC_GetState(GPT_HandleTypeDef *htim)
{
    return htim->State;
}

/**
  * @brief  Return the TIM PWM state
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL state
  */
__HAL_ROM_USED HAL_GPT_StateTypeDef HAL_GPT_PWM_GetState(GPT_HandleTypeDef *htim)
{
    return htim->State;
}

/**
  * @brief  Return the TIM Input Capture state
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL state
  */
__HAL_ROM_USED HAL_GPT_StateTypeDef HAL_GPT_IC_GetState(GPT_HandleTypeDef *htim)
{
    return htim->State;
}

/**
  * @brief  Return the TIM One Pulse Mode state
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL state
  */
__HAL_ROM_USED HAL_GPT_StateTypeDef HAL_GPT_OnePulse_GetState(GPT_HandleTypeDef *htim)
{
    return htim->State;
}

/**
  * @brief  Return the TIM Encoder Mode state
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval HAL state
  */
__HAL_ROM_USED HAL_GPT_StateTypeDef HAL_GPT_Encoder_GetState(GPT_HandleTypeDef *htim)
{
    return htim->State;
}
/**
  * @}
  */

/**
  * @brief  Time Base configuration
  * @param  TIMx TIM peripheral
  * @param  Structure pointer on TIM Time Base required parameters
  * @retval None
  */
__HAL_ROM_USED void GPT_Base_SetConfig(GPT_TypeDef *TIMx, GPT_Base_InitTypeDef *Structure)
{
    uint32_t tmpcr1 = 0U;
    tmpcr1 = TIMx->CR1;

    /* Set TIM Time Base Unit parameters ---------------------------------------*/
    if (IS_GPT_CC3_INSTANCE(TIMx) != RESET)
    {
        /* Select the Counter Mode */
        tmpcr1 &= ~(GPT_CR1_DIR | GPT_CR1_CMS);
        tmpcr1 |= Structure->CounterMode;
    }

    TIMx->CR1 = tmpcr1;

    /* Set the Auto-reload value */
    TIMx->ARR = (uint32_t)Structure->Period ;

    /* Set the Prescaler value */
    TIMx->PSC = (uint32_t)Structure->Prescaler;

    if (IS_GPT_ADVANCED_INSTANCE(TIMx) != RESET)
    {
        /* Set the Repetition Counter value */
#if 1       // Revisit for advanced timer ???? 
        TIMx->RCR = Structure->RepetitionCounter;
#endif
    }

    /* Generate an update event to reload the Prescaler
       and the repetition counter(only for TIM1 and TIM8) value immediately */
    TIMx->EGR = GPT_EGR_UG;
}

/**
  * @brief  Configure the TI1 as Input.
  * @param  TIMx to select the TIM peripheral.
  * @param  GPT_ICPolarity  The Input Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICPolarity_Rising
  *            @arg GPT_ICPolarity_Falling
  *            @arg GPT_ICPolarity_BothEdge
  * @param  GPT_ICSelection specifies the input to be used.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICSelection_DirectTI: TIM Input 1 is selected to be connected to IC1.
  *            @arg GPT_ICSelection_IndirectTI: TIM Input 1 is selected to be connected to IC2.
  *            @arg GPT_ICSelection_TRC: TIM Input 1 is selected to be connected to TRC.
  * @param  GPT_ICFilter Specifies the Input Capture Filter.
  *          This parameter must be a value between 0x00 and 0x0F.
  * @note GPT_ICFilter and GPT_ICPolarity are not used in INDIRECT mode as TI2FP1
  *       (on channel2 path) is used as the input signal. Therefore CCMR1 must be
  *        protected against un-initialized filter and polarity values.
  * @retval None
  */
__HAL_ROM_USED void GPT_TI1_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                                      uint32_t GPT_ICFilter)
{
    uint32_t tmpccmr1 = 0U;
    uint32_t tmpccer = 0U;

    /* Disable the Channel 1: Reset the CC1E Bit */
    TIMx->CCER &= ~GPT_CCER_CC1E;
    tmpccmr1 = TIMx->CCMR1;
    tmpccer = TIMx->CCER;

    /* Select the Input */
    if (IS_GPT_CC2_INSTANCE(TIMx) != RESET)
    {
        tmpccmr1 &= ~GPT_CCMR1_CC1S;
        tmpccmr1 |= GPT_ICSelection;
    }
    else
    {
        tmpccmr1 &= ~GPT_CCMR1_CC1S;
        tmpccmr1 |= GPT_CCMR1_CC1S_0;
    }

    /* Set the filter */
    tmpccmr1 &= ~GPT_CCMR1_IC1F;
    tmpccmr1 |= ((GPT_ICFilter << 4U) & GPT_CCMR1_IC1F);

    /* Select the Polarity and set the CC1E Bit */
    tmpccer &= ~(GPT_CCER_CC1P | GPT_CCER_CC1NP);
    tmpccer |= (GPT_ICPolarity & (GPT_CCER_CC1P | GPT_CCER_CC1NP));

    /* Write to TIMx CCMR1 and CCER registers */
    TIMx->CCMR1 = tmpccmr1;
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Time Output Compare 2 configuration
  * @param  TIMx to select the TIM peripheral
  * @param  OC_Config The output configuration structure
  * @retval None
  */
__HAL_ROM_USED void GPT_OC2_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config)
{
    uint32_t tmpccmrx = 0U;
    uint32_t tmpccer = 0U;
    uint32_t tmpcr2 = 0U;

    /* Disable the Channel 2: Reset the CC2E Bit */
    TIMx->CCER &= ~GPT_CCER_CC2E;

    /* Get the TIMx CCER register value */
    tmpccer = TIMx->CCER;
    /* Get the TIMx CR2 register value */
    tmpcr2 = TIMx->CR2;

    /* Get the TIMx CCMR1 register value */
    tmpccmrx = TIMx->CCMR1;

    /* Reset the Output Compare mode and Capture/Compare selection Bits */
    tmpccmrx &= ~GPT_CCMR1_OC2M;
    tmpccmrx &= ~GPT_CCMR1_CC2S;

    /* Select the Output Compare Mode */
    tmpccmrx |= (OC_Config->OCMode << 8U);

    /* Reset the Output Polarity level */
    tmpccer &= ~GPT_CCER_CC2P;
    /* Set the Output Compare Polarity */
    tmpccer |= (OC_Config->OCPolarity << 4U);

    if (IS_GPT_ADVANCED_INSTANCE(TIMx) != RESET)
    {
        HAL_ASSERT(IS_GPT_OCN_POLARITY(OC_Config->OCNPolarity));

        /* Reset the Output N Polarity level */
        tmpccer &= ~GPT_CCER_CC2NP;
        /* Set the Output N Polarity */
        tmpccer |= (OC_Config->OCNPolarity << 4U);
        /* Reset the Output N State */
        tmpccer &= ~GPT_CCER_CC2NE;

        /* Reset the Output Compare and Output Compare N IDLE State */
        tmpcr2 &= ~GPT_CR2_OIS2;
        tmpcr2 &= ~GPT_CR2_OIS2N;
        /* Set the Output Idle state */
        tmpcr2 |= (OC_Config->OCIdleState << 2U);
        /* Set the Output N Idle state */
        tmpcr2 |= (OC_Config->OCNIdleState << 2U);
    }
    /* Write to TIMx CR2 */
    TIMx->CR2 = tmpcr2;

    /* Write to TIMx CCMR1 */
    TIMx->CCMR1 = tmpccmrx;

    /* Set the Capture Compare Register value */
    TIMx->CCR2 = OC_Config->Pulse;

    /* Write to TIMx CCER */
    TIMx->CCER = tmpccer;
}

/**
  * @brief  TIM DMA Delay Pulse complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  * @retval None
  */
__HAL_ROM_USED void GPT_DMADelayPulseCplt(DMA_HandleTypeDef *hdma)
{
    GPT_HandleTypeDef *htim = (GPT_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

    htim->State = HAL_GPT_STATE_READY;

    if (hdma == htim->hdma[GPT_DMA_ID_CC1])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_1;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC2])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_2;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC3])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_3;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC4])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_4;
    }

    HAL_GPT_PWM_PulseFinishedCallback(htim);

    htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
}

/**
  * @brief  TIM DMA error callback
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
__HAL_ROM_USED void GPT_DMAError(DMA_HandleTypeDef *hdma)
{
    GPT_HandleTypeDef *htim = (GPT_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

    htim->State = HAL_GPT_STATE_READY;

    HAL_GPT_ErrorCallback(htim);
}

/**
  * @brief  TIM DMA Capture complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
void GPT_DMACaptureCplt(DMA_HandleTypeDef *hdma)
{
    GPT_HandleTypeDef *htim = (GPT_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

    htim->State = HAL_GPT_STATE_READY;

    if (hdma == htim->hdma[GPT_DMA_ID_CC1])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_1;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC2])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_2;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC3])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_3;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC4])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_4;
    }

    HAL_GPT_IC_CaptureCallback(htim);

    htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
}

/**
  * @brief  TIM DMA Capture half complete callback.
  * @param  hdma pointer to DMA handle.
  * @retval None
  */
void GPT_DMACaptureHalfCplt(DMA_HandleTypeDef *hdma)
{
    GPT_HandleTypeDef *htim = (GPT_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

    if (hdma == htim->hdma[GPT_DMA_ID_CC1])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_1;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC2])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_2;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC3])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_3;
    }
    else if (hdma == htim->hdma[GPT_DMA_ID_CC4])
    {
        htim->Channel = HAL_GPT_ACTIVE_CHANNEL_4;
    }
    else
    {
        /* nothing to do */
    }

    HAL_GPT_IC_CaptureHalfCpltCallback(htim);

    htim->Channel = HAL_GPT_ACTIVE_CHANNEL_CLEARED;
}


/**
  * @brief  Enables or disables the TIM Capture Compare Channel x.
  * @param  TIMx to select the TIM peripheral
  * @param  Channel specifies the TIM Channel
  *          This parameter can be one of the following values:
  *            @arg GPT_Channel_1: TIM Channel 1
  *            @arg GPT_Channel_2: TIM Channel 2
  *            @arg GPT_Channel_3: TIM Channel 3
  *            @arg GPT_Channel_4: TIM Channel 4
  * @param  ChannelState specifies the TIM Channel CCxE bit new state.
  *          This parameter can be: GPT_CCx_ENABLE or GPT_CCx_Disable.
  * @retval None
  */
void GPT_CCxChannelCmd(GPT_TypeDef *TIMx, uint32_t Channel, uint32_t ChannelState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    HAL_ASSERT(IS_GPT_CC1_INSTANCE(TIMx));
    HAL_ASSERT(IS_GPT_CHANNELS(Channel));

    tmp = GPT_CCER_CC1E << Channel;

    /* Reset the CCxE Bit */
    TIMx->CCER &= ~tmp;

    /* Set or reset the CCxE Bit */
    TIMx->CCER |= (uint32_t)(ChannelState << Channel);
}

/**
  * @brief  TIM DMA Period Elapse complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
static void GPT_DMAPeriodElapsedCplt(DMA_HandleTypeDef *hdma)
{
    GPT_HandleTypeDef *htim = (GPT_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

    htim->State = HAL_GPT_STATE_READY;

    HAL_GPT_PeriodElapsedCallback(htim);
}

/**
  * @brief  TIM DMA Trigger callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
static void GPT_DMATriggerCplt(DMA_HandleTypeDef *hdma)
{
    GPT_HandleTypeDef *htim = (GPT_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

    htim->State = HAL_GPT_STATE_READY;

    HAL_GPT_TriggerCallback(htim);
}

/**
  * @brief  Time Output Compare 1 configuration
  * @param  TIMx to select the TIM peripheral
  * @param  OC_Config The output configuration structure
  * @retval None
  */
static void GPT_OC1_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config)
{
    uint32_t tmpccmrx = 0U;
    uint32_t tmpccer = 0U;
    uint32_t tmpcr2 = 0U;

    /* Disable the Channel 1: Reset the CC1E Bit */
    TIMx->CCER &= ~GPT_CCER_CC1E;

    /* Get the TIMx CCER register value */
    tmpccer = TIMx->CCER;
    /* Get the TIMx CR2 register value */
    tmpcr2 = TIMx->CR2;

    /* Get the TIMx CCMR1 register value */
    tmpccmrx = TIMx->CCMR1;

    /* Reset the Output Compare Mode Bits */
    tmpccmrx &= ~GPT_CCMR1_OC1M;
    tmpccmrx &= ~GPT_CCMR1_CC1S;
    /* Select the Output Compare Mode */
    tmpccmrx |= OC_Config->OCMode;

    /* Reset the Output Polarity level */
    tmpccer &= ~GPT_CCER_CC1P;
    /* Set the Output Compare Polarity */
    tmpccer |= OC_Config->OCPolarity;


    if (IS_GPT_ADVANCED_INSTANCE(TIMx) != RESET)
    {
        /* Reset the Output N Polarity level */
        tmpccer &= ~GPT_CCER_CC1NP;
        /* Set the Output N Polarity */
        tmpccer |= OC_Config->OCNPolarity;
        /* Reset the Output N State */
        tmpccer &= ~GPT_CCER_CC1NE;

        /* Reset the Output Compare and Output Compare N IDLE State */
        tmpcr2 &= ~GPT_CR2_OIS1;
        tmpcr2 &= ~GPT_CR2_OIS1N;
        /* Set the Output Idle state */
        tmpcr2 |= OC_Config->OCIdleState;
        /* Set the Output N Idle state */
        tmpcr2 |= OC_Config->OCNIdleState;
    }
    /* Write to TIMx CR2 */
    TIMx->CR2 = tmpcr2;

    /* Write to TIMx CCMR1 */
    TIMx->CCMR1 = tmpccmrx;

    /* Set the Capture Compare Register value */
    TIMx->CCR1 = OC_Config->Pulse;

    /* Write to TIMx CCER */
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Time Output Compare 3 configuration
  * @param  TIMx to select the TIM peripheral
  * @param  OC_Config The output configuration structure
  * @retval None
  */
static void GPT_OC3_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config)
{
    uint32_t tmpccmrx = 0U;
    uint32_t tmpccer = 0U;
    uint32_t tmpcr2 = 0U;

    /* Disable the Channel 3: Reset the CC2E Bit */
    TIMx->CCER &= ~GPT_CCER_CC3E;

    /* Get the TIMx CCER register value */
    tmpccer = TIMx->CCER;
    /* Get the TIMx CR2 register value */
    tmpcr2 = TIMx->CR2;

    /* Get the TIMx CCMR2 register value */
    tmpccmrx = TIMx->CCMR2;

    /* Reset the Output Compare mode and Capture/Compare selection Bits */
    tmpccmrx &= ~GPT_CCMR2_OC3M;
    tmpccmrx &= ~GPT_CCMR2_CC3S;
    /* Select the Output Compare Mode */
    tmpccmrx |= OC_Config->OCMode;

    /* Reset the Output Polarity level */
    tmpccer &= ~GPT_CCER_CC3P;
    /* Set the Output Compare Polarity */
    tmpccer |= (OC_Config->OCPolarity << 8U);

    if (IS_GPT_ADVANCED_INSTANCE(TIMx) != RESET)
    {
        HAL_ASSERT(IS_GPT_OCN_POLARITY(OC_Config->OCNPolarity));
        HAL_ASSERT(IS_GPT_OCNIDLE_STATE(OC_Config->OCNIdleState));
        HAL_ASSERT(IS_GPT_OCIDLE_STATE(OC_Config->OCIdleState));

        /* Reset the Output N Polarity level */
        tmpccer &= ~GPT_CCER_CC3NP;
        /* Set the Output N Polarity */
        tmpccer |= (OC_Config->OCNPolarity << 8U);
        /* Reset the Output N State */
        tmpccer &= ~GPT_CCER_CC3NE;

        /* Reset the Output Compare and Output Compare N IDLE State */
        tmpcr2 &= ~GPT_CR2_OIS3;
        tmpcr2 &= ~GPT_CR2_OIS3N;
        /* Set the Output Idle state */
        tmpcr2 |= (OC_Config->OCIdleState << 4U);
        /* Set the Output N Idle state */
        tmpcr2 |= (OC_Config->OCNIdleState << 4U);
    }
    /* Write to TIMx CR2 */
    TIMx->CR2 = tmpcr2;

    /* Write to TIMx CCMR2 */
    TIMx->CCMR2 = tmpccmrx;

    /* Set the Capture Compare Register value */
    TIMx->CCR3 = OC_Config->Pulse;

    /* Write to TIMx CCER */
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Time Output Compare 4 configuration
  * @param  TIMx to select the TIM peripheral
  * @param  OC_Config The output configuration structure
  * @retval None
  */
static void GPT_OC4_SetConfig(GPT_TypeDef *TIMx, GPT_OC_InitTypeDef *OC_Config)
{
    uint32_t tmpccmrx = 0U;
    uint32_t tmpccer = 0U;
    uint32_t tmpcr2 = 0U;

    /* Disable the Channel 4: Reset the CC4E Bit */
    TIMx->CCER &= ~GPT_CCER_CC4E;

    /* Get the TIMx CCER register value */
    tmpccer = TIMx->CCER;
    /* Get the TIMx CR2 register value */
    tmpcr2 = TIMx->CR2;

    /* Get the TIMx CCMR2 register value */
    tmpccmrx = TIMx->CCMR2;

    /* Reset the Output Compare mode and Capture/Compare selection Bits */
    tmpccmrx &= ~GPT_CCMR2_OC4M;
    tmpccmrx &= ~GPT_CCMR2_CC4S;

    /* Select the Output Compare Mode */
    tmpccmrx |= (OC_Config->OCMode << 8U);

    /* Reset the Output Polarity level */
    tmpccer &= ~GPT_CCER_CC4P;
    /* Set the Output Compare Polarity */
    tmpccer |= (OC_Config->OCPolarity << 12U);

    /*if((TIMx == TIM1) || (TIMx == TIM8))*/
    if (IS_GPT_ADVANCED_INSTANCE(TIMx) != RESET)
    {
        HAL_ASSERT(IS_GPT_OCIDLE_STATE(OC_Config->OCIdleState));
        /* Reset the Output Compare IDLE State */
        tmpcr2 &= ~GPT_CR2_OIS4;
        /* Set the Output Idle state */
        tmpcr2 |= (OC_Config->OCIdleState << 6U);
    }
    /* Write to TIMx CR2 */
    TIMx->CR2 = tmpcr2;

    /* Write to TIMx CCMR2 */
    TIMx->CCMR2 = tmpccmrx;

    /* Set the Capture Compare Register value */
    TIMx->CCR4 = OC_Config->Pulse;

    /* Write to TIMx CCER */
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Time Output Compare 4 configuration
  * @param  htim pointer to a GPT_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @param  sSlaveConfig The slave configuration structure
  * @retval None
  */
static void GPT_SlaveTimer_SetConfig(GPT_HandleTypeDef *htim,
                                     GPT_SlaveConfigTypeDef *sSlaveConfig)
{
    uint32_t tmpsmcr = 0U;
    uint32_t tmpccmr1 = 0U;
    uint32_t tmpccer = 0U;

    /* Get the TIMx SMCR register value */
    tmpsmcr = htim->Instance->SMCR;

    /* Reset the Trigger Selection Bits */
    tmpsmcr &= ~GPT_SMCR_TS;
    /* Set the Input Trigger source */
    tmpsmcr |= sSlaveConfig->InputTrigger;

    /* Reset the slave mode Bits */
    tmpsmcr &= ~GPT_SMCR_SMS;
    /* Set the slave mode */
    tmpsmcr |= sSlaveConfig->SlaveMode;

    /* Write to TIMx SMCR */
    htim->Instance->SMCR = tmpsmcr;

    /* Configure the trigger prescaler, filter, and polarity */
    switch (sSlaveConfig->InputTrigger)
    {
    case GPT_TS_ETRF:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_ETR_INSTANCE(htim->Instance));
        HAL_ASSERT(IS_GPT_TRIGGERPRESCALER(sSlaveConfig->TriggerPrescaler));
        HAL_ASSERT(IS_GPT_TRIGGERPOLARITY(sSlaveConfig->TriggerPolarity));
        HAL_ASSERT(IS_GPT_TRIGGERFILTER(sSlaveConfig->TriggerFilter));
        /* Configure the ETR Trigger source */
        GPT_ETR_SetConfig(htim->Instance,
                          sSlaveConfig->TriggerPrescaler,
                          sSlaveConfig->TriggerPolarity,
                          sSlaveConfig->TriggerFilter);
    }
    break;

    case GPT_TS_TI1F_ED:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));
        HAL_ASSERT(IS_GPT_TRIGGERFILTER(sSlaveConfig->TriggerFilter));

        /* Disable the Channel 1: Reset the CC1E Bit */
        tmpccer = htim->Instance->CCER;
        htim->Instance->CCER &= ~GPT_CCER_CC1E;
        tmpccmr1 = htim->Instance->CCMR1;

        /* Set the filter */
        tmpccmr1 &= ~GPT_CCMR1_IC1F;
        tmpccmr1 |= ((sSlaveConfig->TriggerFilter) << 4U);

        /* Write to TIMx CCMR1 and CCER registers */
        htim->Instance->CCMR1 = tmpccmr1;
        htim->Instance->CCER = tmpccer;

    }
    break;

    case GPT_TS_TI1FP1:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC1_INSTANCE(htim->Instance));
        HAL_ASSERT(IS_GPT_TRIGGERPOLARITY(sSlaveConfig->TriggerPolarity));
        HAL_ASSERT(IS_GPT_TRIGGERFILTER(sSlaveConfig->TriggerFilter));

        /* Configure TI1 Filter and Polarity */
        GPT_TI1_ConfigInputStage(htim->Instance,
                                 sSlaveConfig->TriggerPolarity,
                                 sSlaveConfig->TriggerFilter);
    }
    break;

    case GPT_TS_TI2FP2:
    {
        /* Check the parameters */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
        HAL_ASSERT(IS_GPT_TRIGGERPOLARITY(sSlaveConfig->TriggerPolarity));
        HAL_ASSERT(IS_GPT_TRIGGERFILTER(sSlaveConfig->TriggerFilter));

        /* Configure TI2 Filter and Polarity */
        GPT_TI2_ConfigInputStage(htim->Instance,
                                 sSlaveConfig->TriggerPolarity,
                                 sSlaveConfig->TriggerFilter);
    }
    break;

    case GPT_TS_ITR0:
    {
        /* Check the parameter */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
    }
    break;

    case GPT_TS_ITR1:
    {
        /* Check the parameter */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
    }
    break;

    case GPT_TS_ITR2:
    {
        /* Check the parameter */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
    }
    break;

    case GPT_TS_ITR3:
    {
        /* Check the parameter */
        HAL_ASSERT(IS_GPT_CC2_INSTANCE(htim->Instance));
    }
    break;

    default:
        break;
    }
}


/**
  * @brief  Configure the Polarity and Filter for TI1.
  * @param  TIMx to select the TIM peripheral.
  * @param  GPT_ICPolarity  The Input Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICPolarity_Rising
  *            @arg GPT_ICPolarity_Falling
  *            @arg GPT_ICPolarity_BothEdge
  * @param  GPT_ICFilter Specifies the Input Capture Filter.
  *          This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
static void GPT_TI1_ConfigInputStage(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICFilter)
{
    uint32_t tmpccmr1 = 0U;
    uint32_t tmpccer = 0U;

    /* Disable the Channel 1: Reset the CC1E Bit */
    tmpccer = TIMx->CCER;
    TIMx->CCER &= ~GPT_CCER_CC1E;
    tmpccmr1 = TIMx->CCMR1;

    /* Set the filter */
    tmpccmr1 &= ~GPT_CCMR1_IC1F;
    tmpccmr1 |= (GPT_ICFilter << 4U);

    /* Select the Polarity and set the CC1E Bit */
    tmpccer &= ~(GPT_CCER_CC1P | GPT_CCER_CC1NP);
    tmpccer |= GPT_ICPolarity;

    /* Write to TIMx CCMR1 and CCER registers */
    TIMx->CCMR1 = tmpccmr1;
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Configure the TI2 as Input.
  * @param  TIMx to select the TIM peripheral
  * @param  GPT_ICPolarity  The Input Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICPolarity_Rising
  *            @arg GPT_ICPolarity_Falling
  *            @arg GPT_ICPolarity_BothEdge
  * @param  GPT_ICSelection specifies the input to be used.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICSelection_DirectTI: TIM Input 2 is selected to be connected to IC2.
  *            @arg GPT_ICSelection_IndirectTI: TIM Input 2 is selected to be connected to IC1.
  *            @arg GPT_ICSelection_TRC: TIM Input 2 is selected to be connected to TRC.
  * @param  GPT_ICFilter Specifies the Input Capture Filter.
  *          This parameter must be a value between 0x00 and 0x0F.
  * @note GPT_ICFilter and GPT_ICPolarity are not used in INDIRECT mode as TI1FP2
  *       (on channel1 path) is used as the input signal. Therefore CCMR1 must be
  *        protected against un-initialized filter and polarity values.
  * @retval None
  */
static void GPT_TI2_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                              uint32_t GPT_ICFilter)
{
    uint32_t tmpccmr1 = 0U;
    uint32_t tmpccer = 0U;

    /* Disable the Channel 2: Reset the CC2E Bit */
    TIMx->CCER &= ~GPT_CCER_CC2E;
    tmpccmr1 = TIMx->CCMR1;
    tmpccer = TIMx->CCER;

    /* Select the Input */
    tmpccmr1 &= ~GPT_CCMR1_CC2S;
    tmpccmr1 |= (GPT_ICSelection << 8U);

    /* Set the filter */
    tmpccmr1 &= ~GPT_CCMR1_IC2F;
    tmpccmr1 |= ((GPT_ICFilter << 12U) & GPT_CCMR1_IC2F);

    /* Select the Polarity and set the CC2E Bit */
    tmpccer &= ~(GPT_CCER_CC2P | GPT_CCER_CC2NP);
    tmpccer |= ((GPT_ICPolarity << 4U) & (GPT_CCER_CC2P | GPT_CCER_CC2NP));

    /* Write to TIMx CCMR1 and CCER registers */
    TIMx->CCMR1 = tmpccmr1 ;
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Configure the Polarity and Filter for TI2.
  * @param  TIMx to select the TIM peripheral.
  * @param  GPT_ICPolarity  The Input Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICPolarity_Rising
  *            @arg GPT_ICPolarity_Falling
  *            @arg GPT_ICPolarity_BothEdge
  * @param  GPT_ICFilter Specifies the Input Capture Filter.
  *          This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
static void GPT_TI2_ConfigInputStage(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICFilter)
{
    uint32_t tmpccmr1 = 0U;
    uint32_t tmpccer = 0U;

    /* Disable the Channel 2: Reset the CC2E Bit */
    TIMx->CCER &= ~GPT_CCER_CC2E;
    tmpccmr1 = TIMx->CCMR1;
    tmpccer = TIMx->CCER;

    /* Set the filter */
    tmpccmr1 &= ~GPT_CCMR1_IC2F;
    tmpccmr1 |= (GPT_ICFilter << 12U);

    /* Select the Polarity and set the CC2E Bit */
    tmpccer &= ~(GPT_CCER_CC2P | GPT_CCER_CC2NP);
    tmpccer |= (GPT_ICPolarity << 4U);

    /* Write to TIMx CCMR1 and CCER registers */
    TIMx->CCMR1 = tmpccmr1 ;
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Configure the TI3 as Input.
  * @param  TIMx to select the TIM peripheral
  * @param  GPT_ICPolarity  The Input Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICPolarity_Rising
  *            @arg GPT_ICPolarity_Falling
  *            @arg GPT_ICPolarity_BothEdge
  * @param  GPT_ICSelection specifies the input to be used.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICSelection_DirectTI: TIM Input 3 is selected to be connected to IC3.
  *            @arg GPT_ICSelection_IndirectTI: TIM Input 3 is selected to be connected to IC4.
  *            @arg GPT_ICSelection_TRC: TIM Input 3 is selected to be connected to TRC.
  * @param  GPT_ICFilter Specifies the Input Capture Filter.
  *          This parameter must be a value between 0x00 and 0x0F.
  * @note GPT_ICFilter and GPT_ICPolarity are not used in INDIRECT mode as TI4FP3
  *       (on channel4 path) is used as the input signal. Therefore CCMR2 must be
  *        protected against un-initialized filter and polarity values.
  * @retval None
  */
static void GPT_TI3_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                              uint32_t GPT_ICFilter)
{
    uint32_t tmpccmr2 = 0U;
    uint32_t tmpccer = 0U;

    /* Disable the Channel 3: Reset the CC3E Bit */
    TIMx->CCER &= ~GPT_CCER_CC3E;
    tmpccmr2 = TIMx->CCMR2;
    tmpccer = TIMx->CCER;

    /* Select the Input */
    tmpccmr2 &= ~GPT_CCMR2_CC3S;
    tmpccmr2 |= GPT_ICSelection;

    /* Set the filter */
    tmpccmr2 &= ~GPT_CCMR2_IC3F;
    tmpccmr2 |= ((GPT_ICFilter << 4U) & GPT_CCMR2_IC3F);

    /* Select the Polarity and set the CC3E Bit */
    tmpccer &= ~(GPT_CCER_CC3P | GPT_CCER_CC3NP);
    tmpccer |= ((GPT_ICPolarity << 8U) & (GPT_CCER_CC3P | GPT_CCER_CC3NP));

    /* Write to TIMx CCMR2 and CCER registers */
    TIMx->CCMR2 = tmpccmr2;
    TIMx->CCER = tmpccer;
}

/**
  * @brief  Configure the TI4 as Input.
  * @param  TIMx to select the TIM peripheral
  * @param  GPT_ICPolarity  The Input Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICPolarity_Rising
  *            @arg GPT_ICPolarity_Falling
  *            @arg GPT_ICPolarity_BothEdge
  * @param  GPT_ICSelection specifies the input to be used.
  *          This parameter can be one of the following values:
  *            @arg GPT_ICSelection_DirectTI: TIM Input 4 is selected to be connected to IC4.
  *            @arg GPT_ICSelection_IndirectTI: TIM Input 4 is selected to be connected to IC3.
  *            @arg GPT_ICSelection_TRC: TIM Input 4 is selected to be connected to TRC.
  * @param  GPT_ICFilter Specifies the Input Capture Filter.
  *          This parameter must be a value between 0x00 and 0x0F.
  * @note GPT_ICFilter and GPT_ICPolarity are not used in INDIRECT mode as TI3FP4
  *       (on channel3 path) is used as the input signal. Therefore CCMR2 must be
  *        protected against un-initialized filter and polarity values.
  * @retval None
  */
static void GPT_TI4_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ICPolarity, uint32_t GPT_ICSelection,
                              uint32_t GPT_ICFilter)
{
    uint32_t tmpccmr2 = 0U;
    uint32_t tmpccer = 0U;

    /* Disable the Channel 4: Reset the CC4E Bit */
    TIMx->CCER &= ~GPT_CCER_CC4E;
    tmpccmr2 = TIMx->CCMR2;
    tmpccer = TIMx->CCER;

    /* Select the Input */
    tmpccmr2 &= ~GPT_CCMR2_CC4S;
    tmpccmr2 |= (GPT_ICSelection << 8U);

    /* Set the filter */
    tmpccmr2 &= ~GPT_CCMR2_IC4F;
    tmpccmr2 |= ((GPT_ICFilter << 12U) & GPT_CCMR2_IC4F);

    /* Select the Polarity and set the CC4E Bit */
    tmpccer &= ~(GPT_CCER_CC4P | GPT_CCER_CC4NP);
    tmpccer |= ((GPT_ICPolarity << 12U) & (GPT_CCER_CC4P | GPT_CCER_CC4NP));

    /* Write to TIMx CCMR2 and CCER registers */
    TIMx->CCMR2 = tmpccmr2;
    TIMx->CCER = tmpccer ;
}

/**
  * @brief  Selects the Input Trigger source
  * @param  TIMx to select the TIM peripheral
  * @param  GPT_ITRx The Input Trigger source.
  *          This parameter can be one of the following values:
  *            @arg GPT_TS_ITR0: Internal Trigger 0
  *            @arg GPT_TS_ITR1: Internal Trigger 1
  *            @arg GPT_TS_ITR2: Internal Trigger 2
  *            @arg GPT_TS_ITR3: Internal Trigger 3
  *            @arg GPT_TS_TI1F_ED: TI1 Edge Detector
  *            @arg GPT_TS_TI1FP1: Filtered Timer Input 1
  *            @arg GPT_TS_TI2FP2: Filtered Timer Input 2
  *            @arg GPT_TS_ETRF: External Trigger input
  * @retval None
  */
static void GPT_ITRx_SetConfig(GPT_TypeDef *TIMx, uint16_t GPT_ITRx)
{
    uint32_t tmpsmcr = 0U;

    /* Get the TIMx SMCR register value */
    tmpsmcr = TIMx->SMCR;
    /* Reset the TS Bits */
    tmpsmcr &= ~GPT_SMCR_TS;
    /* Set the Input Trigger source and the slave mode*/
    tmpsmcr |= GPT_ITRx | GPT_SLAVEMODE_EXTERNAL1;
    /* Write to TIMx SMCR */
    TIMx->SMCR = tmpsmcr;
}

/**
  * @brief  Configures the TIMx External Trigger (ETR).
  * @param  TIMx to select the TIM peripheral
  * @param  GPT_ExtTRGPrescaler The external Trigger Prescaler.
  *          This parameter can be one of the following values:
  *            @arg GPT_ETRPRESCALER_DIV1 : ETRP Prescaler OFF.
  *            @arg GPT_ETRPRESCALER_DIV2 : ETRP frequency divided by 2.
  *            @arg GPT_ETRPRESCALER_DIV4 : ETRP frequency divided by 4.
  *            @arg GPT_ETRPRESCALER_DIV8 : ETRP frequency divided by 8.
  * @param  GPT_ExtTRGPolarity The external Trigger Polarity.
  *          This parameter can be one of the following values:
  *            @arg GPT_ETRPOLARITY_INVERTED : active low or falling edge active.
  *            @arg GPT_ETRPOLARITY_NONINVERTED : active high or rising edge active.
  * @param  ExtTRGFilter External Trigger Filter.
  *          This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
static void GPT_ETR_SetConfig(GPT_TypeDef *TIMx, uint32_t GPT_ExtTRGPrescaler,
                              uint32_t GPT_ExtTRGPolarity, uint32_t ExtTRGFilter)
{
    uint32_t tmpsmcr = 0U;

    tmpsmcr = TIMx->SMCR;

    /* Reset the ETR Bits */
    tmpsmcr &= ~(GPT_SMCR_ETF | GPT_SMCR_ETPS | GPT_SMCR_ECE | GPT_SMCR_ETP);

    /* Set the Prescaler, the Filter value and the Polarity */
    tmpsmcr |= (uint32_t)(GPT_ExtTRGPrescaler | (GPT_ExtTRGPolarity | (ExtTRGFilter << 8)));

    /* Write to TIMx SMCR */
    TIMx->SMCR = tmpsmcr;
}

/**
  * @}
  */

/**
* @brief  Hall commutation changed callback in non blocking mode
* @param  htim pointer to a TIM_HandleTypeDef structure that contains
*                the configuration information for TIM module.
* @retval None
*/
__weak void HAL_TIMEx_CommutationCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_TIMEx_CommutationCallback could be implemented in the user file
     */
}

/**
  * @brief  Hall Break detection callback in non blocking mode
  * @param  htim pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
__weak void HAL_TIMEx_BreakCallback(GPT_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    /* NOTE : This function Should not be modified, when the callback is needed,
              the HAL_TIMEx_BreakCallback could be implemented in the user file
     */
}


#endif /* HAL_GPT_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */