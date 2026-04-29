#include <ansi.h>
inherit ROOM;
string *names=({
        __DIR__"cave2",
        __DIR__"cave5",
        __DIR__"cave6",
        __DIR__"cave5",
} );
void create()
{
        set("short", "洞穴");
        set("long", @LONG
山岩下秘洞，曲折深邃，有如诸葛武侯之八卦迷阵一般，幽谜繁复处尤有过之。
越是深入越是阴湿黝暗，到后来竟已难见五指。但隐约好像有好多大铁箱子横七
竖八的躺着。
LONG
        );
set("item_desc", ([
                "box": "一个碧磷磷的大箱子，也不知道是用什么做成的，上面没有锁，好像可以打开。\n",
                        ]) );
        setup();
}
void reset()
{
        int i,j;
        string temp;
        ::reset();
        set("havejia",1);
        set("havestone",1);
        for (i=0;i<=3;i++)
        {
                j=random(4);
                temp=names[j];
                names[j]=names[i];
                names[i]=names[j];
                names[i]=temp;
        }
        set("exits", ([
                "north" : names[0],
                "south" : names[1],
                "east" : names[2],
                "west" : names[3],
        ]));
}


void init()
{
        add_action("do_open","open");
}
int do_open(string arg)
{ 
  object me,jia1,jia2;
  me=this_player();
  jia1=new("/d/qiankun/obj/vest");
  jia2=new("/d/qiankun/obj/dragon_armor");
        if ( !arg || arg !="box")   return notify_fail("你要打开什么?\n");
        if ( query("havejia") )
 {
    if ( query("havejia") && (int)me->query("combat_exp") >4999999 )
  {
     if ( (int)me->query_skill("parry",1) > 199 && (int)me->query_skill("parry",1) < 250 )
                {
                        message_vision(HIG"\n$N小心翼翼地打开箱子,突然...\n"NOR,me);
                        message_vision(HIG"一蓬细如牛毛的针雨从箱中射出,\n"NOR,me);
                        message_vision(HIG"尚未等$N反应过来,$N手上已经钉满了绿幽幽的唐门毒针.\n"NOR,me);
                        message_vision(HIG"$N忍着剧痛，从箱子里掏出一件甲来.\n"NOR,me);
                        jia1->move(me);
                        me->apply_condition("tm_poison",50);
                        me->update_condition();
                        delete("havejia");
                        me->check_status();               
                        return 1;
                }
     if ( (int)me->query_skill("parry",1) > 249)
                {
                        message_vision(HIG"\n$N小心翼翼地打开箱子,突然...\n"NOR,me);
                        message_vision(HIG"一蓬细如牛毛的针雨从箱中射出,\n"NOR,me);
                        message_vision(HIG"尚未等$N反应过来,$N手上已经钉满了绿幽幽的唐门毒针.\n"NOR,me);
                        message_vision(HIG"$N忍着剧痛，从箱子里掏出一件甲来.\n"NOR,me);
                        jia2->move(me);
                        me->apply_condition("tm_poison",100);
                        me->update_condition();
                        me->check_status(); 
                        delete("havejia");
                        return 1;
                }else{
                        message_vision(HIG"\n$N小心翼翼地打开箱子,突然...\n"NOR,me);
                        message_vision(HIG"一蓬细如牛毛的针雨从箱中射出,\n"NOR,me);
                        message_vision(HIG"尚未等$N反应过来,$N手上已经钉满了绿幽幽的唐门毒针.\n"NOR,me);
                        me->apply_condition("tm_poison",20);
                        me->update_condition();
                        delete("havejia");
                        me->check_status();               
                        return 1;
                }
    }else{
      message_vision(HIW"\n箱子里突然崩出个鬼森森的骷髅头，$N大骇之下，只觉得气血不畅，眼前一黑...\n"NOR,me);
      me->die();
    }
  }
  write("箱子里空无一物，什么都没有。\n");  
  return 1;
}


int valid_leave(object me,string dir)
{
        object stone;
        stone=new("/d/qiankun/obj/stone");

    if ( query("havestone") && (int)me->query("combat_exp") >4999999 ){
        
        message_vision(HIY"$N刚要离开这个黑乎乎的洞穴，只觉得脚下被什么东西拌了一下。\n"NOR,me);
                        delete("havestone");
                    if(  random(me->query_skill("move")) > 100) {
        message_vision(HIC"$N猛地一个急停换位，脚踏八卦，方才躲开脚下的羁绊之物，随手拣了起来。\n"NOR,me);
                    stone->move(me);
                    me->add("force",-1000);
                    }else{
        message_vision(HIR"$N脚下一个不稳，被绊了个跟头，摔得满脸是土，额头还碰了一个大包，疼得$N直呲牙。\n"NOR,me);
                    me->add("eff_kee",-1*me->query("max_kee")/2);
                    }
           }
                  
        return 1;
}

