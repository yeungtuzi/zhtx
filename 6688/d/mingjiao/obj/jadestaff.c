#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIG"寒玉沉香"NOR, ({ "jade staff", "staff" }));
        set_weight(60000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIG"海底千年寒玉所制成的拐杖，看上去分量不重，其实....\n"NOR);
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N举起$n作为兵器。\n");
                set("unwield_msg", "$N将手中的$n拄在地上。\n");
        }
        init_staff(90);
        setup();
}

