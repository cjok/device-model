#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/string.h>

extern struct bus_type scbus_type;

static char *Version = "revision 1.0, scdriver";

static int sc_probe(struct device *dev)
{
	printk("driver found device\n");
	return 0;
}

static int sc_remove(struct device *dev)
{
	printk("device remove\n");
	return 0;
}

struct device_driver scdriver = {
	.name	= "scdevice0",
	.bus	= &scbus_type,
	.probe	= sc_probe,
	.remove	= sc_remove,
};

/*
* export driver attribute
*/
static ssize_t driver_show_version(struct device_driver *driver, char *buf)
{
	return sprintf(buf, "%s\n", Version);
}
static DRIVER_ATTR(version, S_IRUGO, driver_show_version, NULL);

static int __init scdriver_init(void)
{
	int ret;

	ret = driver_register(&scdriver);
	if (ret)
		return ret;
	
	ret = driver_create_file(&scdriver, &driver_attr_version);
	if (ret) 
		goto err_create;

	printk("driver registered\n");
	return 0;

err_create:
	driver_unregister(&scdriver);
	return ret;
}

static void __exit scdriver_exit(void)
{
	driver_remove_file(&scdriver, &driver_attr_version);
	driver_unregister(&scdriver);
}

module_init(scdriver_init);
module_exit(scdriver_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
