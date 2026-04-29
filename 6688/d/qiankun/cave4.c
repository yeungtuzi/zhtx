#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";
string *names=({
        __DIR__"cave6",
        __DIR__"cave2",
        __DIR__"exit",
        __DIR__"cave1",
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
        set("havejian",1);
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
  object me,jian1,jian2;
  me=this_player();
  jian1=new("/d/qiankun/obj/jian1");
  jian2=new("/d/qiankun/obj/jian2");
        if ( !arg || arg !="box")   return notify_fail("你要打开什么?\n");
        if ( query("havejian") )
   {
    if ( (int)me->query("combat_exp") >4999999 )
  {
     if ( (int)me->query_skill("sword",1) > 199 && (int)me->query_skill("sword",1) < 250 )
                {
                        message_vision(HIW"\n$N谨小慎微地用手中兵器将箱盖挑开,突然...\n"NOR,me);
                        message_vision(HIW"一只森森白骨的手抓住了你的兵器,\n"NOR,me);
                        message_vision(HIW"$N急忙用力回拉，只觉得浑身的内力倾泄而出！！\n"NOR,me);
                        message_vision(HIW"$N急定心神，才发现只不过是幻觉，顺手从箱中拣起一把剑来。\n"NOR,me);
                        me->add("max_force",-20);
                        jian1->move(me);
                        delete("havejian");
                        me->check_status();               
                        return 1;
                }
     if ( (int)me->query_skill("sword",1) > 249)
                {
                        message_vision(HIW"\n$N谨小慎微地用手中兵器将箱盖挑开,突然...\n"NOR,me);
                        message_vision(HIW"一只森森白骨的手抓住了你的兵器,\n"NOR,me);
                        message_vision(HIW"$N急忙用力回拉，只觉得浑身的内力倾泄而出！！！\n"NOR,me);
                        message_vision(HIW"$N急定心神，才发现只不过是幻觉，顺手从箱中拣起一把剑来。\n"NOR,me);
                        me->add("max_force",-30);
                        jian2->move(me);
                        delete("havejian");
                        me->check_status();               
                        return 1;
                }else{
                        message_vision(HIW"\n$N谨小慎微地用手中兵器将箱盖挑开,突然...\n"NOR,me);
                        message_vision(HIW"一只森森白骨的手抓住了你的兵器,\n"NOR,me);
                        message_vision(HIW"$N急忙用力回拉，只觉得浑身的内力倾泄而出！\n"NOR,me);
                        me->add("max_force",-10);
                        delete("havejian");
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



