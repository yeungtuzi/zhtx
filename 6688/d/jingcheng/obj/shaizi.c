//shaizi.c

#include <weapon.h>

inherit THROWING;

void create()
{
       set_name("骰子", ({ "dice" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",     "赌博用的骰子。\n");
                set("unit","些");
               set("base_unit", "粒");
               set("base_weight", 1);
               set("value", 1);
       }
       set_amount(1);
       init_throwing(1);
       setup();
}
