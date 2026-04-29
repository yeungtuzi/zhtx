#include <ansi.h>
//inherit ROOM;
inherit "/u/l/lazypig/room/qiankuncave.c";
string *names=({
        __DIR__"cave5",
        __DIR__"cave7",
        __DIR__"cave3",
        __DIR__"cave6",
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
        set("havebook",1);
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
  object me,shu1,shu2;
  me=this_player();
  shu1=new("/d/qiankun/obj/basicbook1");
  shu2=new("/d/qiankun/obj/basicbook2");
        if ( !arg || arg !="box")   return notify_fail("你要打开什么?\n");
        if ( query("havebook") )
   {
    if ( (int)me->query("combat_exp") >4999999 )
  {
     if ( (int)me->query_skill("literate",1) > 249 && (int)me->query_skill("literate",1) < 300 )
                {
                        message_vision(HIR"\n$N战战兢兢地打开箱子,突然...\n"NOR,me);
                        message_vision(HIR"一股呛人的浓烟从箱子里喷出,\n"NOR,me);
                        message_vision(HIR"尚未等$N屏住呼吸,辛辣的气味已经让$N近乎窒息.\n"NOR,me);
                        message_vision(HIR"$N在半昏迷中从箱中抄起了一样东西！\n"NOR,me);
                        me->apply_condition("ninemoonpoison",50);
                        me->update_condition();
                        shu1->move(me);
                        delete("havebook");
                        me->check_status();               
                        return 1;
                }
     if ( (int)me->query_skill("literate",1) > 299)
                {
                        message_vision(HIR"\n$N战战兢兢地打开箱子,突然...\n"NOR,me);
                        message_vision(HIR"一股呛人的浓烟从箱子里喷出,\n"NOR,me);
                        message_vision(HIR"尚未等$N屏住呼吸,辛辣的气味已经让$N近乎窒息.\n"NOR,me);
                        message_vision(HIR"$N在半昏迷中从箱中抄起了一样东西！\n"NOR,me);
                        me->apply_condition("ninemoonpoison",100);
                        me->update_condition();
                        shu2->move(me);
                        delete("havebook");
                        me->check_status();               
                        return 1;
                }else{
                        message_vision(HIR"\n$N战战兢兢地打开箱子,突然...\n"NOR,me);
                        message_vision(HIR"一股呛人的浓烟从箱子里喷出,\n"NOR,me);
                        message_vision(HIR"尚未等$N屏住呼吸,辛辣的气味已经让$N近乎窒息.\n"NOR,me);
                        me->apply_condition("ninemoonpoison",20);
                        me->update_condition();
                        delete("havebook");
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


