// Room: 山路

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIB"侠客岛密洞"NOR);
        set("long", @LONG
      这是一座黑漆漆的山洞，洞壁上都湿乎乎的，显然受到溪水的拍击，已经冲刷得不
成样子了，倒是光溜溜的，透着外面微弱的光线，甚至可以照出你那饱经沧桑的脸。
奇怪的是地面看起来倒是很松软，你可以试着挖挖看(dig)。
LONG
        );
        set("outdoors", "xkd");
        set("exits", ([ 
                "out" : __DIR__"pubu",
]));

        setup();
}

void reset() 
{
        ::reset();
        set("have_cloth",1);
        set("have_lighting",1);
}

void init()
{
        add_action("do_dig", "dig");
        add_action("do_pao", "pao");
}

int do_dig(string arg)
{

       object me,ob;
       me=this_player();

       if ( !arg || arg !="ground")   
                  return notify_fail("你挖哪里？\n");
 
       if ( !query("have_cloth") )
                  return notify_fail("这里刚才已经被人刨了个大坑，恐怕再挖下去也不会有什么宝贝了。\n");

       if ( me->query("str")< 50 )
                  return notify_fail("你的臂力太低，这么挖会拗断你的小细胳膊的！\n");

      if ( me->query("sen")< 150 )
                  return notify_fail("你的神太少了，还是看清楚一点再挖！\n");

       if ( !me->query_temp("can_dig") )
                  return notify_fail("你是从天上掉下来的还是找人给你背过来的，这种挖坑的脏活为什么不也找别人代劳呢？\n");

       if ( random(me->query("kar")) < 1 )
       {
       message_vision(HIR"\n天空中响起了一声炸雷，冥冥中$N听到有人在怒喝，“老朽的坟墓也是你能随随便便挖的吗？！”\n"NOR,me);
       message("system", HIM "\n【谣言】江湖传说(DIG)：听说"+me->name()+"由于偷坟掘墓，被侠客岛的前辈幽灵送进了监狱！\n"NOR,users() );
       delete("have_cloth");
       me->delete_temp("have_dig");
       me->delete_temp("have_jump");
       me->delete_temp("can_dig");
       me->move("/d/wizard/prizon.c");
       return 1;
       }
       message_vision(HIG"$N掏出了随身的利器，玩命地在地上挖着！！\n"NOR,me);
       me->add_temp("have_dig",1);
       me->receive_damage("sen",100);

       if ( random(me->query_temp("have_dig")) > 10 )
       {
       message_vision(HIC"$N挖着挖着，突然发现一件金光闪闪的宝物，好像是件衣服，\n在地上埋藏了许多年，居然没有任何腐烂的迹象！\n"NOR,me);
       message_vision(HIC"$N脑海中惊现出武林中的掌故传说，原来这就是江湖中失传多年的金缕玉衣！\n兴奋之余，不由得仰天长啸！！\n"NOR,me);
       ob=new("/u/m/masterall/obj/goldencloth.c");
       ob->move(me);
       delete("have_cloth");
       me->delete_temp("have_dig");
       me->delete_temp("have_jump");
       me->delete_temp("can_dig");
       me->set_temp("can_pao", 1);
       return 1;
       }

       return 1;
 
}


int do_pao(string arg)
{

       object me,ob;
       me=this_player();

       if ( !arg || arg !="ground")   
                  return notify_fail("你刨哪里？\n");
 
       if ( query("have_cloth") )
                  return notify_fail("这里的地面这么坚硬，你是刨不动的，还是先找个东西挖挖看吧！\n");

       if ( !query("have_lighting") )
                  return notify_fail("这里的土已经被人刨得干干净净了。\n");

       if ( me->query("force")< 8000)
                  return notify_fail("你的内力太低了，刨不动的！\n");

      if ( me->query("sen")< 150 )
                  return notify_fail("你的神太少了，还是看清楚一点再刨！\n");

       if ( !me->query_temp("can_pao") )
                  return notify_fail("你自己又没有挖坑，刨什么啊？\n");

       if ( random(me->query("kar")) < 2 )
       {
       message_vision(HIR"\n天空中亮起了一道厉闪，冥冥中$N听到有人在怒喝，“老朽的坟墓你挖也就挖了，怎么还刨起来没完啊？！”\n"NOR,me);
       message("system", HIM "\n【谣言】江湖传说(DIG)：听说"+me->name()+"由于偷坟掘墓，被侠客岛的前辈幽灵送进了监狱！\n"NOR,users() );
       delete("have_cloth");
       me->delete_temp("have_dig");
       me->delete_temp("have_pao");
       me->delete_temp("have_jump");
       me->delete_temp("can_dig");
       me->delete_temp("can_pao");
       me->move("/d/wizard/prizon.c");
       return 1;
       }
       message_vision(HIG"$N把手上的兵器扔在一边，玩命地在地上刨着！！\n"NOR,me);
       me->add_temp("have_pao",1);
       me->receive_damage("sen",100);

       if ( random(me->query_temp("have_pao")) > 30 )
       {
       message_vision(HIW"$N刨了半天，仍然一无所获，不由得仰天长叹！\n"NOR,me);
       message_vision(HIW"但手指尖突然一阵剧痛，好像触到了什么硬物！\n"NOR,me);
          if (random(2) == 0)
          {
          message_vision(HIC"$N把那件硬物翻出来一看，居然之是在江湖中司空见惯的寒于宝衣！\n"NOR,me);
          message_vision(HIC"$N待等拿起来仔细鉴别，才猛醒原来现世的寒于宝衣都是赝品！\n"NOR,me);
          message_vision(HIC"只有这件埋藏数百年而光洁如新的宝甲才是名副其实的——“寒于宝衣”！！！\n"NOR,me);
          ob=new("/d/xueshan/npc/obj/xxarmor.c");
          ob->move(me);
          }
          else
          {
          message_vision(HIC"$N把那件硬物翻出来一看，居然之是在江湖中司空见惯的旋芒宝剑！\n"NOR,me);
          message_vision(HIC"$N待等拿起来仔细鉴别，才猛醒原来现世的旋芒宝剑都是赝品！\n"NOR,me);
          message_vision(HIC"只有这把埋藏数百年仍然切金断玉的神剑才是名副其实的——“旋芒宝剑！！！”\n"NOR,me);
          ob=new("/d/xueshan/npc/obj/xxsword.c");
          ob->move(me);
          }
       delete("have_lighting");
       me->delete_temp("have_dig");
       me->delete_temp("have_jump");
       me->delete_temp("can_dig");
       me->delete_temp("can_pao");
       return 1;
       }

       return 1;
 
}


