//stone.c
//by masterall
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW"猪"+HIR"头"NOR , ({ "zhu tou","zt" }) );
        set_weight(6000);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", "这就闻名中外的猪头，据说只有真正是猪头的人才能戴。\n");
        set("wear_msg", HIG"$N将一个猪头戴在自己的头上，这下看起来更像是猪头了。\n" NOR); 
        set("remove_msg", HIY "$N将猪头从脑袋上取了下来，对着镜子照了照，怎么看还觉得自己像猪头。\n" NOR);
        set("armor_prop/personality", -100);
        set("armor_prop/armor", 10);
        set("armor_prop/armor_vs_force", 10);


        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "个");
        
}

int query_autoload() { return 1; }

