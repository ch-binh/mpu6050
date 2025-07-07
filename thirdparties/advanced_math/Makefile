.PHONY: all test cli run clean clean-all dll

all: test-all cli dll

test-all:
	$(MAKE) -C test all

test:
	$(MAKE) -C test run

rm_data:
	$(MAKE) -C test rm_data

cli:
	$(MAKE) -C cli

dll:
	$(MAKE) -C src


clean:
	$(MAKE) -C test clean
	$(MAKE) -C cli clean
	$(MAKE) -C src clean
	rm -rf build/*

clean-all: clean
	rm -rf bin/*