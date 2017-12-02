#ifndef LOGGER_HPP_INCLUDE
#define LOGGER_HPP_INCLUDE

#include "main.h"

#include <string>
#include <unordered_map>

#include "service.hpp"

#include "logchannel.hpp"

namespace Util
{

#ifdef _WIN32
class DLL_EXPORT Logger : public Service
#else
class Logger : public Service
#endif // _WIN32
{
public:
    Logger();
    virtual ~Logger();

    bool HasLogChannel(std::string channelName) const;
    void CreateLogChannel(std::string channelName, std::string tag, FILE* fileDesc);
    void EnableLogChannel(std::string channelName);
    void DisableLogChannel(std::string channelName);
    bool IsLogChannelEnabled(std::string channelName) const;

    void Log(std::string channelName, std::string message);
    void FlushAll();

protected:
    std::unordered_map<std::string, LogChannel*> logChannels;

};

}

#endif // LOGGER_HPP_INCLUDE