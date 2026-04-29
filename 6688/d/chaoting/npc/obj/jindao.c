#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIY"金刀"NOR, ({ "jin dao", "dao" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一柄厚背薄刃金刀，刃上金光闪闪，冷气森森。\n");
                set("value", 1000);
                set("material", "steel");
                set("rigidity", 500);
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_blade(50);
        setup();
}

