// guangchang.c 广场
// by Masterall
 
inherit ROOM;
 
void create()
{set("short", "广场");
set("long", @LONG
    这是一个由大石板铺成的广场，是乾坤教弟子学习武功和互相切磋的地点。近来乾
坤教之所以势大，就是由于博采众长，吸取了不少门派武功的精华。几个乾坤教弟子正
在研习武艺，他们一看到你，立即放下身边的事情，一个个横眉立目，虎视耽耽的瞪着
你。
LONG
        );
         set("outdoors", "wudang");
 
        set("exits", ([
                "southdown" : __DIR__"shanlu1",
                "north" : __DIR__"gate",
        ]));
        set("objects",([
                 __DIR__"npc/jiaotu" : 4,
         ]));
setup();
replace_program(ROOM);
}
 

