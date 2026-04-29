// /d/xizang/class/budala/npc/obj/zcloth1.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"锦饰藏袍"NOR, ({ "zang pao", "robe", "cloth" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
set("long", "这是一件缀有许多锦绣装饰的藏袍,只有藏边府的高官有资格穿着.\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	setup();
}
