#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
	 set_name(HIC "玉手镯" NOR, ({"bracelet jade","bracelet"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一只由和阗玉作成的美丽手镯。\n");
            set("unit", "只");
            set("value", 5000);
            set("armor_prop/armor",2);
            set("armor_prop/dodge", 2);
            set("armor_prop/spells", 2);
            set("wear_msg", "$N把$n带在手上。\n");
     }
     setup();
}

