//ROOM:/d/qiankun/prizon1.c
//by masterall
//2003.6.30 

#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{
        set("short", HIB"乾坤教暗牢"NOR);
      set("long",HIW"这是一间阴暗的地牢，里面黑洞洞的隐隐现出一丝亮光，隐约可以听到
滴滴答答的水声，刹那间你感觉到一声低啸，好似负伤的野兽般呻吟，定睛
一看却是一个人浑身是血，面目难辨，呲牙咧嘴的向你冲了过来！\n"NOR);     

        set("objects", ([
                          __DIR__"npc/mp19" : 1,
                ])
        );
        setup();
}


void init()
{
        add_action("do_roar", "roar");
}

int do_roar(string arg)
{

       object me;
       me=this_player();

       if ( !me->query_temp("mpweapon_win") )
                  return notify_fail("你没事在那里瞎吼什么！\n");

       if ( me->query("force") < 2000 )
                  return notify_fail("你的内力不够！\n");

       message_vision(HIC"$N听完师门前辈的临终遗言，一手抱着着他未冷的尸身，一手抚着微热的本派神兵，\n"+HIR"一想到师门的重托，不由得心潮澎湃，热血奔涌，\n"+HIY"$N突然鼓足中气，发出惊天地、泣鬼神般的怒吼！\n"+HIW"只见四周的墙壁突然间不断的塌陷……塌陷…………直至完全湮灭.........\n"NOR,me);
       if ( !me->query("mpweapon_got")){
       me->add("combat_exp",500000);
       me->add("potential",200000);
       me->set("mpweapon_got",1);
       message("system",  HIM "\n【谣言】江湖传说(WEAPON)：听说"+me->name()+"得到了本派神兵，已晋升到一代豪侠的境界！\n"NOR,users() );
       tell_object(me,HIG"\n鉴于你在找寻本派神兵中的出色表现，你得到了50万经验值，20万潜能的高额奖励！\n\n"NOR);
       }
       me->delete_temp("mpweapon_win");
       me->move(__DIR__"shanlu2.c");
       return 1;
 
}

