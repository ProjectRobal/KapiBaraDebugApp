#ifndef GRPC_H
#define GRPC_H

#include <QObject>
#include <QDebug>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>

#include "_grpc/rc_service.grpc.pb.h"


using grpc::Status;


class GRPC
{
private:

std::unique_ptr<RCRobot::Stub> stub;

Motor motor1;
Motor motor2;

Servo servo1;
Servo servo2;

Message msg;

public:

    GRPC(const std::string& ip_addr);

    uint32_t MotorDirA()
    {
        return this->motor1.direction();
    }

    uint32_t MotorSpeedA()
    {
        return this->motor1.speed();
    }

    uint32_t MotorDirB()
    {
        return this->motor1.direction();
    }

    uint32_t MotorSpeedB()
    {
        return this->motor1.speed();
    }

    void setMotorSpeedA(const uint32_t& speed)
    {
        this->motor1.set_speed(speed);
    }

    void setMotorSpeedB(const uint32_t& speed)
    {
        this->motor2.set_speed(speed);
    }

    void setMotorDirA(const uint32_t& direction)
    {
        qDebug()<<direction;
        this->motor1.set_direction(direction);
    }

    void setMotorDirB(const uint32_t& direction)
    {
        qDebug()<<direction;
        this->motor2.set_direction(direction);
    }

    void setServoAngelA(const float& angle)
    {
        this->servo1.set_angle(angle);
    }

    void setServoAngelB(const float& angle)
    {
        this->servo2.set_angle(angle);
    }

    void sendCommand();

    bool Process();

    bool GetData();

    const Message& getMessage()
    {
        return msg;
    }

    operator bool()
    {
        return (bool)this->stub;
    }

};

#endif // GRPC_H
