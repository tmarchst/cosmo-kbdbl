#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        unsigned int level;
        const char kbdled[50] = "/sys/class/leds/kbd_backlight/brightness";
        FILE *fd;
        
        if(geteuid() != 0){
                printf("Not running as root");
                return 3;
        };

        switch(argc) {
                case 1:
                  printf("Usage: %s <brightness>\n<brigthness> ... a value between 0..5\n",argv[0]);
                  return 2 ;

                case 2:
                  level =(int) *argv[1];
                  break;

                default:
                  printf("Wrong nummer of arguments\n");
                  return 2;
        }
        
        if (level >= 48 && level <= 53){
                fd = fopen(kbdled, "w");
                if (fd == NULL) { return -1;}
                if (!putc((char) level, fd)) { printf("Error writing to file\n");}
                fclose(fd);
        }

}
