// /d/xizang/class/hama/hamadong.c

inherit ROOM;

void create()
{
        set("short", "蛤蟆洞");
        set("long", @LONG
这里是一个阴暗潮湿的洞穴,弥漫着一股难闻的气味,几乎把你熏得晕了
过去.黑暗中隐约看见洞底有个模糊的影子,不知是人是兽,向你扑来!
LONG
        );
        set("exits", ([ 
  "out" : __DIR__"yvalley0",
]));
        set("objects", ([
                NPC_DIR"hama1" : random(4),
                NPC_DIR"hama2" : random(4),
                __DIR__"npc/hamawang" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
