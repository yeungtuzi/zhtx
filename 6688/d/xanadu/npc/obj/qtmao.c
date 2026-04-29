#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIR"擎天"+HIW"长矛" NOR, ({ "chang mao", "mao" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是「毒手」乾罗的随身兵器，丝毫不亚于厉若海的丈二红枪。\n");
                set("value", 0);                     
                set("rigidity",1000000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");
                set("weapon_prop/attack",50);
        }
        init_spear(320);
        set("no_get",1);        
        set("no_give",1);       
        set("no_drop",1);       
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        return damage_bonus*6+random(damage_bonus*6);
}

