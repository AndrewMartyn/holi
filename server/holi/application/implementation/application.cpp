#include "holi/application/implementation/application.hpp"
#include <mutex>
#include <iostream>

#include "holi/rooms/implementation/factory.hpp"
#include "holi/rooms/implementation/manager.hpp"

namespace holi
{
     application_implementation::application_implementation()
     {
          this->version = 1.0;
     }

     int application_implementation::run()
     {
          std::cout << "running\n";

          // rooms
          // auto rooms_dao = std::make_unique<rooms::dao_implementation>();
          auto rooms_factory = std::make_unique<rooms::factory_implementation>();
          auto rooms_manager = std::make_unique<rooms::manager_implementation>(
               *rooms_factory
          );

          auto room1 = rooms_manager->create("room 1");
          auto room2 = rooms_manager->create("room 2");
          auto room3 = rooms_manager->create("room 3");


          //////////////////////////////
          // wait for shutdown signal //
          //////////////////////////////
          std::mutex stop_lock;
          std::unique_lock<std::mutex> ul(stop_lock);
          this->stop_condition.wait(ul);

          ///////////////
          // shutdown //
          //////////////
          std::cout << "shutdown\n";

          return 0;
     }

     void application_implementation::stop()
     {
          this->stop_condition.notify_all();
     }
};