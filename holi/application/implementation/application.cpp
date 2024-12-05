#include "holi/application/implementation/application.hpp"
#include <mutex>
#include <iostream>

namespace holi
{
     application_implementation::application_implementation()
     {
          this->version = 1.0;
     }

     int application_implementation::run()
     {
          std::cout << "run\n";
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