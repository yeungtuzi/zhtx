// by Masterall
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"石室"NOR);
      set("long",HIW"这是一间石室，东面是块打磨光滑的“大石壁”，石壁旁点燃着
八根大火把，照耀明亮。壁上刻得有图有字。石室中已有十多人，有
的注目凝思，有的打坐练功，有的闭着双目喃喃自语，更有三四人在
大声争辩。

　　┌─────────────────────┐
　　│                                          │
　  │　                                        │
　　│           洹  赫  大  梁  城             │
　　│                                          │
　　│                                          │
    └─────────────────────┚
\n"NOR);     
 
        set("exits", ([
                "north" : __DIR__"sc1",
        ]));
        set("objects",([
                "/d/xkd/npc/puren2" : 1,
        ]) );

        setup();

} 
 

void init()
{
        add_action("do_yandu", "yandu");
}

int do_yandu(string arg)
{
       int wx;
       object me;
       me=this_player();

       wx = me->query("int");


       if ( !arg || arg != "wall" )
                return notify_fail("你要研读什么？\n");

       if ( !me->query("got_ling") )
                return notify_fail("你钻研了石壁半天，好像上面的图形文字对于你来说过于艰深了。\n");

       if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("你的潜能不够，无法继续研读石壁上的文字。\n");

       if ( me->query("force") < 10 )
                return notify_fail("你的内力太低了，还是休息一下再钻研石壁上的武学吧。\n");

       if ( me->query("gin") < 100 )
                return notify_fail("你的精太少了，还是休息一下再钻研石壁上的武学吧。\n");

       if ( me->query("sen") < 100 )
                return notify_fail("你的神太少了，还是休息一下再钻研石壁上的武学吧。\n");

       if ( me->query_skill("finger",1) < 200 )
                return notify_fail("你的基本功不够扎实，看了也是白看，甭在那里装蒜逞能了。\n");

       if ( me->query_skill("finger",1) > 250 )
                return notify_fail("墙壁上的武学精要对于你来说已经非常浅显了，不必再耗费精力研读了。\n");

       if ( me->query_skill("literate") ){
               
        tell_object(me,HIW"你一边看着墙壁上的图谱，一边研读边上的注释，参详对比之时顿觉疑窦重重，\n"+HIB"你苦苦思索了半天，还是一点头绪都找不出来。情急之下，不由得有些精神恍惚，觉得天旋地转，"+HIR"\n胸口有些发闷，随即“哇”的一声，鲜血吐了一地！\n"NOR);

        me->add("max_force", -100);
        me->add("max_mana", -50);
        me->add("max_atman", -50);
        me->unconcious();
          
        }else{

              printf("你全神贯注的研读石壁上的蝌蚪文，似乎对基本指法颇有心得。\n");
              me->receive_damage("sen", 100 );
              me->receive_damage("gin", 100 );
              me->add("force", -5 );
              me->add("learned_points", 1 + random(5));
              me->improve_skill("finger", wx + random(50) );
             }
}



