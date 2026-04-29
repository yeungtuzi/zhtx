#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIG"玄玉"+HIW"冰霜"+HIM"靴"NOR, ({ "ice boots", "boots" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIG"这是一件散发着寒气的靴子，但穿着之人却从不会感到寒冷。\n据说穿着此靴飞岩走壁，踏雪无痕，如履平地，可以将自身的轻功发挥至及致。"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "ice");
                set("armor_prop/armor", this_player()->query_skill("force",1)/10);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/30);
                set("armor_prop/dodge", this_player()->query_skill("dodge",1)/20); 
        }
        setup();
}

