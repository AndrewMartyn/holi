#pragma once

#include <sqlite3.h>
#include <string>

namespace holi
{
     namespace database
     {
          class sqlite
          {
          public:
               const std::string& db_name;

               sqlite(
                    const std::string& db_name
               );

               bool connect(void);
               bool disconnect(void);
          };
     };
};