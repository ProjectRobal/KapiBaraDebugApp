/*
 *  To do:
 *
 *  Add timer that will sample data from
 *  Add manual controll function
 *  ReadData must be implemented on the server side
 *  CheckBox is glitching
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector3D>
#include <QTimer>
#include <qqml.h>

#include "grpc.h"

#define GRPC_EXITS if(!this->_grpc) return;


class Controller : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:

    enum EngineDirection
    {
        Forward=0,
        Backward=1,
        Stop=2
    };

    Q_ENUM(EngineDirection);

    const char* DirectionToText(EngineDirection dir)
    {
        switch(dir)
        {
            case Forward:

                return "forward";

            break;

            case Backward:

                return "backward";

            break;

            case Stop:

                return "stop";

            break;

            default:

                return "unknow";
        }
    }

private:

std::unique_ptr<GRPC> _grpc;

int32_t speed;

QString msg;

QVector3D rotation;

bool ManualControl;

QString SensorsText;

QString SerializeMessage(const Message& msg);

void formatSensors();

QTimer readTimer;

public:
    Q_PROPERTY(QString msg READ getMSG WRITE setMSG NOTIFY MSGUpdated)
    Q_PROPERTY(QVector3D rotation READ getRotation WRITE setRotation NOTIFY RotationUpdated)
    Q_PROPERTY(bool ManualControl READ getManualControl WRITE setManualControl NOTIFY ControlChanged)
    Q_PROPERTY(QString SensorsText READ getSensorsText WRITE setSensorsText NOTIFY SensorsUpdated)


    explicit Controller(QObject *parent = nullptr);

public slots:

    void setSpeed(uint32_t _speed);

    void getIPandConnect(QString link);

    void readData();

    void startReadRoutine();
    void stopReadRoutine();

    void manualModeUpdated();

    QString getMSG()
    {
        return msg;
    }

    void setMSG(QString _msg)
    {
        msg=_msg;
        emit MSGUpdated();
    }

    QVector3D getRotation()
    {
        return rotation;
    }

    void setRotation(QVector3D rot)
    {
        this->rotation=rot;
        emit RotationUpdated();
    }

    void setManualControl(bool manual)
    {
        this->ManualControl=manual;
        emit ControlChanged();
    }

    bool getManualControl()
    {
        return this->ManualControl;
    }

    void setSensorsText(QString text)
    {
        this->SensorsText=text;
        emit SensorsUpdated();
    }

    QString getSensorsText()
    {
        return this->SensorsText;
    }

    void setDirectionLeft(EngineDirection dir)
    {
        if(!ManualControl)
        {
            return;
        }
        GRPC_EXITS

        this->_grpc->setMotorDirA(static_cast<uint32_t>(dir));

        this->_grpc->sendCommand();

        this->formatSensors();
    }

    void setDirectionRight(EngineDirection dir)
    {
        if(!ManualControl)
        {
            return;
        }
        GRPC_EXITS

        this->_grpc->setMotorDirB(static_cast<uint32_t>(dir));

        this->_grpc->sendCommand();

        this->formatSensors();
    }

    void updateSpeed(int32_t val)
    {
        if(!ManualControl)
        {
            return;
        }
        GRPC_EXITS
        speed+=val;

        speed= speed>100 ? 100 : speed;
        speed= speed<0 ? 0 : speed;

        this->_grpc->setMotorSpeedA(speed);
        this->_grpc->setMotorSpeedB(speed);

        this->_grpc->sendCommand();

        this->formatSensors();
    }


signals:

    void MSGUpdated();

    void RotationUpdated();

    void ControlChanged();

    void SensorsUpdated();

};

Q_DECLARE_METATYPE(Controller::EngineDirection);

#endif // CONTROLLER_H
