          //kouan.c 侠客岛口岸

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"侠客岛海岸"NOR);
        set("long","这里就是传说中的侠客岛了，据说很多的武林前辈都隐居在此。
 
                         " + HIC "侠     "+HIG"客     "+HIY"岛" NOR + "
 
只见岸边茫茫无际的大海，让人心旷神怡。岛上乔木修竹，苍翠蔽天，
层峦奇幽，静窈幽深。一条青石小径伸向前方花丛深处。\n");

        set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"shanjing",
 // "south" : __DIR__"houting",
 
]));
/*
        set("objects",([
                "/d/xkd/npc/diamond" : 1,
                "/d/xkd/npc/sevenf" : 1,
                "/d/xkd/npc/duou" : 1,
        ]) );
*/

        set("outdoors", "xkd");

        setup();
}


void init() {

        add_action("do_yell","yell");
}


int do_yell(string arg) {

        object ling,me;
        me=this_player();

        if(!arg || (arg != "boat" && arg != "渡船" )) 
                return 0;
        else 
//               if (!objectp(ling = present("shangshan fae ling",me) ) )
//                return notify_fail("你身上没有赏善罚恶令，在那里乱叫什么！\n"); 
               if( !me->query("got_ling"))
                return notify_fail("你怎么这么不害臊，从哪里偷了个破东西就带着跑来穷嚎？！\n"); 
                call_out("telling_boat", 1, 0); 
                return 1;
}




void telling_boat(int i)
{
        object me=this_player();
        string *msg = ({
"$N用足内力，长啸一声，伴随着充沛的中气传入无边的海洋～～～！\n\n",
"一叶轻舟自远方急速驶来，未等靠岸停稳，$N已然一个纵身跃了上去。\n\n",
"船夫向$N会意的点了点头，也不问话，随即掉转船头，箭一般驶离了海岸。\n\n",
"不到半盏茶的功夫，前面已然隐隐出现一道海岸线，中原大地近在眼前。\n\n",
"$N向船夫拱了拱手，正要道谢，连人带船已然踪迹不见。\n\n",
});

        
        if( i >= sizeof(msg) ){
                this_object()->delete_temp("telling");
        tell_object(me,HIC"大陆本土到了，别忘了师门的重任！！！！\n\n"NOR);
                me->move("/d/xkd/seaside");
                return;
        }
        message_vision(HIG+msg[i]+NOR, me);
        call_out("telling_boat", 1, i+1);
        return;
}


