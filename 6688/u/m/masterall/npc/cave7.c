#include <ansi.h>
inherit ROOM;
string *names=({
        __DIR__"cave7",
        __DIR__"cave5",
        __DIR__"cave1",
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
        set("haveweapon",1);
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
  object me;
  me=this_player();


        if ( !arg || arg !="box")   return notify_fail("你要打开什么?\n");
        if ( query("haveweapon") )
   {
    if ( (int)me->query("combat_exp") >4999999 )
  {
     if ( (int)me->query_skill("strike",1) >229 
       && (int)me->query_skill("cuff",1) >229
       && (int)me->query_skill("jingang-quan",1) >249)
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon11.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("liumai-shenjian",1) >199 )
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon12.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("pixie-sword",1) >219 )
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon13.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("spring-blade",1) > 219 )
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon14.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("essence-sword",1) >199 )
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon15.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("ill-quan",1) >199 )
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon16.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("cloudstaff",1) >249 )
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon17.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("dugu-jiujian",1) > 219)
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon18.c");
                        delete("haveweapon");
                        return 1;
                }
     if ( (int)me->query_skill("xuantie-sword",1) > 219)
                {
                        message_vision(HIY"\n$N试着摸索着箱子的缝隙，突然间....\n"NOR,me);
                        message_vision(HIR"$N觉得脚下一空，身子不住的下陷，落入了无穷无尽的深渊！\n"NOR,me);
                        me->move("/d/qiankun/prizon19.c");
                        delete("haveweapon");
                        return 1;
                }
  message_vision(YEL"\n$N在箱子里摸索了半天，一无所获，只好悻悻而返....\n"NOR,me); 
  return 1;
       }
    }else{
      message_vision(HIW"\n箱子里突然崩出个鬼森森的骷髅头，$N大骇之下，只觉得气血不畅，眼前一黑...\n"NOR,me);
      me->die();
    }
  write("箱子里空无一物，什么都没有。\n");  
  return 1;
}
