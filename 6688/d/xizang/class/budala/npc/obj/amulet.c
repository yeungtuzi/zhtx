// /d/xizang/class/budala/npc/obj/amulet.c

#include <armor.h>

inherit HEAD;

void create()
{
        set_name("护身符", ({ "amulet", "hushenfu", "fu" }));
	set_weight(4);
	if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "个");
		set("long", "这是一个达赖喇嘛祝福过的镀金护身符.\n");
		set("value", 10);
		set("material", "gold");
		set("armor_prop/karma", 5);
		set("wear_msg", "$N把$n戴在脖子上。\n");
                set("unwield_msg", "$N把$n从脖子上除了下来。\n");
        }
}
