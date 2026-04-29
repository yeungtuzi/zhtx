// daopao.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(WHT"灰白道袍"NOR, ({ "dao pao", "cloth" }));
	set("long", "这是一件有点发白的灰道袍。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 200);
		set("armor_prop/armor", 10);
	}
	setup();
}
