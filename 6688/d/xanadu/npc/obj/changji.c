#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
        set_name(GRN "三八长戟" NOR, ({ "sanba changji", "ji","changji" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long","一柄玄铁打制的方天画戟,冒着寒气令人不寒而栗!\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");
		set("rigidity",500000);
                set("value", 0);
                set("material", "steel");
        }
        init_halberd(120);
        setup();
}
