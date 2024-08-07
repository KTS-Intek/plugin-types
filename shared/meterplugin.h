#ifndef METERPLUGIN_H
#define METERPLUGIN_H

#include <QList>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QDateTime>
#include <QVariant>
#include <QHash>
#include <QPair>



#include "meterplugintypes.h"
#define PLG_VER_1_0     10//10 - only electric
#define PLG_VER_1_1     11//11 - + water and maybe other
#define PLG_VER_1_2     12//12 - + Hash -> Struct
#define PLG_VER_1_3     12//13 - + sleep commands

#define PLG_VER_RELEASE PLG_VER_1_3

#define CHECK_METERDT_PERIOD_MSEC     86400000 // 24 hours,
//a test line for nothing

class MeterPlugin
{
public:
    virtual ~MeterPlugin() {}

    virtual QString getMeterType() = 0;    

    virtual quint16 getPluginVersion() = 0;

    virtual quint8 getPasswdType() = 0;

    virtual QByteArray getDefPasswd() = 0;

    virtual QString getVersion() = 0;

    virtual QString getMeterAddrsAndPsswdRegExp() = 0;

    virtual QString getSupportedMeterList() = 0;

    virtual quint8 getMaxTariffNumber(const QString &version) = 0;

    virtual QStringList getEnrgList4thisMeter(const quint8 &pollCode, const QString &version) = 0;

    virtual quint8 getMeterTypeTag() = 0;

    virtual Mess2meterRezult mess2meter(const Mess2meterArgs &pairAboutMeter) = 0;

    virtual QVariantHash decodeMeterData(const DecodeMeterMess &threeHash) = 0;

    virtual QVariantHash helloMeter(const QVariantHash &hashMeterConstData) = 0;

    virtual QString meterTypeFromMessage(const QByteArray &readArr) = 0;

    virtual QVariantHash isItYour(const QByteArray &arr) = 0;

    virtual QVariantHash isItYourRead(const QByteArray &arr) = 0;

    virtual QByteArray niChanged(const QByteArray &arr) = 0;

    virtual QVariantHash meterSn2NI(const QString &meterSn) = 0;


    //parametryzatsiya
    virtual Mess2meterRezult messParamPamPam(const Mess2meterArgs &pairAboutMeter) = 0;
    virtual QVariantHash decodeParamPamPam(const DecodeMeterMess &threeHash) = 0;

    virtual QVariantHash how2logout(const QVariantHash &hashConstData, const QVariantHash &hashTmpData) = 0;

    virtual QVariantHash getDoNotSleep(const quint8 &minutes) = 0;

    virtual QVariantHash getGoToSleep(const quint8 &seconds) = 0;

    virtual QVariantList getDefaultVirtualMetersSchema() = 0 ;//{ return QVariantList(); }// hashTmpData.insert("virtualmetersonly", true);



};

#if QT_VERSION < 0x050000
Q_DECLARE_INTERFACE(MeterPlugin, "ua.zbyralko.hello_zb.MeterPlugin")
#else
QT_BEGIN_NAMESPACE

#define PluginInterface_iid "ua.zbyralko.hello_zb.MeterPlugin"

Q_DECLARE_INTERFACE(MeterPlugin, PluginInterface_iid)
QT_END_NAMESPACE

#endif
#endif // METERPLUGIN_H
