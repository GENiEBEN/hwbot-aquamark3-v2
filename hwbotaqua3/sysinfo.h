#ifndef SYSINFO_H
#define SYSINFO_H

#include <QApplication>

extern bool _rungpuz();
extern bool _delgpuz();
extern bool _rundxdiag();
extern bool _rundmid(QStringList);

extern QString SYSINFO_GFX_GetLevelOfDetail_AMD();
extern QString SYSINFO_CPU_NAME();
extern QString SYSINFO_CPU_COUNT();
extern QString SYSINFO_CPU_THREADCOUNT();
extern QString SYSINFO_CPU_SPEED_NOW();
extern QString SYSINFO_CPU_SPEED_MAX();
extern QString SYSINFO_CPU_SPEED_EXTCLK();
extern QString SYSINFO_CPU_SOCKET_NAME();
extern QString SYSINFO_CPU_SOCKET_UPGRADE();
extern QString SYSINFO_CPU_FAMILY_NAME();
extern QString SYSINFO_CPU_VOLTAGE();
extern QString SYSINFO_MOBO_VENDOR();
extern QString SYSINFO_MOBO_NAME();
extern QString SYSINFO_MOBO_SERIALNUMBER();
extern QString SYSINFO_MOBO_SOCKET_COUNT();
extern QString SYSINFO_SYSTEM_PRODUCTNAME();
extern QString SYSINFO_SYSTEM_SKU();
extern QString SYSINFO_CHASIS_TYPE();
extern QString SYSINFO_BIOS_VENDOR();
extern QString SYSINFO_BIOS_VERSION();
extern QString SYSINFO_BIOS_REVISION();
extern QString SYSINFO_BIOS_FIRMWARE_REVISION();
extern QString SYSINFO_BIOS_DATE();
extern QString SYSINFO_BIOS_ROM_SIZE();
extern QString SYSINFO_BIOS_IS_UEFI();
extern QString SYSINFO_RAM_SLOTCOUNT();
extern QString SYSINFO_RAM_MODULECOUNT();
extern QString SYSINFO_RAM_INSTALLEDSIZE();
extern QString SYSINFO_RAM_MAXCAPACITY();
extern QString SYSINFO_RAM_FORMFACTOR();
extern QString SYSINFO_RAM_TYPE();
extern QString SYSINFO_RAM_RATEDSPEED();
extern QString SYSINFO_RAM_CONFIGUREDSPEED();
extern QString SYSINFO_RAM_VENDOR();
extern QString SYSINFO_RAM_PARTNUMBER();
extern QString SYSINFO_OS_TIMESTAMP();
extern QString SYSINFO_OS_NAME();
extern QString SYSINFO_OS_SP();
extern QString SYSINFO_OS_BITS();
extern QString SYSINFO_GFX_VENDORGPU_NAME();
extern QString SYSINFO_GFX_VENDORGPU_ID();
extern QString SYSINFO_GFX_DEVICE_ID();
extern QString SYSINFO_GFX_SUBSYS_ID();
extern QString SYSINFO_GFX_NAME();
extern QString SYSINFO_GFX_COUNT();
extern QString SYSINFO_GFX_INTEGRATOR_NAME();
extern QString SYSINFO_GFX_INTEGRATOR_ID();
extern QString SYSINFO_GFX_RAM_SIZE();
extern QString SYSINFO_GFX_RAM_TYPE();
extern QString SYSINFO_GFX_RAM_BUSWIDTH();
extern QString SYSINFO_GFX_SPEED_CORE();
extern QString SYSINFO_GFX_SPEED_RAM();
extern QString SYSINFO_GFX_SPEED_SHADER();
extern QString SYSINFO_GFX_DRIVER_INFFILE();
extern QString SYSINFO_GFX_DRIVER_VERSION_RELEASE();
extern QString SYSINFO_GFX_DRIVER_DATE();
extern QString SYSINFO_GFX_DRIVER_VERSION();
extern QString SYSINFO_GFX_DRIVER_NAME();
extern QString SYSINFO_GFX_DXVERSION();
extern QString SYSINFO_GFX_OUTPUTPORTS();


#endif // SYSINFO_H
