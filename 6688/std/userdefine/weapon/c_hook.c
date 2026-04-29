// gangdao.c

#include <weapon.h>
inherit HOOK;

void create()
{
	set_name("钩", ({ "hook" }));
	set_weight(2000);
	if (clonep())                                       
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把锋利的吴钩。\n");
		set("value", 0);
		set("material", "steel");
		set("unpawnable",1);
		set("no_get",1);		
		set("no_drop",1);
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_hook(15);        
	setup();
}   

