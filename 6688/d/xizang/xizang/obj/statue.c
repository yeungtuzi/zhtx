// /d/xizang/npc/obj/statue.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("镀金佛像", ({ "buddha statue", "statue" }));
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "尊");
		set("long", "这是一尊做工精致的镀金佛像,栩栩如生\n");
		set("value", 10000);
		set("material", "gold");
		set("armor_prop/armor", 0);
		set("armor_prop/karma", 1);
		set("wear_msg", "$N把$n戴在脖子上。\n");
                set("unwield_msg", "$N把$n从脖子上除了下来。\n");
        }
}
