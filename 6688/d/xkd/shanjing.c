// Room: 山路

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"岛间山路"NOR);
        set("long", @LONG
  由岸口转入山中后，两旁都是森林，一条山径穿林而过。你留神四周景色，以备 
将来返回时不致迷了道路。行了数里，转入一条岩石嶙峋的山道，左临深涧，涧水 
湍急，激石有声。一路沿着山涧渐行渐高，转了两个弯后，只见一道瀑布从十余丈 
高处直挂下来，看来这瀑布便是山涧的源头。
LONG
        );
        set("outdoors", "xkd");
        set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"kouan",
                "north" : __DIR__"pubu",
]));

        setup();
}

void reset() 
{
        ::reset();
        set("can_jump",1);
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

       object me;
       me=this_player();

       if ( !arg || arg !="shanjian")   
                  return notify_fail("你要往哪里跳？\n");
 
       if ( !query("can_jump") )
                  return notify_fail("刚才已经有人不要命跳下去了，你还是掂量掂量再办吧。\n");

       if ( me->query("cor")< 30 )
                  return notify_fail("你胆子太小了，这么高恐怕很难跳下去！\n");

       if ( me->query("vis")< 30 )
                  return notify_fail("你在山涧旁左右徘徊，踌躇不定，待了大半天还是没有下定决心。\n");

       if ( me->query("combat_exp")< 12800000 )
                  return notify_fail("你想到自己还从未在江湖中立足，还未能尽享人间的荣华富贵，这个险还是不冒的好。\n");

       message_vision(HIR"\n$N仗了仗胆子，眼一闭，心一横，纵身向山涧中跳去！！\n"NOR,me);
       delete("can_jump");

       me->move("/d/xkd/shanjian");
       me->set_temp("have_jump", 1);
       return 1;
 
}

