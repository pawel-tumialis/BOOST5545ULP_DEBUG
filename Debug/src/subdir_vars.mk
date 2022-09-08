################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/csl_irqplug.asm \
../src/vectors.asm 

C_SRCS += \
../src/csl_audioClass.c \
../src/csl_cdc.c \
../src/csl_dat.c \
../src/csl_dma.c \
../src/csl_emif.c \
../src/csl_gpio.c \
../src/csl_gpt.c \
../src/csl_i2c.c \
../src/csl_i2s.c \
../src/csl_intc.c \
../src/csl_lcdc.c \
../src/csl_mcbsp.c \
../src/csl_mcspi.c \
../src/csl_mem.c \
../src/csl_mmcsd.c \
../src/csl_mmcsd_ataIf.c \
../src/csl_msc.c \
../src/csl_pll.c \
../src/csl_rtc.c \
../src/csl_sar.c \
../src/csl_sdio.c \
../src/csl_spi.c \
../src/csl_sysctrl.c \
../src/csl_uart.c \
../src/csl_uhpi.c \
../src/csl_usb.c \
../src/csl_wdt.c \
../src/evm5515.c \
../src/evm5515_gpio.c \
../src/evm5515_i2c.c \
../src/i2c_probe.c \
../src/platform.c \
../src/system_init.c 

C_DEPS += \
./src/csl_audioClass.d \
./src/csl_cdc.d \
./src/csl_dat.d \
./src/csl_dma.d \
./src/csl_emif.d \
./src/csl_gpio.d \
./src/csl_gpt.d \
./src/csl_i2c.d \
./src/csl_i2s.d \
./src/csl_intc.d \
./src/csl_lcdc.d \
./src/csl_mcbsp.d \
./src/csl_mcspi.d \
./src/csl_mem.d \
./src/csl_mmcsd.d \
./src/csl_mmcsd_ataIf.d \
./src/csl_msc.d \
./src/csl_pll.d \
./src/csl_rtc.d \
./src/csl_sar.d \
./src/csl_sdio.d \
./src/csl_spi.d \
./src/csl_sysctrl.d \
./src/csl_uart.d \
./src/csl_uhpi.d \
./src/csl_usb.d \
./src/csl_wdt.d \
./src/evm5515.d \
./src/evm5515_gpio.d \
./src/evm5515_i2c.d \
./src/i2c_probe.d \
./src/platform.d \
./src/system_init.d 

OBJS += \
./src/csl_audioClass.obj \
./src/csl_cdc.obj \
./src/csl_dat.obj \
./src/csl_dma.obj \
./src/csl_emif.obj \
./src/csl_gpio.obj \
./src/csl_gpt.obj \
./src/csl_i2c.obj \
./src/csl_i2s.obj \
./src/csl_intc.obj \
./src/csl_irqplug.obj \
./src/csl_lcdc.obj \
./src/csl_mcbsp.obj \
./src/csl_mcspi.obj \
./src/csl_mem.obj \
./src/csl_mmcsd.obj \
./src/csl_mmcsd_ataIf.obj \
./src/csl_msc.obj \
./src/csl_pll.obj \
./src/csl_rtc.obj \
./src/csl_sar.obj \
./src/csl_sdio.obj \
./src/csl_spi.obj \
./src/csl_sysctrl.obj \
./src/csl_uart.obj \
./src/csl_uhpi.obj \
./src/csl_usb.obj \
./src/csl_wdt.obj \
./src/evm5515.obj \
./src/evm5515_gpio.obj \
./src/evm5515_i2c.obj \
./src/i2c_probe.obj \
./src/platform.obj \
./src/system_init.obj \
./src/vectors.obj 

ASM_DEPS += \
./src/csl_irqplug.d \
./src/vectors.d 

OBJS__QUOTED += \
"src\csl_audioClass.obj" \
"src\csl_cdc.obj" \
"src\csl_dat.obj" \
"src\csl_dma.obj" \
"src\csl_emif.obj" \
"src\csl_gpio.obj" \
"src\csl_gpt.obj" \
"src\csl_i2c.obj" \
"src\csl_i2s.obj" \
"src\csl_intc.obj" \
"src\csl_irqplug.obj" \
"src\csl_lcdc.obj" \
"src\csl_mcbsp.obj" \
"src\csl_mcspi.obj" \
"src\csl_mem.obj" \
"src\csl_mmcsd.obj" \
"src\csl_mmcsd_ataIf.obj" \
"src\csl_msc.obj" \
"src\csl_pll.obj" \
"src\csl_rtc.obj" \
"src\csl_sar.obj" \
"src\csl_sdio.obj" \
"src\csl_spi.obj" \
"src\csl_sysctrl.obj" \
"src\csl_uart.obj" \
"src\csl_uhpi.obj" \
"src\csl_usb.obj" \
"src\csl_wdt.obj" \
"src\evm5515.obj" \
"src\evm5515_gpio.obj" \
"src\evm5515_i2c.obj" \
"src\i2c_probe.obj" \
"src\platform.obj" \
"src\system_init.obj" \
"src\vectors.obj" 

C_DEPS__QUOTED += \
"src\csl_audioClass.d" \
"src\csl_cdc.d" \
"src\csl_dat.d" \
"src\csl_dma.d" \
"src\csl_emif.d" \
"src\csl_gpio.d" \
"src\csl_gpt.d" \
"src\csl_i2c.d" \
"src\csl_i2s.d" \
"src\csl_intc.d" \
"src\csl_lcdc.d" \
"src\csl_mcbsp.d" \
"src\csl_mcspi.d" \
"src\csl_mem.d" \
"src\csl_mmcsd.d" \
"src\csl_mmcsd_ataIf.d" \
"src\csl_msc.d" \
"src\csl_pll.d" \
"src\csl_rtc.d" \
"src\csl_sar.d" \
"src\csl_sdio.d" \
"src\csl_spi.d" \
"src\csl_sysctrl.d" \
"src\csl_uart.d" \
"src\csl_uhpi.d" \
"src\csl_usb.d" \
"src\csl_wdt.d" \
"src\evm5515.d" \
"src\evm5515_gpio.d" \
"src\evm5515_i2c.d" \
"src\i2c_probe.d" \
"src\platform.d" \
"src\system_init.d" 

ASM_DEPS__QUOTED += \
"src\csl_irqplug.d" \
"src\vectors.d" 

C_SRCS__QUOTED += \
"../src/csl_audioClass.c" \
"../src/csl_cdc.c" \
"../src/csl_dat.c" \
"../src/csl_dma.c" \
"../src/csl_emif.c" \
"../src/csl_gpio.c" \
"../src/csl_gpt.c" \
"../src/csl_i2c.c" \
"../src/csl_i2s.c" \
"../src/csl_intc.c" \
"../src/csl_lcdc.c" \
"../src/csl_mcbsp.c" \
"../src/csl_mcspi.c" \
"../src/csl_mem.c" \
"../src/csl_mmcsd.c" \
"../src/csl_mmcsd_ataIf.c" \
"../src/csl_msc.c" \
"../src/csl_pll.c" \
"../src/csl_rtc.c" \
"../src/csl_sar.c" \
"../src/csl_sdio.c" \
"../src/csl_spi.c" \
"../src/csl_sysctrl.c" \
"../src/csl_uart.c" \
"../src/csl_uhpi.c" \
"../src/csl_usb.c" \
"../src/csl_wdt.c" \
"../src/evm5515.c" \
"../src/evm5515_gpio.c" \
"../src/evm5515_i2c.c" \
"../src/i2c_probe.c" \
"../src/platform.c" \
"../src/system_init.c" 

ASM_SRCS__QUOTED += \
"../src/csl_irqplug.asm" \
"../src/vectors.asm" 


