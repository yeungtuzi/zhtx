// /d/xizang/class/budala/npc/obj/ring.c

#include <armor.h>

inherit FINGER;

void create()
{
	set_name("戒指", ({ "ring" }));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个普通的金戒指\n");
		set("unit", "个");
		set("value", 100);
		set("armor_prop/mydefined", 1);
		set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
                set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");
        }
        setup();
}
