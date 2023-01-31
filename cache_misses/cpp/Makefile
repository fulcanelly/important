CC = g++
OLEVEL = 0
OTHER =
ALL = $(OTHER) -O$(OLEVEL)

build: jumping linear


clean:
	rm jumping linear

prof.build.done:
	make OTHER='-fprofile-generate'

profgen: prof.build.done
	time ./jumping
	time ./linear

%: %.cc
	$(CC) $(ALL) $< -o $@

%.gcda: %
	time ./$<

#make $< OTHER='-fprofile-generate'

#profgen

#profs_bins: jumping.prof.bin linear.prof.bin
profs.done: jumping.gcda linear.gcda

# makes_profs:
# 	make profs.done OTHER='-fprofile-generate'


%.prof.bin:
	make $*.gcda OTHER='-fprofile-generate'
	$(CC) $(ALL) -fprofile-use $*.cc -o $@


makes_profs: jumping.prof.bin linear.prof.bin
	echo 3

profbuild: makes_profs
