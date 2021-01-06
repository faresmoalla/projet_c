## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smart_farm

smart_farm_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	client.c client.h \
	fonction.c fonction.h \
	commande.c commande.h \
	equipement.c equipement.h \
	ouvrier.c ouvrier.h \
	absence.c absence.h \
	absenteisme.c absenteisme.h \
	fichier.c fonctionMH.h \
	plantation.c plantation.h \
	capteur.c capteur.h \
mb_seche.c mb_seche.h

smart_farm_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

