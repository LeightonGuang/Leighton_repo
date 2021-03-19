#include <iostream>
#include <thread>

static bool s_finished = false;

void DoWork(){
  using namespace std::literals::chrono_literals;
  int x = 0;

  while(!s_finished){
    std::cout << "work ", std::cout << x << std::endl;
    std::this_thread::sleep_for(1s);
    x++;
  }
}

int main()
{
  std::thread worker(DoWork);

  //waits for the user to press the enter key
  std::cin.get();
  s_finished = true;

  worker.join();
  std::cout << "Finished.\n";

  std::cin.get();
}
