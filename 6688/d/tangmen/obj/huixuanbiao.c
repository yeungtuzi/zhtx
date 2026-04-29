//huixuanbiao.c 回旋镖
//by tang
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIM"回旋镖"NOR, ({ "huixuan biao", "biao", "huixuan" }) );
	set_weight(1000);
       	set("value", 30000);
	set("no_drop",1);
	set("no_get",1);
	set("unpawnable",1);
	set("no_decrease",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "唐门特制的回旋暗器.\n");

		set("base_unit","枚");
                set("unit","枚");

               	set("material", "steel");
        }

	set_amount(1);
        init_throwing(50);
        setup();
}

