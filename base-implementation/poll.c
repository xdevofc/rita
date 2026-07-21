#include <stdio.h>
#include <poll.h>

int main(void)
{
  struct pollfd pfds[1];

  pfds[0].fd = 0; // standard input
  pfds[0].events= POLLIN; //tell me when its ready to read
  
  printf("Hit RETURN or wait 2.5 seconds for timeout\n");

  int num_events = poll(pfds, 1, 2500);

  if(num_events == 0) {
    printf("Poll timed out!\n");
  }else {
    int polling_happend = pfds[0].revents & POLLIN;

    if (polling_happend){
      printf("File descriptod %d is ready to read\n", pfds[0].fd);
    }else{
      printf("Unexpected event ocurred: %d\n", pfds[0].revents);
    }
  }

  return 0;
}
