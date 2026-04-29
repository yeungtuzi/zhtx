#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG"折扇"NOR, ({ "fan" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这把折扇扇骨是用精钢打造的，扇面则是朱丹臣自己的书法。\n");
                set("unit", "柄");
                set("value", 20000);
                set("material", "iron");
        }
        init_sword(45);
        setup();
}
