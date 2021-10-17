// mutex.cpp
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mut;

void workOnResource()
{
  mut.lock();
  std::cout << "Lock acqired, running task ... " << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  mut.unlock();
  std::cout << "Work done" << std::endl;
}

int main()
{
  std::cout << "Main starting ..." << std::endl;
  std::thread t(workOnResource);
  std::thread t2(workOnResource);

  t.join();
  t2.join();
}

// A mutex is an efficient way to manage a resource shared between threads.
// When the thread encounters a lock which it cannot immediately acquire, it
// goes to sleep. This is good on single core/thread systems because that
// resource won't be unlocked anyway (by other parallel proccess). It is also
// good to use when the expected time to wait for the resource is long, since the
// thread is put to sleep instantly (saving CPU cycles). This is in contrast to
// a spinlock which continuously polls the resource in a loop until it is
// available, wasting CPU cycles.
