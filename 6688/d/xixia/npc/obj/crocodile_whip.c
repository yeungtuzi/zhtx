#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(GRN"鳄尾鞭"NOR, ({ "crocodile whip", "whip" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 7000);
                set("material", "crocodile");
        }
        init_whip(45);
        setup();
}
