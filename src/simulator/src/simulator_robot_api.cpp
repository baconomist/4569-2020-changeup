#include "simulator_robot_api.h"

SIM_ROBOT_API SimRobotAPI* GetSharedRobotAPI()
{
    return SimRobotAPI::GetInstance();
}

SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotAPI* api)
{
    delete api;
}

SIM_ROBOT_API float GetControlVelocity(SimRobotAPI* api)
{
    return api->velocity;
}

SIM_ROBOT_API void NotifyOfVelocity(SimRobotAPI* api, float velocity)
{
api->velocity = velocity;
}

SimRobotAPI* SimRobotAPI::instance = nullptr;
SimRobotAPI::SimRobotAPI() = default;

SimRobotAPI* SimRobotAPI::GetInstance()
{
    if (instance == nullptr)
        instance = new SimRobotAPI();
    return instance;
}

SimRobotAPI::~SimRobotAPI()
{
}
