#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xe8213e80, "_printk" },
	{ 0x38a1949b, "usb_deregister" },
	{ 0xd272d446, "__fentry__" },
	{ 0x00af752c, "usb_register_driver" },
	{ 0x35a0db66, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0xe8213e80,
	0x38a1949b,
	0xd272d446,
	0x00af752c,
	0x35a0db66,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__x86_return_thunk\0"
	"_printk\0"
	"usb_deregister\0"
	"__fentry__\0"
	"usb_register_driver\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v2E82p22B8d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "D061A682329FA02B27338E1");
