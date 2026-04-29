#include <weapon.h>
#include <ansi.h>

inherit FORK;

void create()
{
        set_name(GRN"鳄嘴剪"NOR, ({ "crocodile scissor", "scissor" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 7000);
                set("material", "crocodile");
        }
        init_fork(65);
        setup();
}
