#include <armor.h>
#include <weapon.h>
#include <ansi.h>

inherit HEAD;
inherit F_DAGGER;

void create()
{
    set_name("一点伶仃翠玉暖",({"jade clasp","clasp"}));
    set_weight(900);
    if(clonep())
	set_default_object(__FILE__);
    else 
	{
	set("unit","只");
	set("value",50000);
	set("material","jade");
	set("female_only",1);
	set("armor_prop/armor",2);
	set("armor_prop/personality",5);
	set("wear_msg","$N小心地把一$n戴在头上。\n");
	set("wield_msg","$N把$n握在手中。\n");
	set("unwear_msg","$N轻轻地把头上的$n摘下来。\n");
	}
    setup();
    init_dagger(10);
}	
