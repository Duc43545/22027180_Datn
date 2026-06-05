/****************************************************************************
 *
 * Custom SPI config for MY_F427
 *
 ****************************************************************************/

#include <px4_arch/spi_hw_description.h>
#include <drivers/drv_sensor.h>
#include <nuttx/spi/spi.h>

constexpr px4_spi_bus_t px4_spi_buses[SPI_BUS_MAX_BUS_ITEMS] = {
	initSPIBus(SPI::Bus::SPI1, {
		initSPIDevice(DRV_IMU_DEVTYPE_ICM20948,
			      SPI::CS{GPIO::PortC, GPIO::Pin2},
			      SPI::DRDY{GPIO::PortD, GPIO::Pin15}),
	}),
};

static constexpr bool unused = validateSPIConfig(px4_spi_buses);