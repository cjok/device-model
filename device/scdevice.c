/*
* for learn device
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct bus_type scbus_type;
extern struct device scbus;
extern struct class *scclass;

static char *Version = "revision 1.0, scdevice";

void screlease(struct device *dev)
{
	printk("scbus release\n");
}

struct device scdevice = {
	.parent	= &scbus,
	.init_name	= "scdevice0",
	.bus	= &scbus_type,
	.release	= screlease,
	.devt = ((250 << 20) | 3),	//define devno, create device node file
								//under /dev/
};

/*
* export device attribute
*/
static ssize_t show_device_version(struct device *dev, 
			struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%s\n", Version);
}
DEVICE_ATTR(version, 0666, show_device_version, NULL);


static int __init scdevice_init(void)
{
	int ret;

	ret = device_register(&scdevice);
	if (ret) 
		return ret;

	ret = device_create_file(&scdevice, &dev_attr_version);
	if (ret)
		goto err_create;
	
	device_create(scclass, NULL, 0, 0, "scdevice0");

	printk("Create a scdevice");
	return 0;

err_create:
	device_unregister(&scdevice);
	return ret;
}

static void __exit scdevice_exit(void)
{
	device_destroy(scclass, 0);
	device_remove_file(&scdevice, &dev_attr_version);
	device_unregister(&scdevice);
	printk("Remove a scdevice");
}

module_init(scdevice_init);
module_exit(scdevice_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
