/* badsheet1.c*/
#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name( YEL"泡湿的阴界传送符"NOR ,({ "wed sheet","sheet"}));
                
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "团");
                set("base_unit", "张");
                set("long", "被泡湿了的"+YEL"阴界传送符\n"NOR);
                set("base_weight",1);
        }
        set_amount(1);
        setup();
}

