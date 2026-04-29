//feifengmodao.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
    set_name(HIC"水月刀"NOR, ({ "shuiyue dao", "dao" }) );
    set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 0);
                set("no_drop",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_paimai",1);
                set("material", "iron");
                set("rigidity", 90000000); 
                set("long", "这是东瀛第一高手水月大宗亲自打造的一柄刀，只有在东瀛身份极高的忍者才有资格佩戴。\n");
                set("wield_msg",HIM"天际深处飞来一只五彩祥凤，盘旋在$N的上空，瞬时又飞入$N的手中。\n"NOR);
        }
        init_blade(220);
        setup();
}


int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("id") == "dongying renzhe" ) 
        {
        return ::wield();
        }else{
                return notify_fail("这是小鬼子的兵器，你干嘛用这把沾满同胞鲜血的凶器？！\n");
        }

}

