#include "controller.h"
#include "QDebug"

QString Controller::SerializeMessage(const Message& msg)
{
    QString output;

    QTextStream stream(&output);

    if(msg.has_gyroscope())
    {

    stream<<"Angels axis:\n\n";

    stream<<"Roll:"<<msg.gyroscope().gyroscope().at(0)<<" deg\n";
    stream<<"Pitch:"<<msg.gyroscope().gyroscope().at(1)<<" deg\n";
    stream<<"Yaw:"<<msg.gyroscope().gyroscope().at(2)<<" deg\n";


    stream<<"Acceleration:\n\n";

    stream<<"X:"<<msg.gyroscope().acceleration().at(0)<<" g\n";
    stream<<"Y:"<<msg.gyroscope().acceleration().at(1)<<" g\n";
    stream<<"X:"<<msg.gyroscope().acceleration().at(2)<<" g\n";

    }

    stream<<"Distance sensors:\n\n";

    if(msg.has_front())
    {
        stream<<"Front left: "<<msg.front().distance()<<" mm\n";
    }
    if(msg.has_front1())
    {
        stream<<"Front right: "<<msg.front1().distance()<<" mm\n";
    }
    if(msg.has_floor())
    {
        stream<<"Floor: "<<msg.floor().distance()<<" mm\n";
    }

    stream<<"Message id: "<<msg.status()<<"\n";
    stream<<"Message: "<<msg.message().c_str()<<"\n";

    return output;
}

void Controller::formatSensors()
{
    QString output=this->SerializeMessage(this->_grpc->getMessage());

    auto &rotation=this->_grpc->getMessage().gyroscope().gyroscope();

    this->setRotation(QVector3D(rotation[0],rotation[2]+90.f,rotation[1]));

    QTextStream stream(&output);

    stream<<"\n\n";
    stream<<"Output: \n\n";
    stream<<"Motor A speed: "<<speed<<" %\n";
    stream<<"Direction A: "<<DirectionToText(static_cast<EngineDirection>(this->_grpc->MotorDirA()))<<" \n";
    stream<<"Motor B speed: "<<speed<<" %\n";
    stream<<"Direction B: "<<DirectionToText(static_cast<EngineDirection>(this->_grpc->MotorDirB()))<<" \n";


    this->setSensorsText(output);
}

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    this->setMSG("Hello World!");
    this->setRotation(QVector3D(0.f,90.f,0.f));
    this->setSensorsText("Awaiting data!");

    this->readTimer.setInterval(50);

    QObject::connect(this,&Controller::ControlChanged,this,&Controller::manualModeUpdated);
    QObject::connect(&this->readTimer,&QTimer::timeout,this,&Controller::readData);
}

void Controller::getIPandConnect(QString link)
{
    this->stopReadRoutine();

    this->_grpc.reset();

    this->_grpc=std::make_unique<GRPC>(link.toStdString());

    if(*this->_grpc)
    {
        this->setMSG("Created client to ip: "+link);

        this->startReadRoutine();

        qDebug()<<"Created client to ip: "<<link;
    }
    else
    {
        this->setMSG("Failed to create GRPC client!");

        qDebug()<<"Failed to create GRPC client!";
    }

}

void Controller::manualModeUpdated()
{
    if(this->ManualControl)
    {
        this->setMSG("Manual control engaged!");
    }
    else
    {
        this->setMSG("Manual control disabled!");
    }
}

void Controller::readData()
{
    if(*this->_grpc)
    {
        if(this->_grpc->GetData())
        {
            this->formatSensors();
        }
        else
        {
            this->setSensorsText("Read timeout");
            this->stopReadRoutine();
            this->_grpc.reset();
            this->setMSG("Failed to connect, reseting gRPC client!");
        }
    }
}

void Controller::startReadRoutine()
{
    this->readTimer.start();
}

void Controller::stopReadRoutine()
{
    this->readTimer.stop();
}

void Controller::setSpeed(uint32_t _speed)
{
    this->speed=_speed;
}

