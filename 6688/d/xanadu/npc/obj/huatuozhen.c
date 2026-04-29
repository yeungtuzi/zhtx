
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("华佗针", ({ "huatuo zhen","zhen" }) );
	set("no_decrease",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一根银光闪闪，长约五寸的细针，发出蓝油油的光芒。\n");
		set("value", 0);
                set("unit", "根");
		set("base_weight", 1);
		set("base_value", 0);
	}
	set("poison/amount",10000);
	set("poison/type","tm_poison");
        init_sword(120);
	setup();
}
int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( userp(me) )
        {
                return notify_fail("这不是你能用的兵器！\n");
        }
        return ::wield();
}

