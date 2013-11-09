#ifndef WIFI__PM__H
#define WIFI__PM__H

#include <linux/gpio.h>
#define SDIO_WIFI_POWERUP   (1)
#define SDIO_WIFI_INSUSPEND (2)
static char* wifi_para = "wifi_para";

struct wifi_pm_ops {
	char*           mod_name;
	int   wifi_used;
	int   sdio_id;
	int   usb_id;
	int   module_sel;
	int   (*gpio_ctrl)(char* name, int level);	
	void  (*standby)(int in);
	void  (*power)(int mode, int *updown);

#ifdef CONFIG_PROC_FS
	struct proc_dir_entry		*proc_root;
	struct proc_dir_entry		*proc_power;
#endif
};

void ap6xxx_gpio_init(void);

extern struct wifi_pm_ops wifi_select_pm_ops;
extern void sw_mci_rescan_card(unsigned id, unsigned insert);

#endif
