//fengsword.c
//风清扬亲传佩剑
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( HIR "湛庐剑" NOR, ({ "zhanlu sword", "sword" }) );
        set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "此剑乃欧冶子花毕生心血所铸八大名剑之一，断金切玉如摧枯拉朽。\n");
                set("unpawnable",1);
                set("value", 420000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N「飕」地一声抽出一把锋利的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
//                set("weapon_prop/courage", 15);
//                set("weapon_prop/intelligence", 15);
//                set("weapon_prop/personality", 15);
//                set("weapon_prop/astral_vision", 1);
                set("rigidity", 10000000);

        }

        init_sword(150);
        setup();
}

/*
int query_autoload()
{
	if(this_player()->query("mark/autoload_fengsword")
	&& this_player()->query("family/family_name")=="华山派剑宗")
	   return 1;
	return 0;	
}
*/
