//moling.c
//by masterall

#include <armor.h>
#include <ansi.h>
inherit FEET;

void create()
{
        set_name(HIC"九天"+HIB"魔"+HIG"铃"NOR, ({ "jiutian moling", "feet" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIY"这是一串亮晶晶的铃铛，一共九个穿在一起，甚是好看。\n"
                        "表面上好似孩童的饰物，但其发出的响声却不是一般人可以忍受的。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "gold");
                set("armor_prop/armor", this_player()->query_skill("force",1)/20);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/20);
                set("armor_prop/dodge", this_player()->query_skill("dodge",1)/10);
                set("armor_prop/personality", 15);
        }
        setup();
}

