#include <armor.h>

inherit SURCOAT; 

void create()
{
    set_name("黑色披风",({"black cloak","cloak"}));
    set_weight(4000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","件");
	set("value",1500);
	set("long", "一件黑色披风，上面绣着一个神态狰狞的鹰鹫。\n");
	set("material","cloth");
	set("armor_prop/armor",10);
	}
    setup();
}
