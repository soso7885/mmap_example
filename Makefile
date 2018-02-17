DIR = ./output

all:
	make -C ./driver
	make -C ./app
	install -d $(DIR)
	cp ./driver/my_mmap_drv.ko $(DIR)
	cp ./app/my_mmap_app $(DIR)

clean:
	make clean -C ./driver
	make clean -C ./app
	rm -rf $(DIR)
