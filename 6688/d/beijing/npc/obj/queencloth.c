// queencloth.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{

       string *names = ({
                HIR"金百蝶穿花大红箭袖"NOR, HIM"银红撒花大袄"NOR, 
		HIC"起花八团倭缎排穗褂"NOR,CYN"松绿撒花绫罗裙"NOR,
        });

        set_name( names[random(sizeof(names))], ({ "cloth" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 20000);
		set("armor_prop/armor", 4);
                set("female_only", 1);
	}
	setup();
}
