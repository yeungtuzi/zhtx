#include <ansi.h>
#include <weapon.h>

inherit HAMMER; 

void create()
{
        set_name(  "百宝囊" , ({ "nang" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",

"这是一个用于存放兵器的百宝囊，你可用在里面取（pull）或（repull）兵器。\n"
);
                set("value", 0);
                set("unpawnable",1);
                set_weight(1);
                set("owner","no_owner");
                set("marks/寒于",1);
                set("no_drop",1);
                set("material", "crimson gold");
                set("rigidity", 99);
                
             }

        init_hammer(120);
        setup();

}
 
void init()
{
        add_action("do_pull","pull");
}

 int do_pull(string arg)
{
        object me;
        object obj;
        me=this_player();
  if (arg!="hammer" && arg!="fork" && arg!="spear" && arg!="whip" && arg!="halberd" && arg!="hook" && arg!="staff" && arg!="axe") 
             return notify_fail("你想从百宝囊里抽什么？（whip,fork,halberd,hammer,hook,spear,staff,axe）\n");
         if(!arg)
              return notify_fail("你想从百宝囊里抽什么？（whip,fork,halberd,hammer,hook,spear,staff,axe）\n");
        {
                if(arg=="spear") {obj=new(__DIR__"spear");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一杆幽灵神魔枪!\n");}
                if(arg=="hammer") {obj=new(__DIR__"hammer");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一柄霹雳雷霆锤!\n");}
       if(arg=="whip") {obj=new(__DIR__"whip");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一条疾风骤雨鞭!\n");}
       if(arg=="halberd") {obj=new(__DIR__"halberd");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一杆阴溯寒冰戟!\n");}
       if(arg=="hook") {obj=new(__DIR__"hook");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一把迷魂摄魄钩!\n");}
       if(arg=="staff") {obj=new(__DIR__"staff");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一条担山伏魔杖!\n");}
       if(arg=="axe") {obj=new(__DIR__"axe");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一柄开天辟地斧!\n");}
       if(arg=="fork") {obj=new(__DIR__"fork");obj->move(me);
  write("你用手在背后百宝囊里一探，只见寒光一闪，掌中已经多了一柄翻江搅海叉!\n");}            
                destruct(this_object());
                
        }
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
   me->add("force",me->query("force_factor"));
}

int query_autoload()
{
    return query("weapon_prop");
} 
