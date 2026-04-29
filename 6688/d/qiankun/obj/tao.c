#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
        set_name(HIY"五彩"NOR+HIW"丝攒"NOR+HIR"花结"NOR+HIG"长穗"NOR
+CYN"宫绦"NOR, ({ "tao" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIW"这是一件五彩丝攒花结长穗，戴在身上显得雍容华贵，非凡夫俗子所比。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", this_player()->query_skill("force",1)/20);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/20);
                set("armor_prop/dodge", this_player()->query_skill("dodge",1)/30); 
                set("armor_prop/personality", 10);
        }
        setup();
}

