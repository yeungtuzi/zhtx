#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";
string *names=({
        __DIR__"cave5",
        __DIR__"cave7",
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
        set("havejieyao",1);
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
  object me,jieyao1,jieyao2;
  me=this_player();
  jieyao1=new("/d/qiankun/obj/jieyao1");
  jieyao2=new("/d/qiankun/obj/jieyao2");
        if ( !arg || arg !="box")   return notify_fail("你要打开什么?\n");
        if ( query("havejieyao") )
   {
    if ( (int)me->query("combat_exp") >4999999 )
  {
     if ( (int)me->query_skill("force",1) > 199 && (int)me->query_skill("force",1) < 250 )
                {
                        message_vision(HIM"\n$N从地上拣起一根棍子，战战兢兢地挑开箱盖,躲得远远的等了许久...\n"NOR,me);
                        message_vision(HIM"结果什么事情都没有发生,\n"NOR,me);
                        message_vision(HIM"$N心下惭愧，身为一代宗师竟然如此胆怯，不由得仰天长叹！\n"NOR,me);
                        message_vision(HIM"$N走上前去，在箱子里乱翻了半天，找出了亮晶晶的一样物事！\n"NOR,me);
                        me->add("combat_exp",-10000);
                        jieyao1->move(me);
                        delete("havejieyao");
                        me->check_status();               
                        return 1;
                }
     if ( (int)me->query_skill("force",1) > 249 && random(me->query("kar")) > 30 )
                {
                        message_vision(HIM"\n$N从地上拣起一根棍子，战战兢兢地挑开箱盖,躲得远远的等了许久...\n"NOR,me);
                        message_vision(HIM"结果什么事情都没有发生,\n"NOR,me);
                        message_vision(HIM"$N心下惭愧，身为一代宗师竟然如此胆怯，不由得仰天长叹！\n"NOR,me);
                        message_vision(HIM"$N走上前去，在箱子里乱翻了半天，找出了亮晶晶的一样物事！\n"NOR,me);
                        me->add("combat_exp",-20000);
                        jieyao2->move(me);
                        delete("havejieyao");
                        me->check_status();               
                        return 1;
                }else{
                        message_vision(HIM"\n$N从地上拣起一根棍子，战战兢兢地挑开箱盖,躲得远远的等了许久...\n"NOR,me);
                        message_vision(HIM"结果什么事情都没有发生,\n"NOR,me);
                        message_vision(HIM"$N心下惭愧，身为一代宗师竟然如此胆怯，不由得仰天长叹！\n"NOR,me);
                        me->add("combat_exp",-5000);
                        delete("havejieyao");
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



