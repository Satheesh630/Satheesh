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
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xabaed37e, "pci_iounmap" },
	{ 0x3addcf72, "pci_release_regions" },
	{ 0x76450766, "pci_disable_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xd51affba, "pci_unregister_driver" },
	{ 0x4c75fda1, "pci_enable_device" },
	{ 0xc8e6fab8, "pci_request_regions" },
	{ 0xbfd3f847, "pci_set_master" },
	{ 0x4c03a563, "random_kmalloc_seed" },
	{ 0xccaee254, "kmalloc_caches" },
	{ 0x10adfad8, "__kmalloc_cache_noprof" },
	{ 0x8eb82859, "pci_iomap" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x79ba02d7, "__pci_register_driver" },
	{ 0x2d64dd6e, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001C5Cd00001F69sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "1B7B33BA3578F9DC1B9439B");
