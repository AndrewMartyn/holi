#include <iostream>
#include <csignal>
#include "holi/application/implementation/application.hpp"

static void sigquit([[maybe_unused]] int sig)
{
     holi_server::application_implementation::instance().stop();
}

int main (int argc, char* argv[])
{
     signal(SIGINT, sigquit);
     signal(SIGPIPE, SIG_IGN);

     return holi_server::application_implementation::instance().run();
}