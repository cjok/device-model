#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x85c010c6, "module_layout" },
	{ 0x9075a2af, "bus_register" },
	{ 0xd0d8621b, "strlen" },
	{ 0x46f5a8bc, "device_register" },
	{ 0xb72397d5, "printk" },
	{ 0xb4390f9a, "mcount" },
	{ 0x6c2e3320, "strncmp" },
	{ 0x249eecc2, "bus_unregister" },
	{ 0x19de4556, "bus_create_file" },
	{ 0x59f7fb4d, "bus_remove_file" },
	{ 0xd779c086, "device_unregister" },
	{ 0x701d0ebd, "snprintf" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "EC05A19447E4141265E5244");
