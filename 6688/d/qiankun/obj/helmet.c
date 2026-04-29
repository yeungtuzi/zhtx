#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIW"天罡"+HIY"战盔"NOR, ({ "battle helmet", "helmet" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIY"这是当年上官仞浴血杀场出生入死所佩带的防具，要是没有它，十个上官仞也交待了。\n这件头盔金光闪闪，似是一件神物。"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", this_player()->query_skill("force",1)/10);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/30);
                set("armor_prop/attack", this_player()->query_skill("sword",1)/80); 
                set("armor_prop/defence",this_player()->query_skill("parry",1)/80);
        }
        setup();
}

