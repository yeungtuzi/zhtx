// necklace.c 骷髅魔链
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIW"骷髅"+HIB"魔链"NOR, ({ "skeleton necklace", "necklace" }));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIW"这是用当年陈玄风和梅超风修炼九阴白骨爪时杀的人的头骨穿成的项链，\n"
                        "看起来有说不出的恐怖。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "skeleton");
                set("armor_prop/armor", this_player()->query_skill("force",1)/10);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/20);
                set("armor_prop/attack", this_player()->query_skill("sword",1)/80);
                set("armor_prop/personality", -5);
        }
        setup();
}

