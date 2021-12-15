################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CODE/Boma.c \
../CODE/Dajinfa.c \
../CODE/Function.c \
../CODE/Standing.c \
../CODE/adc.c \
../CODE/button.c \
../CODE/cheku.c \
../CODE/encoder.c \
../CODE/image_chalu.c \
../CODE/image_huandao.c \
../CODE/image_process.c \
../CODE/image_shizi.c \
../CODE/mm.c \
../CODE/motor_control.c \
../CODE/phone_BL.c \
../CODE/podao.c \
../CODE/servo_control.c \
../CODE/speed.c 

OBJS += \
./CODE/Boma.o \
./CODE/Dajinfa.o \
./CODE/Function.o \
./CODE/Standing.o \
./CODE/adc.o \
./CODE/button.o \
./CODE/cheku.o \
./CODE/encoder.o \
./CODE/image_chalu.o \
./CODE/image_huandao.o \
./CODE/image_process.o \
./CODE/image_shizi.o \
./CODE/mm.o \
./CODE/motor_control.o \
./CODE/phone_BL.o \
./CODE/podao.o \
./CODE/servo_control.o \
./CODE/speed.o 

COMPILED_SRCS += \
./CODE/Boma.src \
./CODE/Dajinfa.src \
./CODE/Function.src \
./CODE/Standing.src \
./CODE/adc.src \
./CODE/button.src \
./CODE/cheku.src \
./CODE/encoder.src \
./CODE/image_chalu.src \
./CODE/image_huandao.src \
./CODE/image_process.src \
./CODE/image_shizi.src \
./CODE/mm.src \
./CODE/motor_control.src \
./CODE/phone_BL.src \
./CODE/podao.src \
./CODE/servo_control.src \
./CODE/speed.src 

C_DEPS += \
./CODE/Boma.d \
./CODE/Dajinfa.d \
./CODE/Function.d \
./CODE/Standing.d \
./CODE/adc.d \
./CODE/button.d \
./CODE/cheku.d \
./CODE/encoder.d \
./CODE/image_chalu.d \
./CODE/image_huandao.d \
./CODE/image_process.d \
./CODE/image_shizi.d \
./CODE/mm.d \
./CODE/motor_control.d \
./CODE/phone_BL.d \
./CODE/podao.d \
./CODE/servo_control.d \
./CODE/speed.d 


# Each subdirectory must supply rules for building sources it contributes
CODE/%.src: ../CODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"D:\SGG---SGG\DDDDDDDD\CODE" -I"D:\SGG---SGG\DDDDDDDD\Libraries" -I"D:\SGG---SGG\DDDDDDDD\Libraries\doc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Configurations" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Build" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Impl" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_PinMap" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Asc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Lin" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Spi" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Icu" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Timer" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif\Cam" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\CStart" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Irq" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Trap" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma\Dma" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Dsadc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Rdc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts\Dts" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Emem" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Emem\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray\Eray" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth\Phy_Pef7071" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce\Crc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft\Fft" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Flash" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Flash\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12\IncrEnc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tim" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Trig" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl\Hssl" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c\I2c" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom\Driver" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc\Msc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Mtu" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Mtu\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican\Can" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port\Io" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5\Psi5" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s\Psi5s" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\SpiMaster" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\SpiSlave" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Scu" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Scu\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent\Sent" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Smu" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Smu\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Src" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Src\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm\Timer" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc\Adc" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc\Std" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra\Platform" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra\Platform\Tricore" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra\Platform\Tricore\Compilers" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra\Sfr" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra\Sfr\TC26B" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Infra\Sfr\TC26B\_Reg" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Service" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Service\CpuGeneric" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Service\CpuGeneric\_Utilities" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Service\CpuGeneric\If" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Service\CpuGeneric\StdIf" -I"D:\SGG---SGG\DDDDDDDD\Libraries\infineon_libraries\Service\CpuGeneric\SysSe" -I"D:\SGG---SGG\DDDDDDDD\Libraries\seekfree_libraries" -I"D:\SGG---SGG\DDDDDDDD\Libraries\seekfree_libraries\common" -I"D:\SGG---SGG\DDDDDDDD\Libraries\seekfree_peripheral" -I"D:\SGG---SGG\DDDDDDDD\USER" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1; sed -i -e '/ctc\\include/d' -e '/Libraries\\iLLD/d' -e '/Libraries\\Infra/d' -e 's/\(.*\)".*\\DDDDDDDD\(\\.*\)"/\1\.\.\2/g' -e 's/\\/\//g' $(@:.src=.d) && \
	echo $(@:.src=.d) generated
	@echo 'Finished building: $<'
	@echo ' '

CODE/%.o: ./CODE/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


