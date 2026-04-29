#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","牛家村内室");
        set("long", @LONG
       这里看起来破破烂烂 ,不过收拾的相当整洁，旁边有一小灶，
     里面还有不少吃的（chifan)，一看就知道有人来过。 。
LONG
        );

        set("exits", ([
        "south" :__DIR__"xiaowu"
        ]));
        set("sleep_room",1);

        setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan(string arg)
{
        object me;
        me = this_player();
	if( (me->query("food")>=(int)me->max_food_capacity() ) || 
	  (me->query("water") >= (int)me->max_water_capacity() ) ) {
		write(YEL "你不怕撑着呀？\n NOR");
		return 1;
	}

        me->start_busy(5);
        write(YEL "你坐下来饱饱地大吃了一顿\n" NOR);
        write(YEL "直吃得肚肥肠满才心满意足地站起身来\n" NOR);
        me->set("food",(int)me->max_food_capacity());
        me->set("water",(int)me->max_water_capacity());
                return 1;
}
