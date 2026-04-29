// /obj/clothes/hairclip.c

#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "发卡", ({ "hairclip", "clip", "fa qia" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", 
"一个彩色塑料制成的发卡.现在没多少女孩子还戴这东西了.\n");
                set("value", 50);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}
