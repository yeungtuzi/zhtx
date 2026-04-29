//stone.c
//by masterall
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(YEL"狗屎"NOR , ({ "gou shi","shi" }) );
        set_weight(6000);
        set("no_drop","不许随便乱丢垃圾，何况这么臭臭的东西。");
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", "一坨脏兮兮的狗屎，虽然已经好多年了，但仍然散发着刺鼻的臭味。\n");
        set("wear_msg", YEL "$N将一坨脏兮兮的狗屎扣在了脑袋上，哎呀臭死了快点离他远点!!\n" NOR); 
        set("remove_msg", HIY "$N将狗屎从脑袋上取了下来，小心翼翼的收好。\n" NOR);
        set("armor_prop/personality", -150);
        set("armor_prop/karma", 15);
        set("armor_prop/armor", 1);
        set("armor_prop/armor_vs_force", 1);


        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "坨");
        
}

int query_autoload() { return 1; }


