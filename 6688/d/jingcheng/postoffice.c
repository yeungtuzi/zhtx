// by dongsw 2002.2.21
#include <ansi.h>;
inherit ROOM;
void create()
{
  set ("short",HIC"纵横驿站"NOR);
set ("long",@LONG
这个就是位于京城中最大的驿站——纵横驿站了，过去这里的生意冷
冷清清，最近来了些江湖侠客来这里帮忙，这里热闹了起来，这里正
在招工之中，如果想在这里工作你可以问问那个邮差。
LONG
);
  set("objects",([
    "/d/jingcheng/npc/daizong.c":1,
]));
  set("exits",([
  "south":__DIR__"dchjie1",
]));
set("no_steal", "1");
set("no_fight", "1");
set("no_magic", "1");
set("no_spells", "1");
setup();
replace_program(ROOM);
}

