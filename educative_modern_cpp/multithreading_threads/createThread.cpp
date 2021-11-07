// createThread.cpp

#include <iostream>
#include <thread>

void helloFunction()
{
  std::cout << "Hello from a function." << std::endl;
}

class HelloFunctionObject
{
public:
  void operator()() const
  {
    std::cout << "Hello from a function object." << std::endl;
  }
};

int main()
{
  std::cout << std::endl;

  std::thread t1(helloFunction);

  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject);

  std::thread t3([]
                 { std::cout << "Hello from a lambda." << std::endl; });

  t1.join();
  t2.join();
  t3.join();

  std::cout << std::endl;
};

// All three threads(t1, t2, and t3) write their messages to the console.
// The work package of thread t2 is a function object(lines 10 - 15), and the work package of thread t3 is a lambda function(line 26).
// In lines 28 - 30 the main thread is waiting until its children are done.
