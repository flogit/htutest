install:
	mkdir -p $(DESTDIR)/usr/include/htutest-0.1
	cp -f *.h *.hpp $(DESTDIR)/usr/include/htutest-0.1
	cp -f *.pc $(DESTDIR)/usr/lib/pkgconfig