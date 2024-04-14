CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99
SCP=sudo cp
SRM=sudo rm

CALCDIR=libcalc
CALCSOURCES=$(wildcard $(CALCDIR)/*.c)
CALCOBJECTS=$(CALCSOURCES:.c=.o)
CALCLIBRARY=libcalc.a

CONVERTDIR=libconvert
CONVERTSOURCES=$(wildcard $(CONVERTDIR)/*.c)
CONVERTOBJECTS=$(CONVERTSOURCES:.c=.o)
CONVERTLIBRARY=libconvert.so

INSTALL_DIR = /usr/local/bin
INSTALL_PATH_LIB=/usr/local/lib
INSTALL_PATH_INCLUDE=/usr/local/include

ESYMATH=esymath
UPER=uper
LOW=low

all: $(CALCLIBRARY) $(CONVERTLIBRARY) $(ESYMATH) $(UPER) $(LOW)

$(CALCLIBRARY): $(CALCOBJECTS)
	ar rcs $(CALCLIBRARY) $(CALCOBJECTS)

$(CONVERTLIBRARY): $(CONVERTOBJECTS)
	$(CC) -shared -o $(CONVERTLIBRARY) $(CONVERTOBJECTS)

$(ESYMATH): $(ESYMATH).c $(CALCLIBRARY)
	$(CC) $(CFLAGS) -I$(CALCDIR) $< -o $@ -L. -lcalc -lm

$(UPER): $(UPER).c $(CONVERTLIBRARY)
	$(CC) $(CFLAGS) -I$(CONVERTDIR) $< -o $@ -L. -lconvert

$(LOW): $(LOW).c $(CONVERTLIBRARY)
	$(CC) $(CFLAGS) -I$(CONVERTDIR) $< -o $@ -L. -lconvert

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	$(SCP) $(CALCLIBRARY) $(INSTALL_PATH_LIB)
	$(SCP) $(CONVERTLIBRARY) $(INSTALL_PATH_LIB)
	$(SCP) $(CALCDIR)/libcalc.h $(INSTALL_PATH_INCLUDE)
	$(SCP) $(CONVERTDIR)/libconvert.h $(INSTALL_PATH_INCLUDE)
	$(SCP) $(ESYMATH) $(INSTALL_DIR)
	$(SCP) $(LOW) $(INSTALL_DIR)
	$(SCP) $(UPER) $(INSTALL_DIR)
	sudo sh -c 'echo "$(INSTALL_PATH_LIB)" > /etc/ld.so.conf.d/local-libraries.conf'
	sudo ldconfig


clean:
	rm -f $(CALCLIBRARY) $(CALCOBJECTS) $(CONVERTLIBRARY) $(CONVERTOBJECTS) $(ESYMATH) $(UPER) $(LOW)

clean-all: clean
	$(SRM) -f $(INSTALL_PATH_LIB)/$(CONVERTLIBRARY)
	$(SRM) -f $(INSTALL_PATH_LIB)/$(CONVERTLIBRARY)
	$(SRM) -f $(INSTALL_PATH_INCLUDE)/libcalc.h
	$(SRM) -f $(INSTALL_PATH_INCLUDE)/libconvert.h
	$(SRM) -f $(INSTALL_DIR)/$(ESYMATH)
	$(SRM) -f $(INSTALL_DIR)/$(LOW)
	$(SRM) -f $(INSTALL_DIR)/$(UPER)
	$(SRM) -f /etc/ld.so.conf.d/local-libraries.conf
	sudo ldconfig
