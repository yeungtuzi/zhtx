
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("翁四先生的钢拐", ({ "gang guai", "staff" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是翁四先生的成名兵器，乃采集南海精铁锻造而成，光芒四射。\n");
                set("value", 0);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(100);
        setup();
}

