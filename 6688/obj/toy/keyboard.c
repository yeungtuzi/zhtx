// /obj/toy/keyboard.c

#include <weapon.h>
//inherit ITEM;
inherit BLADE;

void create()
{
        set_name("键盘", ({ "keyboard", "jianpan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个windows95键盘.\n");
                set("unit", "个");
                set("value", 10000);
                set("wield_msg", "$N抓起一个$n,握在手中当武器.\n");
                set("unwield_msg", "$N将手中的$n夹在胳膊下。\n");
                set("material", "iron");
        }
        init_blade(25);
        setup();
}
