#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIC"瑶琴"NOR, ({ "yao qin", "yaoqin"}) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "具");
                set("value", 1);
                set("rigidity", 500000);
                set("long","这是一具颜色暗旧的瑶琴，当是数百年甚至是千年以上的古物。\n");
        }
        init_sword(50);
        setup();

}
