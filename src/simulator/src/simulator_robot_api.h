#pragma once

#define SIM_ROBOT_API __declspec(dllexport)

class SimRobotAPI
{
    static SimRobotAPI* instance;

    SimRobotAPI();

public:

    static SimRobotAPI* GetInstance();

    float velocity = 0.0f;

    ~SimRobotAPI();
};

extern "C"
{
SIM_ROBOT_API SimRobotAPI* GetSharedRobotAPI();
SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotAPI* api);
SIM_ROBOT_API float GetControlVelocity(SimRobotAPI* api);
SIM_ROBOT_API void NotifyOfVelocity(SimRobotAPI* api, float velocity);
}
