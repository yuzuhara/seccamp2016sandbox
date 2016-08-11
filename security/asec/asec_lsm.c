/*
 * Attouteki Seityou Security for Seccamp2016
 *
 *  Authors:
 *  Yosuke Chubachi <yosuke.chubachi@gmail.com>
 *
 *  Copyright (C) 2016 Yosuke Chubachi <yosuke.chubachi@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2,
 *      as published by the Free Software Foundation.
 */

#include <linux/security.h>

struct security_operations asec_ops = {
	.name = "asec"
};

/**
 * asec_init - initialize the asec system
 * Returns 0
 */
static __init int asec_init(void)
{
     	/* Register with LSM */
	if (register_security(&asec_ops))
        	panic("asec: Unable to register with kernel.\n");
	
	printk(KERN_INFO "ASEC: Hello sandbox numa!\n");
	return 0;
}

security_initcall(asec_init);
