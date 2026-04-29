// seaside.c
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "蓬莱");
        set("long", @LONG
你已经到了蓬莱岛，传说中的海上仙山。你的正面就是大海，放眼望去，天水
一色，让你心旷神怡。如果你运气足够好，说不定你可以看到海市蜃楼。你的
左边有一艘看起来饱经风雨的古战船，右边是一个仙人洞，仙人早已仙去，
现在只有一个鱼妇在那里卖一些海贝。
LONG
        );

        set("exits", ([ 
        "west" : "/d/road/rjntopl2",
]));

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
               if( !me->query("got_ling"))
                return notify_fail("你怎么这么不害臊，从哪里偷了个破东西就带着跑来穷嚎？！\n"); 
               me->start_busy(10);
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
"不到半盏茶的功夫，前面已然隐隐出现一座小岛，弹指一挥间，侠客岛已近在$N的眼前。\n\n",
"$N向船夫拱了拱手，正要道谢，连人带船已然踪迹不见。\n\n",
});

        
        if( i >= sizeof(msg) ){
                this_object()->delete_temp("telling");
        tell_object(me,HIC"传说中的武林圣地——侠客岛到了！！！！\n\n"NOR);
                me->move("/d/xkd/kouan");
                return;
        }
        message_vision(HIG+msg[i]+NOR, me);
        call_out("telling_boat", 1, i+1);
        return;
}


