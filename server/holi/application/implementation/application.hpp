#pragma once

#include <memory>
#include <condition_variable>
#include "holi/application.hpp"

namespace holi
{
     class application_implementation : public application
     {
     public:
          std::condition_variable stop_condition;

          application_implementation();

          int run() override final;
          void stop() override final;

          static application& instance(void)
          {
               static auto instance = std::make_unique<application_implementation>();

               return *instance;
          }
     };
};