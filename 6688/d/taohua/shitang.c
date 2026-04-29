#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这屋由不剥皮的松木搭成。屋外攀满香藤，进屋后顿感一阵清凉。
屋内有些桌几，哑仆送上茶来，茶颜色碧绿，冷若雪水，入口凉沁心脾。  
LONG
        );
        set("exits", ([ /* sizeof() == 2 */  
  "east" : __DIR__"houting",
  "west" : __DIR__"chufang",
]));


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
