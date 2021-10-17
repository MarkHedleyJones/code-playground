// spinLockSleep.cpp

#include <iostream>
#include <atomic>
#include <thread>

class Spinlock
{
  std::atomic_flag flag;

public:
  Spinlock()
    : flag(ATOMIC_FLAG_INIT)
  {
  }

  void lock()
  {
    while (flag.test_and_set())
      ;
  }

  void unlock()
  {
    flag.clear();
  }
};

Spinlock spin;

void workOnResource()
{
  spin.lock();
  std::cout << "Lock acqired, running task ... " << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  spin.unlock();
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

// A spinlock is more efficient for synchronizing threads (than a mutex) if the
// expected time to syncronise is short. This is because the spinlock
// "busy-waits", continuously polling the resource until it becomes available.
// This keeps the thread active and if another thread unlocks the resource it
// can acquire the resource immediately. The thread is not put to sleep
// (unless the operating system forces a switch because the thread's time
// quanta was exceeded).
