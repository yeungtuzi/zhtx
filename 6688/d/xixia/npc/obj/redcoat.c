#include <armor.h>
#include <ansi.h>

inherit SURCOAT; 

void create()
{
    set_name(HIR"红色披风"NOR, ({"red coat","coat"}));
    set_weight(4000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","件");
	set("value",1500);
	set("material","cloth");
	set("armor_prop/dodge", 3);
	}
    setup();
}
