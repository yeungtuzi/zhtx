#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name("春秋笔", ({ "pen" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枝");
                set("long", "这是一枝很普通的毛笔。\n");
                set("value", 3000);
                set("material", "iron");
		set("wield_msg","$N从怀中拿出一把$n握在手中．\n");
		set("unequip_msg","$N将手中的$n藏入怀中．\n");
        }

        init_dagger(5);
        setup();
}
