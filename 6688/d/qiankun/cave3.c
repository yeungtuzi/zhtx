#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";
string *names=({
        __DIR__"cave5",
        __DIR__"cave6",
        __DIR__"cave4",
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
        set("objects",([
                 __DIR__"npc/niumowang" : 1,
        ]));
        setup();
}
void reset()
{
        int i,j;
        string temp;
        ::reset();
        set("haveyao",1);
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
  object me,yao1,yao2;
  me=this_player();
  yao1=new("/d/qiankun/obj/putizi");
  yao2=new("/d/qiankun/obj/xiandan");
        if ( !arg || arg !="box")   return notify_fail("你要打开什么?\n");
        if ( me->query_condition("xiandan_drug"))   return notify_fail("你刚吃的仙丹还没消化完，那么着急干什么?\n");
        if ( query("haveyao") )
   {          
    if ( (int)me->query("combat_exp") >4999999 )
  {      
     if ( (int)me->query_skill("force",1) > 199 && (int)me->query_skill("force",1) < 251 )
                {
                        message_vision(HIY"\n$N猛的掀开了箱子,把脑袋探了进去,突然...\n"NOR,me);
                        message_vision(HIY"一个斗大的木锤扑面而来,\n"NOR,me);
                        message_vision(HIY"尚未等$N来得及躲避,$N的头部已经受到重重的一击！ \n"NOR,me);
                        message_vision(HIY"$N眼冒金星，但在昏迷的一刹那紧紧抓住了一个小瓶子！\n"NOR,me);
                        me->set("eff_kee",me->query("max_kee")/8);
                        yao1->move(me);
                        delete("haveyao");
                        me->check_status();               
                        return 1;
                }
     if ( (int)me->query_kar()>19 && (int)me->query_skill("force",1) > 250 && random(5)> 0)
                {
                        message_vision(HIY"\n$N猛的掀开了箱子,把脑袋探了进去,突然...\n"NOR,me);
                        message_vision(HIY"一个斗大的木锤扑面而来,\n"NOR,me);
                        message_vision(HIY"尚未等$N来得及躲避,$N的头部已经受到重重的一击！ \n"NOR,me);
                        message_vision(HIY"$N眼冒金星，但在昏迷的一刹那紧紧抓住了一个小瓶子！\n"NOR,me);
                        yao2->move(me);
                        yao2->set("owner", me);
                        me->unconcious();
                        delete("haveyao");
                        me->check_status();               
                        me->move("/d/xanadu/inn.c");               
                        return 1;
                }else
                {
                        message_vision(HIY"\n$N猛的掀开了箱子,把脑袋探了进去,突然...\n"NOR,me);
                        message_vision(HIY"一个斗大的木锤扑面而来,\n"NOR,me);
                        message_vision(HIY"尚未等$N来得及躲避,$N的头部已经受到重重的一击！ \n"NOR,me);
                        me->set("eff_kee",me->query("max_kee")/4);
                        delete("haveyao");
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



