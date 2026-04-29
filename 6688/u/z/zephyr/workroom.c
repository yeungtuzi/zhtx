inherit ROOM;
#include "ansi.h"

void create()
{
        set("short", HIB"天目山"NOR);
        set("long", GRN@LONG

你来到天目山极顶...
你的面前出现了一座宫殿，虽然算不上气势磅礴，但是建筑异常精奇。
整个宫殿仿佛是用汉白玉雕刻而成，雕梁画栋。你仔细观察上面的雕
刻，发现都是些有名的神话传说和故事，皆栩栩如生，呼之欲出。宫
殿高三层，殿顶铺的是蓝色的琉璃瓦，在阳光下闪闪发亮。
一层檐下挂一檀香木牌，上书三个大字，笔笔精神饱满：

                葵      花      宫


宫殿前不远处一条小溪潺潺流过，溪水清澈见底，时有鱼儿游过。
溪边开着许多蓝天鹅，清香醉人。此时小溪边站着一女，宛若仙子。

           Email: ttongcc@163.com               

LONG NOR);
        set("exits", 
        ([
                "west" : "/d/wizard/wizard_room",
                "j" : "/d/jingcheng/tamgch",
                "q" : "/d/qiankun/cave",
                "x" : "/d/xixia/southsquare",
                "p" : "/d/xanadu/lou9",
                "east" : "/u/z/zephyr/sunflower/darkwood/darkwoodedge1",
                        ]));
        set("objects", ([
                __DIR__"xianzi" : 1 ]) );

        set("valid_startroom", 1);
//        set("no_fight", 1);
        replace_program(ROOM);
        setup();
}
