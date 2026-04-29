//ywqiang.c 
//by dwolf
//97.11.8

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(RED "岳王枪" NOR, ({ "yuewang qiang", "qiang" }));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "枪由镔铁做成，沉重厚实，枪尖由玄铁做成，锋利无比。\n");
                set("value", 10000);
                set("material", "greysteel");
                set("wield_msg", "$N「唰」的一声抽出一柄寒气逼人的$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回枪囊。\n");
        }
        init_spear(130);
        setup();
}
