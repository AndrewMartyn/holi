namespace holi_server
{
     class application
     {
     public:
          application() = default;
          application(const application& obj) = delete; 
          application(application& obj) = delete;
          application& operator=(const application&& obj) = delete;
          application& operator=(application&& obj) = delete;
          virtual ~application() = default;

          virtual int run() = 0;
          virtual void stop() = 0;
     };
};