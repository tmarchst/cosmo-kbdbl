# Cosmo Cummunicator Keyboard Backlight
Simple binary to control the Cosmos keyboard backlight.
Becuase SUID doesn't work on shell scripts

## Building and Installing
```
gcc -Wall -Wextra -o kbdbl ./kbdbl.c
sudo install -g root -o root -m 4755 kbdbl /usr/local/bin/
```
or
```
gcc -Wall -Wextra -o kbdbl ./kbdbl.c
sudo chown root:root ./kbdbl
sudo chmod 4755 ./kbdbl
sudo mv kbd
```

## Usage
```
kbdbl \<brigthness\>
```
Where brightness is between 0 (off) and 5 (brightest)

Examples:
```
kbdbl 0
kbdbl 3
```
