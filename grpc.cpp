#include "grpc.h"
#include <QDebug>

GRPC::GRPC(const std::string& ip_addr)
{

    this->stub=RCRobot::NewStub(grpc::CreateChannel(ip_addr+":5051",grpc::InsecureChannelCredentials()));

    this->setMotorDirA(2);
    this->setMotorDirB(2);

    this->setMotorSpeedA(0);
    this->setMotorSpeedB(0);

}


void GRPC::sendCommand()
{
    if(!this->stub)
    {
        return;
    }
    grpc::ClientContext context;
    Command cmd;

    _None none;

    cmd.set_allocated_ma(&this->motor1);
    cmd.set_allocated_mb(&this->motor2);

    cmd.set_allocated_ear1(&this->servo1);
    cmd.set_allocated_ear2(&this->servo2);

    grpc::Status state=this->stub->SendCommand(&context,cmd,&none);

    cmd.release_ear1();
    cmd.release_ear2();
    cmd.release_ma();
    cmd.release_mb();

    if(!state.ok())
    {
        qDebug()<<"Command send failed";
        return;
    }

}

bool GRPC::Process()
{

    if(!this->stub)
    {
        return false;
    }
    grpc::ClientContext context;
    Command cmd;
    Message msg;

    cmd.set_allocated_ma(&this->motor1);
    cmd.set_allocated_mb(&this->motor2);

    cmd.set_allocated_ear1(&this->servo1);
    cmd.set_allocated_ear2(&this->servo2);


    grpc::Status state=this->stub->Process(&context,cmd,&msg);

    cmd.release_ear1();
    cmd.release_ear2();
    cmd.release_ma();
    cmd.release_mb();

    if(!state.ok())
        {
        qDebug()<<"Process send failed";
        return false;
        }


    return true;

}

bool GRPC::GetData()
{

    if(!this->stub)
    {
        return false;
    }
    grpc::ClientContext context;
    Command cmd;

    _None none;

    grpc::Status state=this->stub->ReadData(&context,none,&this->msg);

    if(!state.ok())
        {
        qDebug()<<"GetData send failed";
        return false;
        }


    return true;

}
