#pragma once

namespace holi
{
     class command
     {
     public:
          typedef void(complete_t)(void);

          virtual ~command() = default;

          virtual void abort(void) = 0;
          virtual void execute(void) = 0;
          virtual void execute(complete_t& complete) = 0;
          virtual void execute(complete_t&& complete) { this->execute(complete); };
     };
};