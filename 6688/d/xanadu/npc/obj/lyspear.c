#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIR "丈二红枪" NOR, ({ "hong qiang", "qiang" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是「邪灵」的称手兵器，伴随他多年出生入死。\n");
                set("value", 0);                     
		set("rigidity",1000000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回枪囊。\n");
		set("weapon_prop/attack",50);
        }
        init_spear(320);
	set("no_get",1);	
        setup();
}
