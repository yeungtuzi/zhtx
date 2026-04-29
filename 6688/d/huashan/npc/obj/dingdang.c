// dingdang.c

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( HIY "小铃铛" NOR, ({ "ding dang", "bell ring","bell" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value", 8000);
                set("material", "gold");
                set("armor_type", "feet");
                set("armor_prop/armor", 1);
                set("armor_prop/dodge", 1);
                set("weapon_prop/personality", 15);
        }
}
