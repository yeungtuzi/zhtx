// /d/xizang/class/bad/npc/obj/cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("布衣", ({ "cloth" }) );
        set_weight(2000);
	set("code_name", "布衣");
	if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件据说是恶人谷土产的布衣");
		set("value", 500);
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
