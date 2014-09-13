/**
 * @file SimpleBirdSettings.h
 * Ustawienia aplikacji - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.4
 */

#ifndef SIMPLEBIRDSETTINGS_H
#define SIMPLEBIRDSETTINGS_H

#include "aquila/Tools.h"
#include "aquila/Window.h"
#include "aquila/dtw/Dtw.h"
#include <QBitArray>
#include <QColor>
#include <QMap>
#include <QSettings>
#include <QString>
#include <QVariant>

class SimpleBirdSettings : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(unsigned int verbosity READ getVerbosity WRITE setVerbosity)
    Q_PROPERTY(unsigned int frameLength READ getFrameLength WRITE setFrameLength)
    Q_PROPERTY(double overlap READ getOverlap WRITE setOverlap)
    Q_PROPERTY(QString windowType READ getWindowTypeString WRITE setWindowType)
    Q_PROPERTY(double preemphasis READ getPreemphasis WRITE setPreemphasis)
    Q_PROPERTY(unsigned int paramsPerFrame READ getParamsPerFrame WRITE setParamsPerFrame)
    Q_PROPERTY(int dtwDistanceType READ getDtwDistanceType WRITE setDtwDistanceType)

public:
    SimpleBirdSettings();

    /**
     * Jedynym zadaniem destruktora jest wywołanie destruktora QSettings.
     */
    ~SimpleBirdSettings()
    {
    }

    QVariant value(QString key) const;

public slots:
    void restoreDefaults();

    void save() { sync(); }

    int getVerbosity() const { return value("general/verbosity").toInt(); }
    void setVerbosity(int verbosity) { setValue("general/verbosity", verbosity); }

    unsigned int getFrameLength() const { return value("sound/frameLength").toUInt(); }
    void setFrameLength(unsigned int frameLength) { setValue("sound/frameLength", frameLength); }

    double getOverlap() const { return value("sound/frameOverlap").toDouble(); }
    void setOverlap(double overlap) { setValue("sound/frameOverlap", overlap); }

    Aquila::WindowType getWindowType() const { return Aquila::Tools::stringToWindowType(
                                                      value("sound/windowType").toString().toStdString()); }
    QString getWindowTypeString() const { return value("sound/windowType").toString(); }
    void setWindowType(QString winType) { setValue("sound/windowType", winType); }

    double getPreemphasis() const { return value("sound/preemphasis").toDouble(); }
    void setPreemphasis(double preemphasis) { setValue("sound/preemphasis", preemphasis); }

    QBitArray getEnabledFilters() const { return value("sound/enabledFilters").toBitArray(); }

    unsigned int getParamsPerFrame() const { return value("sound/paramsPerFrame").toUInt(); }
    void setParamsPerFrame(unsigned int paramsPerFrame) { setValue("sound/paramsPerFrame", paramsPerFrame); }

    int getDtwDistanceType() const { return value("dtw/distanceType").toInt(); }
    void setDtwDistanceType(int type) { setValue("dtw/distanceType", type); }

    Aquila::Dtw::NormalizationType getDtwNormalizationType() const
    {
        return static_cast<Aquila::Dtw::NormalizationType>(value("dtw/normalizationType").toInt());
    }

    Aquila::Dtw::PassType getDtwPassType() const
    {
        return static_cast<Aquila::Dtw::PassType>(value("dtw/passType").toInt());
    }

    bool addOverlay() const { return value("charts/addOverlay").toBool(); }

    bool useStylesheet() const { return value("appearance/useStylesheet").toBool(); }

    QString getStylesheet() const { return value("appearance/stylesheet").toString(); }

    QColor getWaveformColor() const { return value("appearance/waveformColor").value<QColor>(); }

private:
    void initDefaults();

    QVariant getDefaultValue(QString key) const;

    static QMap<QString, QVariant> defaults;
};

#endif // SIMPLEBIRDSETTINGS_H
